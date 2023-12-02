#pragma once




#include <CString>

#include "xls.h"
using namespace xls;
class  ReadExcel
{
public:
	
	ReadExcel();

	~ReadExcel();
	//�򿪹�����
	void  openworkbooks(CString strpath);

	// ������
	xlsWorkBook* getworkbooks();

	// ������
	xlsWorkSheet* selectSheet(int sheetIndex);

	//��ȡ����������
	int getSheetsCount();

	//��ȡ����������
	CString getSheetName(int sheetIndex);

	//��ȡ������Ԫ������
	CString getCellValue(int row, int column);

	//��ȡ��Ԫ������
	int getUsedRowsCount();

	//��ȡ��Ԫ������
	int getUsedColsCount();

	//�رչ�����
	void closeSheet();

	//�رչ�����
	void closeWorkBook();
private:
	// ������
	xlsWorkBook *pWB;
	// ������
	xlsWorkSheet *pWS;
	// ��Ԫ��
	xlsCell * cell;

};