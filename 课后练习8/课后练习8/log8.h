#pragma once
#include "afxwin.h"


// log8 对话框

class log8 : public CDialogEx
{
	DECLARE_DYNAMIC(log8)

public:
	log8(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~log8();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString a;
	CListBox b;
	virtual BOOL OnInitDialog();
};
