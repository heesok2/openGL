﻿// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해
// 추가적으로 제공되는 내용입니다.
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// WBFDoc.h: CWBFDoc 클래스의 인터페이스
//


#pragma once

#include "..\WBF_BASE\WBFDocBase.h"

class CWBFPackageSystem;
class CWBFCModelManager;
class CWBFDoc : public CWBFDocBase
{
public: // serialization에서만 만들어집니다.
	CWBFDoc() noexcept;
	virtual ~CWBFDoc();

	DECLARE_DYNCREATE(CWBFDoc)

public:
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	virtual void Serialize(CArchive& ar);
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();

public:
	virtual CWBFPackageData* GetDataPackage() { return (CWBFPackageData*)m_pPackage; }
	virtual CWBFModelBaseManager* GetModelManager() { return (CWBFModelBaseManager*)m_pModelMgr; }

protected:
	void OnInitialUpdate();
	void OnDestroy();

protected:
	DECLARE_MESSAGE_MAP()

protected:
	CWBFPackageSystem* m_pPackage;
	CWBFCModelManager* m_pModelMgr;

};
