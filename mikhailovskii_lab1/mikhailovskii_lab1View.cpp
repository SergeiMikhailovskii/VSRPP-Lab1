
// mikhailovskii_lab1View.cpp: реализация класса Cmikhailovskiilab1View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "mikhailovskii_lab1.h"
#endif

#include "mikhailovskii_lab1Doc.h"
#include "mikhailovskii_lab1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmikhailovskiilab1View

IMPLEMENT_DYNCREATE(Cmikhailovskiilab1View, CView)

BEGIN_MESSAGE_MAP(Cmikhailovskiilab1View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение Cmikhailovskiilab1View

Cmikhailovskiilab1View::Cmikhailovskiilab1View() noexcept
{
	m_Dragging = 0;
	m_HCross = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
}

Cmikhailovskiilab1View::~Cmikhailovskiilab1View()
{
}

BOOL Cmikhailovskiilab1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs
	m_ClassName = AfxRegisterWndClass(
		CS_HREDRAW | CS_VREDRAW, // стили окна
		0,					  // без указателя;
		(HBRUSH)::GetStockObject(WHITE_BRUSH),
		// задать чисто белый фон;
		0);					  //без значка
	cs.lpszClass = m_ClassName;

	return CView::PreCreateWindow(cs);
}

// Рисование Cmikhailovskiilab1View

void Cmikhailovskiilab1View::OnDraw(CDC* pDC)
{
	Cmikhailovskiilab1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int Index = pDoc->GetNumLines();
	while (Index--)
		pDoc->GetLine(Index)->Draw(pDC);

	// TODO: добавьте здесь код отрисовки для собственных данных
}

void Cmikhailovskiilab1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmikhailovskiilab1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика Cmikhailovskiilab1View

#ifdef _DEBUG
void Cmikhailovskiilab1View::AssertValid() const
{
	CView::AssertValid();
}

void Cmikhailovskiilab1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmikhailovskiilab1Doc* Cmikhailovskiilab1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmikhailovskiilab1Doc)));
	return (Cmikhailovskiilab1Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений Cmikhailovskiilab1View


void Cmikhailovskiilab1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_PointOld = point;
	m_PointOrigin = point;

	SetCapture();
	m_Dragging = 1;

	RECT Rect;
	GetClientRect(&Rect);
	ClientToScreen(&Rect);
	::ClipCursor(&Rect);

	CView::OnLButtonDown(nFlags, point);
}

void Cmikhailovskiilab1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Здесь добавьте собственный код обработчика
// и/или вызов стандартного обработчика

	::SetCursor(m_HCross);
	CPen* oldPen;
	if (m_Dragging)
	{
		CClientDC ClientDC(this);
		CPen pen(PS_SOLID, 0, RGB(255, 255, 255));
		oldPen = ClientDC.SelectObject(&pen);
		ClientDC.SetROP2(R2_COPYPEN);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(m_PointOld);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(point);
		ClientDC.SelectObject(oldPen);
		m_PointOld = point;
	}

	CView::OnMouseMove(nFlags, point);
}

void Cmikhailovskiilab1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Здесь добавьте код собственного обработчика 
// и/или вызов стандартного обработчика 

	if (m_Dragging)
	{
		CPen* oldPen;

		m_Dragging = 0;
		::ReleaseCapture();
		::ClipCursor(NULL);
		CClientDC ClientDC(this);
		CPen pen(PS_SOLID, 1, RGB(rand() % 256, rand() % 256, rand() % 256));
		oldPen = ClientDC.SelectObject(&pen);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(m_PointOld);
		ClientDC.SetROP2(R2_COPYPEN);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(point);
		Cmikhailovskiilab1Doc* pDoc = GetDocument();
		pDoc->AddLine(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
	}

	CView::OnLButtonUp(nFlags, point);
}
