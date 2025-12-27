org 0x00;
main:
mov P1,#0X00
call delay
mov P1,#0XFF
call delay
jmp main
delay:
mov r0,#3
l3:mov r1,#3
l2:mov r2, #3
l1:djnz r2,l1
djnz r1,l2
djnz r0,l3
ret
end
	