
section .text

global tea_t000

tea_t000:
	push rbp
	mov rbp, rsp
	sub rsp, 1024 + 4

	lea rdi, [rbp - 1024]
	call tea_t001
	mov [rbp - 1024 - 4], eax

	mov rsp, rbp
	pop rbp
	ret

tea_t001:
	push rbp
	mov rbp, rsp
	sub rsp, 8 * 3

	mov [rbp - (8 * 3)], rdi

	mov rax, "Enter pa"
	mov [rbp - (8 * 2)], rax

	mov rax, "ssword: "
	mov [rbp - (8 * 1)], rax

	mov rax, 1
	mov rdi, 1
	lea rsi, [rbp - (8 * 2)]
	mov rdx, 8 * 2
	syscall

	xor rax, rax
	xor rdi, rdi
	mov rsi, [rbp - (8 * 3)]
	mov rdx, 1024
	syscall

	mov rsp, rbp
	pop rbp
	ret

tea_t004:
	push rbp
	mov rbp, rsp
	sub rsp, 8 * 6

	mov [rbp - (8 * 6)], rdi

	mov rax, "Congratu"
	mov [rbp - (8 * 5)], rax

	mov rax, "lation, "
	mov [rbp - (8 * 4)], rax

	mov rax, "you got "
	mov [rbp - (8 * 3)], rax

	mov rax, "the flag"
	mov [rbp - (8 * 2)], rax

	mov rax, ": e_tea{"
	mov [rbp - (8 * 1)], rax

	mov rax, 1
	mov rdi, 1
	lea rsi, [rbp - (8 * 5)]
	mov rdx, 8 * 5
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, [rbp - (8 * 6)]
	mov rdx, 12
	syscall

	mov rsp, rbp
	pop rbp
	ret
