  .globl _findPaymentsSum
_findPaymentsSum:
  push %rbp
  mov %rsp, %rbp

  mov $0, %rcx
  mov $0, %rax

TOP:
  add 8(%rdi, %rcx, 4), %rax
  inc %rcx
  cmp %rcx, %rsi
  jne TOP
  
  pop %rbp
  ret
