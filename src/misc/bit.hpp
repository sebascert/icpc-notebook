/**
 * Lines: [7,11]
 */
#pragma once
#include "template.hpp"

void submasks(lli mask) {
	for(lli sub = mask; sub; sub = (sub - 1) & mask) perr(sub);
}

#define bits(x) (64 - __builtin_clzll(x))
