#pragma once
//#include "SDIAppDoc.h"


// представление CMyView
class CSDIAppDoc;
class CMyView : public CTreeView
{
	DECLARE_DYNCREATE(CMyView)

protected:
	CMyView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyView();

public:
	HTREEITEM m_hRoot, m_hItem1, m_hItem2, m_hItem3, m_hItem4, m_hItem5, m_hItem6, m_hItem7, m_hItem8, m_hItem9, m_hItem10;

	void UpdateTree();
	
	CSDIAppDoc* pDoc;

	
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


