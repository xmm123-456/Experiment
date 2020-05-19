
// t10View.h : Ct10View 类的接口
//

#pragma once


class Ct10View : public CView
{
protected: // 仅从序列化创建
	Ct10View();
	DECLARE_DYNCREATE(Ct10View)

// 特性
public:
	Ct10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ct10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // t10View.cpp 中的调试版本
inline Ct10Doc* Ct10View::GetDocument() const
   { return reinterpret_cast<Ct10Doc*>(m_pDocument); }
#endif

