// log4.cpp : 实现文件
//

#include "stdafx.h"
#include "t7(4).h"
#include "log4.h"
#include "afxdialogex.h"


// log4 对话框

IMPLEMENT_DYNAMIC(log4, CDialogEx)

log4::log4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, z(_T(""))
	, x(0)
	, c(_T(""))
{

}

log4::~log4()
{
}

void log4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, z);
	DDX_Text(pDX, IDC_EDIT2, x);
	DDX_Text(pDX, IDC_EDIT3, c);
}


BEGIN_MESSAGE_MAP(log4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &log4::OnBnClickedButton1)
END_MESSAGE_MAP()


// log4 消息处理程序


void log4::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString s;
	s.Format(_T("%d"),x);
	c = z + s;
	UpdateData(false);
}
