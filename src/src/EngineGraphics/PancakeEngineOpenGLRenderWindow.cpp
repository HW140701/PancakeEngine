#include "PancakeEngineOpenGLRenderWindow.h"
#include "EngineUI/MainWindow.h"

PancakeEngineOpenGLRenderWindow::PancakeEngineOpenGLRenderWindow()
	:m_bLeftButtonDown(false),
	m_bMouseMoving(false)
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
		OnCreate(hWnd, wParam, lParam);
		
		break;
	}


	case WM_SIZE:
	{
		OnSize(hWnd, wParam, lParam);

		break;
	}

	case WM_PAINT:
	{
		OnPaint(hWnd, wParam, lParam);

		break;
	}

	case WM_DESTROY:
	{
		OnDestory(hWnd, wParam, lParam);

		break;
	}

	case WM_LBUTTONDOWN:
	{
		OnLeftButtonDown(hWnd, wParam, lParam);

		break;
	}

	case WM_LBUTTONUP:
	{
		OnLeftButtonUp(hWnd, wParam, lParam);

		break;
	}

	case WM_MOUSEMOVE:
	{
		OnMouseMove(hWnd, wParam, lParam);

		break;
	}

	case WM_RBUTTONDOWN:
	{
		OnRightButtonDown(hWnd, wParam, lParam);

		break;
	}

	case WM_RBUTTONUP:
	{
		OnRightButtonUp(hWnd, wParam, lParam);

		break;
	}

	case WM_MBUTTONDOWN:
	{
		OnMiddleButtonDown(hWnd, wParam, lParam);

		break;
	}

	case WM_MBUTTONUP:
	{
		OnMiddleButtonUp(hWnd, wParam, lParam);

		break;
	}

	case WM_MOUSEWHEEL:
	{
		OnMouseWheel(hWnd, wParam, lParam);

		break;
	}

	case WM_KEYDOWN:
	{
		OnKeyDown(hWnd, wParam, lParam);

		break;
	}


	default:
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT PancakeEngineOpenGLRenderWindow::TempOpenGLWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void PancakeEngineOpenGLRenderWindow::OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_HWND = hWnd;

	if (InitOpenGLContext(hWnd,true))
	{
		LOG(INFO) << "InitOpenGLContext Success!";
	}
	else
	{
		LOG(ERROR) << "InitOpenGLContext Failed!";
		exit(1);
	}

	LOG(INFO) << "PancakeEngineOpenGLRenderWindow��WM_CREATE";
}

void PancakeEngineOpenGLRenderWindow::OnDestory(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	UnInitOpenGLContext();

	LOG(INFO) << "PancakeEngineOpenGLRenderWindow��WM_DESTROY";
}

void PancakeEngineOpenGLRenderWindow::OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// �ü�����ΪԲ��
	//HRGN hRgn;
	//RECT windowRect;
	//GetWindowRect(hWnd, &windowRect);
	//hRgn = CreateRoundRectRgn(0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, 20, 20);
	//SetWindowRgn(hWnd, hRgn, true);
	//DeleteObject(hRgn);

	// ���ڻ�����ɫ
	//HDC hDC = ::GetDC(hWnd);
	//RECT clientRect = { 0 };
	//GetClientRect(hWnd, &clientRect);
	//HBRUSH hbr = ::CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF)); // ��ɫ��ˢ
	//::FillRect(hDC, &clientRect, hbr);
	//::DeleteObject(hbr);
	//::ReleaseDC(hWnd, hDC);

	// ����OpenGL
	UpdateOpenGLRender(hWnd);

	LOG(INFO) << "PancakeEngineOpenGLRenderWindow��WM_PAINT";
}

void PancakeEngineOpenGLRenderWindow::OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// lParam�е�λΪ��ȣ���λΪ�߶�
	int window_width = LOWORD(lParam);
	int window_height = HIWORD(lParam);

	PancakeEngine::PancakeEngineScene::GetSingleton()->Resize(window_width,window_height);
}

void PancakeEngineOpenGLRenderWindow::OnLeftButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int mouse_x = LOWORD(lParam);
	int mouse_y = HIWORD(lParam);

	m_bLeftButtonDown = true;
}


void PancakeEngineOpenGLRenderWindow::OnLeftButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int mouse_x = LOWORD(lParam);
	int mouse_y = HIWORD(lParam);

	m_bLeftButtonDown = false;
}

