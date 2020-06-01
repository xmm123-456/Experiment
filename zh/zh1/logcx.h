#pragma once


// logcx 对话框

class logcx : public CDialogEx
{
	DECLARE_DYNAMIC(logcx)

public:
	logcx(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~logcx();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString cxtj;
};
