// logpx.cpp : 实现文件
//

#include "stdafx.h"
#include "zh1.h"
#include "logpx.h"
#include "afxdialogex.h"


// logpx 对话框

IMPLEMENT_DYNAMIC(logpx, CDialogEx)

logpx::logpx(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, pxtj(_T(""))
{

}

logpx::~logpx()
{
}

void logpx::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, pxtj);
}


BEGIN_MESSAGE_MAP(logpx, CDialogEx)
END_MESSAGE_MAP()


// logpx 消息处理程序
