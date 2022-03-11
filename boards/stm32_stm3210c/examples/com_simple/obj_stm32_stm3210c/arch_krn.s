# 1 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
# 9 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
# 1 "./asm_offset.h" 1
# 10 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx" 2
# 1 "./arch_offset.h" 1
# 11 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx" 2
# 1 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_stack.h" 1
# 12 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx" 2

.extern Os_Sys
.extern TailChaining

 .syntax unified
 .cpu cortex-m3
 .fpu softvfp
 .thumb

 .section .text

  .global Irq_Handler
    .type Irq_Handler, %function
  .global SVC_Handler
    .type SVC_Handler, %function
  .global PendSV_Handler
    .type PendSV_Handler, %function
# 40 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
SVC_Handler:
    add sp,sp,#(8*4)
    bx lr

PendSV_Handler:
    cpsid i
    push {r4-r8,r10,r11,lr}
    sub.w sp,sp,#8
    mov.w r4,#0xad
    str r4,[sp,#4]
    mov r2,sp

 mov r1,#0x01000000
 ldr r0,=TailChaining
 push {r0-r1}
 sub sp,sp,#(5*4)
    push {r2}
  bx lr

Irq_Handler:
    push {r4-r8,r10,r11,lr}
    sub.w sp,sp,#8
    mov.w r4,#0xad
    str r4,[sp,#4]
    mov r6,sp


 ldr r4,=Os_Sys
 ldr r5,[r4,#16]
 cmp r5, #0
 bgt arggg
 ldr sp,[r4,#24]
arggg:

 cpsid i
 ldr r4,=0xE000ED04
 ldr r3, [r4, #0]
 ldr r4,=0x1ff
 and.w r0,r3,r4
 bl Os_Isr_cm3
 cpsie i

    mov sp, r6


    add.w sp,sp,#8
    pop {r4-r8,r10,r11,lr}
    bx lr
# 105 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
  .global Irq_EOI2
  .type Irq_EOI2, %function

Irq_EOI2:
 mov.w r1,0x01000000
 mov r0,lr
 push {r0,r1}
 sub.w sp,sp,#(6*4)
 mov.w lr,#0xfffffff9
 bx lr
# 124 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
  .global Os_ArchSetSpAndCall
  .type Os_ArchSetSpAndCall, %function
Os_ArchSetSpAndCall:
 mov.w sp,r0
 mov.w lr,r1
 bx lr
# 145 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
  .global Os_ArchSwapContext
  .type Os_ArchSwapContext, %function
Os_ArchSwapContext:

    push {r4-r8,r10,r11,lr}


    sub.w sp,sp,#8


    mov.w r4,#0xde
    str r4,[sp,#4]



    mov.w r4,sp
    str r4,[r0,#0]



 .global Os_ArchSwapContextTo
 .type Os_ArchSwapContextTo, %function
Os_ArchSwapContextTo:


    ldr r2,[r1,#0]

    mov.w sp,r2




    ldr r5,= Os_Sys
    str r1,[r5,#0]


    ldr r6,[sp,#4]
    cmp r6,#0xde
    beq os_sc_restore
    cmp r6,#0xad
    beq os_lc_restore
os_stack_problem:

    b os_stack_problem
# 197 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
os_sc_restore:
    add.w sp,sp,#8
    pop {r4-r8,r10,r11,lr}
    bx lr
# 213 "/home/marco/Projects/classic-platform/arch/arm/arm_cm3/kernel/arch_krn.sx"
os_lc_restore:
    add.w sp,sp,#8

    pop {r4-r8,r10,r11,lr}
    cpsie i
    svc 0
