
// t10(1)View.h : Ct101View ��Ľӿ�
//

#pragma once

class Ct101Set;

class Ct101View : public CRecordView
{
protected: // �������л�����
	Ct101View();
	DECLARE_DYNCREATE(Ct101View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_T101_FORM };
#endif
	Ct101Set* m_pSet;

// ����
public:
	Ct101Doc* GetDocument() const;

// ����
public:
	CString  s;
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
	virtual ~Ct101View();
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
	CString name;
	CString xh;
	long nl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // t10(1)View.cpp �еĵ��԰汾
inline Ct101Doc* Ct101View::GetDocument() const
   { return reinterpret_cast<Ct101Doc*>(m_pDocument); }
#endif

