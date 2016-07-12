.orig x3000

	; DO NOT MODIFY THE FOLLOWING CODE!

	LD R0, A
	LD R1, B
	JSR special_func
	ST R0, ANSWER
	HALT
	
A	.fill 4
B	.fill 4
ANSWER	.blkw 1

; PRE-CONDITIONS:
; R0 contains argument A
; R1 contains argument B
; A and B are both >= 0
;
; POST-CONDITIONS:
; R0 contains ((A*B) - A) | ((A*B) - B)

special_func

	; YOUR CODE HERE
LD R2, B ; Counter
AND R3, R3, #0
PRODUCT ADD R3, R3, R0
ADD R2, R2, #-1
BRp PRODUCT

AND R4, R4, #0;
AND R5, R5, #0

NOT R0, R0
ADD R0, R0, #1

NOT R1, R1
ADD R1, R1, #1

ADD R4, R3, R0 ; product - a
ADD R5, R3, R1 ; product - b

NOT R4, R4

NOT R5, R5

AND R0, R5, R4
NOT R0, R0


	RET
	
.end

