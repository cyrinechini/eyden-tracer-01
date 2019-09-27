// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"
#include <math.h>

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
    /**
     * @brief Constructor
     * @param a Position of the first vertex
     * @param b Position of the second vertex
     * @param c Position of the third vertex
     */
    CPrimTriangle(Vec3f a, Vec3f b, Vec3f c)
    : CPrim()
    , m_a(a)
    , m_b(b)
    , m_c(c)
    {}
    virtual ~CPrimTriangle(void) = default;
    
    virtual bool Intersect(Ray& ray) override
    {
        Vec3f plane_normal = normalize((m_b - m_a).cross((m_c - m_a))) ;
        
        float intersect_pt = plane_normal.dot(m_a - ray.org) / ray.dir.dot(m_normal);
        if ((((m_b - m_a).cross((intersect_pt - a))).dot(plane_normal)) < 0 ||
            (((m_c - m_b).cross((intersect_pt - b))).dot(plane_normal)) < 0 ||
            (((m_a - m_c).cross((intersect_pt - c))).dot(plane_normal)) < 0) {
            return false; // else the triangle and ray do intersect
        }
        if (intersect_pt < Epsilon || intersect_pt >= ray.t) {
            return false;
        }
        else {
            ray.t = intersect_pt;
            return true;
            
        }
        
        
    private:
        Vec3f m_a;    ///< Position of the first vertex
        Vec3f m_b;    ///< Position of the second vertex
        Vec3f m_c;    ///< Position of the third vertex
    };
