#pragma once


// logzj 对话框

class logzj : public CDialogEx
{
	DECLARE_DYNAMIC(logzj)

public:
	logzj(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~logzj();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit8();
	CString xm;
	CString xh;
	CString zy;
	CString xb;

	CString hm;
	double csny;
	CString zz;
	CString lj;
};
