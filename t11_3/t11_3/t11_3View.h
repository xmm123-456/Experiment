
// t11_3View.h : Ct11_3View ��Ľӿ�
//

#pragma once

class Ct11_3Set;

class Ct11_3View : public CRecordView
{
protected: // �������л�����
	Ct11_3View();
	DECLARE_DYNCREATE(Ct11_3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_T11_3_FORM };
#endif
	Ct11_3Set* m_pSet;

// ����
public:
	Ct11_3Doc* GetDocument() const;
	
	void tp(CString file);
// ����
public:
	CString path;
	bool t;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~Ct11_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString xm;
	CString xh;

	long nl;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // t11_3View.cpp �еĵ��԰汾
inline Ct11_3Doc* Ct11_3View::GetDocument() const
   { return reinterpret_cast<Ct11_3Doc*>(m_pDocument); }
#endif

