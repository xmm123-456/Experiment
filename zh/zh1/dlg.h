#pragma once


// dlg �Ի���

class dlg : public CDialogEx
{
	DECLARE_DYNAMIC(dlg)

public:
	dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString s;
	afx_msg void OnBnClickedOk();
};
