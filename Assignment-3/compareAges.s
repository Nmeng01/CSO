  .globl _compareAges
_compareAges:
  push %rbp
  mov %rsp, %rbp
  mov 4(%rdi), %rdx
  mov 4(%rsi), %rcx
  
  cmp %rdx, %rcx
  je EQUAL
  jne NOTEQUAL
EQUAL:
  mov $1, %rax
  jmp DONE
NOTEQUAL:
  mov $0, %rax
DONE:
  pop %rbp
  ret
