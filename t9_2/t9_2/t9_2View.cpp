
// t9_2View.cpp : Ct9_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// Ct9_2View 构造/析构

Ct9_2View::Ct9_2View()
{
	// TODO: 在此处添加构造代码

}

Ct9_2View::~Ct9_2View()
{
}

BOOL Ct9_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct9_2View 绘制

void Ct9_2View::OnDraw(CDC* pDC)
{
	Ct9_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for(int i=0;i<pDoc->list.GetSize();i++)
	pDC->Ellipse(pDoc->list[i]);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ct9_2View 诊断

#ifdef _DEBUG
void Ct9_2View::AssertValid() const
{
	CView::AssertValid();
}

void Ct9_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct9_2Doc* Ct9_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct9_2Doc)));
	return (Ct9_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct9_2View 消息处理程序


void Ct9_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct9_2Doc* pDoc = GetDocument();
	pDoc->c.left = point.x - 60;
	pDoc->c.right = point.x +60;
	pDoc->c.top = point.y - 50;
	pDoc->c.bottom = point.y + 50;
	pDoc->list.Add(pDoc->c);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
