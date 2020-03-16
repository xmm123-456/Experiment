
// t2View.cpp : Ct2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t2.h"
#endif

#include "t2Doc.h"
#include "t2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct2View

IMPLEMENT_DYNCREATE(Ct2View, CView)

BEGIN_MESSAGE_MAP(Ct2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Ct2View 构造/析构

Ct2View::Ct2View()
{
	// TODO: 在此处添加构造代码

}

Ct2View::~Ct2View()
{
}

BOOL Ct2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct2View 绘制

void Ct2View::OnDraw(CDC* pDC)
{
	Ct2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->c1);
	pDC->Rectangle(pDoc->c2);
	pDC->Rectangle(pDoc->c3);
	pDC->Rectangle(pDoc->c4);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ct2View 诊断

#ifdef _DEBUG
void Ct2View::AssertValid() const
{
	CView::AssertValid();
}

void Ct2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct2Doc* Ct2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct2Doc)));
	return (Ct2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct2View 消息处理程序


void Ct2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s =_T("左键正被按下");
	CString  x= _T("A+B=");
	Ct2Doc* pDoc = GetDocument();
	int sum = pDoc->A + pDoc->B;
	CString su,nu;
	nu =_T(" ");
	su.Format(_T("%d"),sum);
	x = x + su;
	CClientDC dc(this);
	dc.TextOutW(100,100,s);
	dc.TextOutW(100, 200, x);
	int ax = pDoc->c1.left + 50;
	int ay = pDoc->c1.top + 100;
	int bx = pDoc->c2.left + 50;
	int by = pDoc->c2.top + 100;
	int cx = pDoc->c3.left + 50;
	int cy = pDoc->c3.top + 100;
	CString a,b,d;
	a.Format(_T("%d"), pDoc->a);
	b.Format(_T("%d"), pDoc->b);
	if(point.x> pDoc->c1.left&&point.x< pDoc->c1.right&&point.y > pDoc->c1.top&&point.y < pDoc->c1.bottom)
		dc.TextOutW(ax, ay, a);
		else if (point.x> pDoc->c2.left&&point.x< pDoc->c2.right&&point.y > pDoc->c2.top&&point.y < pDoc->c2.bottom)
		{
			
			pDoc->count++;

			int i = pDoc->count % 4;
			if(i==1)
			dc.TextOutW(bx, by, _T("＋"));
			if (i == 2)
				dc.TextOutW(bx, by, _T("－"));
			if (i == 3)
				dc.TextOutW(bx, by, _T("×"));
			if (i ==0)
				dc.TextOutW(bx, by, _T("÷"));

		}	else
		if (point.x> pDoc->c3.left&&point.x< pDoc->c3.right&&point.y > pDoc->c3.top&&point.y < pDoc->c3.bottom)
		dc.TextOutW(cx, cy, b);
	else{
			d = _T("显示无效");
			dc.TextOutW(700, 100, d);}
	
	

	
	
		

	CView::OnLButtonDown(nFlags, point);
}


void Ct2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s=_T("左键正在抬起");
	CClientDC dc(this);
	dc.TextOutW(100,100, s);
	CView::OnLButtonUp(nFlags, point);
}


void Ct2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct2Doc* pDoc = GetDocument();
	CClientDC dc(this);
	double s = 1.0;
	double sum;
	CString su;
	int i = pDoc->count % 4;
	if (i == 1)
	{
		sum = pDoc->a + pDoc->b;
		su.Format(_T("%.0lf"), sum);
	}
	if (i == 2)
	{sum = pDoc->a - pDoc->b;
	su.Format(_T("%.0lf"), sum);
	}
	if (i == 3)
	{sum = pDoc->a * pDoc->b;
	su.Format(_T("%.0lf"), sum);
	}
	if (i == 0)
	{
		sum = (pDoc->a *s) / pDoc->b;

		su.Format(_T("%.5lf"), sum);
	}
	int dx = pDoc->c4.left + 50;
	int dy = pDoc->c4.top + 100;
	if (point.x> pDoc->c4.left&&point.x< pDoc->c4.right)
		if (point.y> pDoc->c4.top&&point.y< pDoc->c4.bottom)
			dc.TextOutW(dx, dy, su);
	CView::OnRButtonDown(nFlags, point);
}
