// logjl.cpp : 实现文件
//

#include "stdafx.h"
#include "zh1.h"
#include "logjl.h"
#include "afxdialogex.h"


// logjl 对话框

IMPLEMENT_DYNAMIC(logjl, CDialogEx)

logjl::logjl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

logjl::~logjl()
{
}

void logjl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, jl);
}


BEGIN_MESSAGE_MAP(logjl, CDialogEx)
END_MESSAGE_MAP()


// logjl 消息处理程序


BOOL logjl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for(int i=0;i<s.GetSize();i++)
	jl.AddString(s[i]);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
