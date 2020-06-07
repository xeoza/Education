; extern "C" char *CopyStr(char *s1, char *s2, int L);
.386
.model FLAT,C
PUBLIC CopyStr

.CODE
PUSHR MACRO LIST 
;б яохяйе  LIST опнаекш ме дносяйючряъ
  IRP A,<LIST>
    IFIDN <A>,<F>
      PUSHF
    ELSE
      PUSH A
    ENDIF
  ENDM
ENDM

POPR MACRO LIST 
;б яохяйе  LIST опнаекш ме дносяйючряъ
  IRP A,<LIST>
    IFIDN <A>,<F>
      POPF
    ELSE
      POP A
    ENDIF
  ENDM
ENDM

PROLOG MACRO
	push ebp
	mov ebp,esp
ENDM

EPILOG MACRO
	mov esp,ebp
	pop ebp
ENDM

CopyStr:
	PROLOG
	PUSHR <F,edi,esi>

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
	POPR <esi,edi,F>
	EPILOG
RET
END
