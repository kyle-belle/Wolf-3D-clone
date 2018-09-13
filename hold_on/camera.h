#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class camera
{
    public:

 camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar){
        p_perspective = glm::perspective(fov, aspect, zNear, zFar);
        p_position = pos;
        p_forward = glm::vec3(0,0,1);
        p_up = glm::vec3(0,1,0);
    }
    inline glm::mat4 get_view_projection(){
        return p_perspective * glm::lookAt(p_position, p_position + p_forward, p_up);
    }
        ~camera(){}
        void set_camera(){}

    protected:

    private:
    glm::mat4 p_perspective;
    glm::vec3 p_position;
    glm::vec3 p_forward;
    glm::vec3 p_up;
};


#endif // CAMERA_H_INCLUDED
