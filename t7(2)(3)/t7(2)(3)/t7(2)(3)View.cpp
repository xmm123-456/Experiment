
// t7(2)(3)View.cpp : Ct723View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t7(2)(3).h"
#endif

#include "t7(2)(3)Doc.h"
#include "t7(2)(3)View.h"
#include "log3.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct723View

IMPLEMENT_DYNCREATE(Ct723View, CView)

BEGIN_MESSAGE_MAP(Ct723View, CView)
	ON_COMMAND(ID_OpenD, &Ct723View::OnOpend)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Ct723View 构造/析构

Ct723View::Ct723View()
{
	// TODO: 在此处添加构造代码

}

Ct723View::~Ct723View()
{
}

BOOL Ct723View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct723View 绘制

void Ct723View::OnDraw(CDC* pDC)
{
	Ct723Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->o)
	{
	CRect c;
	GetClientRect(&c);
	pDoc->cr.top = (c.bottom - c.top) / 2 - 40;
	pDoc->cr.bottom = (c.bottom - c.top) / 2 +40;
	pDC->Ellipse(pDoc->cr); }
	else
		pDC->Ellipse(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ct723View 诊断

#ifdef _DEBUG
void Ct723View::AssertValid() const
{
	CView::AssertValid();
}

void Ct723View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct723Doc* Ct723View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct723Doc)));
	return (Ct723Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct723View 消息处理程序


void Ct723View::OnOpend()
{
	log3 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
	// TODO: 在此添加命令处理程序代码
}


void Ct723View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct723Doc* pDoc = GetDocument();
	pDoc->t = false;
	CView::OnLButtonDblClk(nFlags, point);
}


void Ct723View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct723Doc* pDoc = GetDocument();
	SetTimer(1,100,NULL);
	pDoc->t = true;
	CView::OnLButtonDown(nFlags, point);
}





void Ct723View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct723Doc* pDoc = GetDocument();
	CRect r;
	GetClientRect(&r);
	if (pDoc->t)
	{
		if ((pDoc->cr.right + 10) <= r.right&&pDoc->h)
		{
			pDoc->cr.left += 10;
			pDoc->cr.right += 10;
		}
		else if ((pDoc->cr.right + 10) > r.right)
			pDoc->h = false;
		   
			
		if (!pDoc->h && (pDoc->cr.left - 10) >= 0)
		{
			pDoc->cr.left -= 10;
			pDoc->cr.right -= 10;
		}
		else if ((pDoc->cr.left - 10) < 0)
			pDoc->h = true;
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}
