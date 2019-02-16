#if !defined(AFX_POWER_H__0F642496_941B_4227_A5CB_9435393106D0__INCLUDED_)
#define AFX_POWER_H__0F642496_941B_4227_A5CB_9435393106D0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Power.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Power dialog

class Power : public CDialog
{
// Construction
public:
	Power(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Power)
	enum { IDD = IDD_Power };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Power)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Power)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWER_H__0F642496_941B_4227_A5CB_9435393106D0__INCLUDED_)
