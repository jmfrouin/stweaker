#if !defined(AFX_LEANRUN_H__47D6B52A_E4F6_45BE_8BDB_E54CFE0DBA6F__INCLUDED_)
#define AFX_LEANRUN_H__47D6B52A_E4F6_45BE_8BDB_E54CFE0DBA6F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// leanRun.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CleanRun dialog

class CleanRun : public CDialog
{
// Construction
public:
	CleanRun(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CleanRun)
	enum { IDD = IDD_CleanRun };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CleanRun)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CleanRun)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEANRUN_H__47D6B52A_E4F6_45BE_8BDB_E54CFE0DBA6F__INCLUDED_)
