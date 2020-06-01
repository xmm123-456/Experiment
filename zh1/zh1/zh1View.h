
// zh1View.h : Czh1View 类的接口
//

#pragma once

class Czh1Set;

class Czh1View : public CRecordView
{
protected: // 仅从序列化创建
	Czh1View();
	DECLARE_DYNCREATE(Czh1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ZH1_FORM };
#endif
	Czh1Set* m_pSet;

// 特性
public:
	Czh1Doc* GetDocument() const;

// 操作
public:
	CString path,file;
	bool b;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual void onxs(CString file);
// 实现
public:
	virtual ~Czh1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // zh1View.cpp 中的调试版本
inline Czh1Doc* Czh1View::GetDocument() const
   { return reinterpret_cast<Czh1Doc*>(m_pDocument); }
#endif

