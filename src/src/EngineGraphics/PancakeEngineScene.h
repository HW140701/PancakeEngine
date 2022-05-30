#ifndef ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_
#define ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "EngineGraphics/Manager/ShaderManager.h"
#include "EngineGraphics/Manager/CameraManager.h"
#include "EngineGraphics/Base/Camera/Camera.h"


namespace PancakeEngine
{
	class PancakeEngineScene
	{
	public:
		PancakeEngineScene();
		virtual~PancakeEngineScene();

		static std::shared_ptr<PancakeEngineScene> GetSingleton();

	public:
		void BeforeRender();
		void Render();
		void AfterRender();

		void Resize(int width, int height);

		
		std::shared_ptr<CameraManager> GetCameraManager();

	private:
		void InitScene();
		void UnInitScene();


		void CreateManager();
		bool CreateCamera();

	private:
		int m_SceneWidth;
		int m_SceneHeight;

		std::shared_ptr<ShaderManager> m_pShaderManager;
		std::shared_ptr<CameraManager> m_pCameraManager;
	};
}


#endif // !ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_
