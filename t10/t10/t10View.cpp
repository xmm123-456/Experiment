
// t10View.cpp : Ct10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// Ct10View 构造/析构

Ct10View::Ct10View()
{
	// TODO: 在此处添加构造代码

}

Ct10View::~Ct10View()
{
}

BOOL Ct10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct10View 绘制

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
	s = _T("静态库5的阶层：") +s;
	pDC->TextOutW(200, 100, s);
	FAC fac;
	float d;

	d=fac.convert(30);
	CString f;
	f.Format(_T("%.10f"), d);
	f = _T("静态库30度转弧度：") + f;
	pDC->TextOutW(200, 200, f);
	
	
	int m;
	m = factorial2(6);
	CString ss;
	ss.Format(_T("%d"), m);
	ss = _T("动态库6的阶层：") + ss;
	pDC->TextOutW(600, 100, ss);
	FAC2 fac2;
	float dd;

	dd = fac2.convert(40);
	CString ff;
	ff.Format(_T("%.10f"), dd);
	ff = _T("动态库40度转弧度：") + ff;
	pDC->TextOutW(600, 200, ff);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ct10View 诊断

#ifdef _DEBUG
void Ct10View::AssertValid() const
{
	CView::AssertValid();
}

void Ct10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct10Doc* Ct10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct10Doc)));
	return (Ct10Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct10View 消息处理程序
