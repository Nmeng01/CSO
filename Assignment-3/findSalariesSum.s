  .globl _findSalariesSum
_findSalariesSum:
  push %rbp
  mov %rsp, %rbp

  mov $0, %rcx
  mov $0, %rax
  imul $3, %rsi
TOP:
  add 8(%rdi, %rcx, 4), %rax
  add $3, %rcx
  cmp %rcx, %rsi
  jne TOP

  pop %rbp
  ret
  