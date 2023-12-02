
// ExcelToBinDlg.h : 头文件
//

#pragma once

#include "RuleFile.h"
#include "ReadExcel.h"
/* 扩展帧还是标准帧 */
#define CAN_GAFLID_ID_EXTENDED        0x80000000UL
#define CAN_GAFLID_ID_STANDARD        0x00000000UL
/* 数据帧还是远程帧 */
#define CAN_GAFLID_DATA_FRAME         0x00000000UL
#define CAN_GAFLID_REMOTE_FRAME       0x40000000UL
/* ID */
#define CAN_GAFLID_ID(id)             (id & 0x1FFFFFFFUL)



/* Mask基本类型，判断帧类型和报文格式 */
#define CAN_GAFLIM_CARE_TYPE          0x80000000UL
#define CAN_GAFLIM_NOCARE_TYPE        0x00000000UL
#define CAN_GAFLIM_CARE_FRAME         0x40000000UL
#define CAN_GAFLIM_NOCARE_FRAME       0x00000000UL
#define CAN_GAFLIM_IDMASK(id)         CAN_GAFLID_ID(id)


/* 长度检查 */
#define CAN_GAFLP0_DLC_CHECK(len)     ((0x0FUL&len) << 28)
/* label */
#define CAN_GAFLP0_LABLE(label)       ((0x0FFFUL&label) << 16)

/* 发送接收队列的编号 */
#define CAN_GAFLP1_TXRX_FIFO_IDX(idx) ((0x01UL << idx) << 8)
/* 接收队列的编号 */
#define CAN_GAFLP1_RX_FIFO_IDX(idx)   (0x01UL << idx)



typedef struct
{
	uint32_t lword[4];
}can_cre_type;




// CExcelToBinDlg 对话框
class CExcelToBinDlg : public CDialogEx
{
// 构造
public:
	CExcelToBinDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXCELTOBIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButton1Sel();
	afx_msg void OnBnClickedButton2Gen();


private:
	CString		  m_strFilePath;				/* 所选xls 文件路径 */

	TCHAR m_szHomePath[MAX_PATH];				/* 生成路由表文件路径 */
	TCHAR szRTFileName[MAX_PATH];				/* 生成的路由表名字 */

	can_cre_type   m_RTdata;	

	ReadExcel	m_excel;

	RuleFile    m_RuleFile;


	CMFCButton	m_Button;

	// var  for bin2S19 
	uint32_t addr_offset;
	uint32_t begin_addr;
	uint32_t end_addr;
	uint32_t addr_bytes;
	uint32_t line_length;
	FILE	 *infile;  //打开二进制文件 
	char *filename;

	bool verbose;		//true 输出参数值 false 就是不用输出，确定这个参数不要是否可以？
	bool do_headers;


private :
	void ReadRuleTableData(uint8_t  sheet,CBuffer * buffer);

	CString  process(void);
	void  syntax(void);

	uint8_t   BinToS19(uint8_t argc, char * argv[]);
	uint32_t   file_size(FILE *f);
	uint8_t    char_to_uint8(char s);
	uint32_t   str_to_uint32(char  *s);

};
