
// t7(4)View.h : Ct74View 类的接口
//

#pragma once


class Ct74View : public CView
{
protected: // 仅从序列化创建
	Ct74View();
	DECLARE_DYNCREATE(Ct74View)

// 特性
public:
	Ct74Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ct74View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onljie();
};

#ifndef _DEBUG  // t7(4)View.cpp 中的调试版本
inline Ct74Doc* Ct74View::GetDocument() const
   { return reinterpret_cast<Ct74Doc*>(m_pDocument); }
#endif

