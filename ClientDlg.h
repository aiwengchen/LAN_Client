
// ClientDlg.h : 头文件
//

#pragma once


// CClientDlg 对话框
class CClientDlg : public CDialogEx
{
// 构造
public:
	CClientDlg(CWnd* pParent = NULL);	// 标准构造函数

	SOCKET  m_Socket;		//客户端套接字
	CString m_ServerIP;		//服务器IP
	int     m_X, m_Y;		//抓取屏幕的起始坐标
	WORD    m_RecvX, m_RecvY;//收到服务器发来的抓取屏幕的起始坐标
	BOOL	m_Confirm;		//确认信息
	int     m_FrameIndex;	//记录索引
	int     mod;			//记录余数
	int     count;			//每一个位图分报的数量
	int     bmpsize;		//位图的实际大小
	char*	pSendBuf;		//发送缓冲区指针
	char*	pHeader;		//临时指针
	sockaddr_in  addr1;		//套接字地址
	BOOL    m_Received;		//是否接收到服务器发来的确认信息
	int     m_Counter;		//记数器

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

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
	int SendData(UINT index, int mod, int bmpsize, int frames, char *pSendBuf, sockaddr_in &addr);
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void OnReceived();
	afx_msg void OnBnClickedCancel();
};
