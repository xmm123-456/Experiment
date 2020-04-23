
// 课后练习9View.cpp : C课后练习9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "课后练习9.h"
#endif

#include "课后练习9Doc.h"
#include "课后练习9View.h"
#include "log9.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C课后练习9View

IMPLEMENT_DYNCREATE(C课后练习9View, CView)

BEGIN_MESSAGE_MAP(C课后练习9View, CView)
	ON_COMMAND(ID_lujing, &C课后练习9View::Onlujing)
	ON_COMMAND(ID_xianshi, &C课后练习9View::Onxianshi)

END_MESSAGE_MAP()

// C课后练习9View 构造/析构

C课后练习9View::C课后练习9View()
{
	// TODO: 在此处添加构造代码

}

C课后练习9View::~C课后练习9View()
{
}

BOOL C课后练习9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C课后练习9View 绘制

void C课后练习9View::OnDraw(CDC* /*pDC*/)
{
	C课后练习9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C课后练习9View 诊断

#ifdef _DEBUG
void C课后练习9View::AssertValid() const
{
	CView::AssertValid();
}

void C课后练习9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C课后练习9Doc* C课后练习9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C课后练习9Doc)));
	return (C课后练习9Doc*)m_pDocument;
}
#endif //_DEBUG


// C课后练习9View 消息处理程序


void C课后练习9View::Onlujing()
{C课后练习9Doc* pDoc = GetDocument();
	// TODO: 在此添加命令处理程序代码
	CFileDialog cf(true);
	int r = cf.DoModal();
	if (r == IDOK)
	{
		CString s;
		s = cf.GetPathName();
		
		ofstream ofs("abc.txt");
		ofs <<CT2A(s.GetString())<< endl;
	}
}


void C课后练习9View::Onxianshi()
{
	// TODO: 在此添加命令处理程序代码
	C课后练习9Doc* pDoc = GetDocument();
	log9 dlg;
	
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}



