.386
.model flat, stdcall

_data segment
	message1 db 'AABBCC' ,0
	message2 db 'DDEEFF' ,0
_data ends

_text segment
start:
	xor eax, eax
	mov eax, offset message1
	xor ecx, ecx
	mov ecx, offset message2
	ret
_text ends
end start