
// mikhailovskii_lab1View.h: интерфейс класса Cmikhailovskiilab1View
//

#pragma once


class Cmikhailovskiilab1View : public CView
{
protected: // создать только из сериализации
	Cmikhailovskiilab1View() noexcept;
	DECLARE_DYNCREATE(Cmikhailovskiilab1View)

// Атрибуты
protected:
	CString m_ClassName;
	int m_Dragging;
	HCURSOR m_HCross;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
public:
	Cmikhailovskiilab1Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~Cmikhailovskiilab1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // версия отладки в mikhailovskii_lab1View.cpp
inline Cmikhailovskiilab1Doc* Cmikhailovskiilab1View::GetDocument() const
   { return reinterpret_cast<Cmikhailovskiilab1Doc*>(m_pDocument); }
#endif

