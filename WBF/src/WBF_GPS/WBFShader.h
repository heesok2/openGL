#pragma once

#include <vector>
#include "HeaderPre.h"
class __MY_EXT_CLASS__ CWBFShader
{
public:
	CWBFShader();
	virtual ~CWBFShader();

public:
	void GLCreateProgram();
	void GLAttachShader(UINT nShaderType, UINT uiResID);
	void GLLinkShader();

	void GLBind();
	void GLUnbind();

protected:
	unsigned int m_nProg;
	std::vector<UINT> m_vShader;
};

#include "HeaderPost.h"
