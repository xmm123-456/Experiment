// logjl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zh1.h"
#include "logjl.h"
#include "afxdialogex.h"


// logjl �Ի���

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


// logjl ��Ϣ�������


BOOL logjl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	for(int i=0;i<s.GetSize();i++)
	jl.AddString(s[i]);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
