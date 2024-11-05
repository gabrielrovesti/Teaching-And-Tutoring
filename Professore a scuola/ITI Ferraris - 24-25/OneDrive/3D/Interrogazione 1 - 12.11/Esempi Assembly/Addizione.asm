name "Addizione"

data segment
    num1 DB 1Ah	 ;primo addendo dimensione un byte
	num2 DB 0D2h ;secondo addendo dimensione un byte
	ris	 DB 00h	 ;risultato inizializzato a zero

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
;-----------------------------------------------------------
    mov ax,0000h	;inizializza a 0 il registro AX
	mov bx,0000h	;inizializza a 0 il registro BX
	mov al,num1	;carica num1 da memoria a parte bassa di AX
	mov bl,num2	;carica num2 da memoria a parte bassa di BX
    
    add al,bl	;calcola la somma e mette il risultato in AL
	mov ris,al	;salva il risultato in memoria
;-----------------------------------------------------------            
    lea dx, pkey
    mov ah, 9
    int 21h        
        
    mov ah, 1
    int 21h
    
    mov ax, 4c00h 
    int 21h    
ends

end start