#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "camera.h"
//#include "level.h"
#include "input.h"
#include "enemies.h"

extern level Level;
extern enemy eee;
extern shader Shader;

class player{

public :

    transformation Transformation;
    transformation gun_transform;

    vector3f old_pos;
    vector3f new_pos;

    input Inputs;
    input Inputs2;

    static IndexedModel gun_model;
    static mesh3DD gun_mesh;
    static material gun_material;

    static shader* gun_shader;

    texture gun_tex;
    texture gun_tex2;

    float HEIGHT = 0.0625f;
    float LENGTH = HEIGHT/2.07f;
    float WIDTH = 0.02f;
    float START = 0.0f;

    float player_size = 0.25f;
    float player_height = 0.4f;

    float move_amt    = 0.0008f;
    float rotate_amt  = 0.015f;
    float _rotate_amt = -rotate_amt;

    const float SHOOT_DISTANCE = 100.0f;

    bool free_movement = false;
    bool HAS_SHOT = false;

    vector3f movement_vector;

    vector3f direction_to_camera;
    vector3f Orientation;
    vector3f Position;


    player(){}

    player(vector3f& pos,shader* shader){

        gun_tex.load_texture("PISGB0.png");
        gun_shader = shader;

        if(gun_model.position.size() == 0){

            gun_model.position.reserve(4);
            gun_model.texCoord.reserve(4);
            gun_model.indices.reserve(6);

            gun_model.position.push_back(vector3f(-LENGTH,START,START)); gun_model.texCoord.emplace_back(vector2f(0.0f,0.0f));
            gun_model.position.push_back(vector3f(-LENGTH,HEIGHT,START)); gun_model.texCoord.emplace_back(vector2f(0.0f,1.0f));
            gun_model.position.push_back(vector3f(LENGTH/2,HEIGHT,START)); gun_model.texCoord.emplace_back(vector2f(1.0f,1.0f));
            gun_model.position.push_back(vector3f(LENGTH/2,START,START)); gun_model.texCoord.emplace_back(vector2f(1.0f,0.0f));

            gun_model.indices.push_back(0);
            gun_model.indices.push_back(1);
            gun_model.indices.push_back(2);

            gun_model.indices.push_back(0);
            gun_model.indices.push_back(2);
            gun_model.indices.push_back(3);

            gun_mesh.buffer_data(gun_model);
            gun_material.set_material(gun_tex);
        }

        if(pos.y == 0.0f){
          Transformation.Camera.set_position(0.0f, player_height,0.0f);
        }else{
          Transformation.Camera.set_camera(pos, Transformation.Camera.forward, Transformation.Camera.up);
        }

    }

    void set_player(vector3f& pos, shader* SHADER){

    gun_tex.load_texture("PISGB0.png");
    gun_tex2.load_texture("PISFA0.png");
    gun_material.set_material(gun_tex);

        if(SHADER == nullptr){
            printf("shader is null\n");
        }

        if(gun_shader == nullptr){
            gun_shader = SHADER;
        }
        //gunshader.bind();

        if(gun_shader == nullptr){
            printf("gun_shader is still null\n");
        }

        if(gun_model.position.size() == 0){


            gun_model.position.reserve(4);
            gun_model.texCoord.reserve(4);
            gun_model.indices.reserve(6);

            gun_model.position.push_back(vector3f(-LENGTH,START,START)); gun_model.texCoord.emplace_back(vector2f(0.0f,0.0f));
            gun_model.position.push_back(vector3f(-LENGTH,HEIGHT,START)); gun_model.texCoord.emplace_back(vector2f(0.0f,1.0f));
            gun_model.position.push_back(vector3f(LENGTH/2,HEIGHT,START)); gun_model.texCoord.emplace_back(vector2f(1.0f,1.0f));
            gun_model.position.push_back(vector3f(LENGTH/2,START,START)); gun_model.texCoord.emplace_back(vector2f(1.0f,0.0f));

            gun_model.indices.push_back(0);
            gun_model.indices.push_back(1);
            gun_model.indices.push_back(2);

            gun_model.indices.push_back(0);
            gun_model.indices.push_back(2);
            gun_model.indices.push_back(3);

            gun_mesh.buffer_data(gun_model);
        }

        if(pos.y == 0.0f){
          Transformation.Camera.set_position(0.0f, player_height,0.0f);
        }else{
          Transformation.Camera.set_camera(pos, Transformation.Camera.forward, Transformation.Camera.up);
        }

        gun_transform.set_translation(7.0f,0.4f,15.0f);
        //gun_transform.set_scale(0.1f,0.1f,0.1f);
//        gun_shader->set_uniform_mat4f("u_mvp", gun_transform.get_projected_transformation());
//        gun_shader->set_uniform_4f("u_colour",gun_material.c_colour.r, gun_material.c_colour.g, gun_material.c_colour.b, gun_material.c_colour.a);
    }

