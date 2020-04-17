// log8.cpp : 实现文件
//

#include "stdafx.h"
#include "课后练习8.h"
#include "log8.h"
#include "afxdialogex.h"


// log8 对话框

IMPLEMENT_DYNAMIC(log8, CDialogEx)

log8::log8(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(_T(""))
{

}

log8::~log8()
{
}

void log8::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Control(pDX, IDC_LIST1, b);
}


BEGIN_MESSAGE_MAP(log8, CDialogEx)
END_MESSAGE_MAP()


// log8 消息处理程序


BOOL log8::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	b.AddString(a);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
