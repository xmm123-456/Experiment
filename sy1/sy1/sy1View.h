
// sy1View.h : Csy1View 类的接口
//

#pragma once


class Csy1View : public CView
{
protected: // 仅从序列化创建
	Csy1View();
	DECLARE_DYNCREATE(Csy1View)

// 特性
public:
	Csy1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Csy1View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // sy1View.cpp 中的调试版本
inline Csy1Doc* Csy1View::GetDocument() const
   { return reinterpret_cast<Csy1Doc*>(m_pDocument); }
#endif

