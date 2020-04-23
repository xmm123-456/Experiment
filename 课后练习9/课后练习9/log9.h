#pragma once


// log9 对话框

class log9 : public CDialogEx
{
	DECLARE_DYNAMIC(log9)

public:
	log9(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~log9();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	char s;
	virtual BOOL OnInitDialog();
	CString a;
	afx_msg void OnBnClickedButton1();
};
