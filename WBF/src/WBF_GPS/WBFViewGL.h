#pragma once

#include "HeaderPre.h"

class __MY_EXT_CLASS__ CWBFViewGL : public CView
{
public:
	CWBFViewGL();
	virtual ~CWBFViewGL();
	
public:
	void BeginwglCurrent();
	void EndwglCurrent();
	void SwapBuffers();

protected:
	void InitializePalette();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnQueryNewPalette();
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP();


protected:
	HDC m_hDC;
	HGLRC m_hRC;

	CPalette m_GLPalette;	// Logical Palette
};

#include "HeaderPost.h"