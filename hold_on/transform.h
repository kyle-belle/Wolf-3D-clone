#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

class move
{
    public:
        move(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(),const glm::vec3& scale = glm::vec3(1.0f,1.0f,1.0f))
        :p_position(pos), p_rotation(rot), p_scale(scale){}
        ~move(){}
        inline glm::mat4 get_model()const{
            glm::mat4 position = glm::translate(p_position);
            glm::mat4 rotation_x = glm::rotate(p_rotation.x, glm::vec3(1.0f,0.0f,0.0f));
            glm::mat4 rotation_y = glm::rotate(p_rotation.y, glm::vec3(0.0f,1.0f,0.0f));
            glm::mat4 rotation_z = glm::rotate(p_rotation.z, glm::vec3(0.0f,0.0f,1.0f));
            glm::mat4 scale = glm::scale(p_scale);

            glm::mat4 rotation = rotation_x * rotation_y * rotation_z;

            return  position * rotation * scale;
        }
        inline glm::vec3& get_position(){ return p_position; }
        inline glm::vec3& get_rotation(){ return p_rotation; }
        inline glm::vec3& get_scale(){ return p_scale; }
    protected:

    private:
        glm::vec3 p_position;
        glm::vec3 p_rotation;
        glm::vec3 p_scale;


};




#endif // TRANSFORM_H_INCLUDED
