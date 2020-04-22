// yslog.cpp : 实现文件
//

#include "stdafx.h"
#include "t8(2).h"
#include "yslog.h"
#include "afxdialogex.h"


// yslog 对话框

IMPLEMENT_DYNAMIC(yslog, CDialogEx)

yslog::yslog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, r(0)
	, g(0)
	, b(0)
{

}

yslog::~yslog()
{
}

void yslog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r);
	DDX_Text(pDX, IDC_EDIT2, g);
	DDX_Text(pDX, IDC_EDIT3, b);
}


BEGIN_MESSAGE_MAP(yslog, CDialogEx)
END_MESSAGE_MAP()


// yslog 消息处理程序
