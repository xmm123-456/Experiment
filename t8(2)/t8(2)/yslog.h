#pragma once


// yslog 对话框

class yslog : public CDialogEx
{
	DECLARE_DYNAMIC(yslog)

public:
	yslog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~yslog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int r;
	int g;
	int b;
};
