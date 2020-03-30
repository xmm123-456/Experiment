
// t4View.cpp : Ct4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t4.h"
#endif

#include "t4Doc.h"
#include "t4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct4View

IMPLEMENT_DYNCREATE(Ct4View, CView)

BEGIN_MESSAGE_MAP(Ct4View, CView)
	ON_COMMAND(ID_xuehao, &Ct4View::Onxuehao)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_xian, &Ct4View::Onxian)
	ON_COMMAND(ID_jvxing, &Ct4View::Onjvxing)
	ON_COMMAND(ID_tuoyuan, &Ct4View::Ontuoyuan)
END_MESSAGE_MAP()

// Ct4View 构造/析构zIDR_TU1);

Ct4View::Ct4View()
{
	// TODO: 在此处添加构造代码


	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	W = BM.bmWidth;
	H = BM.bmHeight;
	


}

Ct4View::~Ct4View()
{
}

BOOL Ct4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct4View 绘制

void Ct4View::OnDraw(CDC* pDC)
{
	Ct4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MDC;
	MDC.CreateCompatibleDC(NULL);
	MDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,W,H,&MDC,0,0,SRCCOPY);
}


// Ct4View 诊断

#ifdef _DEBUG
void Ct4View::AssertValid() const
{
	CView::AssertValid();
}

void Ct4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct4Doc* Ct4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct4Doc)));
	return (Ct4Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct4View 消息处理程序


void Ct4View::Onxuehao()
{
	CClientDC dc(this);
	CString s = _T("201812300086");
	dc.TextOutW(800,30,s);
	// TODO: 在此添加命令处理程序代码
}


void Ct4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct4Doc* pDoc = GetDocument();
	pDoc->p = point;
	pDoc->d = true;
	
	CView::OnLButtonDown(nFlags, point);
}


void Ct4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct4Doc* pDoc = GetDocument();
	CClientDC dc(this);

	if (pDoc->d&&pDoc->m)
	{
		

		if (pDoc->x)
		{
			dc.MoveTo(500,100);
			dc.LineTo(600,300);
			pDoc->x = false;
			pDoc->d = false;
			pDoc->m = false;

		}
		else   if(pDoc->y)
		{
			dc.Ellipse(pDoc->cr);

			pDoc->y = false;
			pDoc->d = false;
			pDoc->m = false;
		}
		else if(pDoc->j)
		{
			dc.Rectangle(&pDoc->cr);
			pDoc->j = false;
			pDoc->d = false;
			pDoc->m = false;
		}
	}
	CView::OnLButtonUp(nFlags, point);
}


void Ct4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ct4Doc* pDoc = GetDocument();
	if (pDoc->d && (pDoc->p != point))
	{
		pDoc->m = true;
		
	}
	CView::OnMouseMove(nFlags, point);
}


void Ct4View::Onxian()
{
	// TODO: 在此添加命令处理程序代码
	Ct4Doc* pDoc = GetDocument();
	pDoc->x = true;
}


void Ct4View::Onjvxing()
{
	// TODO: 在此添加命令处理程序代码
	Ct4Doc* pDoc = GetDocument();
	pDoc->j = true;
}


void Ct4View::Ontuoyuan()
{
	// TODO: 在此添加命令处理程序代码
	Ct4Doc* pDoc = GetDocument();
	pDoc->y = true;
}
