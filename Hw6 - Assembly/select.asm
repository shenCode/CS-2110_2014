;;===============================
;;Name: Shen Yang
;;===============================

.orig x3000
	; R0 = LENGTH-1
	; R1 = LENGTH
	; R2 = Counter for i
	; R3 = Counter for j
	; R4 = 
	; R5 = Position of array (x6000)
	; R6 = array[j]
	; R7 = array[indexOfSmallest]

; stores length and length-1 for the 2 loops
LD R0, LENGTH
BRz END	; End the program if length == 0
LD R1, LENGTH
ADD R0, R0, #-1

; negate R0
NOT R0, R0
ADD R0, R0, #1

; negate R1
NOT R1, R1
ADD R1, R1, #1
;

; Starts the outerloop
AND R2, R2, #0		; i = 0
OUTERLOOP ST R2, I	; Save R2
ST R2, IndexOfSmallest	; indexOfSmallest = i;


; j = i+1
LD R3, I
ADD R3, R3, #1
;

; array[j]
INNERLOOP LD R5, ARRAY
ST R3, J
LD R4, J
ADD R5, R5, R4
ST R5, JPosition
LDI R6, JPosition	; R6 = array[j]
;

; array[indexOfSmallest]
LD R5, ARRAY
LD R4, IndexOfSmallest
ADD R5, R5, R4
ST R5, IOSPosition
LDI R7, IOSPosition	; R7 = array[indexOfSmallest]
;

; negate R7 (array[indexOfSmallest])
NOT R7, R7
ADD R7, R7, #1
;

; array[j] < array[indexOfSmallest] // negative if true, else skip
ADD R6, R6, R7
BRzp SKIP
ST R3, IndexOfSmallest	; indexOfSmallest = j
SKIP

; Loop the innerloop if j=i+1<Length
ADD R3, R3, #1	; j++
ST R3, J
ADD R4, R3, R1
BRn INNERLOOP

; temp = array[i]
LD R5, ARRAY
ADD R5, R5, R2
ST R5, IPosition
LDI R5, IPosition
ST R5, TEMP

; array[i] = array[indexOfSmallest]
LD R5, ARRAY
LD R4, IndexOfSmallest
ADD R5, R5, R4
ST R5, IOSPosition
LDI R5, IOSPosition
STI R5, IPosition
;

; array[indexOfSmallest] = temp
LD R5, TEMP
STI R5, IOSPosition
;

; Loop outerloop if i < Length-1
ADD R2, R2, #1
AND R3, R3, #0
ADD R5, R2, R0	; if i < LENGTH-1, true if negative
BRn OUTERLOOP

END
halt


ARRAY   .fill x6000
LENGTH  .fill 12
I	.fill #0
J	.fill #0
IPosition	.fill #0
IndexOfSmallest .fill #0
JPosition	.fill #0
IOSPosition	.fill #0
TEMP	.fill #0
.end

.orig x6000
.fill -47
.fill 5
.fill 40
.fill -180
.fill 387
.fill 25
.fill 0
.fill -24
.fill 28
.fill 39
.fill 5
.fill 80
.end

