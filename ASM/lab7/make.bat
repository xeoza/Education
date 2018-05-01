masm /zi main.asm,,;
masm /zi scan_num.asm,,;
masm /zi signed.asm,,;
masm /zi unsigned.asm,,;
link /co main.obj scan_num.obj signed.obj unsigned.obj,,,;
pause