    void input(display& display){

       movement_vector.set_xyz(0,0,0);

            if(glfwGetKey(display.get_window(),GLFW_KEY_D))
                movement_vector.add(Transformation.Camera.get_right());

            if(glfwGetKey(display.get_window(),GLFW_KEY_I))
                movement_vector.add(Transformation.Camera.get_up());

            if(glfwGetKey(display.get_window(),GLFW_KEY_K))
                movement_vector = Transformation.Camera.get_up() * -1.0f;

            if(glfwGetKey(display.get_window(),GLFW_KEY_A))
                movement_vector.add(Transformation.Camera.get_left());

            if(glfwGetKey(display.get_window(),GLFW_KEY_W))
                movement_vector.add(Transformation.Camera.get_forward());

            if(glfwGetKey(display.get_window(),GLFW_KEY_S))
                movement_vector.add(Transformation.Camera.get_forward() * -1.0f);

            if(glfwGetKey(display.get_window(),GLFW_KEY_UP))
                Transformation.Camera.rotate_x(_rotate_amt);

            if(glfwGetKey(display.get_window(),GLFW_KEY_DOWN))
                Transformation.Camera.rotate_x(rotate_amt);

            if(glfwGetKey(display.get_window(),GLFW_KEY_LEFT))
                Transformation.Camera.rotate_y(_rotate_amt);

            if(glfwGetKey(display.get_window(),GLFW_KEY_RIGHT))
                Transformation.Camera.rotate_y(rotate_amt);

            //if(glfwGetKey(display.get_window(),GLFW_KEY_E))
                //Enemy.damage(34);

//            gun_material.set_material(gun_tex);

            if(Inputs.key_press(display, GLFW_KEY_F)){
                double time = TIME::time/std::chrono::seconds(1);
                double time_decimals = time - ((int)time);
                //if(time_decimals < 0.7f){
                if(!HAS_SHOT){
                    gun_material.set_material(gun_tex2);
                    HAS_SHOT = true;
                    return;
                }else if(time_decimals < 0.1 && HAS_SHOT){
                    gun_material.set_material(gun_tex);
                }
//                }else{
//                    gun_material.set_material(gun_tex);
//                }

            }

            if(Inputs.mouse_press(display, GLFW_MOUSE_BUTTON_LEFT)){
                double time = TIME::time/std::chrono::seconds(1);
                double time_decimals = time - ((int)time);
                //if(time_decimals < 0.7f){
                if(!HAS_SHOT){
                    gun_material.set_material(gun_tex2);
                    HAS_SHOT = true;
                    return;
                }else if(time_decimals < 0.1 && HAS_SHOT){
                    gun_material.set_material(gun_tex);
                }
//                }else{
//                    gun_material.set_material(gun_tex);
//                }

            }

            if(Inputs.key_released(display, GLFW_KEY_F)){
                gun_material.set_material(gun_tex);
                eee.damage(34);
                HAS_SHOT = false;
            }

            if(Inputs.mouse_release(display, GLFW_MOUSE_BUTTON_LEFT)){
                gun_material.set_material(gun_tex);
                eee.damage(34);
                HAS_SHOT = false;
            }


//            if(glfwGetKey(display.get_window(),GLFW_KEY_F)){
//
//                vector2f line_start(Transformation.Camera.position.x, Transformation.Camera.position.z);
//                vector2f cast_direction(Transformation.Camera.forward.x, Transformation.Camera.forward.z);
//                vector2f line_end = line_start + (cast_direction * SHOOT_DISTANCE);
//
//                Level.check_intersection(line_start, line_end, true);
//            }

            if(Inputs2.key_press(display, GLFW_KEY_M)){
            }

            if(Inputs2.key_released(display, GLFW_KEY_M)){
                if(!free_movement){
                        free_movement = true;
                        printf("free movement on.\n");
                    }else{
                        free_movement = false;
                        printf("free movement off.\n");
                    }
            }

            if(glfwGetKey(display.get_window(),GLFW_KEY_R)){
                Transformation.Camera.set_position(7.0f,player_height,15.0f);
                Transformation.Camera.set_up(0,1,0);
                Transformation.Camera.set_forward(0,0,1);
            }
    }

    void update(){

        old_pos = Transformation.Camera.get_position();
        new_pos = old_pos + movement_vector * move_amt;
        if(!free_movement){
            vector3f collision_vector = Level.check_collisions(old_pos, new_pos, player_size, player_size);
            movement_vector.mult(collision_vector);
            Transformation.Camera.position.y = player_height;
        }

        if(movement_vector.length() > 0)
            Transformation.Camera.move(movement_vector, move_amt);


        gun_transform.translation = transformation::Camera.position + (transformation::Camera.forward.normalized() * 0.19f);
        gun_transform.translation.y = gun_transform.translation.y - 0.0875f;


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        direction_to_camera = gun_transform.Camera.position - gun_transform.translation;

        float Angle = (float)atan(direction_to_camera.z/direction_to_camera.x) * (180/M_PI);

        if(direction_to_camera.x < 0)
            Angle += 180.0f;

        gun_transform.rotation.y = Angle + 90.0f;
    }

    void render(){
        gun_material.bind(0);
        //printf("rendered\n");
        //gun_shader->bind();
        //glDisable(GL_CULL_FACE);
        gun_shader->set_uniform_mat4f("u_mvp", gun_transform.get_projected_transformation());
        gun_shader->set_uniform_4f("u_colour",gun_material.c_colour.r, gun_material.c_colour.g, gun_material.c_colour.b, gun_material.c_colour.a);
        //Shader.set_uniform_mat4f("u_mvp", gun_transform.get_projected_transformation());
        gun_mesh.draw((*gun_shader));

    }
};


#endif // PLAYER_H_INCLUDED
