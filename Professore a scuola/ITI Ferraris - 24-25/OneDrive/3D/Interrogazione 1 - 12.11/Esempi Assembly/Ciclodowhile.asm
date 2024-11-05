name "Ciclo do-while"
data segment
    num1	DW 11EBh
	num2	DW 0004h
	ris	    DW 0000h
    pkey db "press any key...$"
ends
stack segment
    dw   128  dup(0)
ends
code segment
start:
    mov ax, data
    mov ds, ax
    mov es, ax

    mov ax,0000h
	mov bx,0000h
	mov dx,0000h ;registro per le somme parziali
	mov ax,num1
	mov bx,num2 ;consente di non modificare num2
inizio-ciclo:    
    add dx,ax   ;operazioni prima del test su BX
    dec bx      ;decrementa num2
    cmp bx,0    ;controlla se e' arrivato a 0
    jne inizio-ciclo ;salta indietro per ripetere il ciclo
mov ris,dx	;salva il risultato della moltiplicazione    
            
    lea dx, pkey
    mov ah, 9
    int 21h      
    mov ah, 1
    int 21h    
    mov ax, 4c00h
    int 21h    
ends
end start
