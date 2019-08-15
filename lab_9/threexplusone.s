;Derek Wu
	;; OPTIMIZATION NOTES:
	;; I originally pushed and popped all of the used registers. However, I changed it so that I only pushed and popped RDI to eliminate uncessary interaction with the stack. I also changed it so that I did not have to use idiv and imul, instead I used the logical operator and to determine the odd or even nature of the input parameter. 




	
	;; r12 stores 1
	;; rdi holds initial parameter
	;; r10 holds counter
	global threexplusone
	section .text 
threexplusone:
	mov rax,0
	cmp rdi, 1
	je done
start:	
	push rdi
	mov rbx,rdi
	and rbx, 1 
	cmp rbx,1 
	je recuro
	jmp recure
	
recuro:
	pop rdi
	lea rdi, [rdi*2 + rdi]
	inc rdi
	call threexplusone
	inc rax
	jmp done
recure:	
	pop rdi
	sar rdi, 1 
	call start
	inc rax 

done:
	ret