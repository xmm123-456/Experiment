
// t11_3View.cpp : Ct11_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t11_3.h"
#endif

#include "t11_3Set.h"
#include "t11_3Doc.h"
#include "t11_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct11_3View

IMPLEMENT_DYNCREATE(Ct11_3View, CRecordView)

BEGIN_MESSAGE_MAP(Ct11_3View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &Ct11_3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &Ct11_3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &Ct11_3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &Ct11_3View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Ct11_3View 构造/析构

Ct11_3View::Ct11_3View()
	: CRecordView(IDD_T11_3_FORM)
	, id(0)
	, xm(_T(""))
	, xh(_T(""))
	, nl(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T(" ");
	t = true;
}

Ct11_3View::~Ct11_3View()
{
}

void Ct11_3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column3);

}

BOOL Ct11_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Ct11_3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_t11_3Set;
	CRecordView::OnInitialUpdate();

}


// Ct11_3View 诊断

#ifdef _DEBUG
void Ct11_3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Ct11_3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Ct11_3Doc* Ct11_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct11_3Doc)));
	return (Ct11_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct11_3View 数据库支持
CRecordset* Ct11_3View::OnGetRecordset()
{
	return m_pSet;
}



// Ct11_3View 消息处理程序


void Ct11_3View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	
 m_pSet->GetFieldValue(short(4),path);
 tp(path);

}


void Ct11_3View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	UpdateData(false);
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	m_pSet->GetFieldValue(short(4), path);
	tp(path);

}


void Ct11_3View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	UpdateData(false);
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	m_pSet->GetFieldValue(short(4), path);
	tp(path);
t = false;
}


void Ct11_3View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	m_pSet->GetFieldValue(short(4), path);
	tp(path);
	t = false;
}
void Ct11_3View::tp(CString file) {
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int x, y, w, h;
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float r = 1.0*cr.Width() / cr.Height();
	float i = 1.0*img.GetWidth() / img.GetHeight();
	if (r > i)
	{
		h = cr.Height();
		w = i*h;
		x = (cr.Width() - w) / 2;
		y = 0;

	}
	else
	{
		w = cr.Width();
		h = w / i;
		x = 0;
		y =( cr.Height() - h) / 2;

	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, x, y, w, h);
}

void Ct11_3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	if (t) {
m_pSet->GetFieldValue(short(4), path);
	tp(path);
	}

	

}
