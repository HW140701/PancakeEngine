#ifndef ENGINE_GRAPHICS_BASE_CAMERA_INTERFACE_H_
#define ENGINE_GRAPHICS_BASE_CAMERA_INTERFACE_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"

namespace PancakeEngine
{
	class CameraInterface
	{
	public:
		virtual glm::mat4 GetProjectMatrix() = 0;
		virtual glm::mat4 GetViewMatrix() = 0;
	};
}


#endif // !ENGINE_GRAPHICS_BASE_CAMERA_INTERFACE_H_
