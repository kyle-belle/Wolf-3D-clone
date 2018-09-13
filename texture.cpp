#include "texture.h"
#include "stb_image.h"
#include "GL/glew.h"

   texture::texture(const char* path)
       : p_renderer_id(0),  p_filepath(path), p_local_buffer(nullptr), p_height(0), p_width(0), p_bpp(0){

           stbi_set_flip_vertically_on_load(1);

           p_local_buffer = stbi_load(path, &p_width, &p_height, &p_bpp, 4);

           glGenTextures(1, &p_renderer_id);
           glBindTexture(GL_TEXTURE_2D, p_renderer_id);

           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

           glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, p_width, p_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, p_local_buffer);
           glBindTexture(GL_TEXTURE_2D, 0);

           if(p_local_buffer){
               stbi_image_free(p_local_buffer);
           }
}

texture::texture(){}

void texture::load_texture(const char* path){
    stbi_set_flip_vertically_on_load(1);

    p_local_buffer = stbi_load(path, &p_width, &p_height, &p_bpp, 4);

    glGenTextures(1, &p_renderer_id);
    glBindTexture(GL_TEXTURE_2D, p_renderer_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, p_width, p_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, p_local_buffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if(p_local_buffer)
        stbi_image_free(p_local_buffer);
}

texture::~texture(){
    glDeleteTextures(1, &p_renderer_id);
}

void texture::bind(unsigned int slot /* = 0 */){
    glActiveTexture(GL_TEXTURE0 + slot);

    glBindTexture(GL_TEXTURE_2D, p_renderer_id);

}


void texture::unbinder(){
    glBindTexture(GL_TEXTURE_2D, 0);
}
