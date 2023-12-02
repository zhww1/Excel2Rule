#pragma once
/*!
 * @file File.h
 *
 * @author 28927
 * @date ʮ���� 2019
 * @�ο����ϴ����װ��һ���ļ���
 *  
 */

#include "StdAfx.h"
#include "Buffer.h"
#include <stdint.h>


	////////////////////////////////////
	//�ļ�ϵ�еĺ���
	////////////////////////////////////
	//��һ���ļ�����ø��ļ��ľ��
	HANDLE GetFileHandle(PCTSTR pszFileName);
	//��ȡ�ļ���С
	DWORD IUGetFileSize(PCTSTR pszFileName);		//��֧�ֳ���4G���ļ�
	DWORD IUGetFileSize(HANDLE hFile);				//��֧�ֳ���4G���ļ�
	UINT64 IUGetFileSize2(PCTSTR pszFileName);		//֧�ֳ���4G���ļ�

	//��ȡ�ļ�ָ������
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
CreateFile �� fopen ��ͬ�����ļ�ʱ������ �ı���ʽ �� ������ ��ʽ
ReadFile �� WriteFile ���ǶԶ��������ݽ��в���
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


