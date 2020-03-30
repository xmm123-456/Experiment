
// t4View.h : Ct4View 类的接口
//

#pragma once


class Ct4View : public CView
{
protected: // 仅从序列化创建
	Ct4View();
	DECLARE_DYNCREATE(Ct4View)

// 特性
public:
	Ct4Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int W, H;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ct4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onxuehao();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void Onxian();
	afx_msg void Onjvxing();
	afx_msg void Ontuoyuan();
};

#ifndef _DEBUG  // t4View.cpp 中的调试版本
inline Ct4Doc* Ct4View::GetDocument() const
   { return reinterpret_cast<Ct4Doc*>(m_pDocument); }
#endif

