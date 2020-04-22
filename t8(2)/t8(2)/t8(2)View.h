
// t8(2)View.h : Ct82View 类的接口
//

#pragma once


class Ct82View : public CView
{
protected: // 仅从序列化创建
	Ct82View();
	DECLARE_DYNCREATE(Ct82View)

// 特性
public:
	Ct82Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ct82View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void Onty();
	afx_msg void Onys();
};

#ifndef _DEBUG  // t8(2)View.cpp 中的调试版本
inline Ct82Doc* Ct82View::GetDocument() const
   { return reinterpret_cast<Ct82Doc*>(m_pDocument); }
#endif

