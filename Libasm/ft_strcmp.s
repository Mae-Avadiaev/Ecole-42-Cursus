		global	_ft_strcmp

		section	.text
_ft_strcmp:	
		mov	rcx, -1
		
loop:		inc	rcx
		movzx	rax, byte [rdi+rcx]
		movzx	rbx, byte [rsi+rcx]
		cmp	rax, 0
		je	if_eq_len
		sub	rax, rbx
		je	loop
		ret

if_eq_len:	cmp	rbx, 0
		jne	if_n_eq_len
		ret

if_n_eq_len:	sub	rax, rbx
		ret