void PancakeEngineOpenGLRenderWindow::OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int mouse_x = LOWORD(lParam);
	int mouse_y = HIWORD(lParam);

	m_bMouseMoving = true;

	if (m_bLeftButtonDown && m_bMouseMoving)
	{
		int x_delta = mouse_x - m_LastLeftButtonDownMouseXPos;
		int y_delta = mouse_y - m_LastLeftButtonDownMouseYPos;

		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
		{
			if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
			{
				PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleMouseMovement(x_delta, y_delta);
			}
		}
	}

	m_bMouseMoving = false;
	m_LastLeftButtonDownMouseXPos = mouse_x;
	m_LastLeftButtonDownMouseYPos = mouse_y;
}

void PancakeEngineOpenGLRenderWindow::OnRightButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int mouse_x = LOWORD(lParam);
	int mouse_y = HIWORD(lParam);

}

void PancakeEngineOpenGLRenderWindow::OnRightButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
}

void PancakeEngineOpenGLRenderWindow::OnMiddleButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
}

void PancakeEngineOpenGLRenderWindow::OnMiddleButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
}

void PancakeEngineOpenGLRenderWindow::OnMouseWheel(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//�������Ĺ���ʱ����Ϣ���� WM_MOUSEWHEEL
	//��ҪҪ������(short)HIWORD(wParam)��ֵ
	//> 0ʱ ���ֹ����������Լ�
	//< 0ʱ ���ֹ�����������Ļ

	short wheel_distance = (short)HIWORD(wParam);

	if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
	{
		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
		{
			PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleMouseScroll(wheel_distance);
		}
	}
}

void PancakeEngineOpenGLRenderWindow::OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// W��
	if (wParam == 0x57)
	{
		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
		{
			if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
			{
				PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleKeyboardPress(CameraMovement::Forward);
			}
		}
	}
	// A��
	else if (wParam == 0x41)
	{
		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
		{
			if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
			{
				PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleKeyboardPress(CameraMovement::Left);
			}
		}
	}
	// S��
	else if (wParam == 0x53)
	{
		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
		{
			if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
			{
				PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleKeyboardPress(CameraMovement::Backward);
			}
		}
	}
	// D��
	else if (wParam == 0x44)
	{
		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
		{
			if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
			{
				PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleKeyboardPress(CameraMovement::Right);
			}
		}
	}
	// Q��
	else if (wParam == 0x51)
	{
		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
		{
			if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
			{
				PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleKeyboardPress(CameraMovement::Up);
			}	
		}
	}
	// E��
	else if (wParam == 0x45)
	{
		if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager() != nullptr)
		{
			if (PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera() != nullptr)
			{
				PancakeEngine::PancakeEngineScene::GetSingleton()->GetCameraManager()->GetMainCamera()->HandleKeyboardPress(CameraMovement::Down);
			}	
		}
	}
}

