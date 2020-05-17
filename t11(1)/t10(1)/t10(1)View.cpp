
// t10(1)View.cpp : Ct101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t10(1).h"
#endif

#include "t10(1)Set.h"
#include "t10(1)Doc.h"
#include "t10(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct101View

IMPLEMENT_DYNCREATE(Ct101View, CRecordView)

BEGIN_MESSAGE_MAP(Ct101View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &Ct101View::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &Ct101View::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Ct101View 构造/析构

Ct101View::Ct101View()
	: CRecordView(IDD_T101_FORM)
	, id(0)
	, name(_T(""))
	, xh(_T(""))
	, nl(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	t = false;
}

Ct101View::~Ct101View()
{
}

void Ct101View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
}

BOOL Ct101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Ct101View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_t101Set;
	CRecordView::OnInitialUpdate();

}


// Ct101View 诊断

#ifdef _DEBUG
void Ct101View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Ct101View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Ct101Doc* Ct101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct101Doc)));
	return (Ct101Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct101View 数据库支持
CRecordset* Ct101View::OnGetRecordset()
{
	return m_pSet;
}



// Ct101View 消息处理程序


void Ct101View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	
	m_pSet->GetFieldValue(short(4),s);

	t = true;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	InvalidateRect(rect,NULL);
	
}


void Ct101View::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Ct101View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	if (t) {

		

		CImage img;
		img.Load(s);
	
		
		CDC *pDC= GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0,400,300);	}

}
