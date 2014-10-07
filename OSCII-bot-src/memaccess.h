// OSCII-bot
// Copyright (C) 2013 Cockos Incorporated
// License: GPL
// Added by Ulrich Melzer

#ifndef _OSCIIBOT_MEMACCESS_H_
#define _OSCIIBOT_MEMACCESS_H_

#include "../WDL/eel2/ns-eel-int.h"

EEL_F getEELMem(compileContext *ctx, int addr) {
	if (ctx && addr >= 0)
	{
		EEL_F **blocks = ctx->ram_state.blocks;
		unsigned int whichblock = addr / NSEEL_RAM_ITEMSPERBLOCK;
		unsigned int offset = addr % NSEEL_RAM_ITEMSPERBLOCK;
		EEL_F *block = blocks[whichblock];
		EEL_F *x = 0;
		if (block) {
			x = block + offset;
		}
		return *x;
	}
	return 0.0;
}

void setEELMem(compileContext *ctx, int addr, EEL_F value) {
	if (ctx && addr >= 0)
	{
		EEL_F **blocks = ctx->ram_state.blocks;
		unsigned int whichblock = addr / NSEEL_RAM_ITEMSPERBLOCK;
		unsigned int offset = addr % NSEEL_RAM_ITEMSPERBLOCK;
		EEL_F *block = blocks[whichblock];
		EEL_F *x;
		if (!block) {
			__NSEEL_RAMAlloc(blocks, addr);
			block = blocks[whichblock];
		}
		if (block) {
			x = block + offset;
			*x = value;
		}
	}
}

#endif