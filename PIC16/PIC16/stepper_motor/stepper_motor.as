opt subtitle "HI-TECH Software Omniscient Code Generator (PRO mode) build 10920"

opt pagewidth 120

	opt pm

	processor	16F877A
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
	FNCALL	_main,_delay
	FNROOT	_main
	global	_PORTC
psect	text29,local,class=CODE,delta=2
global __ptext29
__ptext29:
_PORTC	set	7
	global	_TRISC
_TRISC	set	135
	file	"stepper_motor.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_delay
?_delay:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	delay@time
delay@time:	; 2 bytes @ 0x0
	ds	2
	global	??_delay
??_delay:	; 0 bytes @ 0x2
	ds	2
	global	??_main
??_main:	; 0 bytes @ 0x4
;;Data sizes: Strings 0, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      4       4
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK3           96      0       0
;; BANK2           96      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   _main->_delay
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK3
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0      15
;;                              _delay
;; ---------------------------------------------------------------------------------
;; (1) _delay                                                4     2      2      15
;;                                              0 COMMON     4     2      2
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _delay
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      4       4       1       28.6%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       1       2        0.0%
;;ABS                  0      0       0       3        0.0%
;;BITBANK0            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK0               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK1            50      0       0       6        0.0%
;;BANK1               50      0       0       7        0.0%
;;BITBANK3            60      0       0       8        0.0%
;;BANK3               60      0       0       9        0.0%
;;BITBANK2            60      0       0      10        0.0%
;;BANK2               60      0       0      11        0.0%
;;DATA                 0      0       0      12        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 13 in file "D:\EMBEDDED_CLASS\PIC16\stepper_motor\stepper_motor.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_delay
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"D:\EMBEDDED_CLASS\PIC16\stepper_motor\stepper_motor.c"
	line	13
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 7
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	14
	
l1747:	
;stepper_motor.c: 14: TRISC = 0x00;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(135)^080h	;volatile
	line	15
;stepper_motor.c: 15: PORTC = 0x00;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(7)	;volatile
	line	19
	
l1749:	
;stepper_motor.c: 18: {
;stepper_motor.c: 19: PORTC = 0x01;
	movlw	(01h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	20
	
l1751:	
;stepper_motor.c: 20: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	line	22
	
l1753:	
;stepper_motor.c: 22: PORTC = 0x03;
	movlw	(03h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	23
	
l1755:	
;stepper_motor.c: 23: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	line	25
	
l1757:	
;stepper_motor.c: 25: PORTC = 0x02;
	movlw	(02h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	26
	
l1759:	
;stepper_motor.c: 26: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	line	28
	
l1761:	
;stepper_motor.c: 28: PORTC = 0x06;
	movlw	(06h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	29
	
l1763:	
;stepper_motor.c: 29: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	line	31
	
l1765:	
;stepper_motor.c: 31: PORTC = 0x04;
	movlw	(04h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	32
	
l1767:	
;stepper_motor.c: 32: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	line	34
	
l1769:	
;stepper_motor.c: 34: PORTC = 0x0C;
	movlw	(0Ch)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	35
	
l1771:	
;stepper_motor.c: 35: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	line	37
	
l1773:	
;stepper_motor.c: 37: PORTC = 0x08;
	movlw	(08h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	38
	
l1775:	
;stepper_motor.c: 38: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	line	40
	
l1777:	
;stepper_motor.c: 40: PORTC = 0x09;
	movlw	(09h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(7)	;volatile
	line	41
	
l1779:	
;stepper_motor.c: 41: delay(100);
	movlw	064h
	movwf	(?_delay)
	clrf	(?_delay+1)
	fcall	_delay
	goto	l1749
	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	43
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_delay
psect	text30,local,class=CODE,delta=2
global __ptext30
__ptext30:

;; *************** function _delay *****************
;; Defined at:
;;		line 7 in file "D:\EMBEDDED_CLASS\PIC16\stepper_motor\stepper_motor.c"
;; Parameters:    Size  Location     Type
;;  time            2    0[COMMON] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 60/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         2       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          2       0       0       0       0
;;      Totals:         4       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text30
	file	"D:\EMBEDDED_CLASS\PIC16\stepper_motor\stepper_motor.c"
	line	7
	global	__size_of_delay
	__size_of_delay	equ	__end_of_delay-_delay
	
_delay:	
	opt	stack 7
; Regs used in _delay: [wreg]
	line	8
	
l1743:	
;stepper_motor.c: 8: while(time--)
	goto	l687
	line	9
	
l1745:	
;stepper_motor.c: 9: _delay((unsigned long)((1)*(8000000/4000.0)));
	opt asmopt_off
movlw	3
movwf	((??_delay+0)+0+1),f
	movlw	151
movwf	((??_delay+0)+0),f
u27:
	decfsz	((??_delay+0)+0),f
	goto	u27
	decfsz	((??_delay+0)+0+1),f
	goto	u27
	nop2
opt asmopt_on

	
l687:	
	line	8
	movlw	low(01h)
	subwf	(delay@time),f
	movlw	high(01h)
	skipc
	decf	(delay@time+1),f
	subwf	(delay@time+1),f
	incf	((delay@time)),w
	skipnz
	incf	((delay@time+1)),w

	skipz
	goto	u11
	goto	u10
u11:
	goto	l1745
u10:
	line	10
	
l690:	
	return
	opt stack 0
GLOBAL	__end_of_delay
	__end_of_delay:
;; =============== function _delay ends ============

	signat	_delay,4216
psect	text31,local,class=CODE,delta=2
global __ptext31
__ptext31:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
