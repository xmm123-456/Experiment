#pragma once


// dlg0 �Ի���

class dlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(dlg0)

public:
	dlg0(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlg0();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif
CString s;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
