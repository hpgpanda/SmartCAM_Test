
// uart_testDlg.h : ͷ�ļ�
//
#pragma once
#include "SerialPort.h"

// Cuart_testDlg �Ի���
class Cuart_testDlg : public CDialogEx
{
// ����
public:
	Cuart_testDlg(CWnd* pParent = NULL);	// ��׼���캯��

	CSerialPort m_Port;				 //������
	CString    m_ReceiveData;        //���������ַ���
	CString    m_strSendData;        //���������ַ���

	int m_nBaud;                     //������
	int m_nCom;                      //���ں�
	char m_cParity;                  //У��
	int m_nDatabits;                 //����λ
	int m_nStopbits;                 //ֹͣλ

	BOOL m_IsOpenCom;				 //�����Ƿ��Ѿ���

	char cr,lf;						//�س��� �����ַ�
	char ch1,ch2;					//��¼�ַ���


	
// �Ի�������
	enum { IDD = IDD_UART_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��



// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	//*******************************************
	afx_msg LONG OnCommunication(WPARAM ch, LPARAM port);	//���ڽ��մ�����
	//*******************************************
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
