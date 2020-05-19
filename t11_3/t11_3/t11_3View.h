
// t11_3View.h : Ct11_3View 类的接口
//

#pragma once

class Ct11_3Set;

class Ct11_3View : public CRecordView
{
protected: // 仅从序列化创建
	Ct11_3View();
	DECLARE_DYNCREATE(Ct11_3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_T11_3_FORM };
#endif
	Ct11_3Set* m_pSet;

// 特性
public:
	Ct11_3Doc* GetDocument() const;
	
	void tp(CString file);
// 操作
public:
	CString path;
	bool t;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~Ct11_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // t11_3View.cpp 中的调试版本
inline Ct11_3Doc* Ct11_3View::GetDocument() const
   { return reinterpret_cast<Ct11_3Doc*>(m_pDocument); }
#endif

