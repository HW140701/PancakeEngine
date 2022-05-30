#ifndef ENGINE_GRAPHICS_BASE_PERSPECTIVE_CAMERA_H_
#define ENGINE_GRAPHICS_BASE_PERSPECTIVE_CAMERA_H_

#include "CameraInterface.h"
#include "Object.h"

namespace PancakeEngine
{
	class PerspectiveCamera : public Object,CameraInterface
	{
	public:
		PerspectiveCamera();
		PerspectiveCamera(
			const glm::vec3& camera_position,
			const glm::vec3 world_up,
			float camera_yaw,
			float camera_pitch
		);
		PerspectiveCamera(
			const glm::vec3& camera_position,
			const glm::vec3 world_up,
			float camera_yaw,
			float camera_pitch,
			float fov_angle, 
			float aspect, 
			float near_plane, 
			float far_plane
		);
		virtual~ PerspectiveCamera();

	public:
		virtual void HandleMouseMovement(float delta_x, float delta_y);
		virtual void HandleMouseScroll(float delta);
		virtual void HandleKeyboardPress(float delta);
		virtual glm::mat4 GetProjectMatrix();
		virtual glm::mat4 GetViewMatrix();

		void SetPerspective(float fov_angle, float aspect, float near_plane, float far_plane);

	private:
		void UpdateCameraVectors();

	private:
		float m_FovAngle;
		float m_Aspect;
		float m_Near;
		float m_Far;
	};
}

#endif // !ENGINE_GRAPHICS_BASE_PERSPECTIVE_CAMERA_H_
