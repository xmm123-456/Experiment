
// zh1View.h : Czh1View ��Ľӿ�
//

#pragma once

class Czh1Set;

class Czh1View : public CRecordView
{
protected: // �������л�����
	Czh1View();
	DECLARE_DYNCREATE(Czh1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ZH1_FORM };
#endif
	Czh1Set* m_pSet;

// ����
public:
	Czh1Doc* GetDocument() const;

// ����
public:
	CString path,file;
	bool b;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual void onxs(CString file);
// ʵ��
public:
	virtual ~Czh1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString d1;
	CString d2;
	CString d3;
	afx_msg void OnEnChangeEdit5();
	CString d4;
	CString d5;
	CString d6;
	CString d7;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void Onpx();
	afx_msg void Oncx();
	afx_msg void OnBnClickedButton5();
	afx_msg void Onjl();
};

#ifndef _DEBUG  // zh1View.cpp �еĵ��԰汾
inline Czh1Doc* Czh1View::GetDocument() const
   { return reinterpret_cast<Czh1Doc*>(m_pDocument); }
#endif

