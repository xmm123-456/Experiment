
// t2View.h : Ct2View 类的接口
//

#pragma once


class Ct2View : public CView
{
protected: // 仅从序列化创建
	Ct2View();
	DECLARE_DYNCREATE(Ct2View)

// 特性
public:
	Ct2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ct2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // t2View.cpp 中的调试版本
inline Ct2Doc* Ct2View::GetDocument() const
   { return reinterpret_cast<Ct2Doc*>(m_pDocument); }
#endif

