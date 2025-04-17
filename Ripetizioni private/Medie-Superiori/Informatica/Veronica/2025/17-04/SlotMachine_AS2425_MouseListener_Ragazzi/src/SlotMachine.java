
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.*;

// JFRame = finestra principale dell'applicazione
// Mischia parte logica e parte grafica

public class SlotMachine extends JFrame {

    protected CasellaSlot[] txtCaselleSlot;
    private JButton btnCoin,btnRipristina;
    private JButton btnGioca;
    private JCheckBox cbConferma;
    private MyLabel lblJackpot, lblCoin;
    private int numCaselleSlot;

    // Costruttore classico del tipo SlotMachine - lancia e setta tutte le componenti
    public SlotMachine(int numCaselle) {
        super("SlotMachine");
        // Inizializzazione del dato = caselle

        numCaselleSlot = numCaselle;
        txtCaselleSlot = new CasellaSlot[numCaselleSlot];
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        // impostazione grafica
        initComponenti();
        initPannelli();
        initAscoltatori();
       
        pack();
        setVisible(true);
        btnRipristina.doClick();
    }
    
    private void initComponenti(){
        // Etichette = Labels
        lblJackpot = new MyLabel("JACKPOT", 100);
        
        for(int i = 0; i < txtCaselleSlot.length; i++){
            txtCaselleSlot[i] = new CasellaSlot();
        }

        // Bottoni e abilitazione (costruttori ad oggetti)

        btnCoin = new JButton("INSERT COIN");
        lblCoin = new MyLabel("Coin", 0);
        cbConferma = new JCheckBox("Conferma Giocata");
        
        btnGioca = new JButton("GIOCA");
        btnGioca.setEnabled(false);

        btnRipristina = new JButton("RIPRISTINA");
    } /* FINE INITCOMPONENTI */
    
    private void initPannelli(){
        /* INIT PANNELLO NORD: ETICHETTA JACKPOT */

        // JPanel = azione principale del JFrame (SlotMachine)

        JPanel pnlNord = new JPanel();
        pnlNord.add(lblJackpot);
        
        /*
        PANNELLO SUD = Quattro caselle gialle equispaziate per i numeri slot
        */
        JPanel pnlCentro = new JPanel(new GridLayout(1, 4, 5, 5));
        pnlCentro.setBackground(Color.GRAY);
        pnlCentro.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        for(int i = 0; i < numCaselleSlot; i++){
            pnlCentro.add(txtCaselleSlot[i]);
        }
        
        /*
        PANNELLO SUD = Bottone moneta | Etichetta che viene aggiornata | Conferma
        */
        JPanel pnlSud = new JPanel(new GridLayout(2, 1));
        pnlSud.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        
        JPanel pnlSudUp = new JPanel(new GridLayout(1, 3));
        pnlSudUp.add(btnCoin);
        pnlSudUp.add(lblCoin);
        pnlSudUp.add(cbConferma);
        
        JPanel pnlSudDown = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        pnlSudDown.add(btnGioca);
        pnlSudDown.add(btnRipristina);
        
        pnlSud.add(pnlSudUp);
        pnlSud.add(pnlSudDown);

        /* INIT CONTENT PANE */

        // Container = JContentPane = Buttaci dentro tutto il contenuto principale JFrame

        Container topContainer = this.getContentPane();
        topContainer.add(pnlNord, BorderLayout.NORTH);
        topContainer.add(pnlCentro, BorderLayout.CENTER);
        topContainer.add(pnlSud, BorderLayout.SOUTH);
    }
    private void initAscoltatori(){
        
        /* ASCOLTATORE 1:
            Su btnCoin deve essere associato un ascoltatore ActionListener su classe ANONIMA
            l'Ascoltatore risponde come da DEMO del file JAR
        */

        // LIstener = Aspetta che succeda un certo evento
        // ActionListener = Classe di Java Swing per l'evento
        btnCoin.addActionListener(new ActionListener() {
        @Override
            public void actionPerformed(ActionEvent e) {
                lblCoin.incrementa(); // incrementa etichetta della moneta
            }
        });
 
        /* ASCOLTATORE 2:
        Associo un unico oggetto ai tre bottoni (cancella / gioca / ripristina)
        */
        AscoltaClick ascolta = new AscoltaClick();
        
        cbConferma.addActionListener(ascolta);
        btnGioca.addActionListener(ascolta);
        btnRipristina.addActionListener(ascolta);        
        
        /* ASCOLTATORE 3:
            Sull'array delle caselle Slot devi associate un ascoltatore che implementa MouseListener su classe INTERNA
            L'evento da intercettare è: "è stato cliccato il bottone DESTRO nel mouse in una casella slot ... "
            l'Ascoltatore risponde come da DEMO del file JAR
        
        AscoltaMouse mouse = new AscoltaMouse();
        for(int i = 0; i < numCaselleSlot; i++){
            txtCaselleSlot[i].addMouseListener(mouse);
        }
        */

        /* ASCOLTATORE 4:
            Sostituisci l'ascoltatore 3 presente sulle caselle Slot con un ascoltatore che estende MouseAdapter su classe ESTERNA
            L'evento da intercettare è: "è stato cliccato il bottone DESTRO nel mouse in una casella slot ... "
            l'Ascoltatore risponde come da DEMO del file JAR
        */
        
        AscoltaMouseAdapter mouseAdapter = new AscoltaMouseAdapter();
        for(int i = 0; i < numCaselleSlot; i++){
            txtCaselleSlot[i].addMouseListener(mouseAdapter);
        }

        
    }/* FINE INITASCOLTATORI */

    // extends = Sottoclasse
    // implements = Interfaccia = Per contratto (polimorfo) implementa un'operazione
    public class AscoltaClick implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getActionCommand().equals("Conferma Giocata")){
                btnCoin.setEnabled(false);
                cbConferma.setEnabled(false);
                btnGioca.setEnabled(true);
                btnGioca.doClick();
            }
            else if(e.getActionCommand().equals("GIOCA")){
                if(lblCoin.getValore() > 0){
                    // Aggiornamento (logico e poi grafico) delle monete e del jackpot
                    lblCoin.decrementa();
                    lblJackpot.incrementa();
                    // Chiamata random per numeri e vedere vittoria
                    for(int i = 0; i < numCaselleSlot; i++){
                        CasellaSlot casella = txtCaselleSlot[i];
                        if(!casella.isBloccata())casella.setValoreCasuale();
                        else casella.bloccaSblocca();
                    }
                    boolean vincita = true;
                    for(int i = 0; i < numCaselleSlot - 1; i++){
                        if(txtCaselleSlot[i].getValore() != txtCaselleSlot[i+1].getValore()) vincita = false;
                    }
                    if(vincita){
                        btnGioca.setEnabled(false);
                        btnGioca.setText("HAI VINTO!");
                    }
                }
                else btnRipristina.doClick();
            }
            else{
                lblCoin.setValore(0);
                lblJackpot.setValore(100);
                btnCoin.setEnabled(true);
                cbConferma.setEnabled(true);
                cbConferma.setSelected(false);
                btnGioca.setEnabled(false);
                btnGioca.setText("GIOCA");
                for(int i = 0; i < numCaselleSlot; i++){
                    txtCaselleSlot[i].resetCasella();
                }
            }
        }

    }
    
    public class AscoltaMouse implements MouseListener{

        @Override
        public void mouseClicked(MouseEvent e) {
            if(e.getButton() == 3){
                CasellaSlot casella = (CasellaSlot) e.getComponent();
                casella.bloccaSblocca();
            }
        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }

    }

} /* FINE CLASSE SLOTMACHINE */
