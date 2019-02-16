// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__0AC4588A_4E35_4AF8_A612_C07E49E5953E__INCLUDED_)
#define AFX_MAINFRM_H__0AC4588A_4E35_4AF8_A612_C07E49E5953E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CCeCommandBar	m_wndCommandBar;
	CChildView    m_wndView;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnCp();
	afx_msg void OnAnimation();
	afx_msg void OnSpeedPIE();
	afx_msg void OnHide();
	afx_msg void OnCleanAdd();
	afx_msg void OnCleanRun();
	afx_msg void OnShell();
	afx_msg void OnHelp();
	afx_msg void OnStartup();
	afx_msg void OnAdvanced();
	afx_msg void OnInfos();
	afx_msg void OnPower();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__0AC4588A_4E35_4AF8_A612_C07E49E5953E__INCLUDED_)
