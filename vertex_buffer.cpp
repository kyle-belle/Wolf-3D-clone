#include "vertex_buffer.h"
#include "call.h"


vertex_buffer::vertex_buffer(const void* data , unsigned int size){

    glGenBuffers(1,&p_renderer_id);
    glBindBuffer(GL_ARRAY_BUFFER,p_renderer_id);
    glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);

}

vertex_buffer::vertex_buffer(){}

vertex_buffer::~vertex_buffer(){
    glDeleteBuffers(1,&p_renderer_id);
}

void vertex_buffer::binder()const{
    glBindBuffer(GL_ARRAY_BUFFER,p_renderer_id);
}

void vertex_buffer::unbinder()const{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void vertex_buffer::calc_normals(float* positions, unsigned int* indices){
    float x1,y1,z1,x2,y2,z2;
    unsigned int num_faces = sizeof(indices)*6/(sizeof(unsigned int));
    printf("%d\n",num_faces);

    for(unsigned int i=0;i<num_faces;i+=3){

        int i0 = indices[i];
        int i1 = indices[i+1];
        int i2 = indices[1+2];

        x1 = positions[(i1*i)+5] - positions[(i0*i)+0];
        y1 = positions[(i1*i)+6] - positions[(i0*i)+1];
        z1 = positions[(i1*i)+7] - positions[(i0*i)+2];

        x2 = positions[(i2*i)+5] - positions[(i0*i)+0];
        y2 = positions[(i2*i)+6] - positions[(i0*i)+1];
        z2 = positions[(i2*i)+7] - positions[(i0*i)+2];

        c_normals.push_back(glm::cross(glm::vec3(x1,y1,z1),glm::vec3(x2,y2,z2)).x);
        c_normals.push_back(glm::cross(glm::vec3(x1,y1,z1),glm::vec3(x2,y2,z2)).y);
        c_normals.push_back(glm::cross(glm::vec3(x1,y1,z1),glm::vec3(x2,y2,z2)).z);
        printf("done!\n");
    }

}

void vertex_buffer::draw(){
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),0);

    glDrawArrays(GL_TRIANGLES,0,3);
    //glDisableVertexAttribArray(0);
}
