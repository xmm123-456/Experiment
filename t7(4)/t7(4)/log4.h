#pragma once


// log4 对话框

class log4 : public CDialogEx
{
	DECLARE_DYNAMIC(log4)

public:
	log4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~log4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString z;
	int x;
	CString c;
	afx_msg void OnBnClickedButton1();
};
