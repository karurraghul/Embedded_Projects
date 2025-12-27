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
# 4 "D:\EMBEDDED_CLASS\PIC16\pwm\main.c"
	psect config,class=CONFIG,delta=2 ;#
# 4 "D:\EMBEDDED_CLASS\PIC16\pwm\main.c"
	dw 0xFFFE & 0xFFFB & 0xFFF7 & 0xFFFF & 0xFFFF & 0xFF7F & 0xFFFF & 0xFFFF & 0xFFFF ;#
	FNCALL	_main,_InitPWM
	FNCALL	_main,_SetPWMDutyCycle
	FNCALL	_InitPWM,_SetPWMDutyCycle
	FNROOT	_main
	global	_CCP1CON
psect	text35,local,class=CODE,delta=2
global __ptext35
__ptext35:
_CCP1CON	set	23
	global	_CCP2CON
_CCP2CON	set	29
	global	_CCPR1L
_CCPR1L	set	21
	global	_CCPR2L
_CCPR2L	set	27
	global	_T2CON
_T2CON	set	18
	global	_PR2
_PR2	set	146
	global	_TRISC1
_TRISC1	set	1081
	global	_TRISC2
_TRISC2	set	1082
	file	"pwm.as"
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
	global	?_SetPWMDutyCycle
?_SetPWMDutyCycle:	; 0 bytes @ 0x0
	global	?_InitPWM
?_InitPWM:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	SetPWMDutyCycle@DutyCycle
SetPWMDutyCycle@DutyCycle:	; 2 bytes @ 0x0
	ds	2
	global	??_SetPWMDutyCycle
??_SetPWMDutyCycle:	; 0 bytes @ 0x2
	ds	2
	global	SetPWMDutyCycle@CCP
SetPWMDutyCycle@CCP:	; 1 bytes @ 0x4
	ds	1
	global	??_InitPWM
??_InitPWM:	; 0 bytes @ 0x5
	global	??_main
??_main:	; 0 bytes @ 0x5
;;Data sizes: Strings 0, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      5       5
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK3           96      0       0
;; BANK2           96      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   _main->_SetPWMDutyCycle
;;   _InitPWM->_SetPWMDutyCycle
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
;; (0) _main                                                 0     0      0     150
;;                            _InitPWM
;;                    _SetPWMDutyCycle
;; ---------------------------------------------------------------------------------
;; (1) _InitPWM                                              0     0      0      75
;;                    _SetPWMDutyCycle
;; ---------------------------------------------------------------------------------
;; (1) _SetPWMDutyCycle                                      5     3      2      75
;;                                              0 COMMON     5     3      2
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _InitPWM
;;     _SetPWMDutyCycle
;;   _SetPWMDutyCycle
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      5       5       1       35.7%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       2       2        0.0%
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
;;		line 15 in file "D:\EMBEDDED_CLASS\PIC16\pwm\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 11F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_InitPWM
;;		_SetPWMDutyCycle
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"D:\EMBEDDED_CLASS\PIC16\pwm\main.c"
	line	15
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 6
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	16
	
l2453:	
;main.c: 16: InitPWM();
	fcall	_InitPWM
	line	18
;main.c: 18: SetPWMDutyCycle(1,127);
	movlw	07Fh
	movwf	(?_SetPWMDutyCycle)
	clrf	(?_SetPWMDutyCycle+1)
	movlw	(01h)
	fcall	_SetPWMDutyCycle
	line	19
;main.c: 19: SetPWMDutyCycle(2,127);
	movlw	07Fh
	movwf	(?_SetPWMDutyCycle)
	clrf	(?_SetPWMDutyCycle+1)
	movlw	(02h)
	fcall	_SetPWMDutyCycle
	line	24
;main.c: 22: {
	
l1384:	
	line	21
	goto	l1384
	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	25
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_InitPWM
psect	text36,local,class=CODE,delta=2
global __ptext36
__ptext36:

;; *************** function _InitPWM *****************
;; Defined at:
;;		line 10 in file "D:\EMBEDDED_CLASS\PIC16\pwm\pwm.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_SetPWMDutyCycle
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text36
	file	"D:\EMBEDDED_CLASS\PIC16\pwm\pwm.c"
	line	10
	global	__size_of_InitPWM
	__size_of_InitPWM	equ	__end_of_InitPWM-_InitPWM
	
_InitPWM:	
	opt	stack 6
; Regs used in _InitPWM: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	11
	
l2443:	
;pwm.c: 11: TRISC1 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1081/8)^080h,(1081)&7
	line	12
;pwm.c: 12: TRISC2 = 0;
	bcf	(1082/8)^080h,(1082)&7
	line	13
	
l2445:	
;pwm.c: 13: CCP1CON = 0x0C;
	movlw	(0Ch)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(23)	;volatile
	line	14
;pwm.c: 14: CCP2CON = 0x0C;
	movlw	(0Ch)
	movwf	(29)	;volatile
	line	16
