// logzj.cpp : 实现文件
//

#include "stdafx.h"
#include "zh1.h"
#include "logzj.h"
#include "afxdialogex.h"


// logzj 对话框

IMPLEMENT_DYNAMIC(logzj, CDialogEx)

logzj::logzj(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, xm(_T(""))
	, xh(_T(""))
	, zy(_T(""))
	, xb(_T(""))
	
	, hm(_T(""))
	, csny(0)
	, zz(_T(""))
	, lj(_T(""))
{

}

logzj::~logzj()
{
}

void logzj::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, xm);
	DDX_Text(pDX, IDC_EDIT2, xh);
	DDX_Text(pDX, IDC_EDIT3, zy);
	DDX_Text(pDX, IDC_EDIT4, xb);
	
	DDX_Text(pDX, IDC_EDIT6, hm);
	DDX_Text(pDX, IDC_EDIT9, csny);
	DDX_Text(pDX, IDC_EDIT7, zz);
	DDX_Text(pDX, IDC_EDIT8, lj);
}


BEGIN_MESSAGE_MAP(logzj, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT8, &logzj::OnEnChangeEdit8)
END_MESSAGE_MAP()


// logzj 消息处理程序


void logzj::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
