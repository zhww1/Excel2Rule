/** 
 * Windowsƽ̨�ñ����ʽ�໥ת����, EncodingUtil.h
 * zhww 2019.10.09
 **/
#ifndef __ENCODE_H__
#define __ENCODE_H__

//#ifdef ENCODE_EXPORTS
//#define ENCODE_API __declspec(dllexport)
//#else
//#define ENCODE_API __declspec(dllimport)
//#endif

#include <string>
//class ENCODE_API EncodeUtil
class EncodeUtil
{
public:
    //===BEGIN: ע�⣺����6������,��Ҫ���ⲿ�ͷŷ��ص��ַ���ָ�룬��������ڴ�й¶
    static wchar_t* AnsiToUnicode(const char* lpszStr);
    static char* UnicodeToAnsi(const wchar_t* lpszStr);
    static char* AnsiToUtf8(const char* lpszStr);
    static char* Utf8ToAnsi(const char* lpszStr);
    static char* UnicodeToUtf8(const wchar_t* lpszStr);
    static wchar_t* Utf8ToUnicode(const char* lpszStr);
    //===END: ע�⣺����6������,��Ҫ���ⲿ�ͷŷ��ص��ַ���ָ�룬��������ڴ�й¶

    //===BEGIN: ���º�����һ����������Ҫת����Դ�ַ���ָ�룬�ڶ��������Ǵ��ת�����Ŀ�껺����ָ�룬������������Ŀ�껺�����Ĵ�С
    static bool AnsiToUnicode(const char* lpszAnsi, wchar_t* lpszUnicode, int nLen);
    static bool UnicodeToAnsi(const wchar_t* lpszUnicode, char* lpszAnsi, int nLen);
    static bool AnsiToUtf8(const char* lpszAnsi, char* lpszUtf8, int nLen);
    static bool Utf8ToAnsi(const char* lpszUtf8, char* lpszAnsi, int nLen);
    static bool UnicodeToUtf8(const wchar_t* lpszUnicode, char* lpszUtf8, int nLen);
    static bool Utf8ToUnicode(const char* lpszUtf8, wchar_t* lpszUnicode, int nLen);
    //===END: ���º�����һ����������Ҫת����Դ�ַ���ָ�룬�ڶ��������Ǵ��ת�����Ŀ�껺����ָ�룬������������Ŀ�껺�����Ĵ�С

    static std::wstring AnsiToUnicode(const std::string& strAnsi);
    static std::string UnicodeToAnsi(const std::wstring& strUnicode);
    static std::string AnsiToUtf8(const std::string& strAnsi);
    static std::string Utf8ToAnsi(const std::string& strUtf8);
    static std::string UnicodeToUtf8(const std::wstring& strUnicode);
    static std::wstring Utf8ToUnicode(const std::string& strUtf8);

private:
    EncodeUtil() = delete;
    ~EncodeUtil() = delete;

    EncodeUtil(const EncodeUtil& rhs) = delete;
    EncodeUtil& operator=(const EncodeUtil& rhs) = delete;
};

#endif // !__ENCODE_H__