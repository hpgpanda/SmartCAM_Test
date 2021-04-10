
// uart_testDlg.cpp : ʵ���ļ�
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


// Cuart_testDlg �Ի���




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
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommunication)//���ڽ��մ�����
	//******************************************

END_MESSAGE_MAP()


// Cuart_testDlg ��Ϣ�������

BOOL Cuart_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//���ļ��ж�ȡ���ڲ���
//	char COM[10];				//COM Port
//	char PAR[10];				//Parity
//	char DATA[10];				//Databits
//	char STOP[10];				//Stopbits
//	char BAUD[20];				//Baudrate

	char buf[5][20];				//������

	FILE *fp;					//�ļ�ָ��
	int len;					//���ַ���
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
				buf[i][len - 1] = '\0';  /*ȥ�����з�*/
			}
			//printf("%s %d \n", buf, len - 1);
			//AfxMessageBox(buf[i]);
		}
	}
	



	//��ʼ�����ڲ���
	int m_nCom=atoi(buf[0]);                      //���ں�
	int m_nBaud=atoi(buf[1]);                     //������
	int m_nDatabits=atoi(buf[2]);                 //����λ
	char m_cParity=buf[3][0];					  //У��
	int m_nStopbits=atoi(buf[4]);				  //ֹͣλ	

	/*
	int m_nBaud=9600;                     //������
	int m_nCom=4;                      //���ں�
	char m_cParity='N';                  //У��
	int m_nDatabits=8;                 //����λ
	int m_nStopbits=1;					//ֹͣλ	
	*/

	cr=13;			//�س�
	lf=10;			//����

	//��&�ر� ����

    if (m_Port.InitPort(this, m_nCom, m_nBaud ,m_cParity,m_nDatabits, m_nStopbits))
    {     //���ںţ������ʣ�У��λ������λ��ֹͣλΪ1(�ڴ�����0������ֹͣλΪ1)
        //�򿪴��ڳɹ�
        m_Port.StartMonitoring();
        m_IsOpenCom = TRUE;
    }
    else
    {    
		//���ڴ�ʧ��
		AfxMessageBox("���ڴ�ʧ��");
    }
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cuart_testDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cuart_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


LONG Cuart_testDlg::OnCommunication(WPARAM ch, LPARAM port)
{
    //AfxMessageBox("receive ok");
    //���ڽ��� ������

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