#pragma once

#include "IPrim.h"
#include "PrimPlane.h"
#include "ray.h"

class CPrimDisc : public  CPrimPlane {
    
public:
    CPrimDisc(const Vec3f& origin, const Vec3f& normal, const float radius)
    : CPrimPlane(origin, normal), m_radius(radius)
    {}
    virtual ~CPrimDisc(void) = default;
    
    virtual bool intersect(Ray& ray) const override
    {
        float t = (getOrigin() - ray.org).dot(getNormal()) / ray.dir.dot(getNormal());
        if (t < Epsilon || t > ray.t) return false;
        if (norm(ray.org + (ray.dir * t ) - getOrigin()) > m_radius) {
            return false;
        }
        ray.t = t;
        return true;
    }
    
private:
    float m_radius;    ///< Radius of the disc
};
