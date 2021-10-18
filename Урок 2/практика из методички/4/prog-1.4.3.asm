.386
.model flat, stdcall

ExitProcess PROTO, ExitCode:DWORD
MessageBoxA PROTO, hWnd:DWORD, lpText:DWORD, lpCaption:DWORD, uType:DWORD

_data segment
	messageText db 'Some Text', 0
	messageTitle db 'Some Text', 0
_data ends

_text segment
start:
	push 0
	push offset messageTitle
	push offset messageText
	push 0
	call MessageBoxA
	
	push 0
	call ExitProcess
_text ends
end start