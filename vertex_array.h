#ifndef VERTEX_ARRAY_H_INCLUDED
#define VERTEX_ARRAY_H_INCLUDED

#include "vertex_buffer.h"

class vertex_buffer_layout;

class vertex_array{
    private :
        unsigned int p_renderer_id;
    public :
        vertex_array();
        vertex_array(const char* filename);
        ~vertex_array();

        void add_vertex_buffer(const vertex_buffer& vb, const vertex_buffer_layout& layout);

        void binder()const;
        void unbinder()const;


};


#endif // VERTEX_ARRAY_H_INCLUDED
