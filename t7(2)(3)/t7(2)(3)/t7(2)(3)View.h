
// t7(2)(3)View.h : Ct723View 类的接口
//

#pragma once


class Ct723View : public CView
{
protected: // 仅从序列化创建
	Ct723View();
	DECLARE_DYNCREATE(Ct723View)

// 特性
public:
	Ct723Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ct723View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpend();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // t7(2)(3)View.cpp 中的调试版本
inline Ct723Doc* Ct723View::GetDocument() const
   { return reinterpret_cast<Ct723Doc*>(m_pDocument); }
#endif

