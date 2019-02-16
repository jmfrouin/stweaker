#if !defined(AFX_RENAME_H__60682859_98F2_4741_8FCF_ABC6FFD55C1E__INCLUDED_)
#define AFX_RENAME_H__60682859_98F2_4741_8FCF_ABC6FFD55C1E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Rename.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Rename dialog

class Rename : public CDialog
{
// Construction
public:
	Rename(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Rename)
	enum { IDD = IDD_Rename };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Rename)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Rename)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCp();
	afx_msg void OnMyHPC();
	afx_msg void OnDatabases();
	afx_msg void OnRecycle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RENAME_H__60682859_98F2_4741_8FCF_ABC6FFD55C1E__INCLUDED_)
