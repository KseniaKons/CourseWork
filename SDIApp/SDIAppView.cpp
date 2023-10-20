
// SDIAppView.cpp : реализаци€ класса CSDIAppView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SDIApp.h"
#endif

#include "SDIAppDoc.h"
#include "SDIAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIAppView

IMPLEMENT_DYNCREATE(CSDIAppView, CView)

BEGIN_MESSAGE_MAP(CSDIAppView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// создание/уничтожение CSDIAppView

CSDIAppView::CSDIAppView()
{
	// TODO: добавьте код создани€

}

CSDIAppView::~CSDIAppView()
{
}

BOOL CSDIAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CSDIAppView

void CSDIAppView::OnDraw(CDC* pDC)
{
	CSDIAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBitmap bitmap;
	if (pDoc->selectedLine == 0)
	{
		bitmap.LoadBitmap(IDB_AS);
	}

	else if (pDoc->selectedLine == 1)
	{
		bitmap.LoadBitmap(IDB_KORPUS);
	}

	else if (pDoc->selectedLine == 2)
	{
		bitmap.LoadBitmap(IDB_KRISHKA);
	}

	else if (pDoc->selectedLine == 3)
	{
		bitmap.LoadBitmap(IDB_OPORA);
	}

	else if (pDoc->selectedLine == 4)
	{
		bitmap.LoadBitmap(IDB_MUF);
	}

	else if (pDoc->selectedLine == 5)
	{
		bitmap.LoadBitmap(IDB_NOGI);
	}

	else if (pDoc->selectedLine == 6)
	{
		bitmap.LoadBitmap(IDB_VO);
	}

	else if (pDoc->selectedLine == 7)
	{
		bitmap.LoadBitmap(IDB_NO);
	}

	else if (pDoc->selectedLine == 8)
	{
		bitmap.LoadBitmap(IDB_BALKA);
	}

	
	CDC memdc;
	memdc.CreateCompatibleDC(pDC);
	CBitmap* oldbmp = memdc.SelectObject(&bitmap);

	BITMAP BitMap;
	bitmap.GetBitmap(&BitMap);
	pDC->BitBlt(50, 50, BitMap.bmWidth, BitMap.bmHeight, &memdc, 0, 0, SRCCOPY);

	pDC->SelectObject(oldbmp);

/*
	
	if (m_bShipsDraw)
	{

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				CBitmap bitmap;
				if (i % 2 == 0 && j % 2 == 0)
					bitmap.LoadBitmap(IDB_BITMAP_SHIP);
				else
					bitmap.LoadBitmap(IDB_BITMAP_SEA);

				CDC memdc;
				memdc.CreateCompatibleDC(pDC);
				CBitmap* oldbmp = memdc.SelectObject(&bitmap);

				BITMAP BitMap;
				bitmap.GetBitmap(&BitMap);
				pDC->BitBlt(50 + i * BitMap.bmWidth, 50 + j * BitMap.bmHeight, BitMap.bmWidth, BitMap.bmHeight, &memdc, 0, 0, SRCCOPY);

				pDC->SelectObject(oldbmp);
			}
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				CBitmap bitmap;
				if (i % 2 == 0 && j % 2 == 0)
					bitmap.LoadBitmap(IDB_BITMAP_BANG);
				else
					bitmap.LoadBitmap(IDB_BITMAP_SEA);

				CDC memdc;
				memdc.CreateCompatibleDC(pDC);
				CBitmap* oldbmp = memdc.SelectObject(&bitmap);

				BITMAP BitMap;
				bitmap.GetBitmap(&BitMap);
				pDC->BitBlt(50 + i * BitMap.bmWidth, 50 + j * BitMap.bmHeight, BitMap.bmWidth, BitMap.bmHeight, &memdc, 0, 0, SRCCOPY);

				pDC->SelectObject(oldbmp);
			}
		}

	}*/

}


// печать CSDIAppView

BOOL CSDIAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSDIAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSDIAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CSDIAppView

#ifdef _DEBUG
void CSDIAppView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIAppDoc* CSDIAppView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIAppDoc)));
	return (CSDIAppDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CSDIAppView
