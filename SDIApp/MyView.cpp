// MyView.cpp: ���� ����������
//

#include "stdafx.h"
#include "SDIApp.h"
#include "MyView.h"
#include "SDIAppDoc.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CTreeView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// ����������� CMyView

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// ����������� ��������� CMyView

void CMyView::UpdateTree()
{
	CTreeCtrl &tree = GetTreeCtrl();

	tree.DeleteAllItems();

	m_hRoot = tree.InsertItem(L"������", -1, -1, NULL, TVI_FIRST);

	m_hItem1 = tree.InsertItem(L"������", -1, -1, m_hRoot, TVI_LAST);
	m_hItem2 = tree.InsertItem(L"������", -1, -1, m_hRoot, TVI_LAST);
	m_hItem3 = tree.InsertItem(L"������� �������", -1, -1, m_hRoot, TVI_LAST);
	m_hItem4 = tree.InsertItem(L"�����", -1, -1, m_hRoot, TVI_LAST);
	m_hItem5 = tree.InsertItem(L"�����", -1, -1, m_hRoot, TVI_LAST);
	m_hItem6 = tree.InsertItem(L"������� �����", -1, -1, m_hRoot, TVI_LAST);
	m_hItem7 = tree.InsertItem(L"������ �����", -1, -1, m_hRoot, TVI_LAST);
	m_hItem8 = tree.InsertItem(L"�������������� �����", -1, -1, m_hRoot, TVI_LAST);
	


	tree.Expand(m_hRoot, TVE_EXPAND);

	
	tree.SetItemData(m_hRoot, 0);
	tree.SetItemData(m_hItem1, 1);
	tree.SetItemData(m_hItem2, 2);
	tree.SetItemData(m_hItem3, 3);
	tree.SetItemData(m_hItem4, 4);
	tree.SetItemData(m_hItem5, 5);
	tree.SetItemData(m_hItem6, 6);
	tree.SetItemData(m_hItem7, 7);
	tree.SetItemData(m_hItem8, 8);

}


int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �������� ������������������ ��� ��������


	return 0;
}


void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	CTreeView::OnLButtonDown(nFlags, point);

	CTreeCtrl& tree = GetTreeCtrl();

	HTREEITEM ded = tree.GetSelectedItem();

	pDoc->selectedLine = tree.GetItemData(ded); //� ���������� ��������� ����� ��������� ������

	pDoc->m_pView->Invalidate(TRUE); //���������� ������


}


void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	CTreeCtrl& tree = GetTreeCtrl();

	HTREEITEM as = tree.GetSelectedItem(); //��� �������, ������� ������� ������

	int num = tree.GetItemData(as);

	if (num == 0) //����� ����������� ���� ��� ������� ������� �� ������
	{
		CDlgAssembly dlgAs;
		dlgAs.DoModal();
	}

	CTreeView::OnLButtonDblClk(nFlags, point);
}
