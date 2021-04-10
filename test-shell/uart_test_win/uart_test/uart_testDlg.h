
// uart_testDlg.h : 头文件
//
#pragma once
#include "SerialPort.h"

// Cuart_testDlg 对话框
class Cuart_testDlg : public CDialogEx
{
// 构造
public:
	Cuart_testDlg(CWnd* pParent = NULL);	// 标准构造函数

	CSerialPort m_Port;				 //串口类
	CString    m_ReceiveData;        //接收数据字符串
	CString    m_strSendData;        //发送数据字符串

	int m_nBaud;                     //波特率
	int m_nCom;                      //串口号
	char m_cParity;                  //校验
	int m_nDatabits;                 //数据位
	int m_nStopbits;                 //停止位

	BOOL m_IsOpenCom;				 //串口是否已经打开

	char cr,lf;						//回车， 换行字符
	char ch1,ch2;					//记录字符用


	
// 对话框数据
	enum { IDD = IDD_UART_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持



// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	//*******************************************
	afx_msg LONG OnCommunication(WPARAM ch, LPARAM port);	//串口接收处理函数
	//*******************************************
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
