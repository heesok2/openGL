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

// WBFDoc.cpp: CWBFDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WBF.h"
#endif

#include <propkey.h>

#include "WBFDoc.h"
#include "WBFPakage.h"

#include "..\WBF_LIB\NotifyDefine.h"
#include "..\WAF_GPS\WBFModelManager.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CWBFDoc

IMPLEMENT_DYNCREATE(CWBFDoc, CDocBase)

BEGIN_MESSAGE_MAP(CWBFDoc, CDocBase)
END_MESSAGE_MAP()

// CWBFDoc 생성/소멸

CWBFDoc::CWBFDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

	m_pPackage = new CWBFPackage(this);
}

CWBFDoc::~CWBFDoc()
{
	_SAFE_DELETE(m_pPackage);
}

// CWBFDoc serialization

void CWBFDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CWBFDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CWBFDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWBFDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CWBFDoc 진단

#ifdef _DEBUG
void CWBFDoc::AssertValid() const
{
	CDocBase::AssertValid();
}

void CWBFDoc::Dump(CDumpContext& dc) const
{
	CDocBase::Dump(dc);
}

#endif //_DEBUG

BOOL CWBFDoc::OnNewDocument()
{
	if (!CDocBase::OnNewDocument())
		return FALSE;

	OnInitial();

	return TRUE;
}

BOOL CWBFDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocBase::OnOpenDocument(lpszPathName))
		return FALSE;

	OnInitial();

	return TRUE;
}

void CWBFDoc::OnCloseDocument()
{
	OnDestroy();

	CDocBase::OnCloseDocument();
}

void CWBFDoc::OnInitial()
{
	m_pPackage->OnInitial();
}

void CWBFDoc::OnDestroy()
{
	UpdateAllViews(nullptr, E_DOCUMENT_CLOSE);

	m_pPackage->OnDestroy();
}