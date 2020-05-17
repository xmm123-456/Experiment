
// t10(1)View.h : Ct101View 类的接口
//

#pragma once

class Ct101Set;

class Ct101View : public CRecordView
{
protected: // 仅从序列化创建
	Ct101View();
	DECLARE_DYNCREATE(Ct101View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_T101_FORM };
#endif
	Ct101Set* m_pSet;

// 特性
public:
	Ct101Doc* GetDocument() const;

// 操作
public:
	CString  s;
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
	virtual ~Ct101View();
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
	CString name;
	CString xh;
	long nl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // t10(1)View.cpp 中的调试版本
inline Ct101Doc* Ct101View::GetDocument() const
   { return reinterpret_cast<Ct101Doc*>(m_pDocument); }
#endif

