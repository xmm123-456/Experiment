
// t9_2View.cpp : Ct9_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "t9_2.h"
#endif

#include "t9_2Doc.h"
#include "t9_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct9_2View

IMPLEMENT_DYNCREATE(Ct9_2View, CView)

BEGIN_MESSAGE_MAP(Ct9_2View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ct9_2View ����/����

Ct9_2View::Ct9_2View()
{
	// TODO: �ڴ˴���ӹ������

}

Ct9_2View::~Ct9_2View()
{
}

BOOL Ct9_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ct9_2View ����

void Ct9_2View::OnDraw(CDC* pDC)
{
	Ct9_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for(int i=0;i<pDoc->list.GetSize();i++)
	pDC->Ellipse(pDoc->list[i]);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ct9_2View ���

#ifdef _DEBUG
void Ct9_2View::AssertValid() const
{
	CView::AssertValid();
}

void Ct9_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct9_2Doc* Ct9_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct9_2Doc)));
	return (Ct9_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct9_2View ��Ϣ�������


void Ct9_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Ct9_2Doc* pDoc = GetDocument();
	pDoc->c.left = point.x - 60;
	pDoc->c.right = point.x +60;
	pDoc->c.top = point.y - 50;
	pDoc->c.bottom = point.y + 50;
	pDoc->list.Add(pDoc->c);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
