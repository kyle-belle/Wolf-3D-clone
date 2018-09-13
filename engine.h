#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <thread>
#include <stdio.h>
#include "game.h"
#include "input.h"
#include "render_util.h"
#include "transform.h"
#include "camera.h"
#include <unistd.h>
#include "GLFW/glfw3.h"
#include "texture.h"
#include "material.h"
#include "point_lights.h"
#include "enemies.h"
#include "player.h"
#include "TIMER.H"
#include <iostream>


//game game;
//variables
bool p_engine_running = false;

std::chrono::duration<double, std::milli> TIME::delta;
std::chrono::duration<double, std::milli> TIME::time;

IndexedModel player::gun_model;
mesh3DD player::gun_mesh;
material player::gun_material;

shader* player::gun_shader;

IndexedModel enemy::model;
shader* enemy::Shader = nullptr;
mesh3DD enemy::mesh;
texture* enemy::animation;

IndexedModel door::model;
shader* door::Shader = nullptr;
material door::Material = Material;
mesh3DD door::mesh;

float door::LENGTH = 1.0f;
float door::HEIGHT = 1.0f;
float door::WIDTH = 0.125f;
float door::START = 0.0f;

float door::opening_amt = 0.0002f;


double FRAME_TIME = 0;
int FRAMES = 0;

std::chrono::duration<double, std::milli> frame_counter = std::chrono::milliseconds(0);

float transformation::zNEAR;
float transformation::zFAR;
float transformation::FOV;
float transformation::HEIGHT;
float transformation::WIDTH;

camera transformation::Camera;

