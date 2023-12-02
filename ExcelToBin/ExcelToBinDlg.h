
// ExcelToBinDlg.h : ͷ�ļ�
//

#pragma once

#include "RuleFile.h"
#include "ReadExcel.h"
/* ��չ֡���Ǳ�׼֡ */
#define CAN_GAFLID_ID_EXTENDED        0x80000000UL
#define CAN_GAFLID_ID_STANDARD        0x00000000UL
/* ����֡����Զ��֡ */
#define CAN_GAFLID_DATA_FRAME         0x00000000UL
#define CAN_GAFLID_REMOTE_FRAME       0x40000000UL
/* ID */
#define CAN_GAFLID_ID(id)             (id & 0x1FFFFFFFUL)



/* Mask�������ͣ��ж�֡���ͺͱ��ĸ�ʽ */
#define CAN_GAFLIM_CARE_TYPE          0x80000000UL
#define CAN_GAFLIM_NOCARE_TYPE        0x00000000UL
#define CAN_GAFLIM_CARE_FRAME         0x40000000UL
#define CAN_GAFLIM_NOCARE_FRAME       0x00000000UL
#define CAN_GAFLIM_IDMASK(id)         CAN_GAFLID_ID(id)


/* ���ȼ�� */
#define CAN_GAFLP0_DLC_CHECK(len)     ((0x0FUL&len) << 28)
/* label */
#define CAN_GAFLP0_LABLE(label)       ((0x0FFFUL&label) << 16)

/* ���ͽ��ն��еı�� */
#define CAN_GAFLP1_TXRX_FIFO_IDX(idx) ((0x01UL << idx) << 8)
/* ���ն��еı�� */
#define CAN_GAFLP1_RX_FIFO_IDX(idx)   (0x01UL << idx)



typedef struct
{
	uint32_t lword[4];
}can_cre_type;




// CExcelToBinDlg �Ի���
class CExcelToBinDlg : public CDialogEx
{
// ����
public:
	CExcelToBinDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXCELTOBIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButton1Sel();
	afx_msg void OnBnClickedButton2Gen();


private:
	CString		  m_strFilePath;				/* ��ѡxls �ļ�·�� */

	TCHAR m_szHomePath[MAX_PATH];				/* ����·�ɱ��ļ�·�� */
	TCHAR szRTFileName[MAX_PATH];				/* ���ɵ�·�ɱ����� */

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
	FILE	 *infile;  //�򿪶������ļ� 
	char *filename;

	bool verbose;		//true �������ֵ false ���ǲ��������ȷ�����������Ҫ�Ƿ���ԣ�
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
