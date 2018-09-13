#ifndef RENDER_UTIL_H_INCLUDED
#define RENDER_UTIL_H_INCLUDED

#include <GL/glew.h>

class render_util{

public:

render_util(){}
~render_util(){}

void clear_screen(){
    //TODO: STENCIL BUFFER
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void init_graphics(){


    printf("%s\n", glGetString(GL_VERSION));
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
//
    //glEnable(GL_DEPTH_CLAMP);
//
    //glEnable(GL_FRAMEBUFFER_SRGB);

}

};

#endif // RENDER_UTIL_H_INCLUDED
