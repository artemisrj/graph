// MFClab5_1View.h : interface of the CMFClab5_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCLAB5_1VIEW_H__9023AFA5_C3C3_4636_AAEA_AD6EBB94C0AE__INCLUDED_)
#define AFX_MFCLAB5_1VIEW_H__9023AFA5_C3C3_4636_AAEA_AD6EBB94C0AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFClab5_1View : public CView
{
protected: // create from serialization only
	CMFClab5_1View();
	DECLARE_DYNCREATE(CMFClab5_1View)

// Attributes
public:
	CMFClab5_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFClab5_1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFClab5_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFClab5_1View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFClab5_1View.cpp
inline CMFClab5_1Doc* CMFClab5_1View::GetDocument()
   { return (CMFClab5_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLAB5_1VIEW_H__9023AFA5_C3C3_4636_AAEA_AD6EBB94C0AE__INCLUDED_)
