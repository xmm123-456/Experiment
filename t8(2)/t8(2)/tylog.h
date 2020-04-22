#pragma once


// tylog 对话框

class tylog : public CDialogEx
{
	DECLARE_DYNAMIC(tylog)

public:
	tylog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~tylog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit3();
	int zx;
	int zy;
	int yx;
	int yy;
};
