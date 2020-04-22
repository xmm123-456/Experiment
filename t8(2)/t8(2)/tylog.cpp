// tylog.cpp : 实现文件
//

#include "stdafx.h"
#include "t8(2).h"
#include "tylog.h"
#include "afxdialogex.h"


// tylog 对话框

IMPLEMENT_DYNAMIC(tylog, CDialogEx)

tylog::tylog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, zx(0)
	, zy(0)
	, yx(0)
	, yy(0)
{

}

tylog::~tylog()
{
}

void tylog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, zx);
	DDX_Text(pDX, IDC_EDIT2, zy);
	DDX_Text(pDX, IDC_EDIT3, yx);
	DDX_Text(pDX, IDC_EDIT4, yy);
}


BEGIN_MESSAGE_MAP(tylog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT4, &tylog::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT3, &tylog::OnEnChangeEdit3)
END_MESSAGE_MAP()


// tylog 消息处理程序


void tylog::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void tylog::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
