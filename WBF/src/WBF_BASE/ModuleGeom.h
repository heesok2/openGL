#pragma once

#include "WBFModuleData.hpp"
#include "EntityGeom.h"

#include "HeaderPre.h"

class __MY_EXT_CLASS__ CModuleGeom : public CWBFModuleData<CEntityGeom>
{
public:
	CModuleGeom(CWBFPackageData * pPackage);
	virtual ~CModuleGeom();

public:
	virtual void SetDefaultData();

};

#include "HeaderPost.h"