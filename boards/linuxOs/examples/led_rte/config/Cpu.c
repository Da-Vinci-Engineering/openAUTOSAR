/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/

#include "Cpu.h"

uint8_t ilog2(int _x) 
{
	return (__builtin_ffs(_x));
}

imask_t Irq_Save(imask_t flags)
{
	flags = 0;		// Dummy assignment to avoid compiler warnings
}

void Irq_Restore(imask_t flags)
{
	(void)flags;
}

void Irq_Disable()
{

}

void Irq_Enable()
{
	
}
