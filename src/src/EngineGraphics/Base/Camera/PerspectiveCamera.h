#ifndef ENGINE_GRAPHICS_BASE_PERSPECTIVE_CAMERA_H_
#define ENGINE_GRAPHICS_BASE_PERSPECTIVE_CAMERA_H_

#include "Camera.h"
#include "EngineGraphics/Base/Object.h"

namespace PancakeEngine
{
	class PerspectiveCamera : public Camera
	{
	public:
		PerspectiveCamera();

		PerspectiveCamera(const glm::vec3& camera_position);

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
		virtual void SetCameraViewSize(int view_width, int view_height);
		virtual glm::mat4 GetProjectMatrix();
		virtual glm::mat4 GetViewMatrix();

		virtual void HandleMouseMovement(float delta_x, float delta_y);
		virtual void HandleMouseScroll(float delta);
		virtual void HandleKeyboardPress(CameraMovement direction);

		void SetPerspective(float fov_angle, float aspect, float near_plane, float far_plane);

	private:
		void UpdateCamera();

	private:
		float m_FovAngle;
		float m_Aspect;
		float m_Near;
		float m_Far;

		float m_MouseSensitivity;
		float m_MovementSpeed;
		float m_CameraZoom;
	};
}

#endif // !ENGINE_GRAPHICS_BASE_PERSPECTIVE_CAMERA_H_
