// Perspective Camera class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "ICamera.h"
#include <math.h>
#include <limits>

/**
 * @brief Perspective Camera class
 */
class CCameraPerspective : public ICamera
{
public:
    /**
     * @brief Constructor
     * @param pos Camera origin (center of projection)
     * @param dir Camera viewing direction
     * @param up Up-vector
     * @param angle (Vertical) full opening angle of the viewing frustum (in degrees)
     * @param resolution The image resolution
     */
    CCameraPerspective(Vec3f pos, Vec3f dir, Vec3f up, float angle, Size resolution)
    : ICamera(resolution)
    , m_pos(pos)
    , m_dir(dir)
    , m_up(up)
    {
        m_zAxis = - dir;
        m_yAxis = up;
        m_xAxis = m_zAxis.cross(m_yAxis);
        m_focus = tan(((angle * M_PI)/180)/2);
        m_aspect = resolution.width / resolution.height;
        
    }
    virtual ~CCameraPerspective(void) = default;
    
    virtual bool InitRay(float x, float y, Ray& r) override
    {
        if (x > resolution.width || y > resolution.height) {
            return false;
        }
        r.t = std::numeric_limits<float>::infinity();
        float Px = (2 * ((x + 0.5) / resolution.width) - 1) * m_focus * m_aspect;
        float Py = (1 - 2 * ((y + 0.5) / resolution.height) * m_focus);
        r.org = Vec3f(0, 0, 0);
        r.dir = Vec3f(Px, Py, -1);
        r.dir = normalize(r.dir);
        return true;
    }
    
    
private:
    // input values
    Vec3f m_pos;
    Vec3f m_dir;
    Vec3f m_up;
    
    // preprocessed values
    float m_focus;
    Vec3f m_xAxis;
    Vec3f m_yAxis;
    Vec3f m_zAxis;
    float m_aspect;
};

