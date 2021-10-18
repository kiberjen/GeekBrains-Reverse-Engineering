.386
.model flat, stdcall

_data segment
	message db 'Hello, World!' ,0
_data ends

_text segment
start:
	xor eax, eax
	add eax, 4
	inc	eax
	ret
_text ends
end start