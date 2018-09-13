#include "index_buffer.h"
#include <stdio.h>
#include "GL/glew.h"

index_buffer::index_buffer(const unsigned int* data, unsigned int count): p_count(count){

    if(sizeof(unsigned int) != sizeof(GLuint)){
        printf("unsigned int size not equal to GLuint");
    }

    glGenBuffers(1,&p_renderer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,p_renderer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int),data,GL_STATIC_DRAW);

}


index_buffer::~index_buffer(){
    glDeleteBuffers(1,&p_renderer_id);
}


void index_buffer::draw()const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,p_renderer_id);
    glDrawElements(GL_TRIANGLES,get_count(),GL_UNSIGNED_INT,0);
}


void index_buffer::unbinder()const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
