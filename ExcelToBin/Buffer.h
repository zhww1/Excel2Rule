#pragma once

class CBuffer
{
public:
	CBuffer();
	~CBuffer(void);

public:
	char* GetBuffer(DWORD dwSize);
	void SetSize(DWORD dwNewSize);
	void SetGrowBy(DWORD dwGrowBy);
	BOOL Add(const CHAR* lpStr);
	BOOL Add(const WCHAR* lpStr);
	BOOL Add(CBuffer& src);
	BOOL Add(const char* lpData, DWORD dwSize);

	BOOL Add(const BYTE* lpStr);//֧�ֶ������ļ�
	BOOL Add(const BYTE * lpData, DWORD dwSize);
	BYTE* GetBufferBin(DWORD dwSize);

	const BYTE* GetDataBin();
	const char* GetData();
	void* GetExtra();
	void SetExtra(void* pExtra);
	DWORD GetSize();
	void Release();

private:
	BOOL ReAlloc(DWORD dwSize);

private:
	//char m_cFixData[1024* 4];
	//char* m_lpData;

	//�������ļ�
	BYTE m_cFixData[1024 * 4];
	BYTE * m_lpData;


	void* m_Extra;		//��������
	DWORD m_dwSize;
	DWORD m_dwMaxSize;
	DWORD m_dwGrowBy;
};
