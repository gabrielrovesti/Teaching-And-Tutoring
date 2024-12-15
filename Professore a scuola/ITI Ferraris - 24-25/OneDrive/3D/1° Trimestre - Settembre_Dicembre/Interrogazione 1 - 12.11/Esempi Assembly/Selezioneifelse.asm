name "Selezione if-else"
data segment
    num1 DB 4Bh
	num2 DB 12h
	ris	 DB 00h
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
	mov al,num1    
	cmp al,num2 ;confronta i due numeri attraverso
			    ;una sottrazione e setta i flag
	jge salta ;salta se il primo operando e' maggiore o uguale
	          ;del secondo. Testa il flag S (Sign):
			  ;se S = 0 salta all'istruzione con label "salta", 
			  ;se S = 1 non salta ed esegue le successive istruzioni
	add al,num2	;calcola la somma e mette il risultato in AL
	jmp fine	;salto incondizionato (non serve la CMP)
salta:	
    sub al,num2 ;calcola la differenza e mette il risultato in AL
fine:	
    mov ris,al  ;salva il risultato in memoria nella variabile ris
			    ;comune a entrambi i rami            
    lea dx, pkey
    mov ah, 9
    int 21h     
    mov ah, 1
    int 21h   
    mov ax, 4c00h
    int 21h    
ends
end start
