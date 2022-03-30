/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
*********************************************************************/
#include "Cpu.h"

/* Call architecture specific code */
void Irq_Disable()
{
	__disable_irq();
}

void Irq_Enable()
{
    __enable_irq();
}

void Irq_Save(unsigned long _flags)
{
    _flags = _Irq_Save();
}

void Irq_Restore(_flags)
{
	_Irq_Restore(_flags);
}

void Irq_SuspendAll()
{
 	Irq_Disable();
}

void Irq_ResumeAll()
{
 	Irq_Enable();
}

void Irq_SuspendOs()
{
 	Irq_Disable();
}

void Irq_ResumeOs()
{
 	Irq_Enable();
}
