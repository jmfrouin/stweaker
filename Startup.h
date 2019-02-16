#if !defined(AFX_STARTUP_H__CA3FB014_212C_46F1_A21E_E614F07F8364__INCLUDED_)
#define AFX_STARTUP_H__CA3FB014_212C_46F1_A21E_E614F07F8364__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Startup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Startup dialog

class Startup : public CDialog
{
// Construction
public:
	Startup(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Startup)
	enum { IDD = IDD_Startup };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Startup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Startup)
	virtual BOOL OnInitDialog();
	afx_msg void OnRemove();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTUP_H__CA3FB014_212C_46F1_A21E_E614F07F8364__INCLUDED_)
