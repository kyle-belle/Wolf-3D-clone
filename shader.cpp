#include "shader.h"
#include <stdio.h>
#include "GL/glew.h"


shader::shader(const char* vertex_shader , const char* fragment_shader)
 : p_vertex_shader(vertex_shader), p_fragment_shader(fragment_shader),p_renderer_id(0){

    p_renderer_id = compile(vertex_shader , fragment_shader);

}

void shader::load_shaders(const char* vertex_shader, const char* fragment_shader){

    this->p_vertex_shader = vertex_shader;
    this->p_fragment_shader = fragment_shader;

     p_renderer_id = compile(vertex_shader , fragment_shader);
}

shader::~shader(){

    glDeleteProgram(p_renderer_id);

}



void shader::bind()const{

     glUseProgram(p_renderer_id);

}



void shader::unbinder()const{

     glUseProgram(0);

}



void shader::set_uniform_4f(const char* name, float v1, float v2,float v3, float v4){

    glUniform4f(get_uniform_location(name),v1,v2,v3,v4);

}



void shader::set_uniform_1i(const char* name, int value){

    glUniform1i(get_uniform_location(name), value);

}

void shader::set_uniform_1f(const char* name, float value){

    glUniform1f(get_uniform_location(name), value);

}


void shader::set_uniform_mat4f(const char* name, const glm::mat4 projection){
    glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, &projection[0][0]);
}

void shader::set_uniform_mat4f(const char* name, const matrix4x4& projection){
    glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, &projection.m[0][0]);
}

void shader::set_point_lights(point_light* point_light){
    this->c_point_lights = point_light;
}


void shader::set_uniform_point_light(){


    shader::set_uniform_4f("Point_light[0].base.colour", c_point_lights[0].c_base.colour.x, c_point_lights[0].c_base.colour.y, c_point_lights[0].c_base.colour.z, c_point_lights[0].c_base.colour.w);
    shader::set_uniform_1f("Point_light[0].base.intensity", c_point_lights[0].c_base.intensity);
    shader::set_uniform_1f("Point_light[0].atten.constant", c_point_lights[0].c_atten.c_constant);
    shader::set_uniform_1f("Point_light[0].atten.linear", c_point_lights[0].c_atten.c_linear);
    shader::set_uniform_1f("Point_light[0].atten.exponent", c_point_lights[0].c_atten.c_exponent);
    shader::set_uniform_4f("Point_light[0].position",c_point_lights[0].c_pos.x, c_point_lights[0].c_pos.y, c_point_lights[0].c_pos.z, 1.0f);
    shader::set_uniform_1f("Point_light[0].range", c_point_lights[0].c_range);

    shader::set_uniform_4f("Point_light[1].base.colour", c_point_lights[1].c_base.colour.x, c_point_lights[1].c_base.colour.y, c_point_lights[1].c_base.colour.z, c_point_lights[1].c_base.colour.w);
    shader::set_uniform_1f("Point_light[1].base.intensity", c_point_lights[1].c_base.intensity);
    shader::set_uniform_1f("Point_light[1].atten.constant", c_point_lights[1].c_atten.c_constant);
    shader::set_uniform_1f("Point_light[1].atten.linear", c_point_lights[1].c_atten.c_linear);
    shader::set_uniform_1f("Point_light[1].atten.exponent", c_point_lights[1].c_atten.c_exponent);
    shader::set_uniform_4f("Point_light[1].position",c_point_lights[1].c_pos.x, c_point_lights[1].c_pos.y, c_point_lights[1].c_pos.z, 1.0f);
    shader::set_uniform_1f("Point_light[1].range", c_point_lights[1].c_range);

    shader::set_uniform_4f("Point_light[2].base.colour", c_point_lights[2].c_base.colour.x, c_point_lights[1].c_base.colour.y, c_point_lights[1].c_base.colour.z, c_point_lights[1].c_base.colour.w);
    shader::set_uniform_1f("Point_light[2].base.intensity", c_point_lights[2].c_base.intensity);
    shader::set_uniform_1f("Point_light[2].atten.constant", c_point_lights[2].c_atten.c_constant);
    shader::set_uniform_1f("Point_light[2].atten.linear", c_point_lights[2].c_atten.c_linear);
    shader::set_uniform_1f("Point_light[2].atten.exponent", c_point_lights[2].c_atten.c_exponent);
    shader::set_uniform_4f("Point_light[2].position",c_point_lights[2].c_pos.x, c_point_lights[2].c_pos.y, c_point_lights[2].c_pos.z, 1.0f);
    shader::set_uniform_1f("Point_light[2].range", c_point_lights[2].c_range);

    shader::set_uniform_4f("Point_light[3].base.colour", c_point_lights[3].c_base.colour.x, c_point_lights[3].c_base.colour.y, c_point_lights[3].c_base.colour.z, c_point_lights[3].c_base.colour.w);
    shader::set_uniform_1f("Point_light[3].base.intensity", c_point_lights[3].c_base.intensity);
    shader::set_uniform_1f("Point_light[3].atten.constant", c_point_lights[3].c_atten.c_constant);
    shader::set_uniform_1f("Point_light[3].atten.linear", c_point_lights[3].c_atten.c_linear);
    shader::set_uniform_1f("Point_light[3].atten.exponent", c_point_lights[3].c_atten.c_exponent);
    shader::set_uniform_4f("Point_light[3].position",c_point_lights[3].c_pos.x, c_point_lights[3].c_pos.y, c_point_lights[3].c_pos.z, 1.0f);
    shader::set_uniform_1f("Point_light[3].range", c_point_lights[3].c_range);

}

