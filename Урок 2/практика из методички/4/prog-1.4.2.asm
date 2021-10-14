.386
.model flat, stdcall

_text segment
start:
	xor eax, eax
	inc eax
	push eax

	mov ebx, 4
	push ebx
	
	pop ecx
	pop edx
	
	ret
_text ends
end start