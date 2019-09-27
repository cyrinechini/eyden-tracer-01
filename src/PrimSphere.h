// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim
{
public:
    /**
     * @brief Constructor
     * @param center Position of the center of the sphere
     * @param radius Radius of the sphere
     */
    CPrimSphere(Vec3f center, float radius)
    : CPrim()
    , m_center(center)
    , m_radius(radius)
    {}
    virtual ~CPrimSphere(void) = default;
    
    virtual bool Intersect(Ray &ray) override
    {
        float x = (m_radius * m_radius) - (ray.org.dot(ray.org)) - (m_center.dot(m_center));
        float y = (ray.dir.dot(ray.dir)) - (2 * ray.org * (ray.dir - m_center));
        float intersect_pt = x / y;
        if (intersect_pt < Epsilon || intersect_pt >= ray.t) {
            return false;
        }
        else {
            ray.t = intersect_pt;
            return true;
        }
    }
    
    
private:
    Vec3f m_center;    ///< Position of the center of the sphere
    float m_radius;    ///< Radius of the sphere
};