class gameloop{

public :
render_util render_util;
game Game;

gameloop(display& display){

    FRAME_TIME = display.frame_time;
    Game.init_game(display);
    enemy::Shader = door::Shader;
    player::gun_shader = enemy::Shader;
    start(display);

}



void start(display& display){
render_util.init_graphics();
if(p_engine_running)
    stop();
run(display);
}

private :

void run(display& display){

    p_engine_running = true;
    bool renderr = false;

//    float x=0.5f;
//
//    float positions[] = {
//        -x , -x, 0.0f, 0.0f, 0.0f,
//         x , -x, 0.0f, 1.0f, 0.0f,
//         x ,  x, 0.0f, 1.0f, 1.0f,
//        -x ,  x, 0.0f, 0.0f, 1.0f
//    };
//    unsigned int index[] = {
//        0, 1, 2,
//        2, 3, 0
//    };

    //IndexedModel model = OBJModel("C:\\Users\\stuppzzzz\\Desktop\\game\\sphere3.obj").ToIndexedModel();
    //mesh3D mesh3D(model);

    //base_light p_base1;
    //p_base1.colour = glm::vec4(1.0f,0.0f,0.0f,1.0f);
    //p_base1.intensity = 0.8f;

    //attenuation p_atten1;
    //p_atten1.set_attenuation(1.0f,0.0f,0.0f);

    //attenuation p_atten2;
    //p_atten2.set_attenuation(0.0f,0.0f,0.01f);

    //base_light p_base2;
    //p_base2.colour = glm::vec4(0.0f,0.0f,1.0f,1.0f);
    //p_base2.intensity = 0.8f;

    //point_light point_light1;
    //point_light1.set_point_light(p_base1, p_atten1, glm::vec3(2.0f,0.0f,-1.0f),10);

    //point_light point_light2;
    //point_light2.set_point_light(p_base2, p_atten2, glm::vec3(-2.0f,0.0f,1.0f),10);

    //spot_light spot_light1;
    //spot_light spot_light2;

    //spot_light1.set_spot_light(point_light2,glm::vec3(0,0,1),0.7f);

    //spot_light2.set_spot_light

    //point_light1.set_point_light(base_light())

//    vertex_array va;
//    vertex_buffer vb(positions, sizeof(positions));
//
//    vb.calc_normals(positions, index);
//    vertex_buffer vn(&vb.c_normals[0], sizeof(vb.c_normals));
//
    //shader shader(vertex_shader,fragment_shader);
    //shader.binder();
//
//    vertex_buffer_layout layout;
//    layout.push(3,VALUE_TYPE::FLOAT);
//    layout.push(2, VALUE_TYPE::FLOAT);

    //point_light point_light[shader.MAX_POINT_LIGHTS];
    //spot_light spot_light[shader.MAX_SPOT_LIGHTS];

    //spot_light[0] = spot_light1;

    //point_light[0] = point_light1;
    //point_light[1] = point_light2;

    //shader.set_point_lights(point_light);
    //shader.set_uniform_point_light();

    //shader.set_spot_lights(spot_light);
    //shader.set_uniform_spot_light();

    //vertex_buffer_layout ln;
    //ln.push(3,VALUE_TYPE::FLOAT);

    //va.add_vertex_buffer(vb,layout);
    //va.add_vertex_buffer(vn,ln);

    //index_buffer ib(index, 6);

    //directional_light d_light;

    //printf("%f\n", vb.c_normals[0]);

//    d_light.base.colour = glm::vec4(0.5f,0.5f,0.5f,0.5f);
//    d_light.base.intensity = 1.0f;
//    d_light.direction = glm::vec4(0.0f,0.0f,-1.0f,1.0f);

//    shader.set_uniform_4f("Directional_light.base.colour", d_light.base.colour.x, d_light.base.colour.y, d_light.base.colour.z, d_light.base.colour.w);
//    shader.set_uniform_1f("Directional_light.base.intensity", d_light.base.intensity);
//    shader.set_uniform_4f("Directional_light.direction", d_light.direction.x, d_light.direction.y, d_light.direction.z, d_light.direction.w);

    //va.binder();
    //mesh mesh;
    //mesh.load_mesh("\\box1.obj");

    //texture texture("flat_map1.jpg");
    //texture.binder();

//    camera camera(glm::vec3(0,0,-3),70.0f, 4.0f/3.0f, 0.01f, 1000.0f);
    //spot_light1.c_point_lights.c_pos = camera.p_position;
    //spot_light1.c_direction = camera.p_forward;
    //shader.set_uniform_spot_light();

    //transform transform;

     transformation::zNEAR = 0.1f;
     transformation::zFAR = 1000.0f;
     transformation::FOV = 35.0f;
     transformation::HEIGHT = (float)display.get_window_height();
     transformation::WIDTH = (float)display.get_window_width();


    auto prev = std::chrono::high_resolution_clock::now();
    //float tr=0.0f;

    //glm::vec4 colour = glm::vec4(1.0f,1.0f,1.0f,1.0f);

    //material material(colour);
    //game.Shader.set_uniform_1f("u_specular_intensity",material.c_specular_intensity);
    //game.Shader.set_uniform_1f("u_specular_exponent",material.c_specular_exponent);


    //glm::vec3 cam = glm::vec3(0,0,-3);

    //Game.Shader.set_uniform_4f("u_colour",material.c_colour.r, material.c_colour.g, material.c_colour.b, material.c_colour.a);
    //Game.Shader.set_uniform_4f("ambient_light", 0.3f, 0.3f, 0.3f, 0.3f);

    //vector3f vec3(1,0,0);
    //float t = 0.001f;
    std::chrono::duration<double, std::milli> pass_time;
    char frames[20];
    double unprocessed_time = 0;

    while (p_engine_running){

        auto start = std::chrono::high_resolution_clock::now();

        pass_time = start - prev;

        TIME::time += pass_time;

        //std::cout<<pass_time.count()<<"\n";
        prev = start;

        TIME::delta = pass_time;

        unprocessed_time += pass_time/std::chrono::seconds(1);
        frame_counter += pass_time;

        //TIME::delta = frame_counter;
        //printf("%.2f\n",TIME::time/std::chrono::seconds(1));
        //auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(TIME::time);

        //std::cout<<TIME::time/std::chrono::seconds(1)<<std::endl;

        while(unprocessed_time > FRAME_TIME){

            unprocessed_time -= FRAME_TIME;
            renderr = true;

            if(glfwGetKey(display.get_window(),GLFW_KEY_ESCAPE))
                stop();

            //cam = glm::vec3(,0,-1);
            //camera.set_camera(Game.cam);
            //Game.Shader.set_uniform_4f("eyepos",Game.cam.x,Game.cam.y,Game.cam.z,1.0f);
            //tr+=0.0001f;

//            Game.spot_light[0].c_point_lights.c_pos = camera.p_position;
//            Game.spot_light[0].c_direction = camera.p_forward;
//            Game.Shader.set_spot_lights(Game.spot_light);
//            Game.Shader.set_uniform_spot_light();


            Game.inputs(display);
            Game.update();

            if(glfwWindowShouldClose(display.get_window()))
                stop();

            if(frame_counter >= std::chrono::seconds(1)){

                sprintf(frames,"  FPS: %d",FRAMES);
                display.append_name(display, frames);
                FRAMES=0;
                frame_counter = std::chrono::milliseconds(0);
            }
            //FRAMES++;
        }

            if(renderr){
                render(display);
                FRAMES++;
                //TIME::delta = std::chrono::microseconds(0);
                renderr = false;
            }else{
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
    }
}


void render(display& display){
    /* Render here */
    render_util.clear_screen();
    Game.render();

    //Game.render(ib, shader);

    /* Swap front and back buffers */
    glfwSwapBuffers(display.get_window());

    /* Poll for and process events */
        glfwPollEvents();
}


void stop(){
    if(!p_engine_running)
        glfwTerminate();
    p_engine_running = false;
}

    void cleanup(){}


};


#endif // ENGINE_H_INCLUDED
