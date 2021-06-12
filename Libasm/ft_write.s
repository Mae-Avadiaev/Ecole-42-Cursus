		global	_ft_write
		extern ___error
		
		section	.text

_ft_write:	mov	rax, 0x2000004
		syscall
		jc 	error
		ret

error:		mov	r15, rax
		push	-1
		call	___error
		mov	qword [rax], r15
		pop	rax
		ret