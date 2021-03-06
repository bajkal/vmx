/******************************************************************************
 *   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
 *
 *   This file is part of Real VMX.
 *   Copyright (C) 2015 Surplus Users Ham Society
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

/* wwm.h.h - Window manager header */

#ifndef _wwm_h
#define _wwm_h

#include "uglWin.h"
#include "winManage.h"
#include "winMgr/wwm/wwmConfig.h"

#ifndef _ASMLANGUAGE

#ifdef __cplusplus
extern "C" {
#endif

/* Macros */

/******************************************************************************
 *
 * WWM_RECT_DECREMENT - Decrease rectangle one unit from all sides
 *
 *
 */

#define WWM_RECT_DECREMENT(rect)                                              \
    (rect).left++;                                                            \
    (rect).top++;                                                             \
    (rect).right--;                                                           \
    (rect).bottom--

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ASMLANGUAGE */

#endif /* _wwm_h */

