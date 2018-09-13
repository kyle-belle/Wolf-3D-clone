#ifndef VERTEX_BUFFER_LAYOUT_H_INCLUDED
#define VERTEX_BUFFER_LAYOUT_H_INCLUDED


#include <vector>
#include <gl/glew.h>
#include "call.h"

struct vertex_buffer_element{

    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int get_size_of_type(unsigned int type){

        switch(type){
            case GL_FLOAT           : return sizeof(GL_FLOAT);
            case GL_UNSIGNED_INT    :  return sizeof(GL_UNSIGNED_INT);
            case GL_UNSIGNED_BYTE   : return sizeof(GL_UNSIGNED_BYTE);
        }
        return 0;
    }

};

enum class VALUE_TYPE
{
    FLOAT = 0,UNSIGNED_INT=1,UNSIGNED_CHAR=2,GLM_VEC3=3 //Create outside VertexBufferLayout class
};


class vertex_buffer_layout{
    private :
        std::vector<vertex_buffer_element> p_elements;
        unsigned int p_stride;
    public :
        vertex_buffer_layout():p_stride(0){}
        ~vertex_buffer_layout(){}

    void push(unsigned int count,VALUE_TYPE value){

        switch(value){

        case VALUE_TYPE::FLOAT:
            p_elements.push_back({GL_FLOAT,count,GL_FALSE});
            p_stride += vertex_buffer_element::get_size_of_type(GL_FLOAT) * count;
            break;
        case VALUE_TYPE::UNSIGNED_INT:
            p_elements.push_back({GL_UNSIGNED_INT,count,GL_FALSE});
            p_stride += vertex_buffer_element::get_size_of_type(GL_UNSIGNED_INT) * count;
            break;
        case VALUE_TYPE::UNSIGNED_CHAR:
            p_elements.push_back({GL_UNSIGNED_BYTE,count,GL_TRUE});
            p_stride +=vertex_buffer_element::get_size_of_type(GL_UNSIGNED_BYTE) * count;
            break;
        case VALUE_TYPE::GLM_VEC3:
            p_elements.push_back({GL_FLOAT,count,GL_FALSE});
            p_stride += vertex_buffer_element::get_size_of_type(GL_FLOAT) * count;
        }
    }


        inline const std::vector<vertex_buffer_element>get_elements()const{ return p_elements; }
        inline unsigned int getstride() const{ return p_stride; }


    };



#endif // VERTEX_BUFFER_LAYOUT_H_INCLUDED
