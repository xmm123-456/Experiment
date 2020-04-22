
// t8(1)Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Ct81Dlg 对话框
class Ct81Dlg : public CDialogEx
{
// 构造
public:
	Ct81Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_T81_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	int a;
	int b;
	double c;
	CString x;
	afx_msg void OnBnClickedSplit1();
	CComboBox y;
	CString z;
};
