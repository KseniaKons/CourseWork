
// SDIAppView.h : ��������� ������ CSDIAppView
//

#pragma once

class CSDIAppDoc;

class CSDIAppView : public CView
{
protected: // ������� ������ �� ������������
	CSDIAppView();
	DECLARE_DYNCREATE(CSDIAppView)

// ��������
public:
	CSDIAppDoc* GetDocument() const;

// ��������
public:
	bool m_bShipsDraw = true;

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CSDIAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � SDIAppView.cpp
inline CSDIAppDoc* CSDIAppView::GetDocument() const
   { return reinterpret_cast<CSDIAppDoc*>(m_pDocument); }
#endif

