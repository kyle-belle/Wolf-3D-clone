#ifndef VERTEX_ARRAY_H_INCLUDED
#define VERTEX_ARRAY_H_INCLUDED

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class vertex_array{
public:

unsigned int p_renderer_id;

vertex_array(){
    call(glGenVertexArrays(1,&p_renderer_id));
    //call(glBindVertexArray(p_renderer_id));
}

~vertex_array(){
    call(glDeleteVertexArrays(1, &p_renderer_id))
}

void binder()const{
    call(glBindVertexArray(p_renderer_id));
}

void unbinder()const{
    call(glBindVertexArray(0));
}


void add_vertex_buffer(const vertex_buffer& vb, const vertex_buffer_layout& layout){

    binder();
    vb.binder();
    const auto& elements = layout.get_elements();
    unsigned int offset = 0;
    for(unsigned int i=0; i<elements.size(); i++){
        const auto& element = elements[i];
        call(glVertexAttribPointer(i,element.count,element.type,element.normalized,layout.getstride(),(const void*) offset));
        call(glEnableVertexAttribArray(i));
        offset += element.count * vertex_buffer_element::get_size_of_type(element.type);
}
}


};

#endif // VERTEX_ARRAY_H_INCLUDED
