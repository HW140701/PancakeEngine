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
		glViewport(0, 0, width, height);
		m_SceneWidth = width;
		m_SceneHeight = height;

		if (m_pCameraManager != nullptr)
		{
			if (m_pCameraManager->GetMainCamera() != nullptr && width > 0 && height > 0)
			{
				m_pCameraManager->GetMainCamera()->SetCameraViewSize(width, height);
			}
		}
	}
	std::shared_ptr<CameraManager> PancakeEngineScene::GetCameraManager()
	{
		return m_pCameraManager;
	}
	void PancakeEngineScene::InitScene()
	{
		// 创建各种管理器
		CreateManager();

		// 创建相机
		CreateCamera();
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


		if (m_pCameraManager == nullptr)
		{
			m_pCameraManager = std::make_shared<CameraManager>();
		}

	}
	bool PancakeEngineScene::CreateCamera()
	{
		if (m_pCameraManager == nullptr)
		{
			return false;
		}

		glm::vec3 camera_position = glm::vec3(0.0, 0.0, 0.0);

		m_pCameraManager->CreateMainPerspectiveCamera(camera_position);

		if (m_pCameraManager->GetMainCamera() == nullptr)
			return false;

		return true;
	}
}
