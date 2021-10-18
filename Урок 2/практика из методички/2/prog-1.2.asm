.386
.model flat, stdcall

_text segment
start:
	xor eax, eax
	add eax, 4
	sub eax, 2
	inc eax
	inc eax
	inc eax
	mov ebx, 0
	add bx, 8
	dec bx
	xor ebx, ebx
	xchg eax, ebx
	lea eax, [ebx + 5]
	mov eax, 00402000h
	mov ecx, [eax]
	ret
_text ends
end start