; extern "C" char *CopyStr(char *s1, char *s2, int L);
.386
.model FLAT,C
PUBLIC CopyStr

.CODE
CopyStr:
	push ebp
	mov ebp,esp
	push edx
	push edi
	push esi

	mov edx,[ebp+16] ; L
	mov esi,[ebp+8] ; offset s1
	mov edi,[ebp+12] ; offset s2

	mov eax,edi
	mov ecx,edx
	cld

	cmp esi,edi
	je after
	ja m2		; s1 > s2

	add esi,edx

	cmp esi,edi
	ja m1
	sub esi,edx

	m1:
		std			; going back
		add edi,edx
		dec edi
		dec esi

	m2:
		rep movsb

	after:
	pop esi
	pop edi
	pop edx
	mov esp,ebp
	pop ebp
RET
END
