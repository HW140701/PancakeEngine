#ifndef ENGINE_GRAPHICS_BASE_CAMERA_H_
#define ENGINE_GRAPHICS_BASE_CAMERA_H_

#include "Object.h"
#include "CameraInterface.h"

namespace PancakeEngine
{
	class Camera : public Object, CameraInterface
	{
	public:
		Camera();
		virtual~ Camera();

	public:
		virtual void HandleMouseMovement(float deltaX, float deltaY) = 0;
		virtual void HandleMouseScroll(float delta) = 0;
		virtual void HandleKeyboardPress(float delta) = 0;

	protected:
		glm::vec3 m_CameraPosition;
		glm::vec3 m_CameraFrontVector;
		glm::vec3 m_CameraUpVector;
		glm::vec3 m_CameraRightVector;
		glm::vec3 m_WorldUpVector;
		float m_Yaw;
		float m_Pitch;

		float m_MouseSensitivity;
		float m_WhellSensitivity;

		glm::mat4 m_ProjectMatrix;
		glm::mat4 m_ViewMatrix;
	};
}

#endif // !ENGINE_GRAPHICS_BASE_CAMERA_H_
