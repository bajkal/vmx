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

/* winFrame.h - Universal graphics library window frame header */

#ifndef _winFrame_h
#define _winFrame_h

#ifndef _ASMLANGUAGE

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * winFrameCaptionSet - Set window frame caption
 *
 * RETURNS: UGL_STATUS_OK or UGL_STATUS_ERROR
 */

UGL_STATUS  winFrameCaptionSet (
    WIN_ID      winId,
    UGL_CHAR *  pCaption
    );

/******************************************************************************
 *
 * winFrameResizableGet - Get if frame is resizable
 *
 * RETURNS: UGL_TRUE or UGL_FALSE
 */

UGL_BOOL  winFrameResizableGet (
    WIN_ID  winId
    );

/******************************************************************************
 *
 * winFrameMinimize - Minimize window
 *
 * RETURNS: UGL_TRUE or UGL_FALSE
 */

UGL_STATUS  winFrameMinimize (
    WIN_ID  winId
    );

/******************************************************************************
 *
 * winFrameMaximize - Maximize window
 *
 * RETURNS: UGL_TRUE or UGL_FALSE
 */

UGL_STATUS  winFrameMaximize (
    WIN_ID  winId
    );

/******************************************************************************
 *
 * winFrameRestore- Restore window from minimized or maxmimized state
 *
 * RETURNS: UGL_TRUE or UGL_FALSE
 */

UGL_STATUS  winFrameRestore (
    WIN_ID  winId
    );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ASMLANGUAGE */

#endif /* _winFrame_h */

