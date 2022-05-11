#include "PancakeEngineOpenGLRender.h"

PancakeEngineOpenGLRender::PancakeEngineOpenGLRender()
{
}

PancakeEngineOpenGLRender::~PancakeEngineOpenGLRender()
{
}

void PancakeEngineOpenGLRender::BeforeRender()
{
}

void PancakeEngineOpenGLRender::Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

	// 多重采样
	//glEnable(GL_MULTISAMPLE_ARB);
	glEnable(GL_MULTISAMPLE);

}

void PancakeEngineOpenGLRender::AfterRender()
{
}
