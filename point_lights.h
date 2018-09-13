#ifndef POINT_LIGHTS_H_INCLUDED
#define POINT_LIGHTS_H_INCLUDED

#include "vertex_buffer.h"
#include "vector3f.h"

struct attenuation{

    float c_constant;
    float c_linear;
    float c_exponent;

    attenuation(){}

    void set_attenuation(float constant, float linear, float exponent){

        this->c_constant = constant;
        this->c_linear = linear;
        this->c_exponent = exponent;
    }
};

struct point_light{

    base_light c_base;
    attenuation c_atten;
    glm::vec3 c_pos;
    float c_range;

    point_light(){}

    void set_point_light(base_light& base_light, attenuation& attenuation, glm::vec3 pos, float range){

        this->c_base = base_light;
        this->c_atten = attenuation;
        this->c_pos = pos;
        this->c_range = range;
    }

};

struct spot_light{

   point_light c_point_lights;
   glm::vec3 c_direction;
   float c_cutoff;

   spot_light(){}

   void set_direction_and_pos(vector3f direction, vector3f pos){
    c_direction.x = direction.x;
    c_direction.y = direction.y;
    c_direction.z = direction.z;

    c_point_lights.c_pos.x = pos.x;
    c_point_lights.c_pos.y = pos.y;
    c_point_lights.c_pos.z = pos.z;
   }

   void set_spot_light(point_light& point_light, glm::vec3 direction, float cutoff){
        this->c_point_lights = point_light;
        this->c_direction = direction;
        this->c_cutoff = cutoff;
   }

};












#endif // POINT_LIGHTS_H_INCLUDED