void shader::set_spot_lights(spot_light* spot_light){
    this->c_spot_light = spot_light;
}

void shader::set_uniform_spot_light(){

    shader::set_uniform_4f("Spot_light[0].Point_light.base.colour", c_spot_light[0].c_point_lights.c_base.colour.r, c_spot_light[0].c_point_lights.c_base.colour.g, c_spot_light[0].c_point_lights.c_base.colour.b, c_spot_light[0].c_point_lights.c_base.colour.a);
    shader::set_uniform_1f("Spot_light[0].Point_light.base.intensity", c_spot_light[0].c_point_lights.c_base.intensity);
    shader::set_uniform_1f("Spot_light[0].Point_light.atten.constant", c_spot_light[0].c_point_lights.c_atten.c_constant);
    shader::set_uniform_1f("Spot_light[0].Point_light.atten.linear", c_spot_light[0].c_point_lights.c_atten.c_linear);
    shader::set_uniform_1f("Spot_light[0].Point_light.atten.exponent", c_spot_light[0].c_point_lights.c_atten.c_exponent);
    shader::set_uniform_4f("Spot_light[0].Point_light.position", c_spot_light[0].c_point_lights.c_pos.x, c_spot_light[0].c_point_lights.c_pos.y, c_spot_light[0].c_point_lights.c_pos.z, 1.0f);
    shader::set_uniform_1f("Spot_light[0].Point_light.range", c_spot_light[0].c_point_lights.c_range);
    shader::set_uniform_4f("Spot_light[0].direction", c_spot_light[0].c_direction.x, c_spot_light[0].c_direction.y, c_spot_light[0].c_direction.z, 1.0f);
    shader::set_uniform_1f("Spot_light[0].cutoff", c_spot_light[0].c_cutoff);

    shader::set_uniform_4f("Spot_light[1].Point_light.base.colour", c_spot_light[1].c_point_lights.c_base.colour.r, c_spot_light[1].c_point_lights.c_base.colour.g, c_spot_light[1].c_point_lights.c_base.colour.b, c_spot_light[1].c_point_lights.c_base.colour.a);
    shader::set_uniform_1f("Spot_light[1].Point_light.base.intensity", c_spot_light[1].c_point_lights.c_base.intensity);
    shader::set_uniform_1f("Spot_light[1].Point_light.atten.constant", c_spot_light[1].c_point_lights.c_atten.c_constant);
    shader::set_uniform_1f("Spot_light[1].Point_light.atten.linear", c_spot_light[1].c_point_lights.c_atten.c_linear);
    shader::set_uniform_1f("Spot_light[1].Point_light.atten.exponent", c_spot_light[1].c_point_lights.c_atten.c_exponent);
    shader::set_uniform_4f("Spot_light[1].Point_light.position", c_spot_light[1].c_point_lights.c_pos.x, c_spot_light[1].c_point_lights.c_pos.y, c_spot_light[1].c_point_lights.c_pos.z, 1.0f);
    shader::set_uniform_1f("Spot_light[1].Point_light.range", c_spot_light[1].c_point_lights.c_range);
    shader::set_uniform_4f("Spot_light[1].direction", c_spot_light[1].c_direction.x, c_spot_light[1].c_direction.y, c_spot_light[1].c_direction.z,1.0f);
    shader::set_uniform_1f("Spot_light[1].cutoff", c_spot_light[1].c_cutoff);

    shader::set_uniform_4f("Spot_light[2].Point_light.base.colour", c_spot_light[2].c_point_lights.c_base.colour.r, c_spot_light[2].c_point_lights.c_base.colour.g, c_spot_light[2].c_point_lights.c_base.colour.b, c_spot_light[2].c_point_lights.c_base.colour.a);
    shader::set_uniform_1f("Spot_light[2].Point_light.base.intensity", c_spot_light[2].c_point_lights.c_base.intensity);
    shader::set_uniform_1f("Spot_light[2].Point_light.atten.constant", c_spot_light[2].c_point_lights.c_atten.c_constant);
    shader::set_uniform_1f("Spot_light[2].Point_light.atten.linear", c_spot_light[2].c_point_lights.c_atten.c_linear);
    shader::set_uniform_1f("Spot_light[2].Point_light.atten.exponent", c_spot_light[2].c_point_lights.c_atten.c_exponent);
    shader::set_uniform_4f("Spot_light[2].Point_light.position", c_spot_light[2].c_point_lights.c_pos.x, c_spot_light[2].c_point_lights.c_pos.y, c_spot_light[2].c_point_lights.c_pos.z, 1.0f);
    shader::set_uniform_1f("Spot_light[2].Point_light.range", c_spot_light[2].c_point_lights.c_range);
    shader::set_uniform_4f("Spot_light[2].direction", c_spot_light[2].c_direction.x, c_spot_light[2].c_direction.y, c_spot_light[2].c_direction.z,1.0f);
    shader::set_uniform_1f("Spot_light[2].cutoff", c_spot_light[2].c_cutoff);

    shader::set_uniform_4f("Spot_light[3].Point_light.base.colour", c_spot_light[3].c_point_lights.c_base.colour.r, c_spot_light[3].c_point_lights.c_base.colour.g, c_spot_light[3].c_point_lights.c_base.colour.b, c_spot_light[3].c_point_lights.c_base.colour.a);
    shader::set_uniform_1f("Spot_light[3].Point_light.base.intensity", c_spot_light[3].c_point_lights.c_base.intensity);
    shader::set_uniform_1f("Spot_light[3].Point_light.atten.constant", c_spot_light[3].c_point_lights.c_atten.c_constant);
    shader::set_uniform_1f("Spot_light[3].Point_light.atten.linear", c_spot_light[3].c_point_lights.c_atten.c_linear);
    shader::set_uniform_1f("Spot_light[3].Point_light.atten.exponent", c_spot_light[3].c_point_lights.c_atten.c_exponent);
    shader::set_uniform_4f("Spot_light[3].Point_light.position", c_spot_light[3].c_point_lights.c_pos.x, c_spot_light[3].c_point_lights.c_pos.y, c_spot_light[3].c_point_lights.c_pos.z, 1.0f);
    shader::set_uniform_1f("Spot_light[3].Point_light.range", c_spot_light[3].c_point_lights.c_range);
    shader::set_uniform_4f("Spot_light[3].direction", c_spot_light[3].c_direction.x, c_spot_light[3].c_direction.y, c_spot_light[3].c_direction.z,1.0f);
    shader::set_uniform_1f("Spot_light[3].cutoff", c_spot_light[3].c_cutoff);

}

