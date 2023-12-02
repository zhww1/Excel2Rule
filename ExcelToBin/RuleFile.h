#pragma once
#include "File2.h"
#include "Buffer.h"

#pragma   pack(1)  //按1字节对齐结构体

typedef  struct HANDER
{
	uint32_t    magic;
	uint32_t    size;
	uint32_t    crc;

	uint32_t   offset0;
	uint32_t   len0;
	uint32_t   offset1;
	uint32_t   len1;
	uint32_t   offset2;
	uint32_t   len2;
	uint32_t   offset3;
	uint32_t   len3;
	uint32_t   offset4;
	uint32_t   len4;
	uint32_t   offset5;
	uint32_t   len5;
	uint32_t   res;//预留
}TableHander;




#pragma   pack() //恢复默认的字节对齐方式


class RuleFile
{
public:
	RuleFile();
	~RuleFile();

	void reset();
	void write(CString path);
	void setSection(uint8_t sectionId, const uint8_t *buf, uint32_t lenght);

	
private:
	CFile2 m_file;
	TableHander m_hdr;

	CBuffer  m_buffer;

	//vector<uint8_t> m_buf;
};

