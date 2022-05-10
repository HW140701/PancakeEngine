#include "PancakeEngineOpenGLRenderWindow.h"

PancakeEngineOpenGLRenderWindow::PancakeEngineOpenGLRenderWindow()
	:m_pPancakeEngineOpenGLRender(nullptr)
{
	m_pPancakeEngineOpenGLRender = std::make_unique<PancakeEngineOpenGLRender>();
	if (m_pPancakeEngineOpenGLRender == nullptr)
	{
		LOG(ERROR) << "PancakeEngineOpenGLRender创建失败" << std::endl;
	}
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

void PancakeEngineOpenGLRenderWindow::OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_HWND = hWnd;

	if (InitOpenGLContext(hWnd))
	{
		LOG(INFO) << "InitOpenGLContext Success!";
	}
	else
	{
		LOG(ERROR) << "InitOpenGLContext Failed!";
	}

	LOG(INFO) << "PancakeEngineOpenGLRenderWindow：WM_CREATE";
}

void PancakeEngineOpenGLRenderWindow::OnDestory(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	UnInitOpenGLContext();

	LOG(INFO) << "PancakeEngineOpenGLRenderWindow：WM_DESTROY";
}

void PancakeEngineOpenGLRenderWindow::OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// 裁剪窗口为圆角
	//HRGN hRgn;
	//RECT windowRect;
	//GetWindowRect(hWnd, &windowRect);
	//hRgn = CreateRoundRectRgn(0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, 20, 20);
	//SetWindowRgn(hWnd, hRgn, true);
	//DeleteObject(hRgn);

	// 窗口绘制颜色
	HDC hDC = ::GetDC(hWnd);
	RECT clientRect = { 0 };
	GetClientRect(hWnd, &clientRect);
	HBRUSH hbr = ::CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF)); // 白色画刷
	::FillRect(hDC, &clientRect, hbr);
	::DeleteObject(hbr);
	::ReleaseDC(hWnd, hDC);

	// 更新OpenGL
	UpdateOpenGLRender(hWnd);

	LOG(INFO) << "PancakeEngineOpenGLRenderWindow：WM_PAINT";
}

void PancakeEngineOpenGLRenderWindow::OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
}

bool PancakeEngineOpenGLRenderWindow::InitOpenGLContext(HWND hWnd)
{
	float fPixAttribs[] = { 0, 0 };
	int iPixAttribs[] = { WGL_SUPPORT_OPENGL_ARB, GL_TRUE, // Must support OGL rendering
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, // pf that can run a window 
		WGL_ACCELERATION_ARB,
		WGL_FULL_ACCELERATION_ARB, // must be HW accelerated
		WGL_COLOR_BITS_ARB, 32, // 8 bits of each R, G and B
		WGL_DEPTH_BITS_ARB, 24, // 24 bits of depth precision for window
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE, // Double buffered context
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB, // pf should be RGBA type
		WGL_STENCIL_BITS_ARB, 8,//开启模板缓冲区,模板缓冲区位数=8
		WGL_SAMPLE_BUFFERS_ARB, GL_TRUE, // MSAA on,开启多重采样
		WGL_SAMPLES_ARB, 8, // 4x MSAA ,多重采样样本数量为4
		0 }; // NULL termination


	m_HDC = GetDC(hWnd);

	PIXELFORMATDESCRIPTOR pfd = {
	sizeof(PIXELFORMATDESCRIPTOR),  /* 上述描述符大小 */
	1,                              /* 版本号 */
	PFD_SUPPORT_OPENGL |
	PFD_DRAW_TO_WINDOW |
	PFD_DOUBLEBUFFER,               /* 双重采样 */
	PFD_TYPE_RGBA,                  /* RGBA颜色格式 */
	32,                             /* 颜色深度 */
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

	// 初始化glad
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

	// 获取OpenGL相关信息
	const GLubyte* vender_name = glGetString(GL_VENDOR); //返回负责当前OpenGL实现厂商的名字
	const GLubyte* render_name = glGetString(GL_RENDERER); //返回一个渲染器标识符，通常是个硬件平台
	const GLubyte* opengl_version_name = glGetString(GL_VERSION); //返回当前OpenGL实现的版本号
	const GLubyte* glsl_version_name = glGetString(GL_SHADING_LANGUAGE_VERSION); // glsl版本
	
	LOG(INFO) << "OpenGL实现厂商的名字：" << vender_name;
	LOG(INFO) << "渲染器标识符：" << render_name;
	LOG(INFO) << "OpenGL实现的版本号：" << opengl_version_name;
	LOG(INFO) << "GLSL Version：" << glsl_version_name;

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
		if (m_pPancakeEngineOpenGLRender != nullptr)
		{
			m_pPancakeEngineOpenGLRender->BeforeRender();

			m_pPancakeEngineOpenGLRender->Render();

			m_pPancakeEngineOpenGLRender->AfterRender();
		}

		SwapBuffers(hDC);
	}

	EndPaint(hWnd, &ps);

	InvalidateRect(hWnd, NULL, FALSE);
}


