#if !defined(AFX_LEANADDRESS_H__02B2E8E3_5253_408F_BA63_C1EAACEA717A__INCLUDED_)
#define AFX_LEANADDRESS_H__02B2E8E3_5253_408F_BA63_C1EAACEA717A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// leanAddress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CleanAddress dialog

class CleanAddress : public CDialog
{
// Construction
public:
	CleanAddress(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CleanAddress)
	enum { IDD = IDD_CleanAddress };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CleanAddress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CleanAddress)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEANADDRESS_H__02B2E8E3_5253_408F_BA63_C1EAACEA717A__INCLUDED_)
