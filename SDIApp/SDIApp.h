
// SDIApp.h : главный файл заголовка для приложения SDIApp
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSDIAppApp:
// О реализации данного класса см. SDIApp.cpp
//

class CSDIAppApp : public CWinApp
{
public:
	CSDIAppApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIAppApp theApp;


//класс для диалога построения
class CDlgAssembly : public CDialogEx
{
public:
	CDlgAssembly();

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	afx_msg void Assembly();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	// длина
	int l;
	// высота
	int h;
	// диаметр
	int d;
	afx_msg void OnBnClickedButton4();
};