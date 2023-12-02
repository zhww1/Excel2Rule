#pragma once




#include <CString>

#include "xls.h"
using namespace xls;
class  ReadExcel
{
public:
	
	ReadExcel();

	~ReadExcel();
	//打开工作簿
	void  openworkbooks(CString strpath);

	// 工作簿
	xlsWorkBook* getworkbooks();

	// 工作表
	xlsWorkSheet* selectSheet(int sheetIndex);

	//获取工作表数量
	int getSheetsCount();

	//获取工作表名称
	CString getSheetName(int sheetIndex);

	//获取工作表单元格内容
	CString getCellValue(int row, int column);

	//获取单元表行数
	int getUsedRowsCount();

	//获取单元表列数
	int getUsedColsCount();

	//关闭工作表
	void closeSheet();

	//关闭工作簿
	void closeWorkBook();
private:
	// 工作簿
	xlsWorkBook *pWB;
	// 工作表
	xlsWorkSheet *pWS;
	// 单元格
	xlsCell * cell;

};