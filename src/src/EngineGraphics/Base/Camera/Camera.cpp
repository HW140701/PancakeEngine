#include "Camera.h"
#include "EngineGraphics/Base/DataStructure.h"

namespace PancakeEngine
{
	Camera::Camera()
        :m_CameraPosition(glm::vec3(0.0f)),
        m_CameraFrontVector(CameraLocalFront),
        m_CameraUpVector(CameraLocalUp),
        m_CameraRightVector(CameraLocalRight),
        m_WorldUpVector(CameraWorldUp),
        m_Yaw(CameraYaw),
        m_Pitch(CameraPitch),
        m_ProjectMatrix(glm::mat4(1.0f)),
        m_ViewMatrix(glm::mat4(1.0))
	{
	}
    Camera::~Camera()
    {
    }
    void Camera::SetCameraViewSize(int view_width, int view_height)
    {
        m_CameraViewWidth = view_width;
        m_CameraViewHeight = view_height;
    }
}