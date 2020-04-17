
// t7(4)View.cpp : Ct74View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t7(4).h"
#endif

#include "t7(4)Doc.h"
#include "t7(4)View.h"
#include "log4.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct74View

IMPLEMENT_DYNCREATE(Ct74View, CView)

BEGIN_MESSAGE_MAP(Ct74View, CView)
	ON_COMMAND(ID_ljie, &Ct74View::Onljie)
END_MESSAGE_MAP()

// Ct74View 构造/析构

Ct74View::Ct74View()
{
	// TODO: 在此处添加构造代码

}

Ct74View::~Ct74View()
{
}

BOOL Ct74View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct74View 绘制

void Ct74View::OnDraw(CDC* /*pDC*/)
{
	Ct74Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ct74View 诊断

#ifdef _DEBUG
void Ct74View::AssertValid() const
{
	CView::AssertValid();
}

void Ct74View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct74Doc* Ct74View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct74Doc)));
	return (Ct74Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct74View 消息处理程序


void Ct74View::Onljie()
{
	log4 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
	// TODO: 在此添加命令处理程序代码
}
