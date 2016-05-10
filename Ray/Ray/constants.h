#pragma once

const double epsilon = 0.0001;

// TODO: allow configuration
#define TRACEDEPTH		6

enum hitStatus {
	HIT = 1,
	MISS = 0,
	INPRIM = -1,
};