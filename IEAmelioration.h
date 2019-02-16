#if !defined(AFX_IEAMELIORATION_H__5F0392F6_4C61_48C8_8992_5D0DDCEDA81C__INCLUDED_)
#define AFX_IEAMELIORATION_H__5F0392F6_4C61_48C8_8992_5D0DDCEDA81C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IEAmelioration.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// IEAmelioration dialog

class IEAmelioration : public CDialog
{
// Construction
public:
	IEAmelioration(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(IEAmelioration)
	enum { IDD = IDD_IEAmelioration };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(IEAmelioration)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(IEAmelioration)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IEAMELIORATION_H__5F0392F6_4C61_48C8_8992_5D0DDCEDA81C__INCLUDED_)
