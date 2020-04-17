
// t7View.cpp : Ct7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t7.h"
#endif

#include "t7Doc.h"
#include "t7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct7View

IMPLEMENT_DYNCREATE(Ct7View, CView)

BEGIN_MESSAGE_MAP(Ct7View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Ct7View 构造/析构

Ct7View::Ct7View()
{
	// TODO: 在此处添加构造代码

}

Ct7View::~Ct7View()
{
}

BOOL Ct7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct7View 绘制

void Ct7View::OnDraw(CDC* pDC)
{
	Ct7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ct7View 诊断

#ifdef _DEBUG
void Ct7View::AssertValid() const
{
	CView::AssertValid();
}

void Ct7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct7Doc* Ct7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct7Doc)));
	return (Ct7Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct7View 消息处理程序


void Ct7View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct7Doc* pDoc = GetDocument();
	if (pDoc->t)
	{
		pDoc->cr.left = point.x - 40;
		pDoc->cr.top = point.y - 20;
		pDoc->cr.bottom = point.y + 20;
		pDoc->cr.right = point.x + 40;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void Ct7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct7Doc* pDoc = GetDocument();
	if (((pDoc->cr.left)<point.x) && (point.x< (pDoc->cr.right)) && ((pDoc->cr.top)<point.y) && (point.y< (pDoc->cr.bottom)))
	{

		pDoc->t = true;
	}
	CView::OnLButtonDown(nFlags, point);
}


void Ct7View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct7Doc* pDoc = GetDocument();
	pDoc->t = false;
	CView::OnLButtonUp(nFlags, point);
}
