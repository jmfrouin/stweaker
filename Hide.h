#if !defined(AFX_HIDE_H__F9CD8F41_BD5F_4853_B3FD_1A0F2E1F5362__INCLUDED_)
#define AFX_HIDE_H__F9CD8F41_BD5F_4853_B3FD_1A0F2E1F5362__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Hide.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Hide dialog

class Hide : public CDialog
{
// Construction
public:
	Hide(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Hide)
	enum { IDD = IDD_Hide };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Hide)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Hide)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDE_H__F9CD8F41_BD5F_4853_B3FD_1A0F2E1F5362__INCLUDED_)
