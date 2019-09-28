#include "stdafx.h"
#include "WBFModelDataManager.h"
#include "WBFModelData.h"
#include "WBFVBOManager.h"

#include "WBFViewBase.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWBFModelDataManager::CWBFModelDataManager(CWBFViewBase* pView)
{
	m_pMyDoc = (CWBFDocBase*)pView->GetDocument();
	m_pView = pView;
}

CWBFModelDataManager::~CWBFModelDataManager()
{
}

void CWBFModelDataManager::OnInitial()
{
	for (long indx = 0; indx < E_MODEL_NUM; ++indx)
	{
		auto pObject = (CWBFModelData*)CWBFModelFactory::GetInstance().CreateObject(indx);
		if (pObject == nullptr) continue;

		pObject->SetHelper(this);
		m_vObject.push_back(pObject);
	}
}

void CWBFModelDataManager::OnDestroy()
{
	for (auto pObject : m_vObject)
	{
		_SAFE_DELETE(pObject);
	}

	m_vObject.clear();
}

CWBFModelData * CWBFModelDataManager::GetModel(UINT uiType)
{
	for (auto pObject : m_vObject)
	{
		if (pObject->GetType() == uiType)
			return pObject;
	}

	//ASSERT(g_warning);
	return nullptr;
}

