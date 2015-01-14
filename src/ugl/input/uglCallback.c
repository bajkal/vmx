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

/* uglCallback.c - Universal graphics library callbacks */

#include <string.h>
#include "ugl.h"
#include "uglMsg.h"
#include "uglinput.h"

#define UGL_CB_ARRAY_START_SIZE         4
#define UGL_CB_ARRAY_SIZE_DELTA(_sz)    ((_sz) = (_sz) * 3 / 2)

/* Types */

typedef struct ugl_cb_list {
    UGL_SIZE             arraySize;
    UGL_SIZE             numCallbacks;
    struct ugl_cb_item  *pCbArray;
} UGL_CB_LIST;

/* Locals */

UGL_LOCAL UGL_STATUS uglCbArrayRealloc (
    UGL_CB_LIST_ID  cbListId
    );

/******************************************************************************
 *
 * uglCbAdd - Add callback to callback list
 *
 * RETURNS: UGL_STATUS_OK or UGL_STATUS_ERROR
 */

UGL_STATUS uglCbAdd (
    UGL_CB_LIST_ID  cbListId,
    UGL_UINT32      filterMin,
    UGL_UINT32      filterMax,
    UGL_CB         *pCallback,
    void           *pParam
    ) {
    UGL_STATUS  status;
    UGL_ORD     i;

    if (cbListId == UGL_NULL) {
        status = UGL_STATUS_ERROR;
    }
    else {
        if (cbListId->numCallbacks >= cbListId->arraySize) {
            status = uglCbArrayRealloc(cbListId);
            if (status == UGL_STATUS_OK) {
                i = cbListId->numCallbacks;

                cbListId->pCbArray[i].filterMin = filterMin;
                cbListId->pCbArray[i].filterMax = filterMax;
                cbListId->pCbArray[i].pCallback = pCallback;
                cbListId->pCbArray[i].pParam    = pParam;
                cbListId->numCallbacks++;
            }
        }
        else {
            status = UGL_STATUS_OK;
        }
    }

    return status;
}

/******************************************************************************
 *
 * uglCbAddArray - Add array of callbacks to callback list
 *
 * RETURNS: UGL_STATUS_OK or UGL_STATUS_ERROR
 */

UGL_STATUS uglCbAddArray (
    UGL_CB_LIST_ID    cbListId,
    const UGL_CB_ITEM *pCbArray
    ) {

    return uglCbAdd(cbListId, 0, 0, UGL_NULL, (void *) pCbArray);
}

/******************************************************************************
 *
 * uglCbListCreate - Create callback list
 *
 * RETURNS: UGL_CB_LIST_ID or UGL_NULL
 */

UGL_CB_LIST_ID uglCbListCreate (
    const  UGL_CB_ITEM  *pCbArray
    ) {
    UGL_CB_LIST  *pCbList;

    pCbList = (UGL_CB_LIST *) UGL_CALLOC(1, sizeof(UGL_CB_LIST));
    if (pCbList != UGL_NULL) {
        if (uglCbAddArray(pCbList, pCbArray) != UGL_STATUS_OK) {
            UGL_FREE(pCbList);
            pCbList = UGL_NULL;
        }
    }

    return pCbList;
}

/******************************************************************************
 *
 * uglCbListDestroy - Destroy callback list
 *
 * RETURNS: UGL_STATUS_OK or UGL_STATUS_ERROR
 */

UGL_STATUS uglCbListDestroy (
    UGL_CB_LIST_ID  cbListId
    ) {
    UGL_STATUS  status;

    if (cbListId == UGL_NULL) {
        status = UGL_STATUS_ERROR;
    }
    else {
        if (cbListId->arraySize > 0) {
            UGL_FREE(cbListId->pCbArray);
        }

        UGL_FREE(cbListId);
        status = UGL_STATUS_OK;
    }

    return status;
}

/******************************************************************************
 *
 * uglCbArrayRealloc - Reallocate storage for array
 *
 * RETURNS: UGL_STATUS_OK or UGL_STATUS_ERROR
 */

UGL_LOCAL UGL_STATUS uglCbArrayRealloc (
    UGL_CB_LIST_ID  cbListId
    ) {
    UGL_STATUS  status;
    UGL_SIZE    arraySize = cbListId->arraySize;

    if (cbListId->numCallbacks >= cbListId->arraySize) {
        if (cbListId->pCbArray == UGL_NULL) {
            arraySize = UGL_CB_ARRAY_START_SIZE;
        }
        else {
            arraySize = cbListId->numCallbacks;
            UGL_CB_ARRAY_SIZE_DELTA(arraySize);
        }

        cbListId->pCbArray = (UGL_CB_ITEM *) UGL_REALLOC(
            cbListId->pCbArray,
            arraySize * sizeof(UGL_CB_ITEM)
            );

        if (cbListId->pCbArray == UGL_NULL) {
            status = UGL_STATUS_ERROR;
        }
        else {
            status = UGL_STATUS_OK;
        }
    }
    else {
        status = UGL_STATUS_OK;
    }

    return status;
}
