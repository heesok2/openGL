#include "stdafx.h"
#include "WBFPakage.h"

#include "..\WBF_BASE\WBFDocBase.h"
#include "..\WBF_DATA\ModuleVertex.h"
#include "..\WBF_DATA\ModuleSubBody.h"
#include "..\WBF_DATA\ModuleBody.h"
#include "..\WBF_DATA\ModuleLight.h"
#include "..\WBF_DATA\ModuleBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWBFPackage::CWBFPackage(CWBFDocBase* pDoc)
	: CPackage(pDoc)
{
}

CWBFPackage::~CWBFPackage()
{
}

void CWBFPackage::OnInitial()
{
	auto lambda_module = [&](DTYPE dbType, CModuleBase* datamodule)
	{
		auto itr = m_mModule.find(dbType);
		if (itr != m_mModule.end())
		{
			ASSERT(g_warning);
			m_mModule.erase(itr);
		}

		ASSERT(datamodule->GetDataType() == dbType);
		m_mModule[dbType] = datamodule;
	};

	lambda_module(E_TYPE_VERTEX, new CModuleVertex(this));
	lambda_module(E_TYPE_SUBBODY, new CModuleSubBody(this));
	lambda_module(E_TYPE_BODY, new CModuleBody(this));
	lambda_module(E_TYPE_LIGHT, new CModuleLight(this));
	lambda_module(E_TYPE_BOX, new CModuleBox(this));
}

void CWBFPackage::OnDestroy()
{
	auto itr = m_mModule.begin();
	while (itr != m_mModule.end())
	{
		if (itr->second)
			itr->second->Clear();

		_SAFE_DELETE(itr->second);

		itr++;
	}

	m_mModule.clear();
}

CModuleBase * CWBFPackage::GetModule(DTYPE dbType)
{
	auto itr = m_mModule.find(dbType);
	if (itr == m_mModule.end()) return nullptr;

	return itr->second;
}