bool PancakeEngineOpenGLRenderWindow::InitOpenGLContext(HWND hWnd, bool isUseMsaa)
{
	// ������MSAA
	if (!isUseMsaa)
	{
		m_HDC = GetDC(hWnd);

		PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),  /* ������������С */
		1,                              /* �汾�� */
		PFD_SUPPORT_OPENGL |
		PFD_DRAW_TO_WINDOW |
		PFD_DOUBLEBUFFER,               /* ˫�ز��� */
		PFD_TYPE_RGBA,                  /* RGBA��ɫ��ʽ */
		32,                             /* ��ɫ��� */
		0, 0, 0, 0, 0, 0,               /* color bits (ignored) */
		8,                              /* no alpha buffer */
		0,                              /* alpha bits (ignored) */
		0,                              /* no accumulation buffer */
		0, 0, 0, 0,                     /* accum bits (ignored) */
		24,                             /* depth buffer */
		8,                              /* no stencil buffer */
		0,                              /* no auxiliary buffers */
		PFD_MAIN_PLANE,                 /* main layer */
		0,                              /* reserved */
		0, 0, 0,                        /* no layer, visible, damage masks */
		};

		int pixelFormat = ChoosePixelFormat(m_HDC, &pfd);
		if (pixelFormat == 0)
		{
			MessageBox(NULL, "ChoosePixelFormat failed.", NULL, NULL);
			return false;
		}

		if (!SetPixelFormat(m_HDC, pixelFormat, &pfd))
		{
			MessageBox(NULL, "SetPixelFormat failed.", NULL, NULL);
			return false;
		}

		DescribePixelFormat(m_HDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
		if (pfd.dwFlags & PFD_NEED_PALETTE)
		{
			MessageBox(NULL, "Palette pixel format not supported..", NULL, NULL);
			return false;
		}

		m_HGLRC = wglCreateContext(m_HDC);
		if (m_HGLRC == NULL)
		{
			MessageBox(NULL, "wglCreateContext failed!", NULL, NULL);
			return false;
		}

		if (wglMakeCurrent(m_HDC, m_HGLRC) == false)
		{
			return false;
		}

		// ��ʼ��glad
		if (!gladLoadGL())
		{
			LOG(ERROR) << "Could not instantiate GLAD OpenGL 2.1 context";
			return false;
		}
		else if (GLVersion.major < 2)
		{
			LOG(ERROR) << "Your system doesn't support OpenGL >= 2!";
			return false;
		}	
	}
	// ����MSAA
	else
	{
		/*----- 1 ����һ����ʱ�Ĵ������ڵõ����������ĳ�ʼ��wgl��glad -----*/
		HWND tempWnd = CreateWindow(_T("TempOpenGLWindow"), _T("win32"), WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS, 0, 0, 0, 0, MainWindow::GetMainWindowHWND(), NULL, NULL, NULL);
		HDC tempHdc = GetDC(tempWnd);

		if (tempHdc == NULL)
			return false;

		PIXELFORMATDESCRIPTOR pfd;

		int pixelFormat = ChoosePixelFormat(tempHdc, &pfd);
		if (pixelFormat == 0)
		{
			MessageBox(WindowFromDC(tempHdc), "ChoosePixelFormat failed.", NULL, NULL);
			return false;
		}

		if (!SetPixelFormat(tempHdc, pixelFormat, &pfd))
		{
			MessageBox(WindowFromDC(tempHdc), "SetPixelFormat failed.", NULL, NULL);
			return false;
		}

		DescribePixelFormat(tempHdc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
		if (pfd.dwFlags & PFD_NEED_PALETTE)
		{
			MessageBox(NULL, "Palette pixel format not supported..", NULL, NULL);
			exit(1);
		}

		HGLRC temphRC = wglCreateContext(tempHdc);
		if (temphRC == NULL)
		{
			MessageBox(NULL, "wglCreateContext failed!", NULL, NULL);
			return false;
		}

		if (wglMakeCurrent(tempHdc, temphRC) == false)
		{
			return false;
		}

		// ��ʼ��glad WGL
		if (!gladLoadWGL(tempHdc))
		{
			LOG(ERROR) << "Could not instantiate GLAD WGL";
			return false;
		}

		// ��ʼ��glad
		if (!gladLoadGL())
		{
			LOG(ERROR) << "Could not instantiate GLAD OpenGL 2.1 context";
			return false;
		}
		else if (GLVersion.major < 2)
		{
			LOG(ERROR) << "Your system doesn't support OpenGL >= 2!";
			return false;
		}

		// glad��ʼ�����֮��������ʱ����
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(temphRC);
		DestroyWindow(tempWnd);

		/*----- 2 Ϊ��ǰʵ�ʴ������ö��ز������ظ�ʽ -----*/
		float fPixAttribs[] = { 0, 0 };
		int iPixAttribs[] = { WGL_SUPPORT_OPENGL_ARB, GL_TRUE, // Must support OGL rendering
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, // pf that can run a window 
			WGL_ACCELERATION_ARB,
			WGL_FULL_ACCELERATION_ARB, // must be HW accelerated
			WGL_COLOR_BITS_ARB, 32, // 8 bits of each R, G and B
			WGL_DEPTH_BITS_ARB, 24, // 24 bits of depth precision for window
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE, // Double buffered context
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB, // pf should be RGBA type
			WGL_STENCIL_BITS_ARB, 8,//����ģ�建����,ģ�建����λ��=8
			WGL_SAMPLE_BUFFERS_ARB, GL_TRUE, // MSAA on,�������ز���
			WGL_SAMPLES_ARB, 8, // 4x MSAA ,���ز�����������Ϊ4
			0 }; // NULL termination

		m_HDC = GetDC(hWnd);

		//gladLoadWGL(m_HDC);

		//if (!gladLoadWGL(m_HDC))
		//{
		//	LOG(ERROR) << "Could not instantiate GLAD WGL Extension";
		//	return false;
		//}

		int nPixelFormat = -1;
		int nPixCount = 0;

		// ��ѯ�ʺ϶��ز��������ظ�ʽ
		wglChoosePixelFormatARB(m_HDC, iPixAttribs, fPixAttribs, 1, &nPixelFormat, (UINT*)&nPixCount);

		//���ز���ʱ,���Ӳ����֧�־�ʹ������Ĵ���رն��ز��� 
		if (nPixelFormat == -1)
		{
			// ʹ��û��MSAA�����ظ�ʽ
			iPixAttribs[19] = 1;
			wglChoosePixelFormatARB(m_HDC, iPixAttribs, fPixAttribs, 1, &nPixelFormat, (UINT*)&nPixCount);
		}

		PIXELFORMATDESCRIPTOR pfd_MSAA = {
		sizeof(PIXELFORMATDESCRIPTOR),  /* ������������С */
		1,                              /* �汾�� */
		PFD_SUPPORT_OPENGL |
		PFD_DRAW_TO_WINDOW |
		PFD_DOUBLEBUFFER,               /* ˫�ز��� */
		PFD_TYPE_RGBA,                  /* RGBA��ɫ��ʽ */
		32,                             /* ��ɫ��� */
		0, 0, 0, 0, 0, 0,               /* color bits (ignored) */
		8,                              /* no alpha buffer */
		0,                              /* alpha bits (ignored) */
		0,                              /* no accumulation buffer */
		0, 0, 0, 0,                     /* accum bits (ignored) */
		24,                             /* depth buffer */
		8,                              /* no stencil buffer */
		0,                              /* no auxiliary buffers */
		PFD_MAIN_PLANE,                 /* main layer */
		0,                              /* reserved */
		0, 0, 0,                        /* no layer, visible, damage masks */
		};

		if (!SetPixelFormat(m_HDC, nPixelFormat, &pfd_MSAA))
		{
			MessageBox(WindowFromDC(m_HDC), "SetPixelFormat failed.", NULL, NULL);
			return false;
		}

		GLint attribs[] = { WGL_CONTEXT_MAJOR_VERSION_ARB, 4,//���汾4
		WGL_CONTEXT_MINOR_VERSION_ARB, 6,//�ΰ汾��3
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
		0 };

		m_HGLRC = wglCreateContextAttribsARB(m_HDC, 0, attribs);

		if (m_HGLRC == NULL)
		{
			MessageBox(NULL, "!!! Could not create an OpenGL 4.3 context.\n", NULL, NULL);
			attribs[1] = 1;
			attribs[3] = 3;
			m_HGLRC = wglCreateContextAttribsARB(m_HDC, 0, attribs);
			if (m_HGLRC == NULL)
			{
				MessageBox(NULL, NULL, "!!! Could not create an OpenGL 1.3 context.\n", NULL);
				return -1;
			}
		}

		if (!wglMakeCurrent(m_HDC, m_HGLRC))
			return false;

	}

	SwapBuffers(m_HDC);

	// ��ȡOpenGL�����Ϣ
	const GLubyte* vender_name = glGetString(GL_VENDOR); //���ظ���ǰOpenGLʵ�ֳ��̵�����
	const GLubyte* render_name = glGetString(GL_RENDERER); //����һ����Ⱦ����ʶ����ͨ���Ǹ�Ӳ��ƽ̨
	const GLubyte* opengl_version_name = glGetString(GL_VERSION); //���ص�ǰOpenGLʵ�ֵİ汾��
	const GLubyte* glsl_version_name = glGetString(GL_SHADING_LANGUAGE_VERSION); // glsl�汾

	LOG(INFO) << "OpenGLʵ�ֳ��̵����֣�" << vender_name;
	LOG(INFO) << "��Ⱦ����ʶ����" << render_name;
	LOG(INFO) << "OpenGLʵ�ֵİ汾�ţ�" << opengl_version_name;
	LOG(INFO) << "GLSL Version��" << glsl_version_name;

	return true;
}

void PancakeEngineOpenGLRenderWindow::UnInitOpenGLContext()
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_HGLRC);
	ReleaseDC(m_HWND, m_HDC);
}

void PancakeEngineOpenGLRenderWindow::UpdateOpenGLRender(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hDC = BeginPaint(hWnd, &ps);

	if (m_HGLRC)
	{
		PancakeEngine::PancakeEngineScene::GetSingleton()->BeforeRender();

		PancakeEngine::PancakeEngineScene::GetSingleton()->Render();

		PancakeEngine::PancakeEngineScene::GetSingleton()->AfterRender();

		SwapBuffers(hDC);
	}

	EndPaint(hWnd, &ps);

	InvalidateRect(hWnd, NULL, FALSE);
}


