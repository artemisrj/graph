// MFClab5_1Doc.h : interface of the CMFClab5_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCLAB5_1DOC_H__0AB4E774_DB38_40F5_AC9E_D949B1D55C64__INCLUDED_)
#define AFX_MFCLAB5_1DOC_H__0AB4E774_DB38_40F5_AC9E_D949B1D55C64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFClab5_1Doc : public CDocument
{
protected: // create from serialization only
	CMFClab5_1Doc();
	DECLARE_DYNCREATE(CMFClab5_1Doc)

	
public:
BOOL m_startRect;   //绘制矩形框标志
CPoint m_startPoint; //矩形框开始点
CPoint m_OldPoint;   //矩形框终点（但是它是上一次的点，所以这里用了Old标识）
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFClab5_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFClab5_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFClab5_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLAB5_1DOC_H__0AB4E774_DB38_40F5_AC9E_D949B1D55C64__INCLUDED_)