void shader::set_uniform_material(material& material){

    shader::set_uniform_1f("u_specular_intensity",material.c_specular_intensity);
    shader::set_uniform_1f("u_specular_exponent",material.c_specular_exponent);

    shader::set_uniform_4f("u_colour",material.c_colour.r, material.c_colour.g, material.c_colour.b, material.c_colour.a);
}

void shader::set_uniform_mvp(transformation& transformation){

    shader::set_uniform_mat4f("translate", transformation.get_transformation());
    shader::set_uniform_mat4f("u_mvp", transformation.get_projected_transformation());
}

unsigned int shader::compile_shader(unsigned int shader_type, const char* shader){

    unsigned int shader_id = glCreateShader(shader_type);
    const char* src = shader;
    glShaderSource(shader_id,1,&src,0);
    glCompileShader(shader_id);

    int result;
    glGetShaderiv(shader_id,GL_COMPILE_STATUS,&result);
    if(result==GL_FALSE){
        printf("Failed to compile ");
        if(shader_type==GL_VERTEX_SHADER){printf("vertex ");}else{printf("fragment ");}
        printf("shader\n");
        int length;
        glGetShaderiv(shader_id,GL_INFO_LOG_LENGTH,&length);
        char message[length];
        glGetShaderInfoLog(shader_id,length,&length,message);
        printf("%s",message);
        return 0;
    }


    return shader_id;

}



unsigned int shader::compile(const char* vertex, const char* fragment){

    unsigned int program = glCreateProgram();
    unsigned int vertex_shader = compile_shader(GL_VERTEX_SHADER,vertex);
    unsigned int fragment_shader = compile_shader(GL_FRAGMENT_SHADER,fragment);

    glAttachShader(program,vertex_shader);
    glAttachShader(program,fragment_shader);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;

}

void shader::update(const char* name, transform& transform){

    //shader::binder();
    glm::mat4 position = transform.get_model();

    set_uniform_mat4f(name, position);
}

void shader::update(const char* name, transformation& transformation){

    //shader::binder();
    matrix4x4 position = transformation.get_transformation();

    set_uniform_mat4f(name, position);
}

void shader::update(const char* name, camera& camera){
    //shader::binder();
      //glm::mat4 cam = camera.get_view_projection();
//      set_uniform_mat4f(name, cam);
}

const int shader::get_uniform_location(const char* name){
    if(p_location_cache.find(name) != p_location_cache.end())
        return p_location_cache[name];

    int location = glGetUniformLocation(p_renderer_id, name);
    if(location == -1)
        printf(" warning uniform %s doesn't exist!\n",name);
    p_location_cache[name] = location;
    return location;
}
