#pragma once


// logpx �Ի���

class logpx : public CDialogEx
{
	DECLARE_DYNAMIC(logpx)

public:
	logpx(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~logpx();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString pxtj;
};
