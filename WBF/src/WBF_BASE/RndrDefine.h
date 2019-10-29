#pragma once

#ifndef DEFINE_RNDR
#define DEFINE_RNDR

enum E_RNDR_TYPE
{
	E_RNDR_UNKNOWN = -1,
	E_RNDR_SCREEN = 0,
	E_RNDR_SAMPLE,
	E_RNDR_LIGHT,
	E_RNDR_BOX,

	E_RNDR_NUM
};

#endif // !DEFINE_RNDR