
// ExcelToBin.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExcelToBinApp: 
// �йش����ʵ�֣������ ExcelToBin.cpp
//

class CExcelToBinApp : public CWinApp
{
public:
	CExcelToBinApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExcelToBinApp theApp;