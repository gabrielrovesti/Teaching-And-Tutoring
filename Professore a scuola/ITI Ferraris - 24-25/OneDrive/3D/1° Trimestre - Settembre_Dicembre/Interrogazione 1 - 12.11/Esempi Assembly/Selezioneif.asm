name "Selezione if"
; in ris c'e' 0 se AX=BX, in ris c'e' AX+BX se AX diverso da BX
data segment
    num1 DW 1B3Ch ;primo addendo dimensione una word (2 byte)
	num2 DW 1A3Ch ;secondo addendo dimensione una word (2 byte)
	ris	 DW 0000h ;risultato inizializzato a zero

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
	mov ax,num1
	mov bx,num2
	cmp ax,bx ;confronta i due registri attraverso una sottrazione 
	          ;e setta i flag
	je salta ;salta se sono uguali. Testa il flag Z (Zero): 
			 ;se Z = 1 salta all'istruzione con label "salta:"
			 ;se Z = 0 non salta ed esegue le successive istruzioni
	add ax,bx	;calcola la somma e mette il risultato in AX
    mov ris,ax	;salva il risultato in memoria nella variabile ris
salta:                       
    lea dx, pkey
    mov ah, 9
    int 21h                
    mov ah, 1
    int 21h    
    mov ax, 4c00h
    int 21h    
ends
end start
