// log9.cpp : 实现文件
//

#include "stdafx.h"
#include "课后练习9.h"
#include "log9.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// log9 对话框

IMPLEMENT_DYNAMIC(log9, CDialogEx)

log9::log9(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(0)
	, a(_T(""))
{

}

log9::~log9()
{
}

void log9::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
}


BEGIN_MESSAGE_MAP(log9, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &log9::OnBnClickedButton1)
END_MESSAGE_MAP()


// log9 消息处理程序


BOOL log9::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*int x, y, w, h;
	CImage img;
	img.Load(a);
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float c = cr.Width()*1.0 / cr.Height();
	float i = img.GetWidth()*1.0 / img.GetHeight();
	if (c > i)
	{
	h = cr.Height();
	w = i*h;
	x = (cr.Width() - w) / 2;
	y = 0;

	}
	else
	{
	w = cr.Width();
	h = w / i;

	y = (cr.Height() - h) / 2;
	x = 0;

	}
	
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	
	

	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());*/
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void log9::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ifstream ifs("abc.txt");
	CString ss;
	string s;
	while (ifs >> s)
	{
		ss += CString(s.c_str());
	}
	a = ss;
	UpdateData(false);
	CImage img;
	img.Load(ss);
	int x, y, w, h;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float c = cr.Width()*1.0 / cr.Height();
	float i = img.GetWidth()*1.0 / img.GetHeight();
	if (c > i)
	{
	h = cr.Height();
	w = i*h;
	x = (cr.Width() - w) / 2;
	y = 0;

	}
	else
	{
	w = cr.Width();
	h = w / i;

	y = (cr.Height() - h) / 2;
	x = 0;

	}
	CDC *pDC =GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());

}
