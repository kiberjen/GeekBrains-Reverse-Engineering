.386
.model flat, stdcall

ExitProcess PROTO, ExitCode:DWORD
WinExec PROTO, lpCmdLine:DWORD, uCmdShow:DWORD

_data segment
	lpCmdLine db 'calc',0
_data ends

_text segment
start:
	push 1
	push offset lpCmdLine	
	call WinExec
	
	push 0
	call ExitProcess
_text ends
end start