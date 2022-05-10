#include "PancakeEngineOpenGLRenderWindow.h"

PancakeEngineOpenGLRenderWindow::PancakeEngineOpenGLRenderWindow()
{
}

PancakeEngineOpenGLRenderWindow::~PancakeEngineOpenGLRenderWindow()
{
}

std::shared_ptr<PancakeEngineOpenGLRenderWindow> PancakeEngineOpenGLRenderWindow::GetSingleton()
{
	return Singleton<PancakeEngineOpenGLRenderWindow>::GetInstance();
}

LRESULT PancakeEngineOpenGLRenderWindow::OpenGLWndDisplayProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_CREATE:
	{
		break;
	}


	case WM_SIZE:
	{
		break;
	}

	case WM_PAINT:
	{
		HDC hDC = ::GetDC(hWnd);

		RECT rc = { 0 };

		GetClientRect(hWnd, &rc);

		//HBRUSH hbr = ::CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF)); // °×É«»­Ë¢

		//HBRUSH hbr = ::CreateSolidBrush(RGB(0x00, 0x00, 0x00)); // ºÚÉ«»­Ë¢

		HBRUSH hbr = ::CreateSolidBrush(RGB(0x00, 0xFF, 0x00)); // ÂÌÉ«»­Ë¢

		//HBRUSH hbr = (HBRUSH)::GetStockObject(NULL_BRUSH); //Í¸Ã÷»­Ë¢

		::FillRect(hDC, &rc, hbr);

		::DeleteObject(hbr);

		::ReleaseDC(hWnd, hDC);

		LOG(INFO) << "WM_PAINT";

		break;
	}

	case WM_DESTROY:
	{
		break;
	}

	case WM_LBUTTONDOWN:
	{


		break;
	}

	case WM_LBUTTONUP:
	{


		break;
	}

	case WM_MOUSEMOVE:
	{


		break;
	}

	case WM_RBUTTONDOWN:
	{


		break;
	}

	case WM_RBUTTONUP:
	{


		break;
	}

	case WM_MBUTTONDOWN:
	{

		break;
	}

	case WM_MBUTTONUP:
	{

		break;
	}

	case WM_MOUSEWHEEL:
	{

		break;
	}

	case WM_KEYDOWN:
	{

		break;
	}


	default:
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
