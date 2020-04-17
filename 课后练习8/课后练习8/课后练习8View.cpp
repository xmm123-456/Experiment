
// 课后练习8View.cpp : C课后练习8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "课后练习8.h"
#endif

#include "课后练习8Doc.h"
#include "课后练习8View.h"
#include "log8.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C课后练习8View

IMPLEMENT_DYNCREATE(C课后练习8View, CView)

BEGIN_MESSAGE_MAP(C课后练习8View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_tanchu, &C课后练习8View::Ontanchu)
END_MESSAGE_MAP()

// C课后练习8View 构造/析构

C课后练习8View::C课后练习8View()
{
	// TODO: 在此处添加构造代码

}

C课后练习8View::~C课后练习8View()
{
}

BOOL C课后练习8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C课后练习8View 绘制

void C课后练习8View::OnDraw(CDC* /*pDC*/)
{
	C课后练习8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C课后练习8View 诊断

#ifdef _DEBUG
void C课后练习8View::AssertValid() const
{
	CView::AssertValid();
}

void C课后练习8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C课后练习8Doc* C课后练习8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C课后练习8Doc)));
	return (C课后练习8Doc*)m_pDocument;
}
#endif //_DEBUG


// C课后练习8View 消息处理程序


void C课后练习8View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	C课后练习8Doc* pDoc = GetDocument();
	CFileDialog cf(true);
	int t = cf.DoModal();
	if (t == IDOK)
	{
		pDoc->s = cf.GetFileName();
		GetDC()->TextOutW(200,200, pDoc->s);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void C课后练习8View::Ontanchu()
{
	// TODO: 在此添加命令处理程序代码
	C课后练习8Doc* pDoc = GetDocument();
	log8 dlg;
	dlg.a = pDoc->s;
	if (dlg.DoModal()== IDOK)
	{

	}
}
