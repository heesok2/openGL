#include "stdafx.h"
#include "ModelManager.h"
#include "ModelData.h"

#include "WBFVBOManager.h"

#include "WBFViewBase.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CModelManager::CModelManager(CViewBase* pView)
{
	m_pMyDoc = (CDocBase*)pView->GetDocument();
	m_pView = pView;
}

CModelManager::~CModelManager()
{
}

void CModelManager::OnInitial()
{
	for (long indx = 0; indx < E_MODEL_NUM; ++indx)
	{
		auto pObject = (CModelData*)CModelFactory::GetInstance().CreateObject(indx);
		if (pObject == nullptr) continue;

		pObject->SetHelper(this);
		m_vObject.push_back(pObject);
	}
}

void CModelManager::OnDestroy()
{
	for (auto pObject : m_vObject)
	{
		_SAFE_DELETE(pObject);
	}

	m_vObject.clear();
}

CModelData * CModelManager::GetModel(UINT uiType)
{
	for (auto pObject : m_vObject)
	{
		if (pObject->GetType() == uiType)
			return pObject;
	}

	//ASSERT(g_warning);
	return nullptr;
}

