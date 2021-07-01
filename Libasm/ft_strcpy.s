		global	_ft_strcpy

		section	.text
_ft_strcpy:	
		mov	rax, rdi
		mov	rcx, -1
		
loop:		inc	rcx
		mov	dh, byte [rsi+rcx]
		mov	byte [rdi+rcx], dh
		cmp	byte [rdi+rcx], 0
		jne	loop
		
		ret