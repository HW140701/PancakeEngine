#include "MainWindow.h"

MainWindow::MainWindow()
{
	m_pMinBtn = nullptr;
	m_pMaxBtn = nullptr;
	m_pCloseBtn = nullptr;
	m_pRestoreBtn = nullptr;
}

MainWindow::~MainWindow()
{
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

void MainWindow::InitControl()
{
	m_pMinBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Min_Btn_Name));
	m_pMaxBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Max_Btn_Name));
	m_pRestoreBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Restore_Btn_Name));
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(MainWindow_Close_Btn_Name));
	
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
}
