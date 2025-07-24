#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

//#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>

class Transform
{
private:
    /* data */
public:
    Transform(/* args */);
    ~Transform();

    void Translate(glm::vec3 direction_);

    glm::vec3 position_;
    glm::vec3 scale_;
    glm::vec3 rotation_;

};


#endif