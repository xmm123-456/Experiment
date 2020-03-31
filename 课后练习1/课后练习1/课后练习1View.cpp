
// 课后练习1View.cpp : C课后练习1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "课后练习1.h"
#endif

#include "课后练习1Doc.h"
#include "课后练习1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C课后练习1View

IMPLEMENT_DYNCREATE(C课后练习1View, CView)

BEGIN_MESSAGE_MAP(C课后练习1View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C课后练习1View::OnFileOpen)
END_MESSAGE_MAP()

// C课后练习1View 构造/析构

C课后练习1View::C课后练习1View()
{
	// TODO: 在此处添加构造代码

}

C课后练习1View::~C课后练习1View()
{
}

BOOL C课后练习1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C课后练习1View 绘制

void C课后练习1View::OnDraw(CDC* pDC)
{
	C课后练习1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (pDoc->t)
	{
		CRect cr;
		GetClientRect(&cr);
		float cr_ra = 1.0*cr.Width() / cr.Height();
		float img_ra = 1.0*pDoc->img.GetWidth() / pDoc->img.GetHeight();
		if (cr_ra > img_ra)
		{
			pDoc->h = cr.Height();
			pDoc->w = img_ra*pDoc->h;
			pDoc->sx = (cr.Width() - pDoc->w) / 2;
			pDoc->sy = 0;
		}
		else
		{
			pDoc->w = cr.Width();
			pDoc->h = img_ra*pDoc->w;
			pDoc->sx = 0;
			pDoc->sy = (cr.Height() - pDoc->h) / 2;

		}
		pDoc->img.Draw(pDC->m_hDC, pDoc->sx, pDoc->sy, pDoc->w, pDoc->h);
		

	}

	// TODO: 在此处为本机数据添加绘制代码
}


// C课后练习1View 诊断

#ifdef _DEBUG
void C课后练习1View::AssertValid() const
{
	CView::AssertValid();
}

void C课后练习1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C课后练习1Doc* C课后练习1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C课后练习1Doc)));
	return (C课后练习1Doc*)m_pDocument;
}
#endif //_DEBUG


// C课后练习1View 消息处理程序


void C课后练习1View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	C课后练习1Doc* pDoc = GetDocument();
	CString finame;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CImage img;
	CClientDC dc(this);
	pDoc->t = true;
	
	if (r == IDOK)
	{	 finame = cfd.GetPathName();
		 pDoc->img.Load(finame);
	
		 CRect cr;
		 GetClientRect(&cr);
		 float cr_ra = 1.0*cr.Width() / cr.Height();
		 float img_ra = 1.0*pDoc->img.GetWidth() / pDoc->img.GetHeight();
		 if (cr_ra > img_ra)
		 {
			 pDoc->h = cr.Height();
			 pDoc->w = img_ra*pDoc->h;
			 pDoc->sx = (cr.Width() - pDoc->w) / 2;
			 pDoc->sy = 0;
		 }
		 else
		 {
			 pDoc->w = cr.Width();
			 pDoc->h = img_ra*pDoc->w;
			 pDoc->sx = 0;
			 pDoc->sy = (cr.Height() - pDoc->h) / 2;

		 }
		
	}

	


	pDoc->img.Draw(dc.m_hDC, pDoc->sx, pDoc->sy, pDoc->w, pDoc->h);






}
