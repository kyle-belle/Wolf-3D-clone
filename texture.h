#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

class texture{

    public :

       unsigned int p_renderer_id;
       const char* p_filepath;
       unsigned char* p_local_buffer;
       int p_height, p_width, p_bpp;

    public :

        texture(const char* path);
        texture();
        ~texture();

        void load_texture(const char* path);
        void bind(unsigned int slot=0);
        void unbinder();

        inline int get_width()const{ return p_width; }
        inline int get_height()const{ return p_height; }
        inline int get_bpp()const{ return p_bpp; }


};

#endif // TEXTURE_H_INCLUDED
