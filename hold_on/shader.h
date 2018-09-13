#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include "transform.h"
#include "camera.h"
#include <unordered_map>

#define ASSERT(x) if (!(x)) __builtin_trap();

#define call(x) clear_error();\
    x;\
    ASSERT(get_error(#x,__FILE__,__LINE__))

void clear_error(){

    while(glGetError() != GL_NO_ERROR);
}

bool get_error(const char* function_n, const char* file, int line){

    while(GLenum error = glGetError()){

        printf("[opengl error](%i)\n%s %s %d",error, function_n,file,line);
        return false;
    }
    return true;
}

class shader{

public:
    const char* p_vertex_shader;
    const char* p_fragment_shader;
    unsigned int p_renderer_id;

        std::unordered_map<const char*,int> p_location_cache;

        //const int get_uniform_location(const char* name);
        //unsigned int compile(const char* vertex,const char* fragment);
        //unsigned int compile_shader(unsigned int shader_type , const char* shader);

shader(const char* vertex_shader , const char* fragment_shader)
 : p_vertex_shader(vertex_shader), p_fragment_shader(fragment_shader),p_renderer_id(0){

    p_renderer_id = compile(vertex_shader , fragment_shader);

}



~shader(){

    call(glDeleteProgram(p_renderer_id));

}



void binder()const{

     call(glUseProgram(p_renderer_id));

}



void unbinder()const{

     call(glUseProgram(0));

}



void set_uniform_4f(const char* name, float v1, float v2,float v3, float v4){

    call(glUniform4f(get_uniform_location(name),v1,v2,v3,v4));

}



void set_uniform_1i(const char* name, int value){

    call(glUniform1i(get_uniform_location(name), value));

}

void set_uniform_1f(const char* name, float value){

    call(glUniform1f(get_uniform_location(name), value));

}


void set_uniform_mat4f(const char* name, const glm::mat4 projection){

    call(glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, &projection[0][0]));


}

unsigned int compile_shader(unsigned int shader_type, const char* shader){

    unsigned int shader_id = glCreateShader(shader_type);
    const char* src = shader;
    call(glShaderSource(shader_id,1,&src,0));
    call(glCompileShader(shader_id));

    int result;
    call(glGetShaderiv(shader_id,GL_COMPILE_STATUS,&result));
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



unsigned int compile(const char* vertex, const char* fragment){

    unsigned int program = glCreateProgram();
    unsigned int vertex_shader = compile_shader(GL_VERTEX_SHADER,vertex);
    unsigned int fragment_shader = compile_shader(GL_FRAGMENT_SHADER,fragment);

    call(glAttachShader(program,vertex_shader));
    call(glAttachShader(program,fragment_shader));
    call(glLinkProgram(program));
    call(glValidateProgram(program));

    call(glDeleteShader(vertex_shader));
    call(glDeleteShader(fragment_shader));

    return program;

}

void update(const char* name, move& move){

    glm::mat4 position = move.get_model();

    set_uniform_mat4f(name, position);
}

void update(const char* name, camera& camera){
      glm::mat4 cam = camera.get_view_projection();
      set_uniform_mat4f(name, cam);
}

const int get_uniform_location(const char* name){
    if(p_location_cache.find(name) != p_location_cache.end())
        return p_location_cache[name];

    int location = glGetUniformLocation(p_renderer_id, name);
    if(location == -1)
        printf(" warning uniform %s doesn't exist!\n",name);
    p_location_cache[name] = location;
    return location;
}

inline unsigned int get_program(){ return p_renderer_id; }

};

#endif // SHADER_H_INCLUDED
