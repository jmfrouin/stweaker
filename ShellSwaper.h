#if !defined(AFX_SHELLSWAPER_H__EDE2F527_66E0_4D7E_8E59_D1462F7D92DD__INCLUDED_)
#define AFX_SHELLSWAPER_H__EDE2F527_66E0_4D7E_8E59_D1462F7D92DD__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ShellSwaper.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ShellSwaper dialog

class ShellSwaper : public CDialog
{
// Construction
public:
	ShellSwaper(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ShellSwaper)
	enum { IDD = IDD_Shell };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ShellSwaper)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ShellSwaper)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHELLSWAPER_H__EDE2F527_66E0_4D7E_8E59_D1462F7D92DD__INCLUDED_)