;pwm.c: 16: PR2 = 0xFF;
	movlw	(0FFh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(146)^080h	;volatile
	line	17
;pwm.c: 17: T2CON = 0x01;
	movlw	(01h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(18)	;volatile
	line	19
	
l2447:	
;pwm.c: 19: SetPWMDutyCycle(1, 0);
	clrf	(?_SetPWMDutyCycle)
	clrf	(?_SetPWMDutyCycle+1)
	movlw	(01h)
	fcall	_SetPWMDutyCycle
	line	20
	
l2449:	
;pwm.c: 20: SetPWMDutyCycle(2, 0);
	clrf	(?_SetPWMDutyCycle)
	clrf	(?_SetPWMDutyCycle+1)
	movlw	(02h)
	fcall	_SetPWMDutyCycle
	line	22
	
l2451:	
;pwm.c: 22: T2CON |= 0x04;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(18)+(2/8),(2)&7	;volatile
	line	23
	
l687:	
	return
	opt stack 0
GLOBAL	__end_of_InitPWM
	__end_of_InitPWM:
;; =============== function _InitPWM ends ============

	signat	_InitPWM,88
	global	_SetPWMDutyCycle
psect	text37,local,class=CODE,delta=2
global __ptext37
__ptext37:

;; *************** function _SetPWMDutyCycle *****************
;; Defined at:
;;		line 30 in file "D:\EMBEDDED_CLASS\PIC16\pwm\pwm.c"
;; Parameters:    Size  Location     Type
;;  CCP             1    wreg     unsigned char 
;;  DutyCycle       2    0[COMMON] unsigned int 
;; Auto vars:     Size  Location     Type
;;  CCP             1    4[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 11F/0
;;		On exit  : 11F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         2       0       0       0       0
;;      Locals:         1       0       0       0       0
;;      Temps:          2       0       0       0       0
;;      Totals:         5       0       0       0       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InitPWM
;;		_main
;; This function uses a non-reentrant model
;;
psect	text37
	file	"D:\EMBEDDED_CLASS\PIC16\pwm\pwm.c"
	line	30
	global	__size_of_SetPWMDutyCycle
	__size_of_SetPWMDutyCycle	equ	__end_of_SetPWMDutyCycle-_SetPWMDutyCycle
	
_SetPWMDutyCycle:	
	opt	stack 7
; Regs used in _SetPWMDutyCycle: [wreg-fsr0h+status,2+status,0]
;SetPWMDutyCycle@CCP stored from wreg
	movwf	(SetPWMDutyCycle@CCP)
	line	31
	
l2433:	
;pwm.c: 31: DutyCycle = 4*DutyCycle;
	clrc
	rlf	(SetPWMDutyCycle@DutyCycle),f
	rlf	(SetPWMDutyCycle@DutyCycle+1),f
	clrc
	rlf	(SetPWMDutyCycle@DutyCycle),f
	rlf	(SetPWMDutyCycle@DutyCycle+1),f
	line	33
;pwm.c: 33: switch(CCP)
	goto	l2441
	line	37
	
l2435:	
;pwm.c: 37: CCPR1L = DutyCycle>>2;
	movf	(SetPWMDutyCycle@DutyCycle+1),w
	movwf	(??_SetPWMDutyCycle+0)+0+1
	movf	(SetPWMDutyCycle@DutyCycle),w
	movwf	(??_SetPWMDutyCycle+0)+0
	clrc
	rrf	(??_SetPWMDutyCycle+0)+1,f
	rrf	(??_SetPWMDutyCycle+0)+0,f
	clrc
	rrf	(??_SetPWMDutyCycle+0)+1,f
	rrf	(??_SetPWMDutyCycle+0)+0,f
	movf	0+(??_SetPWMDutyCycle+0)+0,w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(21)	;volatile
	line	38
;pwm.c: 38: CCP1CON &= 0xCF;
	movlw	(0CFh)
	andwf	(23),f	;volatile
	line	39
;pwm.c: 39: CCP1CON |= (0x30&(DutyCycle<<4));
	swapf	(SetPWMDutyCycle@DutyCycle),w
	andlw	(0ffh shl 4) & 0ffh
	andlw	030h
	iorwf	(23),f	;volatile
	line	40
;pwm.c: 40: break;
	goto	l694
	line	44
	
l2437:	
;pwm.c: 44: CCPR2L = DutyCycle>>2;
	movf	(SetPWMDutyCycle@DutyCycle+1),w
	movwf	(??_SetPWMDutyCycle+0)+0+1
	movf	(SetPWMDutyCycle@DutyCycle),w
	movwf	(??_SetPWMDutyCycle+0)+0
	clrc
	rrf	(??_SetPWMDutyCycle+0)+1,f
	rrf	(??_SetPWMDutyCycle+0)+0,f
	clrc
	rrf	(??_SetPWMDutyCycle+0)+1,f
	rrf	(??_SetPWMDutyCycle+0)+0,f
	movf	0+(??_SetPWMDutyCycle+0)+0,w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(27)	;volatile
	line	45
;pwm.c: 45: CCP2CON &= 0xCF;
	movlw	(0CFh)
	andwf	(29),f	;volatile
	line	46
;pwm.c: 46: CCP2CON |= (0x30&(DutyCycle<<4));
	swapf	(SetPWMDutyCycle@DutyCycle),w
	andlw	(0ffh shl 4) & 0ffh
	andlw	030h
	iorwf	(29),f	;volatile
	line	47
;pwm.c: 47: break;
	goto	l694
	line	33
	
l2441:	
	movf	(SetPWMDutyCycle@CCP),w
	; Switch size 1, requested type "space"
; Number of cases is 2, Range of values is 1 to 2
; switch strategies available:
; Name         Instructions Cycles
; simple_byte            7     4 (average)
; direct_byte           17    11 (fixed)
; jumptable            263     9 (fixed)
;	Chosen strategy is simple_byte

	opt asmopt_off
	xorlw	1^0	; case 1
	skipnz
	goto	l2435
	xorlw	2^1	; case 2
	skipnz
	goto	l2437
	goto	l694
	opt asmopt_on

	line	49
	
l694:	
	return
	opt stack 0
GLOBAL	__end_of_SetPWMDutyCycle
	__end_of_SetPWMDutyCycle:
;; =============== function _SetPWMDutyCycle ends ============

	signat	_SetPWMDutyCycle,8312
psect	text38,local,class=CODE,delta=2
global __ptext38
__ptext38:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
