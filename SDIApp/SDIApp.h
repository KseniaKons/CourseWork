
// SDIApp.h : ������� ���� ��������� ��� ���������� SDIApp
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CSDIAppApp:
// � ���������� ������� ������ ��. SDIApp.cpp
//

class CSDIAppApp : public CWinApp
{
public:
	CSDIAppApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIAppApp theApp;


//����� ��� ������� ����������
class CDlgAssembly : public CDialogEx
{
public:
	CDlgAssembly();

	// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	afx_msg void Assembly();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	// �����
	int l;
	// ������
	int h;
	// �������
	int d;
	afx_msg void OnBnClickedButton4();
};