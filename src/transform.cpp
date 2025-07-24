#include "transform.h"

Transform::Transform(/* args */)
{
    position_ = glm::vec3(0.0f);
    scale_ = glm::vec3(1.0f);
    rotation_ = glm::vec3(0.0f);
}

Transform::~Transform()
{
    
}

void Transform::Translate(glm::vec3 direction_)
{
    position_ = position_ + direction_;
}
