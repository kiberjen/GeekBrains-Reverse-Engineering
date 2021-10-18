.386
.model flat, stdcall

_text segment
start:
	xor eax, eax
label_1:
	inc eax
	dec eax 
	cmp eax, 0
	jz label_2
	add eax,4
	ret
label_2:
	ret
_text ends
end start