// STweaker 2004.h : main header file for the STWEAKER 2004 application
//

#if !defined(AFX_STWEAKER2004_H__30150BBD_F2D9_4375_A336_B565EB129E17__INCLUDED_)
#define AFX_STWEAKER2004_H__30150BBD_F2D9_4375_A336_B565EB129E17__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSTweaker2004App:
// See STweaker 2004.cpp for the implementation of this class
//

class CSTweaker2004App : public CWinApp
{
public:
	CSTweaker2004App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSTweaker2004App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSTweaker2004App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STWEAKER2004_H__30150BBD_F2D9_4375_A336_B565EB129E17__INCLUDED_)
