
// uart_test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cuart_testApp:
// �йش����ʵ�֣������ uart_test.cpp
//

class Cuart_testApp : public CWinApp
{
public:
	Cuart_testApp();
	

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cuart_testApp theApp;