// logcx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zh1.h"
#include "logcx.h"
#include "afxdialogex.h"


// logcx �Ի���

IMPLEMENT_DYNAMIC(logcx, CDialogEx)

logcx::logcx(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, cxtj(_T(""))
{

}

logcx::~logcx()
{
}

void logcx::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, cxtj);
}


BEGIN_MESSAGE_MAP(logcx, CDialogEx)
END_MESSAGE_MAP()


// logcx ��Ϣ�������
