
// uart_testDlg.cpp : 实现文件
//

#include "stdafx.h"
#include <string>
#include "uart_test.h"
#include "uart_testDlg.h"
#include "afxdialogex.h"
#include "SerialPort.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuart_testDlg 对话框




Cuart_testDlg::Cuart_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cuart_testDlg::IDD, pParent)
{
	m_ReceiveData = _T("");
	m_strSendData = _T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cuart_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cuart_testDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//******************************************
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommunication)//串口接收处理函数
	//******************************************

END_MESSAGE_MAP()


// Cuart_testDlg 消息处理程序

BOOL Cuart_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//从文件中读取串口参数
//	char COM[10];				//COM Port
//	char PAR[10];				//Parity
//	char DATA[10];				//Databits
//	char STOP[10];				//Stopbits
//	char BAUD[20];				//Baudrate

	char buf[5][20];				//缓冲区

	FILE *fp;					//文件指针
	int len;					//行字符数
	//if ((fp = fopen("D:\\Project\\uart_test\\Debug\\test.txt", "r")) == NULL)
	if ((fp = fopen("config.ini", "r")) == NULL)
	{
		perror("fail to read");
		exit(1);
	}
	for(int i=0; i<5; i++)
	{
		if(fgets(buf[i], 20, fp) != NULL)
		{
			len = strlen(buf[i]);
			if(buf[i][len-1] == 13)
			{
				buf[i][len - 1] = '\0';  /*去掉换行符*/
			}
			//printf("%s %d \n", buf, len - 1);
			//AfxMessageBox(buf[i]);
		}
	}
	



	//初始化串口参数
	int m_nCom=atoi(buf[0]);                      //串口号
	int m_nBaud=atoi(buf[1]);                     //波特率
	int m_nDatabits=atoi(buf[2]);                 //数据位
	char m_cParity=buf[3][0];					  //校验
	int m_nStopbits=atoi(buf[4]);				  //停止位	

	/*
	int m_nBaud=9600;                     //波特率
	int m_nCom=4;                      //串口号
	char m_cParity='N';                  //校验
	int m_nDatabits=8;                 //数据位
	int m_nStopbits=1;					//停止位	
	*/

	cr=13;			//回车
	lf=10;			//换行

	//打开&关闭 串口

    if (m_Port.InitPort(this, m_nCom, m_nBaud ,m_cParity,m_nDatabits, m_nStopbits))
    {     //串口号，波特率，校验位，数据位，停止位为1(在此输入0，代表停止位为1)
        //打开串口成功
        m_Port.StartMonitoring();
        m_IsOpenCom = TRUE;
    }
    else
    {    
		//串口打开失败
		AfxMessageBox("串口打开失败");
    }
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cuart_testDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cuart_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


LONG Cuart_testDlg::OnCommunication(WPARAM ch, LPARAM port)
{
    //AfxMessageBox("receive ok");
    //串口接收 处理函数

    CString str;
	//int n_len;

	str.Format("%c",ch);
    m_ReceiveData+=str;

	ch2=ch;
	if(ch1==cr && ch2==lf)
	{
		AfxMessageBox(m_ReceiveData);
		if(strlen(m_ReceiveData)>2)
		{
			//m_strSendData=m_ReceiveData;
			m_strSendData="new world";
			m_strSendData+=(char) cr;
			m_strSendData+=(char) lf;
			//PurgeComm(m_Port.m_hComm, PURGE_RXABORT);
			m_Port.WriteToPort(m_strSendData);
		}
//		PurgeComm(m_Port.m_hComm, PURGE_RXABORT);
		m_ReceiveData.Empty();
		m_strSendData.Empty();
	}
	ch1=ch2;
    return 0;
}