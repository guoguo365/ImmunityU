
// ImmunityUDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ImmunityU.h"
#include "ImmunityUDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define AUTORUN "autorun.inf"
#define IMMUNITY "\\Immunity...\\"



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CImmunityUDlg dialog



CImmunityUDlg::CImmunityUDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IMMUNITYU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImmunityUDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DRIVER, m_ComboDriver);
}

BEGIN_MESSAGE_MAP(CImmunityUDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_DRIVER, &CImmunityUDlg::OnCbnSelchangeComboDriver)
	ON_BN_CLICKED(IDOK, &CImmunityUDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CImmunityUDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CImmunityUDlg message handlers

BOOL CImmunityUDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitComboDriver();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// ��ʼ�������б�
void CImmunityUDlg::InitComboDriver() {
	char szDriverString[MAXBYTE] = { 0 };
	char* pTmp = NULL;

	// ���������б������
	SetDlgItemText(IDC_COMBO_DRIVER, _T("��ѡ�������ߵ��̷�..."));

	// ��ȡ�ַ������͵��������б�
	GetLogicalDriveStrings(MAXBYTE, szDriverString);

	pTmp = szDriverString;

	while (*pTmp) {
		m_ComboDriver.AddString(pTmp);

		// ÿ���̷�ռ��4���ֽڣ����Լ���4�����л�����һ���̷�
		pTmp += 4;
	}
}

void CImmunityUDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImmunityUDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CImmunityUDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CImmunityUDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}

void CImmunityUDlg::OnCbnSelchangeComboDriver()
{
	// TODO: Add your control notification handler code here
}


void CImmunityUDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	char szPath[MAX_PATH] = { 0 };

	// ��ȡ�����б���ֵ
	GetDlgItemText(IDC_COMBO_DRIVER, szPath, MAX_PATH);
	
	char szText[MAX_PATH] = { 0 };
	strcat_s(szText, szPath);

	// ����autorun.inf�ļ���
	strcat_s(szPath, AUTORUN);
	bool bRet = CreateDirectory(szPath, NULL);

	// �̷��޷�ɾ��
	if (!bRet) {

		// ��MFC���Ƽ�ʹ��AfxMessageBox
		AfxMessageBox("�����޷�����");
		return;
	}

	// �����޷�ɾ�����ļ������������ļ���
	strcat_s(szPath, IMMUNITY);
	bRet = CreateDirectory(szPath, NULL);
	if (!bRet) {
		AfxMessageBox("�����޷�����");
	}

	AfxMessageBox("���߳ɹ���");
	CDialogEx::OnOK();
}


void CImmunityUDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	char szPath[MAX_PATH] = { 0 };

	// ɾ���ļ���Immunity... ·��Ϊx:\autorun.inf\Immunity...
	GetDlgItemText(IDC_COMBO_DRIVER, szPath, MAX_PATH);
	
	strcat_s(szPath, AUTORUN);
	strcat_s(szPath, IMMUNITY);

	// ɾ��Ŀ¼ 
	RemoveDirectory(szPath);

	// ��ձ�����·����Ϣ������
	ZeroMemory(szPath, MAX_PATH);

	// Ŀ¼��Ҫһ��һ��ɾ��
	GetDlgItemText(IDC_COMBO_DRIVER, szPath, MAX_PATH);
	strcat_s(szPath, AUTORUN);
	RemoveDirectory(szPath);

	CDialogEx::OnCancel();
}
