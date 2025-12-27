org 0x00
main:
clr p1.0
setb p1.1
setb p1.2
call delay
setb p1.0
clr p1.1
setb p1.2
call delay
setb p1.0
setb p1.1
clr p1.2
call delay
jmp main
delay:
mov r0,#255
l2:mov r1,#255
l1:djnz r1,l1
djnz r0,l2
ret
end