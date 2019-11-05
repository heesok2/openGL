#pragma once

#include "Shader.h"

#include "HeaderPre.h"

class __MY_EXT_CLASS__ CShaderManager
{
public:
	CShaderManager();
	virtual ~CShaderManager();

public:
	BOOL IsValid(UINT uiType);
	CShader& GetAt(UINT uiType);

	void GLVersion();
	void GLCreateAll();
	void GLCreate(UINT uiType);

protected:
	std::map<UINT, CShader> m_mBuild;

};

#include "HeaderPost.h"