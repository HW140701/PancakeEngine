#ifndef ENGINE_GRAPHICS_BASE_CAMERA_H_
#define ENGINE_GRAPHICS_BASE_CAMERA_H_

#include "EngineGraphics/Base/Object.h"
#include "CameraInterface.h"
#include "EngineGraphics/Base/DataStructure.h"

namespace PancakeEngine
{
	class Camera : public Object, CameraInterface
	{
	public:
		Camera();
		virtual~ Camera();

	public:
		virtual void SetCameraViewSize(int view_width, int view_height);
		virtual glm::mat4 GetProjectMatrix() = 0;
		virtual glm::mat4 GetViewMatrix() = 0;

		virtual void HandleMouseMovement(float deltaX, float deltaY) = 0;
		virtual void HandleMouseScroll(float delta) = 0;
		virtual void HandleKeyboardPress(CameraMovement direction) = 0;

	protected:
		int m_CameraViewWidth;
		int m_CameraViewHeight;
		glm::vec3 m_CameraPosition;
		glm::vec3 m_CameraFrontVector;
		glm::vec3 m_CameraUpVector;
		glm::vec3 m_CameraRightVector;
		glm::vec3 m_WorldUpVector;
		float m_Yaw;
		float m_Pitch;

		glm::mat4 m_ProjectMatrix;
		glm::mat4 m_ViewMatrix;
	};
}

#endif // !ENGINE_GRAPHICS_BASE_CAMERA_H_
