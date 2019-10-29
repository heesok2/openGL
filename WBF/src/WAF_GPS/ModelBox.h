#pragma once

#include "..\WBF_BASE\ModelData.h"

#include "HeaderPre.h"

class __MY_EXT_CLASS__ CModelBox : public CModelData
{
	struct TModelBox
	{
		UINT uiVAO;
		UINT uiDataNum;
		glm::vec3 ModelPos;
		glm::vec3 LightPos;
	};

public:
	CModelBox();
	virtual ~CModelBox();

	DECLARE_MODEL(CModelBox);

public:
	virtual UINT GetType() override { return E_MODEL_BOX; }
	virtual void Release() override;
	virtual void Build() override;
	virtual void Draw(CShader * pShader) override;

protected:
	std::vector<TModelBox> m_lstBox;
};

#include "HeaderPost.h"