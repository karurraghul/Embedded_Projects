org 0x00
main:
mov p2,#0xc0;
call delay
mov p2,#0xf9;
call delay
mov p2,#0xa4;
call delay
mov p2,#0xb0;
call delay
mov p2,#0x99;
call delay
mov p2,#0x92;
call delay
mov p2,#0x82;
call delay
mov p2,#0xf8;
call delay
mov p2,#0x80;
call delay
mov p2,#0x90;
call delay
jmp main
delay:
mov r0,#7
l3:mov r1,#255
l2:mov r2,#255
l1:djnz r2,l1
djnz r1,l2
djnz r0,l3
ret
end