
// 课后练习View.cpp : C课后练习View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "课后练习.h"
#endif

#include "课后练习Doc.h"
#include "课后练习View.h"
#include  "diolog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C课后练习View

IMPLEMENT_DYNCREATE(C课后练习View, CView)

BEGIN_MESSAGE_MAP(C课后练习View, CView)
	ON_COMMAND(ID_ck, &C课后练习View::Onck)
END_MESSAGE_MAP()

// C课后练习View 构造/析构

C课后练习View::C课后练习View()
{
	// TODO: 在此处添加构造代码

}

C课后练习View::~C课后练习View()
{
}

BOOL C课后练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C课后练习View 绘制

void C课后练习View::OnDraw(CDC* /*pDC*/)
{
	C课后练习Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C课后练习View 诊断

#ifdef _DEBUG
void C课后练习View::AssertValid() const
{
	CView::AssertValid();
}

void C课后练习View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C课后练习Doc* C课后练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C课后练习Doc)));
	return (C课后练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C课后练习View 消息处理程序


void C课后练习View::Onck()
{
	// TODO: 在此添加命令处理程序代码

	diolog di;
	int r = di.DoModal();

	if (r == IDOK)
	{
		GetDC()->TextOutW(200,200,_T("你已退出对话框"));
	}

}
