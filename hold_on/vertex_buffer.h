#ifndef VERTEX_BUFFER_H_INCLUDED
#define VERTEX_BUFFER_H_INCLUDED

class vertex_buffer{
public:

unsigned int p_renderer_id;
unsigned int p_num_indices;
GLuint p_vertex_ArrayObject;
GLuint p_vertex_ArrayBuffers[4];

vertex_buffer(const void* data , unsigned int size){

    call(glGenBuffers(1,&p_renderer_id));
    call(glBindBuffer(GL_ARRAY_BUFFER,p_renderer_id));
    call(glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW));
}

~vertex_buffer(){
    call(glDeleteBuffers(1,&p_renderer_id));
}

void binder()const{
    call(glBindBuffer(GL_ARRAY_BUFFER,p_renderer_id));
}

void unbinder()const{
    call(glBindBuffer(GL_ARRAY_BUFFER,0));
}

};

#endif // VERTEX_BUFFER_H_INCLUDED
