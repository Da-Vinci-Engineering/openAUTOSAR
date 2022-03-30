/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 *******************************************************************/
#ifndef CPU_EXT_H_
#define CPU_EXT_H_

#include <stdint.h>

extern void Irq_Disable();
extern void Irq_Enable();
extern void Irq_Save(unsigned long _flags);
extern void Irq_Restore(unsigned long _flags);

extern void Irq_SuspendAll();
extern void Irq_ResumeAll();
extern void Irq_SuspendOs();
extern void Irq_ResumeOs();
extern uint8_t ilog2(int x);
typedef uint32_t imask_t;

#endif /* CPU_EXT_H_ */
