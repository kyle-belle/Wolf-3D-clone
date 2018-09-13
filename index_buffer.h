#ifndef INDEX_BUFFER_H_INCLUDED
#define INDEX_BUFFER_H_INCLUDED

#include <vector>
#include "obj_loader.h"

class index_buffer{

    private :
        unsigned int p_renderer_id;
        unsigned int p_count;
    public :
        index_buffer(const unsigned int* data , unsigned int count);
        ~index_buffer();

        void draw()const;
        void unbinder()const;

        inline unsigned int get_count()const{ return p_count; }

};


#endif // INDEX_BUFFER_H_INCLUDED
