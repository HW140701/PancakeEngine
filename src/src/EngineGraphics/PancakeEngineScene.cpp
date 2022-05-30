#include "PancakeEngineScene.h"

namespace PancakeEngine
{
	PancakeEngineScene::PancakeEngineScene()
	{
		InitScene();
	}

	PancakeEngineScene::~PancakeEngineScene()
	{
		UnInitScene();
	}

	std::shared_ptr<PancakeEngineScene> PancakeEngineScene::GetSingleton()
	{
		return Singleton<PancakeEngineScene>::GetInstance();
	}

	void PancakeEngineScene::BeforeRender()
	{
	}

	void PancakeEngineScene::Render()
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// 多重采样
		glEnable(GL_MULTISAMPLE);

	}

	void PancakeEngineScene::AfterRender()
	{
	}
	void PancakeEngineScene::Resize(int width, int height)
	{
	}
	void PancakeEngineScene::InitScene()
	{
		CreateManager();
	}
	void PancakeEngineScene::UnInitScene()
	{
	}
	void PancakeEngineScene::CreateManager()
	{
		if (m_pShaderManager == nullptr)
		{
			m_pShaderManager = std::make_shared<ShaderManager>();
		}


	}
}
