name "main"
data segment
    str1 DB 10 DUP(?);riserva l'area di memoria per la stringa  
    cont DB 1 DUP(0) ;riserva l'area di memoria per il contatore
                     ;e lo inizializza 0
    msg1 DB "inserisci la stringa: $"
    msg2 DB "la stringa introdotta e': $"
    msg3 DB "la sua lunghezza e': $"
    pkey DB "press any key...$"
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
call conta       ;chiama la subroutine
call a-capo 	
	lea dx,msg2 ;carica in DX l'indirizzo del secondo messaggio
	mov ah,09h	
	int 21h     ;visualizza il secondo messaggio		
    lea dx,str1 ;carica in DX l'indirizzo della stringa caricata
	mov ah,09h	
	int 21h     ;visualizza la stringa caricata	        
call a-capo    
    lea dx,msg3 ;carica in DX l'indirizzo del terzo messaggio
	mov ah,09h	
	int 21h     ;visualizza il terzo messaggio		
    add cont,48 ;aggiunge 48 per visualizzare un carattere numerico
	mov dl,cont ;carica in DL cont
	mov ah,02h	
	int 21h     ;visualizza cont	
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

conta proc near  ;codice della subroutine
      lea dx,msg1 ;carica in DX l'indirizzo del primo messaggio
	  mov ah,09h	
	  int 21h     ;visualizza il primo messaggio	
	  mov ah,01h  ;legge da tastiera il primo carattere con echo e salva in AL
	  int 21h 				
	  mov str1[si],al ;salva il carattere nella stringa			
  cicla: 
      cmp str1[si],"$";controllo per fine stringa 
	  je  fine 	
      inc si
      inc cont	
	  mov ah,01h ;legge da tastiera l'i-esimo carattere con echo e salva in AL
	  int 21h 		
	  mov str1[si],al ;salva il carattere nella stringa	 			    
      jmp cicla	       
  fine:
      ret    
endp
end start 
