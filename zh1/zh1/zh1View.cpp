
// zh1View.cpp : Czh1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "zh1.h"
#endif

#include "zh1Set.h"
#include "zh1Doc.h"
#include "zh1View.h"
#include "dlg0.h"
#include "logzj.h"
#include "logcx.h"
#include "logpx.h"
#include "logjl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Czh1View

IMPLEMENT_DYNCREATE(Czh1View, CRecordView)

BEGIN_MESSAGE_MAP(Czh1View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT5, &Czh1View::OnEnChangeEdit5)
	ON_COMMAND(ID_RECORD_FIRST, &Czh1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &Czh1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &Czh1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &Czh1View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &Czh1View::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON2, &Czh1View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Czh1View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Czh1View::OnBnClickedButton4)
	ON_COMMAND(ID_px, &Czh1View::Onpx)
	ON_COMMAND(ID_cx, &Czh1View::Oncx)
	ON_BN_CLICKED(IDC_BUTTON5, &Czh1View::OnBnClickedButton5)
	ON_COMMAND(ID_jl, &Czh1View::Onjl)
END_MESSAGE_MAP()

// Czh1View 构造/析构

Czh1View::Czh1View()
	: CRecordView(IDD_ZH1_FORM)
	, d1(_T(""))
	, d2(_T(""))
	, d3(_T(""))
	, d4(_T(""))
	, d5(_T(""))
	, d6(_T(""))
	, d7(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\Users\\Administrator\\Pictures\\Saved Pictures\\");
	b = true;
}

Czh1View::~Czh1View()
{
}

void Czh1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1,m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column7);
}

BOOL Czh1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Czh1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_zh1Set;
	CRecordView::OnInitialUpdate();

}


// Czh1View 诊断

#ifdef _DEBUG
void Czh1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Czh1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Czh1Doc* Czh1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Czh1Doc)));
	return (Czh1Doc*)m_pDocument;
}
#endif //_DEBUG


// Czh1View 数据库支持
CRecordset* Czh1View::OnGetRecordset()
{
	return m_pSet;
}



// Czh1View 消息处理程序


void Czh1View::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Czh1View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CString s;
	m_pSet->GetFieldValue(short(8),s);

	file= path + s;
	onxs(file);

	

}


void Czh1View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString s;
	m_pSet->GetFieldValue(short(8), s);

	file = path + s;
	onxs(file);

}


void Czh1View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString s;
	m_pSet->GetFieldValue(short(8), s);

	file = path + s;
	onxs(file);
b = false;

}


void Czh1View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);

	CString s;
	m_pSet->GetFieldValue(short(8), s);

	file = path + s;
	onxs(file);
	b = false;
}
void Czh1View::onxs(CString file) {

	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float c = 1.0*cr.Width() / cr.Height();
	float i = 1.0*img.GetWidth() / img.GetHeight();
	int x, y, w, h;
	if (c > i)
	{
		h = cr.Height();
		w = i*h;
		x = (cr.Width() - w) / 2;
		y = 0;

	}
	else {
		w = cr.Width();
		h = w / i;
		x = 0;
		y = (cr.Height() - h) / 2;

	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC,x, y, w, h);
	ReleaseDC(pDC);
}

void Czh1View::OnBnClickedButton1()
{
	dlg0 d;
	d.s = file;
	if (d.DoModal() == IDOK)
	{

	}

	// TODO: 在此添加控件通知处理程序代码
}


void Czh1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	if (b)
	{
		CString s;
		m_pSet->GetFieldValue(short(8), s);

		file = path + s;
		onxs(file);
	}

}


void Czh1View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	logzj dlg;
	if (dlg.DoModal() == IDOK)
	{
		CString xm, xh, xb, zy, hm, zz, lj;
		double csny;
		xm = dlg.xm;
		xh = dlg.xh;
		xb = dlg.xb;
		zy = dlg.zy;
		hm = dlg.hm;
		zz = dlg.zz;
		lj = dlg.lj;
		csny = dlg.csny;

		m_pSet->AddNew();
		m_pSet->column1 = xm;
		m_pSet->column2 = xh;
		m_pSet->column3 = zy;
		m_pSet->column4 = xb;
		m_pSet->column5 = csny;
		m_pSet->column6 = hm;
		m_pSet->column7 = zz;
		m_pSet->column8 = lj;
		m_pSet->Update();
		UpdateData(false);
	}

}


void Czh1View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	logzj dd;
	 dd.xm= m_pSet->column1;
	 dd.xh = m_pSet->column2;
	 dd.xb = m_pSet->column4;
 dd.zy = m_pSet->column3;
	 dd.hm = m_pSet->column6;
	 dd.zz = m_pSet->column7;
	 dd.lj = m_pSet->column8;
	dd.csny = m_pSet->column5;
	UpdateData(false);
	if (dd.DoModal() == IDOK)
	{
		CString xm, xh, xb, zy, hm, zz, lj;
		double csny;
		xm = dd.xm;
		xh = dd.xh;
		xb = dd.xb;
		zy = dd.zy;
		hm = dd.hm;
		zz = dd.zz;
		lj = dd.lj;
		csny = dd.csny;

		m_pSet->Edit();
		m_pSet->column1 = xm;
		m_pSet->column2 = xh;
		m_pSet->column3 = zy;
		m_pSet->column4 = xb;
		m_pSet->column5 = csny;
		m_pSet->column6 = hm;
		m_pSet->column7 = zz;
		m_pSet->column8 = lj;
		m_pSet->Update();
		UpdateData(false);
	}
}


void Czh1View::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);


}


void Czh1View::Onpx()
{
	// TODO: 在此添加命令处理程序代码
	logpx l;
	if (l.DoModal() == IDOK)
	{
		m_pSet->m_strSort = l.pxtj;
		m_pSet->Requery();
		UpdateData(false);
	}
}


void Czh1View::Oncx()
{
	// TODO: 在此添加命令处理程序代码

	logcx c;
	if (c.DoModal() == IDOK)
	{

	
		m_pSet->m_strFilter=c.cxtj;
		m_pSet->Requery();
		UpdateData(false);
	}

}


void Czh1View::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码


	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
	UpdateData(false);
}


void Czh1View::Onjl()
{
	// TODO: 在此添加命令处理程序代码

	logjl j;
	int n=m_pSet->GetODBCFieldCount();
	CString ss;m_pSet->MoveFirst();

	int d = 0;
	while(!(m_pSet->IsEOF()))
 {
		
		for (int i =1; i <n; i++)
		{
			CString str;
			m_pSet->GetFieldValue(short(i), str);
			ss = ss + _T("  ") + str;
		}


		j.s.Add( ss);
		ss = _T("");
		d = d + 1;
		m_pSet->MoveNext();
	}
	if (j.DoModal() == IDOK)
	{

	}
}
