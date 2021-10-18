.386
.model flat, stdcall

_text segment
start:
	xor eax, eax
	mov ecx, 3
label_1:
	inc eax
	loop label_1
	ret
_text ends
end start