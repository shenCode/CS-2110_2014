;;===============================
;;Name: Shen Yang
;;===============================

.orig x3000

AND R1, R1, #0	; sum = 0
LD R0, U	; R0 = U
BRz END		; if U == 0, END
BRp CONTINUE	; if U > 0, skip to continue
NOT R0, R0	; u = -u
ADD R0, R0, #1	; u = -u
CONTINUE AND R3, R0, #0	; counter = 0
ADD R3, R1, R0		; counter = u
ADDLOOP ADD R1, R1, R0	; sum += u
ADD R3, R3, #-1	; counter--
BRp ADDLOOP	; loop
END ST R1, ANSWER	; Store answer from R1 in to ANSWER
HALT
U       .fill 8
ANSWER  .fill 0
.end

