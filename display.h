#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "vertex_array.h"
#include <stdio.h>
#include <string.h>


class display{
public :
const char* c_name;
double frame_time;
int WIDTH;
int HEIGHT;
display(const char* name, int width, int height, double frame_cap): c_name(name), WIDTH(width), HEIGHT(height){
    GLFWwindow* window;

    this->frame_time = 1.0/frame_cap;

    /* Initialize the library */
    if (!glfwInit())
        printf("failed to init GLFW!\n");

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, name, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }

    glfwSwapInterval(0);

    p_window = window;

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if(glewInit()!=GLEW_OK)
        printf("error");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    }

    ~display(){}

void append_name(display& display, char* name){
    char aname[15];
    strcpy(aname,c_name);
    strcat(aname, name);

    glfwSetWindowTitle(display.get_window(),aname);

}

void render(){
  glClear(GL_COLOR_BUFFER_BIT);
}

 int get_window_height()const{
     int a, b;
     glfwGetWindowSize(get_window(),&a,&b);
     return b;
 }

 int get_window_width()const{
    int a, b;
     glfwGetWindowSize(get_window(),&a,&b);
     return a;
 }

    inline bool should_window_close()const{ return p_window_should_closed; }
    inline GLFWwindow* get_window()const { return p_window; }

private :
    GLFWwindow* p_window;
    bool p_window_should_closed = false;
};

#endif // DISPLAY_H_INCLUDED
