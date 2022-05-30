#ifndef ENGINE_GRAPHICS_MANAGER_CAMERA_MANAGER_H_
#define ENGINE_GRAPHICS_MANAGER_CAMERA_MANAGER_H_

#include <string>

#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "EngineGraphics/Base/Camera/Camera.h"

namespace PancakeEngine
{
	class CameraManager
	{
	public:
		CameraManager();
		virtual~CameraManager();

	public:
		bool CreateMainPerspectiveCamera(const glm::vec3& camera_position);

		bool CreateMainPerspectiveCamera(
			const glm::vec3& camera_position,
			const glm::vec3 world_up,
			float camera_yaw,
			float camera_pitch,
			float fov_angle,
			float aspect,
			float near_plane,
			float far_plane
		);



		std::shared_ptr<Camera> GetMainCamera();

	private:
		std::shared_ptr<Camera> m_MainCamera;
	};

}

#endif // !ENGINE_GRAPHICS_MANAGER_CAMERA_MANAGER_H_
