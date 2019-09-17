
// mikhailovskii_lab1.h: основной файл заголовка для приложения mikhailovskii_lab1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Cmikhailovskiilab1App:
// Сведения о реализации этого класса: mikhailovskii_lab1.cpp
//

class Cmikhailovskiilab1App : public CWinAppEx
{
public:
	Cmikhailovskiilab1App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cmikhailovskiilab1App theApp;
