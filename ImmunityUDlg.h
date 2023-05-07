
// ImmunityUDlg.h : header file


#pragma once


// CImmunityUDlg dialog
class CImmunityUDlg : public CDialogEx
{
// Construction
public:
	CImmunityUDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMMUNITYU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	void InitComboDriver();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeComboDriver();
	CComboBox m_ComboDriver;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
