#include "Object.h"

namespace PancakeEngine
{
	Object::Object()
	{
	}
	Object::~Object()
	{
	}
	void Object::SetScene(std::shared_ptr<PancakeEngineScene> p_scene)
	{
		m_pScene = p_scene;
	}
	std::shared_ptr<PancakeEngineScene> Object::GetScene()
	{
		if (m_pScene.expired())
			return nullptr;
		
		return m_pScene.lock();
	}
}