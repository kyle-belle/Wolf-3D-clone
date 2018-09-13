#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <unordered_map>
#include "glm/glm.hpp"
#include "transform.h"
#include "camera.h"
#include "point_lights.h"
#include "material.h"

class shader{

    private :
        point_light* c_point_lights;
        spot_light* c_spot_light;
        const char* p_vertex_shader;
        const char* p_fragment_shader;
        unsigned int p_renderer_id;

        std::unordered_map<const char*,int> p_location_cache;

        const int get_uniform_location(const char* name);
        unsigned int compile(const char* vertex,const char* fragment);
        unsigned int compile_shader(unsigned int shader_type , const char* shader);


    public :

        const static int MAX_POINT_LIGHTS = 4;
        const static int MAX_SPOT_LIGHTS = 4;

        shader(){}
        void load_shaders(const char* vertex_shader, const char* fragment_shader);
        shader(const char* vertex_shader , const char* fragment_shader);
        ~shader();

        void bind()const;
        void unbinder()const;

        void set_uniform_4f(const char* name, float v1, float v2,float v3, float v4);
        void set_uniform_mat4f(const char* name, glm::mat4 projection);
        void set_uniform_mat4f(const char* name, const matrix4x4& projection);
        void set_uniform_1i(const char* name, int value);
        void set_uniform_1f(const char* name, float value);
        void set_point_lights(point_light* point_light);
        void set_spot_lights(spot_light* spot_light);
        void set_uniform_point_light();
        void set_uniform_spot_light();
        void set_uniform_material(material& material);
        void set_uniform_mvp(transformation& transformation);
        void update(const char* name, transform& transform);
        void update(const char* name, transformation& transformation);
        void update(const char* name,camera& camera);

        inline unsigned int get_program(){ return p_renderer_id; }

};

#endif // SHADER_H_INCLUDED
