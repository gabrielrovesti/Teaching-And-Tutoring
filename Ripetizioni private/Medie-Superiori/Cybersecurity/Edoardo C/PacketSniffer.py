#!/usr/bin/env python3

import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox
import threading
import time
from collections import defaultdict, deque
import ipaddress
import socket
from scapy.all import *
from scapy.layers.l2 import ARP, Ether
from scapy.layers.inet import IP, TCP, UDP, ICMP
import netifaces
import subprocess
import platform
import os

class StrumentoScopertaRete:
    def __init__(self, root):
        self.root = root
        self.root.title("Strumento di Scoperta Rete e Monitor Comunicazioni")
        self.root.geometry("1200x800")
        
        # Strutture dati
        self.dispositivi_scoperti = {}
        self.dati_comunicazione = defaultdict(lambda: defaultdict(int))
        self.buffer_pacchetti = deque(maxlen=1000)
        self.monitoraggio_attivo = False
        self.thread_scoperta = None
        self.thread_monitor = None
        
        # Interfaccia di rete
        self.interfaccia_selezionata = tk.StringVar()
        self.range_rete = tk.StringVar()
        
        self.configura_interfaccia()
        self.ottieni_interfacce_rete()
        
    def configura_interfaccia(self):
        # Notebook principale per le schede
        notebook = ttk.Notebook(self.root)
        notebook.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        
        # Scheda Scoperta
        frame_scoperta = ttk.Frame(notebook)
        notebook.add(frame_scoperta, text="Scoperta Rete")
        self.configura_scheda_scoperta(frame_scoperta)
        
        # Scheda Monitor Comunicazioni
        frame_monitor = ttk.Frame(notebook)
        notebook.add(frame_monitor, text="Monitor Comunicazioni")
        self.configura_scheda_monitor(frame_monitor)
        
        # Scheda Analisi Pacchetti
        frame_analisi = ttk.Frame(notebook)
        notebook.add(frame_analisi, text="Analisi Pacchetti")
        self.configura_scheda_analisi(frame_analisi)
        
    def configura_scheda_scoperta(self, parent):
        # Frame di controllo
        frame_controllo = ttk.LabelFrame(parent, text="Configurazione Rete")
        frame_controllo.pack(fill=tk.X, padx=5, pady=5)
        
        # Selezione interfaccia
        ttk.Label(frame_controllo, text="Interfaccia di Rete:").grid(row=0, column=0, sticky=tk.W, padx=5, pady=5)
        combo_interfaccia = ttk.Combobox(frame_controllo, textvariable=self.interfaccia_selezionata, width=20)
        combo_interfaccia.grid(row=0, column=1, padx=5, pady=5)
        self.combo_interfaccia = combo_interfaccia
        
        # Range di rete
        ttk.Label(frame_controllo, text="Range Rete:").grid(row=0, column=2, sticky=tk.W, padx=5, pady=5)
        entry_rete = ttk.Entry(frame_controllo, textvariable=self.range_rete, width=20)
        entry_rete.grid(row=0, column=3, padx=5, pady=5)
        
        # Pulsanti
        ttk.Button(frame_controllo, text="Auto-rileva", command=self.auto_rileva_rete).grid(row=0, column=4, padx=5, pady=5)
        ttk.Button(frame_controllo, text="Scopri", command=self.avvia_scoperta).grid(row=0, column=5, padx=5, pady=5)
        
        # Frame risultati
        frame_risultati = ttk.LabelFrame(parent, text="Dispositivi Scoperti")
        frame_risultati.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Treeview per dispositivi
        colonne = ("IP", "MAC", "Hostname", "Fornitore", "Stato")
        self.albero_dispositivi = ttk.Treeview(frame_risultati, columns=colonne, show="headings", height=15)
        
        for col in colonne:
            self.albero_dispositivi.heading(col, text=col)
            self.albero_dispositivi.column(col, width=150)
        
        # Scrollbar
        scrollbar_v = ttk.Scrollbar(frame_risultati, orient=tk.VERTICAL, command=self.albero_dispositivi.yview)
        scrollbar_h = ttk.Scrollbar(frame_risultati, orient=tk.HORIZONTAL, command=self.albero_dispositivi.xview)
        self.albero_dispositivi.configure(yscrollcommand=scrollbar_v.set, xscrollcommand=scrollbar_h.set)
        
        self.albero_dispositivi.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar_v.pack(side=tk.RIGHT, fill=tk.Y)
        scrollbar_h.pack(side=tk.BOTTOM, fill=tk.X)
        
    def configura_scheda_monitor(self, parent):
        # Frame di controllo
        frame_controllo = ttk.LabelFrame(parent, text="Controlli Monitoraggio")
        frame_controllo.pack(fill=tk.X, padx=5, pady=5)
        
        self.pulsante_monitor = ttk.Button(frame_controllo, text="Avvia Monitoraggio", command=self.commuta_monitoraggio)
        self.pulsante_monitor.pack(side=tk.LEFT, padx=5, pady=5)
        
        ttk.Button(frame_controllo, text="Cancella Dati", command=self.cancella_dati_comunicazione).pack(side=tk.LEFT, padx=5, pady=5)
        
        # Etichetta stato
        self.etichetta_stato = ttk.Label(frame_controllo, text="Stato: Fermato")
        self.etichetta_stato.pack(side=tk.RIGHT, padx=5, pady=5)
        
        # Frame dati comunicazione
        frame_comm = ttk.LabelFrame(parent, text="Matrice Comunicazioni")
        frame_comm.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Treeview per dati comunicazione
        colonne_comm = ("IP Sorgente", "IP Destinazione", "Protocollo", "Pacchetti", "Ultimo Visto")
        self.albero_comm = ttk.Treeview(frame_comm, columns=colonne_comm, show="headings", height=20)
        
        for col in colonne_comm:
            self.albero_comm.heading(col, text=col)
            self.albero_comm.column(col, width=120)
        
        scrollbar_comm = ttk.Scrollbar(frame_comm, orient=tk.VERTICAL, command=self.albero_comm.yview)
        self.albero_comm.configure(yscrollcommand=scrollbar_comm.set)
        
        self.albero_comm.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar_comm.pack(side=tk.RIGHT, fill=tk.Y)
        
    def configura_scheda_analisi(self, parent):
        # Dettagli pacchetti
        frame_dettagli = ttk.LabelFrame(parent, text="Dettagli Pacchetti")
        frame_dettagli.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        self.testo_pacchetti = scrolledtext.ScrolledText(frame_dettagli, height=25, width=80)
        self.testo_pacchetti.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Bind evento selezione
        self.albero_comm.bind('<<TreeviewSelect>>', self.su_selezione_comunicazione)
        
    def ottieni_interfacce_rete(self):
        """Ottieni interfacce di rete disponibili"""
        try:
            interfacce = netifaces.interfaces()
            # Filtra interfacce loopback e virtuali
            interfacce_reali = []
            for iface in interfacce:
                if not iface.startswith(('lo', 'Loopback')):
                    interfacce_reali.append(iface)
            
            self.combo_interfaccia['values'] = interfacce_reali
            if interfacce_reali:
                self.interfaccia_selezionata.set(interfacce_reali[0])
        except Exception as e:
            messagebox.showerror("Errore", f"Impossibile ottenere interfacce di rete: {e}")
    
    def auto_rileva_rete(self):
        """Auto-rileva range di rete basato sull'interfaccia selezionata"""
        try:
            interfaccia = self.interfaccia_selezionata.get()
            if not interfaccia:
                messagebox.showwarning("Avviso", "Seleziona un'interfaccia di rete")
                return
            
            indirizzi = netifaces.ifaddresses(interfaccia)
            if netifaces.AF_INET in indirizzi:
                info_ip = indirizzi[netifaces.AF_INET][0]
                ip = info_ip['addr']
                netmask = info_ip['netmask']
                
                # Calcola range di rete
                rete = ipaddress.IPv4Network(f"{ip}/{netmask}", strict=False)
                self.range_rete.set(str(rete))
            else:
                messagebox.showwarning("Avviso", "Nessun indirizzo IPv4 trovato per l'interfaccia selezionata")
        except Exception as e:
            messagebox.showerror("Errore", f"Impossibile auto-rilevare la rete: {e}")
    
    def avvia_scoperta(self):
        """Avvia scoperta rete"""
        if not self.range_rete.get():
            messagebox.showwarning("Avviso", "Specifica il range di rete")
            return
        
        if self.thread_scoperta and self.thread_scoperta.is_alive():
            messagebox.showinfo("Info", "Scoperta già in corso")
            return
        
        self.thread_scoperta = threading.Thread(target=self.scopri_rete, daemon=True)
        self.thread_scoperta.start()
    
    def scopri_rete(self):
        """Esegui scansione ARP per scoprire dispositivi"""
        try:
            rete = self.range_rete.get()
            interfaccia = self.interfaccia_selezionata.get()
            
            # Cancella dati esistenti
            self.albero_dispositivi.delete(*self.albero_dispositivi.get_children())
            self.dispositivi_scoperti.clear()
            
            # Crea richiesta ARP
            richiesta_arp = ARP(pdst=rete)
            broadcast = Ether(dst="ff:ff:ff:ff:ff:ff")
            richiesta_arp_broadcast = broadcast / richiesta_arp
            
            # Invia richiesta e ricevi risposta
            lista_risposte = srp(richiesta_arp_broadcast, timeout=2, verbose=False, iface=interfaccia)[0]
            
            # Processa risposte
            for elemento in lista_risposte:
                ip = elemento[1].psrc
                mac = elemento[1].hwsrc
                
                # Prova a risolvere hostname
                try:
                    hostname = socket.gethostbyaddr(ip)[0]
                except:
                    hostname = "Sconosciuto"
                
                # Ottieni info fornitore (semplificato)
                fornitore = self.ottieni_info_fornitore(mac)
                
                # Memorizza info dispositivo
                info_dispositivo = {
                    'ip': ip,
                    'mac': mac,
                    'hostname': hostname,
                    'fornitore': fornitore,
                    'stato': 'Attivo'
                }
                
                self.dispositivi_scoperti[ip] = info_dispositivo
                
                # Aggiorna GUI
                self.root.after(0, self.aggiorna_albero_dispositivi, info_dispositivo)
                
        except Exception as e:
            self.root.after(0, lambda: messagebox.showerror("Errore", f"Scoperta fallita: {e}"))
    
    def ottieni_info_fornitore(self, mac):
        """Ottieni informazioni fornitore da indirizzo MAC (semplificato)"""
        # Versione semplificata. In pratica useresti un database OUI
        oui = mac[:8].upper().replace(':', '')
        mappa_fornitori = {
            '00:50:56': 'VMware',
            '08:00:27': 'VirtualBox',
            '00:0C:29': 'VMware',
            '00:1B:21': 'Intel',
            '00:E0:4C': 'Realtek',
        }
        return mappa_fornitori.get(oui, 'Sconosciuto')
    
    def aggiorna_albero_dispositivi(self, info_dispositivo):
        """Aggiorna albero dispositivi con nuovo dispositivo"""
        self.albero_dispositivi.insert('', 'end', values=(
            info_dispositivo['ip'],
            info_dispositivo['mac'],
            info_dispositivo['hostname'],
            info_dispositivo['fornitore'],
            info_dispositivo['stato']
        ))
    
    def commuta_monitoraggio(self):
        """Avvia/ferma monitoraggio pacchetti"""
        if not self.monitoraggio_attivo:
            self.avvia_monitoraggio()
        else:
            self.ferma_monitoraggio()
    
    def avvia_monitoraggio(self):
        """Avvia monitoraggio pacchetti"""
        interfaccia = self.interfaccia_selezionata.get()
        if not interfaccia:
            messagebox.showwarning("Avviso", "Seleziona un'interfaccia di rete")
            return
        
        self.monitoraggio_attivo = True
        self.pulsante_monitor.config(text="Ferma Monitoraggio")
        self.etichetta_stato.config(text="Stato: Monitoraggio")
        
        self.thread_monitor = threading.Thread(target=self.monitora_pacchetti, daemon=True)
        self.thread_monitor.start()
        
        # Avvia timer aggiornamento GUI
        self.aggiorna_display_comunicazione()
    
    def ferma_monitoraggio(self):
        """Ferma monitoraggio pacchetti"""
        self.monitoraggio_attivo = False
        self.pulsante_monitor.config(text="Avvia Monitoraggio")
        self.etichetta_stato.config(text="Stato: Fermato")
    
    def monitora_pacchetti(self):
        """Monitora pacchetti di rete"""
        try:
            interfaccia = self.interfaccia_selezionata.get()
            
            def gestore_pacchetti(pacchetto):
                if not self.monitoraggio_attivo:
                    return
                
                if IP in pacchetto:
                    ip_src = pacchetto[IP].src
                    ip_dst = pacchetto[IP].dst
                    protocollo = "Sconosciuto"
                    
                    if TCP in pacchetto:
                        protocollo = f"TCP:{pacchetto[TCP].dport}"
                    elif UDP in pacchetto:
                        protocollo = f"UDP:{pacchetto[UDP].dport}"
                    elif ICMP in pacchetto:
                        protocollo = "ICMP"
                    
                    # Memorizza dati comunicazione
                    chiave_comm = (ip_src, ip_dst, protocollo)
                    self.dati_comunicazione[chiave_comm]['conteggio'] += 1
                    self.dati_comunicazione[chiave_comm]['ultimo_visto'] = time.strftime("%H:%M:%S")
                    
                    # Memorizza pacchetto per analisi
                    self.buffer_pacchetti.append({
                        'timestamp': time.time(),
                        'src': ip_src,
                        'dst': ip_dst,
                        'protocollo': protocollo,
                        'pacchetto': pacchetto
                    })
            
            # Avvia cattura pacchetti
            sniff(iface=interfaccia, prn=gestore_pacchetti, store=0, stop_filter=lambda x: not self.monitoraggio_attivo)
            
        except Exception as e:
            self.root.after(0, lambda: messagebox.showerror("Errore", f"Monitoraggio fallito: {e}"))
    
    def aggiorna_display_comunicazione(self):
        """Aggiorna display comunicazione"""
        if self.monitoraggio_attivo:
            # Cancella e aggiorna albero comunicazioni
            self.albero_comm.delete(*self.albero_comm.get_children())
            
            for (src, dst, protocollo), dati in self.dati_comunicazione.items():
                self.albero_comm.insert('', 'end', values=(
                    src, dst, protocollo, dati['conteggio'], dati['ultimo_visto']
                ))
            
            # Pianifica prossimo aggiornamento
            self.root.after(1000, self.aggiorna_display_comunicazione)
    
    def cancella_dati_comunicazione(self):
        """Cancella dati comunicazione"""
        self.dati_comunicazione.clear()
        self.buffer_pacchetti.clear()
        self.albero_comm.delete(*self.albero_comm.get_children())
        self.testo_pacchetti.delete(1.0, tk.END)
    
    def su_selezione_comunicazione(self, event):
        """Gestisci selezione albero comunicazioni"""
        selezione = self.albero_comm.selection()
        if not selezione:
            return
        
        elemento = self.albero_comm.item(selezione[0])
        valori = elemento['values']
        
        if len(valori) >= 3:
            ip_src, ip_dst, protocollo = valori[0], valori[1], valori[2]
            
            # Trova pacchetti correlati
            pacchetti_correlati = []
            for info_pacchetto in self.buffer_pacchetti:
                if (info_pacchetto['src'] == ip_src and 
                    info_pacchetto['dst'] == ip_dst and 
                    info_pacchetto['protocollo'] == protocollo):
                    pacchetti_correlati.append(info_pacchetto)
            
            # Mostra dettagli pacchetti
            self.mostra_dettagli_pacchetti(pacchetti_correlati)
    
    def mostra_dettagli_pacchetti(self, pacchetti):
        """Mostra informazioni dettagliate sui pacchetti"""
        self.testo_pacchetti.delete(1.0, tk.END)
        
        if not pacchetti:
            self.testo_pacchetti.insert(tk.END, "Nessun pacchetto trovato per questa comunicazione.\n")
            return
        
        self.testo_pacchetti.insert(tk.END, f"Trovati {len(pacchetti)} pacchetti per questa comunicazione:\n\n")
        
        for i, info_pacchetto in enumerate(pacchetti[-10:]):  # Mostra ultimi 10 pacchetti
            self.testo_pacchetti.insert(tk.END, f"=== Pacchetto {i+1} ===\n")
            self.testo_pacchetti.insert(tk.END, f"Timestamp: {time.ctime(info_pacchetto['timestamp'])}\n")
            self.testo_pacchetti.insert(tk.END, f"Sorgente: {info_pacchetto['src']}\n")
            self.testo_pacchetti.insert(tk.END, f"Destinazione: {info_pacchetto['dst']}\n")
            self.testo_pacchetti.insert(tk.END, f"Protocollo: {info_pacchetto['protocollo']}\n")
            
            # Mostra riassunto pacchetto
            try:
                riassunto_pacchetto = info_pacchetto['pacchetto'].summary()
                self.testo_pacchetti.insert(tk.END, f"Riassunto: {riassunto_pacchetto}\n")
            except:
                pass
            
            self.testo_pacchetti.insert(tk.END, "\n" + "="*50 + "\n\n")

def main():
    # Controlla se eseguito come root/amministratore
    if platform.system() != "Windows":
        if os.geteuid() != 0:
            messagebox.showerror("Errore", "Questa applicazione richiede privilegi di root per catturare pacchetti.\nEsegui con sudo.")
            return
    
    root = tk.Tk()
    app = StrumentoScopertaRete(root)
    root.mainloop()

if __name__ == "__main__":
    main()