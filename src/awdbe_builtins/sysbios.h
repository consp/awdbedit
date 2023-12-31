//
// Award BIOS Editor - sysbios.h
// Copyright (C) 2002-2004, Michael Tedder
// All rights reserved
//
// $Id: sysbios.h,v 1.3 2004/04/11 07:17:15 bpoint Exp $
//
//----------------------------------------------------------------------------
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.
// 
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
//---------------------------------------------------------------------------------------------------------------------

#ifndef SYSBIOS_H
#define SYSBIOS_H

typedef uchar	u24[3];

#define U24_TO_ULONG(x)			((x[2] << 16) | (x[1] << 8) | (x[0]))
#define U24_TO_STRING(u2, str)	(snprintf(str,  sizeof(str), "%02X%02X%02X", u2[2], u2[1], u2[0]))
#define ULONG_TO_U24(ul, u2)	(memcpy(&u2[0], ((uchar *)&ul), 3))
#define STRING_TO_U24(str, u2)	{ ulong __temp__ = 0; sscanf(str, "%x", &__temp__); ULONG_TO_U24(__temp__, u2); }


#define METHOD_ADD				1
#define METHOD_SUB				2

extern uchar *sysbiosBasePtr;
extern awdbeBIOSVersion sysbiosVersion, sysbiosNowVer;

typedef struct
{
	ulong	 id;
	char	*name;

	int		 dialogID;
	DLGPROC	 dialogProc;

	HWND	 hwnd;
} sysbiosTabEntry;

extern sysbiosTabEntry sysbiosTabList[];


void sysbiosOnLoad(fileEntry *fe);

HWND sysbiosCreateDialog(HWND parentWnd);
void sysbiosOnDestroyDialog(HWND dialogWnd);
void sysbiosRefreshDialog(HWND hwnd, fileEntry *fe);
bool sysbiosUpdateDialog(HWND hwnd, fileEntry *fe);

void sysbiosOnResizeDialog(HWND dialogWnd, RECT *rc);


awdbeBIOSVersion sysbiosGetVersion(uchar *sptr, int len);

int   sysbiosFindLimit(uchar *base);
void  sysbiosUpdateLimit(HWND hdlg, int id, int curlen, int maxlen);
uchar sysbiosCalcBiosChecksum(uchar *ptr, ulong start, ulong end, int method);
void  sysbiosRecalcChecksum(bool showErr);

#endif
