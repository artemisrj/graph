// MFClab5_1.h : main header file for the MFCLAB5_1 application
//

#if !defined(AFX_MFCLAB5_1_H__70330191_1E87_48A9_AEEA_3FA66EFA473C__INCLUDED_)
#define AFX_MFCLAB5_1_H__70330191_1E87_48A9_AEEA_3FA66EFA473C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1App:
// See MFClab5_1.cpp for the implementation of this class
//

class CMFClab5_1App : public CWinApp
{
public:
	CMFClab5_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFClab5_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFClab5_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLAB5_1_H__70330191_1E87_48A9_AEEA_3FA66EFA473C__INCLUDED_)
