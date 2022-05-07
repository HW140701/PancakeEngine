#include "MainWindow.h"

MainWindow::MainWindow()
{
	m_pMinBtn = nullptr;
	m_pMaxBtn = nullptr;
	m_pCloseBtn = nullptr;
	m_pRestoreBtn = nullptr;
	m_pFileBtn = nullptr;

	m_pFileMenu = nullptr;
}

MainWindow::~MainWindow()
{
	CMenuWnd::DestroyMenu();
	if (m_pFileMenu != nullptr) 
	{
		delete m_pFileMenu;
		m_pFileMenu = nullptr;
	}
}

LPCTSTR MainWindow::GetWindowClassName() const
{
	return _T("PancakeEngineMainWindow");
}

DuiLib::CDuiString MainWindow::GetSkinFile()
{
	return _T("PancakeEngineMainWindow.xml");
}

CDuiString MainWindow::GetSkinFolder()
{
	return PancakeEnginePathUtils::GetSkinDirectory().c_str();
}

void MainWindow::Notify(TNotifyUI& msg)
{
	if (_tcsicmp(msg.sType, _T("click")) == 0)
	{
		ProcessClickMessage(msg);
	}

	WindowImplBase::Notify(msg);
}

void MainWindow::InitWindow()
{
	InitControl();
}

LRESULT MainWindow::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	return LRESULT();
}

LRESULT MainWindow::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// 有时会在收到WM_NCDESTROY后收到wParam为SC_CLOSE的WM_SYSCOMMAND
	if (wParam == SC_CLOSE) {
		::PostQuitMessage(0L);
		bHandled = TRUE;
		return 0;
	}
	BOOL bZoomed = ::IsZoomed(*this);
	LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
	if (::IsZoomed(*this) != bZoomed) 
	{
		if (!bZoomed) 
		{
			if (m_pMaxBtn != nullptr)
			{
				m_pMaxBtn->SetVisible(false);
			}

			if (m_pRestoreBtn != nullptr)
			{
				m_pRestoreBtn->SetVisible(true);
			}
		}
		else {

			if (m_pMaxBtn != nullptr)
			{
				m_pMaxBtn->SetVisible(true);
			}

			if (m_pRestoreBtn != nullptr)
			{
				m_pRestoreBtn->SetVisible(false);
			}
		}
	}
	return lRes;
}

LRESULT MainWindow::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	// 关闭窗口，退出程序
	if (uMsg == WM_DESTROY)
	{
		::PostQuitMessage(0L);
		bHandled = TRUE;
		return 0;
	}
	// 菜单按钮消息
	else if (uMsg == WM_MENUCLICK)
	{
		MenuCmd* pMenuCmd = (MenuCmd*)wParam;

		if (pMenuCmd != NULL)
		{
			BOOL bChecked = pMenuCmd->bChecked;
			CDuiString sMenuName = pMenuCmd->szName;
			CDuiString sUserData = pMenuCmd->szUserData;
			CDuiString sText = pMenuCmd->szText;
			m_PaintManager.DeletePtr(pMenuCmd);

			if (sMenuName == _T("openfile"))
			{
				MessageBox(NULL, _T("aaa"), NULL, NULL);
			}
		}
		bHandled = TRUE;
		return 0;
	}

}


void MainWindow::InitControl()
{
	m_pMinBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Min_Btn_Name));
	m_pMaxBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Max_Btn_Name));
	m_pRestoreBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Restore_Btn_Name));
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Close_Btn_Name));
	m_pFileBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_File_Btn_Name));
}

void MainWindow::ProcessClickMessage(TNotifyUI& msg)
{
	if (msg.pSender == m_pMinBtn)
	{
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
	}
	else if (msg.pSender == m_pMaxBtn)
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	}
	else if (msg.pSender == m_pRestoreBtn)
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
	}
	else if (msg.pSender == m_pCloseBtn)
	{
		::SendMessage(this->GetHWND(), WM_CLOSE, NULL, NULL);
		PostQuitMessage(0);
	}
	else if (msg.pSender == m_pFileBtn)
	{
		if (m_pFileMenu != nullptr)
		{
			delete m_pFileMenu;
			m_pFileMenu = nullptr;
		}

		m_pFileMenu = new CMenuWnd();
		//CDuiPoint point;
		//::GetCursorPos(&point);
		// 获取当前被点击按钮的客户区坐标
		RECT fileBtnPosRect = m_pFileBtn->GetClientPos();

		// 将当前按钮的客户区坐标转换为屏幕坐标
		POINT fileBtnClientPoint;
		fileBtnClientPoint.x = fileBtnPosRect.left;
		fileBtnClientPoint.y = fileBtnPosRect.top + (fileBtnPosRect.bottom - fileBtnPosRect.top);
		::ClientToScreen(m_hWnd, &fileBtnClientPoint);

		// 在当前按钮的下方显示菜单
		CDuiPoint point(fileBtnClientPoint.x, fileBtnClientPoint.y);
		m_pFileMenu->Init(NULL, _T("PancakeEngineMainWindowFileMenu.xml"), point, &m_PaintManager);

		m_pFileMenu->ResizeMenu();
	}
}
