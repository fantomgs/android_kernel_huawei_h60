/*!
 *****************************************************************************
 *
 * @file       vdecfw_bin.h
 *
 * : Declarations of data structures for the compiled firmware.
 * ---------------------------------------------------------------------------
 *
 * Copyright (c) Imagination Technologies Ltd.
 * 
 * The contents of this file are subject to the MIT license as set out below.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 * 
 * Alternatively, the contents of this file may be used under the terms of the 
 * GNU General Public License Version 2 ("GPL")in which case the provisions of
 * GPL are applicable instead of those above. 
 * 
 * If you wish to allow use of your version of this file only under the terms 
 * of GPL, and not to allow others to use your version of this file under the 
 * terms of the MIT license, indicate your decision by deleting the provisions 
 * above and replace them with the notice and other provisions required by GPL 
 * as set out in the file called �GPLHEADER� included in this distribution. If 
 * you do not delete the provisions above, a recipient may use your version of 
 * this file under the terms of either the MIT license or GPL.
 * 
 * This License is also included in this distribution in the file called 
 * "MIT_COPYING".
 *
 *****************************************************************************/

#ifndef _VDECFW_BIN_H_
#define _VDECFW_BIN_H_

#include "img_include.h"
#include "vdec_api.h"

typedef struct
{
    /* Base */
    IMG_UINT32* aui32Text;
    IMG_UINT32  ui32TextSize;
    IMG_UINT32  ui32TextOrigin;
    IMG_UINT32* aui32Data;
    IMG_UINT32  ui32DataSize;
    IMG_UINT32  ui32DataOrigin;
#ifdef USE_FW_CTX_TRIMMING
    IMG_UINT32  ui32PsrCtxSize;
#endif /* USE_FW_CTX_TRIMMING */
#ifdef USE_FW_RELOC_INFO_PACKING
    IMG_UINT32  ui32PackedRelocInfoSize;
#else /* not USE_FW_RELOC_INFO_PACKING */
    /* Relocatable */
    IMG_UINT32* aui32TextReloc;
    IMG_UINT32  ui32TextRelocSize;
    IMG_UINT8*  aui8TextRelocType;
    IMG_UINT32* aui32TextRelocFullAddr;
    IMG_UINT32* aui32DataReloc;
    IMG_UINT32  ui32DataRelocSize;
#endif /* not USE_FW_RELOC_INFO_PACKING */

} VDECFW_sFirmwareBinInfo;


IMG_RESULT VDECFW_GetBaseFirmware(
    VDECFW_sFirmwareBinInfo *  psFirmwareBinInfo,
    IMG_BOOL                   bSingleStream,
    IMG_BOOL                   bOold,
    VDEC_eVidStd               eVidStd);

IMG_RESULT VDECFW_GetStdFirmware(
    VDECFW_sFirmwareBinInfo *  psFirmwareBinInfo,
    VDEC_eVidStd               eStd,
    IMG_BOOL                   bOold);
#endif /* _VDECFW_BIN_H_ */
