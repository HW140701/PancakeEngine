#include "MainWindow.h"

MainWindow::MainWindow()
{
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
}

void MainWindow::InitWindow()
{
}

LRESULT MainWindow::OnClose(UINT, WPARAM, LPARAM, BOOL& bHandled)
{
	return LRESULT();
}
