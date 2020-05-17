
// t10(1)View.cpp : Ct101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// Ct101View ����/����

Ct101View::Ct101View()
	: CRecordView(IDD_T101_FORM)
	, id(0)
	, name(_T(""))
	, xh(_T(""))
	, nl(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	t = false;
}

Ct101View::~Ct101View()
{
}

void Ct101View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
}

BOOL Ct101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Ct101View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_t101Set;
	CRecordView::OnInitialUpdate();

}


// Ct101View ���

#ifdef _DEBUG
void Ct101View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Ct101View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Ct101Doc* Ct101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct101Doc)));
	return (Ct101Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct101View ���ݿ�֧��
CRecordset* Ct101View::OnGetRecordset()
{
	return m_pSet;
}



// Ct101View ��Ϣ�������


void Ct101View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	
	m_pSet->GetFieldValue(short(4),s);

	t = true;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	InvalidateRect(rect,NULL);
	
}


void Ct101View::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Ct101View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	if (t) {

		

		CImage img;
		img.Load(s);
	
		
		CDC *pDC= GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0,400,300);	}

}
