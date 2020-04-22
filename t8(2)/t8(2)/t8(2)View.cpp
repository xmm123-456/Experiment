
// t8(2)View.cpp : Ct82View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t8(2).h"
#endif

#include "t8(2)Doc.h"
#include "t8(2)View.h"
#include "tylog.h"
#include "yslog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct82View

IMPLEMENT_DYNCREATE(Ct82View, CView)

BEGIN_MESSAGE_MAP(Ct82View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_ty, &Ct82View::Onty)
	ON_COMMAND(ID_ys, &Ct82View::Onys)
END_MESSAGE_MAP()

// Ct82View 构造/析构

Ct82View::Ct82View()
{
	// TODO: 在此处添加构造代码

}

Ct82View::~Ct82View()
{
}

BOOL Ct82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct82View 绘制

void Ct82View::OnDraw(CDC* pDC)
{
	Ct82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for(int i=0;i<pDoc->lis.GetSize();i++)
	{
		pDC->Ellipse(&pDoc->lis[i]);
	
	}	
	pDC->Ellipse(&pDoc->cr);
	if (pDoc->e)
	{


		CPen newpen(PS_DOT,1,RGB(0,0,0));
		CPen *oldpen = pDC->SelectObject(&newpen);
	

		int a = pDoc->a;
		pDC->Rectangle(pDoc->lis[a]);
	
		pDC->SelectObject(oldpen);
		newpen.DeleteObject();
		
if (pDoc->s)
	{
		CBrush fill;
		CBrush *old;
		fill.CreateSolidBrush(RGB(pDoc->ysr, pDoc->ysg, pDoc->ysb));
		old = pDC->SelectObject(&fill);
		pDC->Ellipse(&pDoc->lis[a]);
		pDC->SelectObject(old);
		fill.DeleteObject();
		pDoc->s = false;
	}
else
		pDC->Ellipse(&pDoc->lis[a]);


	}
	
	


	// TODO: 在此处为本机数据添加绘制代码
}


// Ct82View 诊断

#ifdef _DEBUG
void Ct82View::AssertValid() const
{
	CView::AssertValid();
}

void Ct82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct82Doc* Ct82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct82Doc)));
	return (Ct82Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct82View 消息处理程序


void Ct82View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct82Doc* pDoc = GetDocument();
	if((point.x>pDoc->cr.left)&& (point.x<pDoc->cr.right)&& (point.y>pDoc->cr.top)&& (point.y<pDoc->cr.bottom))
		pDoc->t=true;

		for(int i=0;i<pDoc->lis.GetSize();i++)
			if ((point.x > pDoc->lis[i].left) && (point.x < pDoc->lis[i].right) && (point.y > pDoc->lis[i].top) && (point.y < pDoc->lis[i].bottom))
			{
				pDoc->e = true;
				pDoc->a = i;
				Invalidate();
				break;
	}
	CView::OnLButtonDown(nFlags, point);
}


void Ct82View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct82Doc* pDoc = GetDocument();
	if (pDoc->t)
	{
		pDoc->cr.left = point.x - 100;
		pDoc->cr.top = point.y -50;
		pDoc->cr.right = point.x+100;
		pDoc->cr.bottom = point.y + 50;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void Ct82View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct82Doc* pDoc = GetDocument();
	pDoc->t = false;
	CView::OnLButtonUp(nFlags, point);
}


void Ct82View::Onty()
{
	Ct82Doc* pDoc = GetDocument();
	// TODO: 在此添加命令处理程序代码
	tylog dlg;
	if (dlg.DoModal() == IDOK)
	{
		CRect cr(dlg.zx,dlg.zy,dlg.yx,dlg.yy);
	
	pDoc->lis.Add(cr);
	
		Invalidate();
	}

}


void Ct82View::Onys()
{
	// TODO: 在此添加命令处理程序代码
	Ct82Doc* pDoc = GetDocument();
	yslog dlg;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->ysr = dlg.r;
		pDoc->ysg = dlg.g;
		pDoc->ysb = dlg.b;
		pDoc->s = true;
		Invalidate();
	}

}
