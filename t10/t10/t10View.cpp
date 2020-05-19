
// t10View.cpp : Ct10View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "t10.h"
#endif

#include "t10Doc.h"
#include "t10View.h"
#include "w1.h"
#include "lib2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct10View

IMPLEMENT_DYNCREATE(Ct10View, CView)

BEGIN_MESSAGE_MAP(Ct10View, CView)
END_MESSAGE_MAP()

// Ct10View ����/����

Ct10View::Ct10View()
{
	// TODO: �ڴ˴���ӹ������

}

Ct10View::~Ct10View()
{
}

BOOL Ct10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ct10View ����

void Ct10View::OnDraw(CDC* pDC)
{
	Ct10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n;
	n = factorial(5);
	CString s;
	s.Format(_T("%d"),n);
	s = _T("��̬��5�Ľײ㣺") +s;
	pDC->TextOutW(200, 100, s);
	FAC fac;
	float d;

	d=fac.convert(30);
	CString f;
	f.Format(_T("%.10f"), d);
	f = _T("��̬��30��ת���ȣ�") + f;
	pDC->TextOutW(200, 200, f);
	
	
	int m;
	m = factorial2(6);
	CString ss;
	ss.Format(_T("%d"), m);
	ss = _T("��̬��6�Ľײ㣺") + ss;
	pDC->TextOutW(600, 100, ss);
	FAC2 fac2;
	float dd;

	dd = fac2.convert(40);
	CString ff;
	ff.Format(_T("%.10f"), dd);
	ff = _T("��̬��40��ת���ȣ�") + ff;
	pDC->TextOutW(600, 200, ff);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ct10View ���

#ifdef _DEBUG
void Ct10View::AssertValid() const
{
	CView::AssertValid();
}

void Ct10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct10Doc* Ct10View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct10Doc)));
	return (Ct10Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct10View ��Ϣ�������
