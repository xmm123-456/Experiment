
// 课后作业View.cpp : C课后作业View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "课后作业.h"
#endif

#include "课后作业Doc.h"
#include "课后作业View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C课后作业View

IMPLEMENT_DYNCREATE(C课后作业View, CView)

BEGIN_MESSAGE_MAP(C课后作业View, CView)
	ON_COMMAND(ID_yuan, &C课后作业View::Onyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C课后作业View 构造/析构

C课后作业View::C课后作业View()
{
	// TODO: 在此处添加构造代码

}

C课后作业View::~C课后作业View()
{
}

BOOL C课后作业View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C课后作业View 绘制

void C课后作业View::OnDraw(CDC* pDC)
{
	C课后作业Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect c;
	GetClientRect(&c);
	int x = (c.right - c.left) / 2, y = (c.bottom - c.top) / 2;
	if (!pDoc->set)
	{
		if (x > y)
		{
			if (pDoc->cr.top <= 5)
			{
				KillTimer(1);
				pDoc->set = true;
			}
			else
			{
				CPen newcp(PS_SOLID, 2, pDoc->color);
				CPen *oldcp = pDC->SelectObject(&newcp);


				pDC->Ellipse(pDoc->cr);
				pDC->SelectObject(oldcp);
			}
		}
		else
		{
			if (pDoc->cr.left <= 5)
			{
				KillTimer(1);
				pDoc->set = true;
			}
			else
			{
				CPen newcp(PS_SOLID, 2, pDoc->color);
				CPen *oldcp = pDC->SelectObject(&newcp);


				pDC->Ellipse(pDoc->cr);
				pDC->SelectObject(oldcp);
			}


		}
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C课后作业View 诊断

#ifdef _DEBUG
void C课后作业View::AssertValid() const
{
	CView::AssertValid();
}

void C课后作业View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C课后作业Doc* C课后作业View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C课后作业Doc)));
	return (C课后作业Doc*)m_pDocument;
}
#endif //_DEBUG


// C课后作业View 消息处理程序


void C课后作业View::Onyuan()
{
	C课后作业Doc* pDoc = GetDocument();
	
	if (pDoc->set) {
		SetTimer(1, 500, NULL);
		pDoc->set = false;
	}
	CRect c;
	GetClientRect(&c);
	int x = (c.right - c.left) / 2, y = (c.bottom - c.top) / 2;

	 pDoc->cr.left = x-10;
	pDoc->cr.right = x +10;
	pDoc->cr.top =y-10;
	pDoc->cr.bottom = y+10;
	
	// TODO: 在此添加命令处理程序代码
}


void C课后作业View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C课后作业Doc* pDoc = GetDocument();
	
	pDoc->r += 32;
	pDoc->g += 16;
	pDoc->b += 8;
	pDoc->color = RGB(pDoc->r, pDoc->g, pDoc->b);
	pDoc->cr.left -= 10;
	pDoc->cr.right += 10;
	pDoc->cr.top -= 10;
	pDoc->cr.bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
