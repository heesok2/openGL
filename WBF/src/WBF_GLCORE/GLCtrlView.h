#pragma once

#include "GLView.h"
#include "Camera.h"
#include "FrameBufferManager.h"

#include "HeaderPre.h"

class __MY_EXT_CLASS__ CGLCtrlView : public CGLView
{
public:
	CGLCtrlView();
	virtual ~CGLCtrlView();

public:
	glm::vec3 GetEyePosition();
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

protected:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP();

protected:
	CFrameBufferManager m_FrameBufferManager;
	CCamera m_Camera;

};

#include "HeaderPost.h"