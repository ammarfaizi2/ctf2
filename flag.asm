
section .text

global tea_t000
global tea_mmap

tea_mmap:
	mov rax, 9
	xor rdi, rdi
	mov esi, 0x209
	mov edx, 0x6
	mov ecx, 0x22
	mov r8d, 0xffffffff
	xor r9, r9
	syscall
	ret

tea_t000:
	push rbp
	mov rbp, rsp
	sub rsp, 1024 + 4 + (8 * 3)

	mov rax, 0x25b185c99d95d1b9
	; ror rax, 6
	mov [rbp - 1028 - (8 * 3)], rax

	mov rax, 0xb905d9a5c9951191
	; ror rax, 14
	mov [rbp - 1028 - (8 * 2)], rax

	mov rax, 0x9a5d18400000195d
	; ror rax, 26
	mov [rbp - 1028 - (8 * 1)], rax

	lea rdi, [rbp - 1024]
	call tea_t001
	mov [rbp - 1024 - 4], eax
	cmp eax, 22
	jne .L1

	lea rsi, [rbp - 1028 - (8 * 3)]
	call tea_t002

	test al, al
	jne .L0
	jmp .L1
.L0:
	call tea_t003
	jmp .L2
.L1:
	call tea_t004
.L2:
	mov rsp, rbp
	pop rbp
	ret

tea_t001:
	push rdi
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
	pop rdi
	ret

tea_t002:
	push rbp
	mov rbp, rsp
	sub rsp, 8

	mov rax, [rdi]
	ror rax, 6
	mov rdx, [rsi]
	cmp rax, rdx
	jne .L0

	mov rax, [rdi + 8]
	ror rax, 14
	mov rdx, [rsi + 8]
	cmp rax, rdx
	jne .L0

	mov rax, [rdi + 16]
	ror rax, 26
	mov rdx, [rsi + 16]
	mov rcx, 0xffffffff00000000
	and rax, rcx
	and rdx, rcx
	cmp rax, rdx
	jne .L0

	jmp .L1
.L0:
	xor al, al
	jmp .L2
.L1:
	mov al, 1
.L2:
	mov rsp, rbp
	pop rbp
	ret

tea_t003:
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
	mov rdx, 21 + 2
	mov dword [rsi + 21], dword 0x0a7d
	sub dword [rsi], 0x32000018
	sub dword [rsi + 4], 0x002d0000
	syscall

	mov rsp, rbp
	pop rbp
	ret

tea_t004:
	push rbp
	mov rbp, rsp
	sub rsp, 8 * 3

	mov rax, "Sorry, w"
	mov [rbp - (8 * 3)], rax

	mov rax, "rong pas"
	mov [rbp - (8 * 2)], rax

	mov rax, "sword!"
	mov [rbp - (8 * 1)], rax

	mov byte [rbp - (8 * 1) + 6], 0xa

	mov rax, 1
	mov rdi, 1
	lea rsi, [rbp - (8 * 3)]
	mov rdx, (8 * 3) - (8 - 7)
	syscall

	mov rsp, rbp
	pop rbp
	ret
