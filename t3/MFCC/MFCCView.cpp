
// MFCCView.cpp : CMFCCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCC.h"
#endif

#include "MFCCDoc.h"
#include "MFCCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCView

IMPLEMENT_DYNCREATE(CMFCCView, CView)

BEGIN_MESSAGE_MAP(CMFCCView, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCCView 构造/析构

CMFCCView::CMFCCView()
{
	// TODO: 在此处添加构造代码

}

CMFCCView::~CMFCCView()
{
}

BOOL CMFCCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCCView 绘制

void CMFCCView::OnDraw(CDC* pDC)
{
	CMFCCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (pDoc->b)
	{
		SetTimer(1,100,NULL);
		pDoc->b = false;
	}
	pDC->Ellipse(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCCView 诊断

#ifdef _DEBUG
void CMFCCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCCDoc* CMFCCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCCDoc)));
	return (CMFCCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCCView 消息处理程序


void CMFCCView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCCDoc* pDoc = GetDocument();
	CRect c;
	GetClientRect(&c);
	if(pDoc->cr.bottom<(c.bottom-c.top)&&pDoc->t)
	{ 
	pDoc->cr.top += 5;
	pDoc->cr.bottom += 5;}
	else pDoc->t = false;
		if (pDoc->cr.top>0&& !pDoc->t) {
		pDoc->cr.top -= 5;
		pDoc->cr.bottom -= 5;
	}
		else pDoc->t = true;

	Invalidate();
	CView::OnTimer(nIDEvent);
}
