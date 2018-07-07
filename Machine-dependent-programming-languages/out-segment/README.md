# Out segment
Task 1
Make a program of two modules. The module lr05-1-1.asm contains a description of the stack, the data segment with the variable X db `R`, and the code segment with the entry point. lr05-1-1.asm control is transferred to lr05-1-2.asm (there must be one code segment in the program), where the output to the video memory is executed from X to the 3rd row and the 2nd column and exit from the program by RET. The video memory should represent the DS2 segment of the second module, its beginning is the byte variable CA, the second familiarity in the third line is the variable Z (use the ORG and LABEL directives).

Task 2
Make a program of two modules. Modules lr05-2-1.asm and lr05-2-2.asm must have a description of memory segment SD1, starting with the same paragraph of the OP. In the SD1 module lr05-2-1.asm, the word W must be declared with an initial value of 3444h, and the byte variables C1 and C2 must be declared in the SD1 of the lr05-2-2asm module. The code segment must be declared only in the second module. The program should output the values ​​C1 and C2 as characters.

Task 3
Create a single-module program lr05-3-1.asm, containing only one code segment and three data segments SD1, SD2, SD3. The data segments must have lengths of 64K-2 and descriptions of the byte variables S1, S2, S3 with initial values. These values ​​are output in the form of characters sequentially, starting with the new lines.

Task 4
Create a program from two source modules. Module 1 should contain descriptions of the SSTK stack segment, the data segment SD1 (with the variable X DB 'X'), and the part of the code segment description SC1. Module 2 should contain a description of the data segment SD2 (with the variable Y DB 'Y') and the other part of the description of the data segment SC2.
The control must receive Module 1 and immediately transfer the control to Module 2 with the JMP command.
In Module 2, you have to change the values ​​of the variables X and Y, and output the value of the variable Y (that is, the character 'Y') by the function 2 DOS and exit the program using the 4Ch function of the INT 21h command.