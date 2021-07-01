		global	_ft_strdup
		extern	_malloc
		
		section	.text

_ft_strdup:	cmp	rdi, 0
		je	error


_ft_strlen:	mov	rcx, -1
		
loop:		inc	rcx
		cmp	byte [rdi+rcx], 0
		jne	loop

		
		
		inc	rcx
		push	rdi
		mov	rdi, rcx
		call	_malloc
		pop 	rdi
		cmp	rax, 0
		je	error
		
		mov	rcx, -1
copy:		inc	rcx
		mov	rsi, [rdi + rcx]
		mov	[rax + rcx], rsi
		cmp	rsi, 0
		jne	copy
		ret


error:		mov	rax, 0
		ret			

		