// dlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zh1.h"
#include "dlg0.h"
#include "afxdialogex.h"


// dlg0 �Ի���

IMPLEMENT_DYNAMIC(dlg0, CDialogEx)

dlg0::dlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

dlg0::~dlg0()
{
}

void dlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(dlg0, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// dlg0 ��Ϣ�������


void dlg0::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	CImage img;
	img.Load(s);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float c = 1.0*cr.Width() / cr.Height();
	float i = 1.0*img.GetWidth() / img.GetHeight();
	int x, y, w, h;
	if (c > i)
	{
		h = cr.Height();
		w = i*h;
		x = (cr.Width() - w) / 2;
		y = 0;

	}
	else {
		w = cr.Width();
		h = w / i;
		x = 0;
		y = (cr.Height() - h) / 2;

	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, x, y, w, h);
	ReleaseDC(pDC);
}
