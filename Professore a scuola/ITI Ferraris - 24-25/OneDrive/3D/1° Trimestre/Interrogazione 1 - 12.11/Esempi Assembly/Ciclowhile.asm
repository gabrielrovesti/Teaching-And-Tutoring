name "Ciclo while"
data segment
    num1	DW 123Ah
	num2	DW 0003h
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
    cmp bx,0	
	je fine-ciclo    ;se BX=0 esce dal ciclo
	add dx,ax	     ;calcola le somme parziali		
	dec bx	         ;decrementa num2
	jmp inizio-ciclo ;salta indietro per ripetere il ciclo
fine-ciclo:
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
