#ifndef INDEX_BUFFER_H_INCLUDED
#define INDEX_BUFFER_H_INCLUDED

class index_buffer{
public:

    unsigned int p_renderer_id;
    unsigned int p_count;


index_buffer(const unsigned int* data, unsigned int count): p_count(count){

    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    call(glGenBuffers(1,&p_renderer_id));
    call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,p_renderer_id));
    call(glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int),data,GL_STATIC_DRAW));

}


~index_buffer(){
    call(glDeleteBuffers(1,&p_renderer_id));
}


void draw()const{
    call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,p_renderer_id));
    call(glDrawElements(GL_TRIANGLES,get_count(),GL_UNSIGNED_INT,0));
}


void unbinder()const{
    call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0));
}

inline unsigned int get_count()const{return p_count;}

};


#endif // INDEX_BUFFER_H_INCLUDED
