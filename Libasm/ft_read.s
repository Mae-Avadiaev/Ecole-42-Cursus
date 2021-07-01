		extern ___error
		global	_ft_read

		section	.text
_ft_read:	
		mov	rax, 0x2000003
		syscall
		jc	error
		ret
		
error:		mov	r15, rax
		push	-1
		call	___error
		mov	qword [rax], r15
		pop	rax
		ret