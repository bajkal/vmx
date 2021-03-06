/******************************************************************************
 *   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
 *
 *   This file is part of Real VMX.
 *   Copyright (C) 2013 Surplus Users Ham Society
 *
 *   Real VMX is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Real VMX is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Real VMX.  If not, see <http://www.gnu.org/licenses/>.
 */

/* i8259a.h - Programable interrupt controller */

#ifndef _i8259a_h
#define _i8259a_h

#include <vmx.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Defines */
#define PIC1_BASE_ADR           0x20
#define PIC2_BASE_ADR           0xa0
#define PIC_ADRS(base,reg)      (base + reg * PIC_REG_ADDR_INTERVAL)

/* Macros */
#define PIC_Port1(base)         PIC_ADRS(base,0x00)     /* Port 1 */
#define PIC_Port2(base)         PIC_ADRS(base,0x01)     /* Port 2 */
#define PIC_IMASK(base)         PIC_Port2(base)         /* Interrupt msk */
#define PIC_IACK(base)          PIC_Port1(base)         /* Intrrupt ack */
#define PIC_ISR_MASK(base)      PIC_Port1(base)         /* In service reg msk */
#define PIC_IRR_MASK(base)      PIC_Port1(base)         /* Interrupt req reg */

/******************************************************************************
 * sysIntInitPIC - Initialize PIC
 *
 * RETURNS: N/A
 */

void sysIntInitPIC(
    void
    );

/******************************************************************************
 * sysIntEnablePIC - Enable interrupt level
 *
 * RETURNS: OK
 */

STATUS sysIntEnablePIC(
    int level
    );

/******************************************************************************
 * sysIntDisablePIC - Disable interrupt level
 *
 * RETURNS: OK
 */

STATUS sysIntDisablePIC(
    int level
    );

/******************************************************************************
 * sysIntLock - Disable interrupts and store level
 *
 * RETURNS: N/A
 */

void sysIntLock(
    void
    );

/******************************************************************************
 * sysIntUnlock - Restore interrupt level
 *
 * RETURNS: N/A
 */

void sysIntUnlock(
    void
    );

/******************************************************************************
 * sysIntLevel - Get interrupt level
 *
 * RETURNS: Interrupt level
 */

int sysIntLevel(
    void
    );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _i8259a_h */

