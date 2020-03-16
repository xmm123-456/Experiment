
// sy1View.cpp : Csy1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "sy1.h"
#endif

#include "sy1Doc.h"
#include "sy1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Csy1View

IMPLEMENT_DYNCREATE(Csy1View, CView)

BEGIN_MESSAGE_MAP(Csy1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Csy1View 构造/析构

Csy1View::Csy1View()
{
	// TODO: 在此处添加构造代码

}

Csy1View::~Csy1View()
{
}

BOOL Csy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Csy1View 绘制

void Csy1View::OnDraw(CDC* pDC)
{
	Csy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	CString s = _T("我是薛敏敏");
	int a = 13;

	CString A;
A.Format(_T("%d"), a);
	pDC->TextOutW(200, 300, s);
	pDC->TextOutW(200,200, A);
	
}


// Csy1View 诊断

#ifdef _DEBUG
void Csy1View::AssertValid() const
{
	CView::AssertValid();
}

void Csy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csy1Doc* Csy1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csy1Doc)));
	return (Csy1Doc*)m_pDocument;
}
#endif //_DEBUG


// Csy1View 消息处理程序


void Csy1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Csy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->count++;

	CView::OnLButtonDown(nFlags, point);
}


void Csy1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	Csy1Doc* pDoc = GetDocument();
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString z;
	z.Format(_T("%d"),pDoc->count);
	dc.TextOutW(300, 300, z);

}
