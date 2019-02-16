#if !defined(AFX_SPEEDIE_H__21F055BC_3161_4D30_B7A8_0822D42FC871__INCLUDED_)
#define AFX_SPEEDIE_H__21F055BC_3161_4D30_B7A8_0822D42FC871__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SpeedIE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SpeedIE dialog

class SpeedIE : public CDialog
{
// Construction
public:
	SpeedIE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SpeedIE)
	enum { IDD = IDD_SpeedPIE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SpeedIE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SpeedIE)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEEDIE_H__21F055BC_3161_4D30_B7A8_0822D42FC871__INCLUDED_)
