#pragma once
/*!
 * @file File.h
 *
 * @author 28927
 * @date 十二月 2019
 * @参考网上代码封装成一个文件类
 *  
 */

#include "StdAfx.h"
#include "Buffer.h"
#include <stdint.h>


	////////////////////////////////////
	//文件系列的函数
	////////////////////////////////////
	//打开一个文件并获得该文件的句柄
	HANDLE GetFileHandle(PCTSTR pszFileName);
	//获取文件大小
	DWORD IUGetFileSize(PCTSTR pszFileName);		//不支持超过4G的文件
	DWORD IUGetFileSize(HANDLE hFile);				//不支持超过4G的文件
	UINT64 IUGetFileSize2(PCTSTR pszFileName);		//支持超过4G的文件

	//获取文件指定部分
	BOOL GetFileData(HANDLE hFile, DWORD dwOffset, DWORD dwLength, char* buffer);
	BOOL GetFileData(PCTSTR pszFileName, DWORD dwOffset, DWORD dwLength, char* buffer);


	class CAutoFileHandle
	{
	public:
		CAutoFileHandle(HANDLE hFile);
		~CAutoFileHandle();

	public:
		operator HANDLE();
		void Release();

	private:
		HANDLE m_hFile;
	};
	


	/*
CreateFile 跟 fopen 不同，打开文件时不区分 文本方式 或 二进制 方式
ReadFile 或 WriteFile 都是对二进制数据进行操作
*/

	class CFile2
	{
	public:
		CFile2();
		~CFile2();

		BOOL Open(LPCTSTR lpszFileName, BOOL bCreateAlways = TRUE);
		long GetSize();

		const char* Read();

		const BYTE* ReadBin();


		

		BOOL Write(const char* pBuffer, long nSize);
		
		BOOL Write(const BYTE* pBuffer, long nSize);
		HANDLE GetFileHandle(){ return m_hFile; }

		void Close();

	private:
		HANDLE	m_hFile;
		CBuffer	m_Buffer;
	};


