#pragma once
#include "afxwin.h"


// logjl 对话框

class logjl : public CDialogEx
{
	DECLARE_DYNAMIC(logjl)

public:
	logjl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~logjl();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox jl;
	CStringArray s;
	virtual BOOL OnInitDialog();
};
