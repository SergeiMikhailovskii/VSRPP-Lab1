
// mikhailovskii_lab1Doc.cpp: реализация класса Cmikhailovskiilab1Doc 
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "mikhailovskii_lab1.h"
#endif

#include "mikhailovskii_lab1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cmikhailovskiilab1Doc

IMPLEMENT_DYNCREATE(Cmikhailovskiilab1Doc, CDocument)

BEGIN_MESSAGE_MAP(Cmikhailovskiilab1Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение Cmikhailovskiilab1Doc

Cmikhailovskiilab1Doc::Cmikhailovskiilab1Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

Cmikhailovskiilab1Doc::~Cmikhailovskiilab1Doc()
{
}

BOOL Cmikhailovskiilab1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация Cmikhailovskiilab1Doc

void Cmikhailovskiilab1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void Cmikhailovskiilab1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void Cmikhailovskiilab1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void Cmikhailovskiilab1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика Cmikhailovskiilab1Doc

#ifdef _DEBUG
void Cmikhailovskiilab1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cmikhailovskiilab1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды Cmikhailovskiilab1Doc

void CLine::Draw(CDC *PDC)
{
	PDC->MoveTo(m_X1, m_Y1);
	PDC->LineTo(m_X2, m_Y2);
}

void Cmikhailovskiilab1Doc::AddLine(int X1, int Y1, int X2, int Y2)
{
	CLine *pLine = new CLine(X1, Y1, X2, Y2);
	m_LineArray.Add(pLine);
}
CLine* Cmikhailovskiilab1Doc::GetLine(int Index)
{
	if (Index<0 || Index>m_LineArray.GetUpperBound())
		return 0;
	return m_LineArray.GetAt(Index);
}

int Cmikhailovskiilab1Doc::GetNumLines()
{
	return (int)m_LineArray.GetSize();
}
