TITLE	LAB_05
    SSTACK     SEGMENT PARA STACK  'STACK'
               DB   64 DUP('Stack____')
    SSTACK     ENDS

	DSEG	SEGMENT
		MAS		DB	7,3,1,6,0,3,9,4
		NUM		DB	8
	DSEG	ENDS


SUBTTL         MAIN_PROGRAMM
PAGE
	CSEG      SEGMENT PARA PUBLIC 'CODE'
              ASSUME CS:CSEG,DS:DSEG,SS:SSTACK

    BEGIN     PROC FAR
		MOV   AX,0
		PUSH  AX

		MOV  AX,DSEG
		MOV  DS,AX
		
		
		
		XOR		CX, CX
	J2:	MOV		CL, NUM
		DEC		CL
		
	C0:	MOV		BX, CX
		MOV		AL, MAS[BX]
		CMP		AL, MAS[BX-1]
		JL		J1
		LOOP	C0
		
		ret

	J1:	
		XCHG		AL, MAS[BX-1]
		MOV		MAS[BX], AL

		;MOV		AH, MAS[BX-1]
		;MOV		MAS[BX], AH ; без XCHG
		;MOV		MAS[BX-1], AL
		JMP		J2
		
    BEGIN     ENDP
    CSEG      ENDS
              END  BEGIN
COMMENT @
