.386
.model flat, stdcall

_text segment
start:
	xor eax, eax
	call my_func
	add eax, 4
	ret
	
my_func proc
	xor eax, eax
	inc eax
	ret
my_func endp

_text ends
end start