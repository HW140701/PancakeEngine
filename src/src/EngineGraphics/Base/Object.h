#ifndef ENGINE_GRAPHICS_BASE_OBJECT_H_
#define ENGINE_GRAPHICS_BASE_OBJECT_H_

#include <memory>

namespace PancakeEngine
{
	class PancakeEngineScene;
	class Object
	{
	public:
		Object();
		virtual~Object();

	public:
		virtual void SetScene(std::shared_ptr<PancakeEngineScene> p_scene);

	private:
		std::weak_ptr<PancakeEngineScene> m_pScene;
	};
}

#endif // !ENGINE_GRAPHICS_BASE_OBJECT_H_
