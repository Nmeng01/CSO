.globl _sumOfPowers
_sumOfPowers:
  push %rbp
  mov %rsp, %rbp

  mov %rdi, %rcx 
  mov $0, %rax     

TOP:
  cmp $0, %rcx
  jle DONE
  mov %rcx, %rdx
  imul %rdx, %rdx   
  add %rdx, %rax    
  dec %rcx
  jmp TOP
DONE:
  pop %rbp
  ret
  