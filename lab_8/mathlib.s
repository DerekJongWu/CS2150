   ;mathlib.s
;Derek Wu
;3/27/2018
;8AM Lab

	global product
	global power
	section.text
product:
	xor	rax, rax	;zero out the return register
	xor 	r10, r10	;zero out the counter i

start:
	cmp	r10,rsi		;does i == n?
	je	done		;if so, we are done with the loop
	add	rax, rdi	;add to sum
	inc	r10		;increment counter by 1
	jmp	start		;re-loop

done:
	ret

power:
	xor	r12,r12
base:	
	cmp	rsi,r12		;if i = 0
	je 	fin
recursion:
	push	rdi		;save the original base
	push	rsi		;save the exponent
	dec	rsi		;decrease value of rsi by 1
	call 	power		;call power method recursively 
	pop	rsi		
	pop	rdi		
	push 	rsi
	mov 	rsi,rax
	call	product
	pop	rsi
	ret
	
fin:
	mov	rax,1
	ret
