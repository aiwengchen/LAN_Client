
// ClientDlg.h : ͷ�ļ�
//

#pragma once


// CClientDlg �Ի���
class CClientDlg : public CDialogEx
{
// ����
public:
	CClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

	SOCKET  m_Socket;		//�ͻ����׽���
	CString m_ServerIP;		//������IP
	int     m_X, m_Y;		//ץȡ��Ļ����ʼ����
	WORD    m_RecvX, m_RecvY;//�յ�������������ץȡ��Ļ����ʼ����
	BOOL	m_Confirm;		//ȷ����Ϣ
	int     m_FrameIndex;	//��¼����
	int     mod;			//��¼����
	int     count;			//ÿһ��λͼ�ֱ�������
	int     bmpsize;		//λͼ��ʵ�ʴ�С
	char*	pSendBuf;		//���ͻ�����ָ��
	char*	pHeader;		//��ʱָ��
	sockaddr_in  addr1;		//�׽��ֵ�ַ
	BOOL    m_Received;		//�Ƿ���յ�������������ȷ����Ϣ
	int     m_Counter;		//������

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

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
	int SendData(UINT index, int mod, int bmpsize, int frames, char *pSendBuf, sockaddr_in &addr);
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void OnReceived();
	afx_msg void OnBnClickedCancel();
};
