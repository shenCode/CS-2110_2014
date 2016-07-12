.orig x3000

	; DO NOT MODIFY THE FOLLOWING CODE!

	LD R0, A
	LD R1, B
	JSR is_multiple
	ST R0, ANSWER
	HALT
	
A	.fill 30
B	.fill 6
ANSWER	.blkw 1

; PRE-CONDITIONS:
; R0 contains argument A
; R1 contains argument B
; A and B are both > 0
;
; POST-CONDITIONS:
; R0 contains a 1 if A is a multiple of B
; Otherwise it contains a 0

is_multiple
; R2 = -B
	; YOUR CODE HERE
NOT R2, R1
ADD R2, R2, #1

WHILE ADD R3, R2, R0 ; if a > b
BRnz SKIP
ADD R0, R0, R2 ; a = a-b

ADD R4, R2, R0
BRp WHILE

SKIP AND R5, R5, #0
ADD R2, R2, R0
BRz ZERO
ADD R5, R5, #0
BRnzp STORE
ZERO ADD R5, R5, #1
BRnzp STORE
STORE AND R0, R0, #0
ADD R0, R0, R5
	RET
	

.end

