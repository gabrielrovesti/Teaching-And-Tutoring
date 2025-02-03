name "Ciclo for"
data segment
    ;vet1 db 22h,1Bh,0Ah,34h,6Ch
    ;vet1 dw 10E2h,0B01Ah,16h,10D4h,31Ch
    ;ris  db 00h 
    vet1 dw 500,250,150,100,400 ;variabili in base 10
    ris  dw 0000h
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
    mov cx,0004h ;inizializza CX al numero di cicli
		         ;con 5 elementi eseguo 4 cicli di somma        
	mov ax,vet1[si] ;carica in AX il primo elemento di tipo DW 
	;mov al,vet1[si] ;carica in AX il primo elemento di tipo DB
inizio-for:    	
    inc si
    inc si
    add ax,vet1[si] ;somma ad AX l'i-esimo elemento di tipo DW
    ;add al,vet1[si] ;somma ad AX l'i-esimo elemento di tipo DB
    mov ris,ax
	loop inizio-for	;decrementa CX e, se e' diverso da 0, salta alla label	    
    mov ris,ax
    ;mov ris,al               
    lea dx, pkey
    mov ah, 9
    int 21h     
    mov ah, 1
    int 21h    
    mov ax, 4c00h 
    int 21h    
ends
end start