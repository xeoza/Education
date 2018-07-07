;Составить подпрограмму с именем DlinaStroki типа
;      extern "C" int DlinaStroki(char *s);
.386
.model FLAT,C
PUBLIC DlinaStroki

.CODE
PUSHR MACRO LIST 
;В СПИСКЕ  LIST ПРОБЕЛЫ НЕ ДОПУСКАЮТСЯ
  IRP A,<LIST>
    IFIDN <A>,<F>
      PUSHF
    ELSE
      PUSH A
    ENDIF
  ENDM
ENDM

POPR MACRO LIST 
;В СПИСКЕ  LIST ПРОБЕЛЫ НЕ ДОПУСКАЮТСЯ
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

DlinaStroki:
	PROLOG
	PUSHR <F,edi>

	mov edi,[ebp+8] ; offset s
	
	xor eax,eax
	cld				; DF := 0
	mov ecx,-1
	
	repne scasb

	neg ecx
	sub ecx,2

	mov eax,ecx

	POPR <edi,F>
	EPILOG
	RET
END