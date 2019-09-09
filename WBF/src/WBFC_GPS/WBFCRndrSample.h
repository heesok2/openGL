#pragma once

#include "..\WBF_BASE\WBFRndrBase.h"

#include "HeaderPre.h"

class __MY_EXT_CLASS__ CWBFCRndrSample : public CWBFRndrBase
{
	DECLARE_RENDERER(CWBFCRndrSample);

public:
	CWBFCRndrSample();
	virtual ~CWBFCRndrSample();

public:
	virtual void OnInitialData();
	virtual void GLDraw();

};

#include "HeaderPost.h"