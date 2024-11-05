name "Subroutine"
data segment
	char1 DB ?
    char2 DB ?
	msg1  DB "inserisci il primo carattere: $"
	msg2  DB "inserisci il secondo carattere: $"
	msg3  DB "il maggiore e': $"
	pkey  DB "press any key $"
ends
stack segment 
	DW 128 DUP(?) ;area di stack riservata
	top DW ? ;top punta l'indirizzo inserito in cima allo stack
ends
code segment
start:
    mov ax, data
    mov ds, ax
    mov es, ax
    
    mov ax,stack ;carica l'indirizzo dell'area di stack in AX
	mov ss,ax    ;carica il contenuto di AX nello Stack Segment
	lea sp,top   ;carica il primo elemento dello stack nello Stack Pointer
    
	mov bx,0000h ;inizializza a 0 il registro BX	   
    lea dx,msg1 ;carica in DX l'indirizzo del primo messaggio
	mov ah,09h	
	int 21h     ;visualizza il primo messaggio
	mov ah,01h	;legge da tastiera con echo e salva in AL
	int 21h
	mov char1,al;salva il dato in memoria (e' buona regola)
call a-capo
	lea dx,msg2 ;carica in DX l'indirizzo del secondo messaggio
	mov ah,09h	
	int 21h     ;visualizza il secondo messaggio
	mov ah,01h	;legge da tastiera con echo e salva in AL
	int 21h
	mov char2,al;salva il dato in memoria (e' buona regola)
    mov bl,al   ;salva il dato anche in un registro per poter fare la CMP    
call a-capo     	
	lea dx,msg3 ;carica in DX l'indirizzo del terzo messaggio
	mov ah,09h	 
	int 21h     ;visualizza il terzo messaggio	
call confronta       	
call a-capo 	
    lea dx, pkey
    mov ah, 9
    int 21h     
    mov ah, 1
    int 21h
    mov ax, 4c00h
    int 21h    
ends
a-capo proc near  ;codice della subroutine
       mov dl,0Ah ;carica in DL il codice ASCII Line feed
	   mov ah,02h
	   int 21h    ;esegue il Line feed
       mov dl,0Dh ;carica in DL il codice ASCII Carriage return
	   mov ah,02h	   
	   int 21h    ;esegue il Carriage return
       ret    
endp
confronta proc near  ;codice della subroutine
    cmp char1,bl;non si possono confrontare due locazioni di memoria
    jl  false   ;se l'op1 e' minore dell'op2, salta alla label	
	mov dl,char1;carica char1 in DL
	mov ah,02h
	int 21h     ;visualizza char1	
    jmp true    ;salta incondizionatamente alla label specificata
  false:		
    mov dl,char2;carica char2 in DL
	mov ah,02h
	int 21h     ;visualizza char2            
  true:
    ret    
endp
end start
