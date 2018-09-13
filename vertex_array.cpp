#include "vertex_array.h"
#include "call.h"
#include "vertex_buffer_layout.h"

vertex_array::vertex_array(){

    glGenVertexArrays(1,&p_renderer_id);
    //glBindVertexArray(p_renderer_id);
}
vertex_array::~vertex_array(){

    glDeleteVertexArrays(1, &p_renderer_id);
}
void vertex_array::binder()const{

    glBindVertexArray(p_renderer_id);

}

void vertex_array::unbinder()const{

    glBindVertexArray(0);

}
vertex_array::vertex_array(const char* name){




}


void vertex_array::add_vertex_buffer(const vertex_buffer& vb, const vertex_buffer_layout& layout){

    binder();
    vb.binder();
    const auto& elements = layout.get_elements();
    unsigned int offset = 0;
    for(unsigned int i=0; i<elements.size(); i++){
        const auto& element = elements[i];
        glVertexAttribPointer(i,element.count,element.type,element.normalized,layout.getstride(),(const void*) offset);
        glEnableVertexAttribArray(i);
        offset += element.count * vertex_buffer_element::get_size_of_type(element.type);
}
}
