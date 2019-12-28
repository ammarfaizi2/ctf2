
section .data
global tea_mmap

tea_mmap:
	mov rax, 9
	xor rdi, rdi
	mov esi, 0x209
	mov edx, 0x6
	mov ecx, 0x22
	mov r8d, 0xffffffff
	xor r9, r9
	mov r10, 0x22
	mov rbx, 0x22
	syscall
	ret