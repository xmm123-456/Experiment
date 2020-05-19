
// t11_3View.cpp : Ct11_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// Ct11_3View ����/����

Ct11_3View::Ct11_3View()
	: CRecordView(IDD_T11_3_FORM)
	, id(0)
	, xm(_T(""))
	, xh(_T(""))
	, nl(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T(" ");
	t = true;
}

Ct11_3View::~Ct11_3View()
{
}

void Ct11_3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column3);

}

BOOL Ct11_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Ct11_3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_t11_3Set;
	CRecordView::OnInitialUpdate();

}


// Ct11_3View ���

#ifdef _DEBUG
void Ct11_3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Ct11_3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Ct11_3Doc* Ct11_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct11_3Doc)));
	return (Ct11_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct11_3View ���ݿ�֧��
CRecordset* Ct11_3View::OnGetRecordset()
{
	return m_pSet;
}



// Ct11_3View ��Ϣ�������


void Ct11_3View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	
 m_pSet->GetFieldValue(short(4),path);
 tp(path);

}


void Ct11_3View::OnRecordPrev()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	if (t) {
m_pSet->GetFieldValue(short(4), path);
	tp(path);
	}

	

}
