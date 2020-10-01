#pragma once

#include "ICamera.h"
#include "ray.h"

class CCameraOrthographic : public ICamera {
    
public:
    CCameraOrthographic(Size resolution, const Vec3f& pos, const Vec3f& dir, const Vec3f& up)
    : ICamera(resolution), m_pos(pos) {
        m_dir = dir;
        m_up = m_dir.cross(up);
        m_horizontal = m_up.cross(m_dir);
        
        m_dir = normalize(m_dir);
        m_up = normalize(m_up);
        m_horizontal = normalize(m_horizontal);
        
        
    }

    
    virtual ~CCameraOrthographic(void) = default;
    
    virtual void InitRay(Ray& ray, int x, int y) override {
        float ndcx = x / getResolution().width;
        float ndcy = y / getResolution().height;
        
        ray.org = normalize(m_pos +
                            (ndcx * m_horizontal) +
                            (ndcy * m_up)
                            );
       
        ray.dir = - m_dir;
        ray.t = std::numeric_limits<float>::infinity();
        
    }
    
private:
    // input values
    Vec3f m_pos;            ///< Camera origin (center of projection)
    Vec3f m_dir;            ///< Camera viewing direction
    Vec3f m_up;                ///< Camera up-vector
    Vec3f m_horizontal;
};
