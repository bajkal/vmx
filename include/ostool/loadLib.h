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

/* loadLib.h - Loader library header */

#ifndef _loadLib_h
#define _loadLib_h

#include <ostool/moduleNumber.h>

#define S_loadLib_ROUTINE_NOT_INSTALLED         (M_loadLib | 0x0001)
#define S_loadLib_TOO_MANY_SYMBOLS              (M_loadLib | 0x0002)

#include <vmx.h>
#include <os/symbol.h>
#include <os/symLib.h>
#include <ostool/moduleLib.h>
#include <ostool/private/loadLibP.h>

/* Load symbols */
#define NO_SYMBOLS              -1
#define GLOBAL_SYMBOLS          0
#define ALL_SYMBOLS             1

#define LOAD_NO_SYMBOLS         0x02
#define LOAD_LOCAL_SYMBOLS      0x04
#define LOAD_GLOBAL_SYMBOLS     0x08
#define LOAD_ALL_SYMBOLS        (LOAD_LOCAL_SYMBOLS | LOAD_GLOBAL_SYMBOLS)

/* Match symbols */
#define LOAD_COMMON_MATCH_NONE  0x100
#define LOAD_COMMON_MATCH_USER  0x200
#define LOAD_COMMON_MATCH_ALL   0x400

/* Module flags */
#define HIDDEN_MODULE           16

#ifndef _ASMLANGUAGE

#ifdef __cplusplus
extern "C" {
#endif

/* Types */

typedef struct
{
    char          *addrText;              /* Address to text segment */
    char          *addrData;              /* Address to data segment */
    char          *addrBss;               /* Address to bss segment */
    unsigned int   sizeText;              /* Size of text segment */
    unsigned int   sizeProtectedText;     /* Size of protected text segment */
    unsigned int   sizeData;              /* Size of data segment */
    unsigned int   sizeBss;               /* Size of bss segment */
    int            flagsText;             /* Flag for text segment */
    int            flagsData;             /* Flags for data segment */
    int            flagsBss;              /* Flags for bss segment */
} SEG_INFO;

/* Macros */

#define LD_NO_ADDRESS                   ((char *) NONE)

/* Functions */

/******************************************************************************
 * loadLibInit - Inititalize loader library
 *
 * RETURNS: OK 
 */

STATUS loadLibInit(
    void
    );

/******************************************************************************
 * loadFuncSet - Set load function
 *
 * RETURNS: N/A
 */

void loadFuncSet(
    FUNCPTR load,
    FUNCPTR sync
    );

/******************************************************************************
 * loadModule - Load module
 *
 * RETURNS: MODULE_ID or NULL
 */

MODULE_ID loadModule(
    int fd,
    int symFlags
    );

/******************************************************************************
 * loadModuleAt - Load module at system symbol table
 *
 * RETURNS: MODULE_ID or NULL
 */

MODULE_ID loadModuleAt(
    int    fd,
    int    symFlags,
    void **ppText,
    void **ppData,
    void **ppBss
    );

/******************************************************************************
 * loadModuleAtSym - Load module at symbol table
 *
 * RETURNS: MODULE_ID or NULL
 */

MODULE_ID loadModuleAtSym(
    int         fd,
    int         symFlags,
    void      **ppText,
    void      **ppData,
    void      **ppBss,
    SYMTAB_ID   symTable
    );

/******************************************************************************
 * loadModuleGet - Create module for loadable code
 *
 * RETURNS: MODULE_ID or NULL
 */

MODULE_ID loadModuleGet(
    char *name,
    int   format,
    int  *symFlags
    );

/******************************************************************************
 * loadSegmentsAllocate - Allocate text, data and bss segments
 *
 * RETURNS: OK or ERROR
 */

STATUS loadSegmentsAllocate(
    SEG_INFO *pSegInfo
    );

/******************************************************************************
 * loadCommonMatch - Fill in common info
 *
 * RETURNS: OK
 */

STATUS loadCommonMatch(
    COMMON_INFO *pCommonInfo,
    SYMTAB_ID    symTable
    );

/******************************************************************************
 * loadCommonManage - Process common symbol
 *
 * RETURNS: OK or ERROR
 */

STATUS loadCommonManage(
    int             size,
    int             align,
    char           *symName,
    SYMTAB_ID       symTable,
    SYM_ADDR       *pSymAddr,
    SYM_TYPE       *pSymType,
    int             loadFlag,
    SEG_INFO       *pSegInfo,
    unsigned short  group
    );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ASMLANGUAGE */

#endif /* _loadLib_h */

