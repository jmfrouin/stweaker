#if !defined(AFX_ANIMATION_H__5E6C6DD3_AC59_46A7_9E23_C7A096E13612__INCLUDED_)
#define AFX_ANIMATION_H__5E6C6DD3_AC59_46A7_9E23_C7A096E13612__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Animation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Animation dialog

class Animation : public CDialog
{
// Construction
public:
	Animation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Animation)
	enum { IDD = IDD_Animation };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Animation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Animation)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATION_H__5E6C6DD3_AC59_46A7_9E23_C7A096E13612__INCLUDED_)
