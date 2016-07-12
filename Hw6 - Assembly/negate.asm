;;===============================
;;Name: Shen Yang
;;===============================

.orig x3000

LD R0, U	; Load U into R0
NOT R0, R0	; Negate R0
ADD R0, R0, #1	; answer = -u -> answer = NOT(U)+1
ST R0, ANSWER	; Store R0 at the address labeled ANSWER
HALT

U       .fill 8
ANSWER  .fill 0
.end

