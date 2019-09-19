#pragma once

#include "WBFGraphicDef.h"
#include "WBFModelFactory.h"
#include "HeaderPre.h"

class CWBFOption;
class CWBFModelBaseManager;
class __MY_EXT_CLASS__ CWBFModelBase : public CObject
{
public:
	CWBFModelBase();
	virtual ~CWBFModelBase();

public: // Update Flag
	virtual void InitFlag() { m_uiFlag = MODEL_UNKNOWN; }
	virtual void SetFlag(UINT uiFlag) { m_uiFlag |= uiFlag; }
	virtual UINT GetFlag() { return m_uiFlag; }

public:
	virtual UINT GetType() { ASSERT(g_warning); return gps::E_GPS_UNKNOWN; }
	virtual CWBFOption* GetOption() { ASSERT(g_warning); return nullptr; }

	virtual BOOL IsValidModel() = 0;
	virtual void GLInitialData() = 0;
	virtual void GLCreateVBO() = 0;
	virtual void GLAttachData() = 0;
	virtual void GLBind() = 0;
	virtual void GLDraw() = 0;
	virtual void GLUnbind() = 0;
	virtual void GLDelete() = 0;

public:
	void SetHelper(CWBFModelBaseManager* pModelMgr)
	{
		m_pModelMgr = pModelMgr;
	}

protected:
	UINT m_uiFlag;
	CWBFModelBaseManager* m_pModelMgr;
};

#include "HeaderPost.h"

#define DECLARE_MODEL(class_name)\
DECLARE_DYNCREATE(class_name);\
virtual UINT GetType();

#define IMPLEMENT_MODEL(class_name, type)\
IMPLEMENT_DYNCREATE(class_name, CWBFModelBase);\
BOOL bRegModel = CWBFModelFactory::GetInstance().RegisterObject(RUNTIME_CLASS(class_name), type);\
UINT class_name::GetType() { return type; }