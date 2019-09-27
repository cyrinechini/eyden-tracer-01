// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief The Plane Geaometrical Primitive class
 */
class CPrimPlane : public CPrim
{
public:
    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    CPrimPlane(Vec3f origin, Vec3f normal)
    : CPrim()
    , m_normal(normal)
    , m_origin(origin)
    {
        normalize(m_normal);
    }
    virtual ~CPrimPlane(void) = default;
    
    virtual bool Intersect(Ray& ray) override
    {
        float x = m_normal.dot(m_origin - ray.org);
        float y = ray.dir.dot(m_normal);
        float intersect_pt = x / y;
        if (intersect_pt < Epsilon || intersect_pt > ray.t) {
            return false;
        }
        else {
            ray.t = intersect_pt;
        }
        
    }
    
    
private:
    Vec3f m_normal;    ///< Point on the plane
    Vec3f m_origin;    ///< Normal to the plane
};
