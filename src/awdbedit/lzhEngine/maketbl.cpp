//
// Award BIOS Editor - maketbl.cpp
// [ make table for decoding ]
//
// $Id: maketbl.cpp,v 1.3 2004/04/11 07:17:16 bpoint Exp $
//
//----------------------------------------------------------------------------
//
// Award BIOS Editor's LZH Engine was adapted from "ar" archiver written by 
// Haruhiko Okumura.
//

#include <stdint.h>
#include "lzhEngine.h"

void make_table(ushort nchar, uchar bitlen[], ushort tablebits, ushort table[])
{
	ushort count[17], weight[17], start[18], *p;
	ushort i, k, len, ch, jutbits, avail, nextcode, mask;

	for (i = 1; i <= 16; i++) count[i] = 0;
	for (i = 0; i < nchar; i++) count[bitlen[i]]++;

	start[1] = 0;
	for (i = 1; i <= 16; i++)
		start[i + 1] = start[i] + static_cast<uint16_t>(count[i] << (16 - i));
	if (start[17] != (ushort)(1U << 16))
	{
//		error("Bad table");
		return;
	}

	jutbits = 16 - tablebits;
	for (i = 1; i <= tablebits; i++) {
		start[i] >>= jutbits;
		weight[i] = static_cast<uint16_t>(1U << (tablebits - i));
	}
	while (i <= 16) weight[i++] = 1U << (16 - i);

	i = start[tablebits + 1] >> jutbits;
	if (i != (ushort)(1U << 16)) {
		k = static_cast<uint16_t>(1U << tablebits);
		while (i != k) table[i++] = 0;
	}

	avail = nchar;
	mask = static_cast<uint16_t>(1U << (15 - tablebits));
	for (ch = 0; ch < nchar; ch++) {
		if ((len = bitlen[ch]) == 0) continue;
		nextcode = start[len] + weight[len];
		if (len <= tablebits) {
			for (i = start[len]; i < nextcode; i++) table[i] = ch;
		} else {
			k = start[len];
			p = &table[k >> jutbits];
			i = len - tablebits;
			while (i != 0) {
				if (*p == 0) {
					right[avail] = left[avail] = 0;
					*p = avail++;
				}
				if (k & mask) p = &right[*p];
				else          p = &left[*p];
				k <<= 1;  i--;
			}
			*p = ch;
		}
		start[len] = nextcode;
	}
}
