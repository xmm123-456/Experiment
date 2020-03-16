
// t2Doc.cpp : Ct2Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t2.h"
#endif

#include "t2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Ct2Doc

IMPLEMENT_DYNCREATE(Ct2Doc, CDocument)

BEGIN_MESSAGE_MAP(Ct2Doc, CDocument)
END_MESSAGE_MAP()


// Ct2Doc 构造/析构

Ct2Doc::Ct2Doc()
{
	// TODO: 在此添加一次性构造代码
	A = 2;
	B = 4;
	a = rand()%8+40;
	b= rand() % 8 + 40;
	c1.left = 200;
	c1.top = 200;
	c1.right = 300;
	c1.bottom = 400;
	c2.left = 400;
	c2.top = 200;
	c2.right = 500;
	c2.bottom = 400;
	c3.left = 600;
	c3.top = 200;
	c3.right = 700;
	c3.bottom = 400;
	c4.left = 800;
	c4.top = 200;
	c4.right = 1000;
	c4.bottom = 400;
	count = 0;
}

Ct2Doc::~Ct2Doc()
{
}



BOOL Ct2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// Ct2Doc 序列化

void Ct2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void Ct2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void Ct2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void Ct2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Ct2Doc 诊断

#ifdef _DEBUG
void Ct2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Ct2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Ct2Doc 命令
