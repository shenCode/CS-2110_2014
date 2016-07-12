;;===============================
;;Name: Shen Yang
;;===============================

.orig x3000

LD R0, LENGTH	; R0 = length
BRz NOLENGTH	; End if length == 0
LD R7, ARRAY	; R7 = Position of array
LDI R1, ARRAY	; max = array[0]
ADD R0, R0, #-1	; Counter--
LOOP ADD R7, R7, #1	; k++
ST R7, ARRAY	; pointer = k++
LDI R2, ARRAY	; array[k]
NOT R3, R2	; NOT(R2)
ADD R3, R3, #1	; Add 1 to R2 so it is negated
ADD R4, R1, R3	; if array[k] > max
BRzp END	; Skip to end if Max - new value is 0 or positive
AND R1, R1, #0	; Reset R1 to 0
ADD R1, R2, R1		; Update the value at R1 with R2
END ADD R0, R0, #-1	; Counter--
BRp LOOP	; if length > 0, go on.
ST R1, MAX	; Store the value in R1 into MAX.
NOLENGTH HALT

ARRAY   .fill x6000
LENGTH  .fill 8
MAX	.fill 0
.end

.orig x6000
.fill 8
.fill 4
.fill 7
.fill 0
.fill -3
.fill 11
.fill 5
.fill -9
.fill 2
.fill 4
.end

