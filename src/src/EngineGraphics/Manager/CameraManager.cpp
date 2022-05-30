#include "CameraManager.h"

#include "EngineGraphics/Base/Camera/PerspectiveCamera.h"

namespace PancakeEngine
{
    CameraManager::CameraManager()
    {
    }
    CameraManager::~CameraManager()
    {
    }
    bool CameraManager::CreateMainPerspectiveCamera(const glm::vec3& camera_position)
    {
        if (m_MainCamera != nullptr)
        {
            m_MainCamera.reset();
            m_MainCamera = nullptr;
        }

        m_MainCamera = std::make_shared<PerspectiveCamera>(camera_position);

        if (m_MainCamera == nullptr)
            return false;

        return true;
    }
    bool CameraManager::CreateMainPerspectiveCamera(
        const glm::vec3& camera_position, 
        const glm::vec3 world_up, 
        float camera_yaw, 
        float camera_pitch, 
        float fov_angle, 
        float aspect, 
        float near_plane, 
        float far_plane
    )
    {
        if (m_MainCamera != nullptr)
        {
            m_MainCamera.reset();
            m_MainCamera = nullptr;
        }

        m_MainCamera = std::make_shared<PerspectiveCamera>(
            camera_position,
            world_up,
            camera_yaw,
            camera_pitch,
            fov_angle,
            aspect,
            near_plane,
            far_plane
        );

        if (m_MainCamera == nullptr)
            return false;

        return true;
    }
    std::shared_ptr<Camera> CameraManager::GetMainCamera()
    {
        return m_MainCamera;
    }
}