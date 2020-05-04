
// t9_1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "t9_1.h"
#include "t9_1Dlg.h"
#include "afxdialogex.h"

#include <fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ct9_1Dlg 对话框



Ct9_1Dlg::Ct9_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_T9_1_DIALOG, pParent)
	, s(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ct9_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Control(pDX, IDC_LIST1, box);
}

BEGIN_MESSAGE_MAP(Ct9_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &Ct9_1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Ct9_1Dlg::OnBnClickedButton1)
	ON_WM_DRAWITEM()
	ON_LBN_SELCHANGE(IDC_LIST1, &Ct9_1Dlg::OnLbnSelchangeList1)

	
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Ct9_1Dlg 消息处理程序

BOOL Ct9_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	ifstream i("学生名单.txt");
	string st;
	
	while (i>>st)
	{
		box.AddString(CString(st.c_str()));
}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ct9_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ct9_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
	
	
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ct9_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ct9_1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void Ct9_1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	box.DeleteString(h);
	UpdateData(true);
	box.InsertString(h, s);
	


}


void Ct9_1Dlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


void Ct9_1Dlg::OnLbnSelchangeList1()
{

	UpdateData(true);
	h = box.GetCurSel();
	if (h != -1)
	{
		CString ss;
		box.GetText(h, ss);
		s = ss;
		UpdateData(false);
	}
	// TODO: 在此添加控件通知处理程序代码
}


	


void Ct9_1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	ofstream o("学生名单.txt", fstream::out);
	CString d;
	for (int i = 0; i < box.GetCount(); i++)
	{
		box.GetText(i, d);
		o << CT2A(d.GetString()) << endl;
	}
	// TODO: 在此处添加消息处理程序代码
}
