;Составить подпрограмму с именем Count типа
;      extern "C" int DlinaStroki(char *s);
.386
.model FLAT,C
PUBLIC DlinaStroki

.CODE
DlinaStroki:
	push ebp
	mov ebp,esp
	push edi

	mov edi,[ebp+8] ; offset s
	
	mov al,0
	cld				; DF := 0
	mov ecx,-1
	
	repne scasb

	neg ecx
	sub ecx,2

	mov eax,ecx

	pop edi
	mov esp,ebp
	pop ebp
	RET
END