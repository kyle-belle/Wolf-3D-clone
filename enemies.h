#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED

#include "level.h"
#include "material.h"
#include "mesh.h"
#include "obj_loader.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "TIMER.h"

//#include "player.h"


//class level;

extern level Level;
//extern player Player;
//extern door doors



class enemy{
public :

        vector2f line_start;
        vector2f cast_direction;
        vector2f cast_distance;
        vector2f line_end;

        vector2f collision_vector;

        vector2f cam_pos;
        vector2f player_size;

        vector2f player_intersect_vec;

        level* lEvel;


    static shader* Shader;
    static IndexedModel model;
    static mesh3DD mesh;

    static texture* animation;

    float HEIGHT = 0.7f;
    float LENGTH = HEIGHT/2.0f;
    float WIDTH = 0.02f;

    float Distance;

    vector3f Direction_to_camera;
    vector3f movement_vector;
    vector3f Orientation;
    vector3f Position;

    float START = 0.0f;

    material Material;
    transformation Transformation;

    enum STATE{IDLE = 0, CHASE, ATTACK, DYING, DEAD};

    int state = STATE::IDLE;

    float move_speed = 0.0005f;
    float MIN_CHASE_DISTANCE = 2.0f;

    float enemy_length = 0.2f;
    float enemy_width = 0.1f;
    const int MAX_HEALTH = 100;
    double DEATH_TIME;

    int health = MAX_HEALTH;

    const float SHOOT_DISTANCE = 25.0f;

    bool can_look = false;
    bool can_attack = false;


    enemy(){}

    enemy(transformation& transformation, shader& shader):Transformation(transformation){

        if(Shader == nullptr){
            Shader = &shader;
        }

        //Material.set_material(Material.tex);
        (*Shader).set_uniform_4f("u_colour",Material.c_colour.r, Material.c_colour.g, Material.c_colour.b, Material.c_colour.a);

//        if(animation == nullptr){
//            animation.push_back(texture("SSWVA1.png"));
//            animation.push_back(texture("SSWVB1.png"));
//            animation.push_back(texture("SSWVC1.png"));
//            animation.push_back(texture("SSWVD1.png"));
//
//            animation.push_back(texture("SSWVE0.png"));
//            animation.push_back(texture("SSWVF0.png"));
//            animation.push_back(texture("SSWVG0.png"));
//
//            animation.push_back(texture("SSWVH0.png"));
//
//            animation.push_back(texture("SSWVI0.png"));
//            animation.push_back(texture("SSWVJ0.png"));
//            animation.push_back(texture("SSWVK0.png"));
//            animation.push_back(texture("SSWVL0.png"));
//
//            animation.push_back(texture("SSWVM0.png"));
//
//
//        }

        if(model.position.size() == 0){
            model.position.reserve(16);
            model.texCoord.reserve(16);
            model.indices.reserve(96);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));

            model.indices.emplace_back(0);
            model.indices.emplace_back(1);
            model.indices.emplace_back(2);

            model.indices.emplace_back(0);
            model.indices.emplace_back(2);
            model.indices.emplace_back(3);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));

            model.indices.emplace_back(6);
            model.indices.emplace_back(5);
            model.indices.emplace_back(4);

            model.indices.emplace_back(7);
            model.indices.emplace_back(6);
            model.indices.emplace_back(4);


            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));

            model.indices.emplace_back(10);
            model.indices.emplace_back(9);
            model.indices.emplace_back(8);

            model.indices.emplace_back(11);
            model.indices.emplace_back(10);
            model.indices.emplace_back(8);

            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));

            model.indices.emplace_back(13);
            model.indices.emplace_back(14);
            model.indices.emplace_back(15);

            model.indices.emplace_back(12);
            model.indices.emplace_back(13);
            model.indices.emplace_back(15);

            mesh.buffer_data(model);
            Material.set_material(animation[0]);
        }
    }


    enemy(float x, float y, float z, shader& shader){

         player_size.set_xy(0.25f, 0.25f);

        Material.load_texture("SSWVA1.png");
        //Material.set_material(Material.tex);

        Transformation.translation.set_xyz(x,y,z);

        if(Shader == nullptr){
            Shader = &shader;
        }

//        if(animation == nullptr){
//            animation.push_back(texture("SSWVA1.png"));
//            animation.push_back(texture("SSWVB1.png"));
//            animation.push_back(texture("SSWVC1.png"));
//            animation.push_back(texture("SSWVD1.png"));
//
//            animation.push_back(texture("SSWVE0.png"));
//            animation.push_back(texture("SSWVF0.png"));
//            animation.push_back(texture("SSWVG0.png"));
//
//            animation.push_back(texture("SSWVH0.png"));
//
//            animation.push_back(texture("SSWVI0.png"));
//            animation.push_back(texture("SSWVJ0.png"));
//            animation.push_back(texture("SSWVK0.png"));
//            animation.push_back(texture("SSWVL0.png"));
//
//            animation.push_back(texture("SSWVM0.png"));
//
//
//        }

        (*Shader).set_uniform_4f("u_colour",Material.c_colour.r, Material.c_colour.g, Material.c_colour.b, Material.c_colour.a);

        if(model.position.size() == 0){
            model.position.reserve(4);
            model.texCoord.reserve(4);
            model.indices.reserve(6);

            model.position.emplace_back(vector3f(-LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
            model.position.emplace_back(vector3f(-LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH/2,HEIGHT,START)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH/2,START,START)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));

            model.indices.emplace_back(0);
            model.indices.emplace_back(1);
            model.indices.emplace_back(2);

            model.indices.emplace_back(0);
            model.indices.emplace_back(2);
            model.indices.emplace_back(3);

//            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
//            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
//            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
//            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));
//
//            model.indices.emplace_back(6);
//            model.indices.emplace_back(5);
//            model.indices.emplace_back(4);
//
//            model.indices.emplace_back(7);
//            model.indices.emplace_back(6);
//            model.indices.emplace_back(4);
//
//
//            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
//            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));
//
//            model.indices.emplace_back(10);
//            model.indices.emplace_back(9);
//            model.indices.emplace_back(8);
//
//            model.indices.emplace_back(11);
//            model.indices.emplace_back(10);
//            model.indices.emplace_back(8);
//
//            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.0,0.0f));
//            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));
//
//            model.indices.emplace_back(13);
//            model.indices.emplace_back(14);
//            model.indices.emplace_back(15);
//
//            model.indices.emplace_back(12);
//            model.indices.emplace_back(13);
//            model.indices.emplace_back(15);

            mesh.buffer_data(model);
            DEATH_TIME = 0.0;
        }
    }


    void create(transformation& transformation, shader& shader){

        //Material.load_texture("instagram.png");
         //Material.load_texture("SSWVA1.png");
        //Material.set_material(Material.tex);

        if(Shader == nullptr){
            Shader = &shader;
        }

//        if(animation == nullptr){
//            animation.push_back(texture("SSWVA1.png"));
//            animation.push_back(texture("SSWVB1.png"));
//            animation.push_back(texture("SSWVC1.png"));
//            animation.push_back(texture("SSWVD1.png"));
//
//            animation.push_back(texture("SSWVE0.png"));
//            animation.push_back(texture("SSWVF0.png"));
//            animation.push_back(texture("SSWVG0.png"));
//
//            animation.push_back(texture("SSWVH0.png"));
//
//            animation.push_back(texture("SSWVI0.png"));
//            animation.push_back(texture("SSWVJ0.png"));
//            animation.push_back(texture("SSWVK0.png"));
//            animation.push_back(texture("SSWVL0.png"));
//
//            animation.push_back(texture("SSWVM0.png"));
//
//
//        }

        (*Shader).set_uniform_4f("u_colour",Material.c_colour.r, Material.c_colour.g, Material.c_colour.b, Material.c_colour.a);

        if(model.position.size() == 0){
            model.position.reserve(16);
            model.texCoord.reserve(16);
            model.indices.reserve(96);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));

            model.indices.emplace_back(0);
            model.indices.emplace_back(1);
            model.indices.emplace_back(2);

            model.indices.emplace_back(0);
            model.indices.emplace_back(2);
            model.indices.emplace_back(3);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));

            model.indices.emplace_back(6);
            model.indices.emplace_back(5);
            model.indices.emplace_back(4);

            model.indices.emplace_back(7);
            model.indices.emplace_back(6);
            model.indices.emplace_back(4);


            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.5f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.0f));

            model.indices.emplace_back(10);
            model.indices.emplace_back(9);
            model.indices.emplace_back(8);

            model.indices.emplace_back(11);
            model.indices.emplace_back(10);
            model.indices.emplace_back(8);

            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));

            model.indices.emplace_back(13);
            model.indices.emplace_back(14);
            model.indices.emplace_back(15);

            model.indices.emplace_back(12);
            model.indices.emplace_back(13);
            model.indices.emplace_back(15);

            mesh.buffer_data(model);
            Material.set_material(animation[0]);
        }
    }


    void create(float x, float y, float z, shader& shader){

        player_size.set_xy(0.25f, 0.25f);

        Material.load_texture("SSWVA1.png");
        //Material.set_material(Material.tex);

        Transformation.translation.set_xyz(x,y,z);

        if(Shader == nullptr){
            Shader = &shader;
        }

        if(animation == nullptr){

            animation = (texture*)malloc(13 * sizeof(texture));

            Material.load_texture("SSWVA1.png");
            animation[0] = (Material.tex);

            Material.load_texture("SSWVB11.png");
            animation[1] = (Material.tex);

            Material.load_texture("SSWVC1.png");
            animation[2] = (Material.tex);

            Material.load_texture("SSWVD1.png");
            animation[3] = (Material.tex);

            Material.load_texture("SSWVE0.png");
            animation[4] = (Material.tex);

            Material.load_texture("SSWVF0.png");
            animation[5] = (Material.tex);

            Material.load_texture("SSWVG0.png");
            animation[6] = (Material.tex);


            Material.load_texture("SSWVH0.png");
            animation[7] = (Material.tex);

            Material.load_texture("SSWVI0.png");
            animation[8] = (Material.tex);

            Material.load_texture("SSWVJ0.png");
            animation[9] = (Material.tex);

            Material.load_texture("SSWVK0.png");
            animation[10] = (Material.tex);

            Material.load_texture("SSWVL0.png");
            animation[11] = (Material.tex);


            Material.load_texture("SSWVM0.png");
            animation[12] = (Material.tex);


        }

        (*Shader).set_uniform_4f("u_colour",Material.c_colour.r, Material.c_colour.g, Material.c_colour.b, Material.c_colour.a);

        if(model.position.size() == 0){
            model.position.reserve(4);
            model.texCoord.reserve(4);
            model.indices.reserve(6);

            model.position.emplace_back(vector3f(-LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
            model.position.emplace_back(vector3f(-LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH/2,HEIGHT,START)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
            model.position.emplace_back(vector3f(LENGTH/2,START,START)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));

            model.indices.emplace_back(0);
            model.indices.emplace_back(1);
            model.indices.emplace_back(2);

            model.indices.emplace_back(0);
            model.indices.emplace_back(2);
            model.indices.emplace_back(3);

//            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
//            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
//            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
//            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));
//
//            model.indices.emplace_back(6);
//            model.indices.emplace_back(5);
//            model.indices.emplace_back(4);
//
//            model.indices.emplace_back(7);
//            model.indices.emplace_back(6);
//            model.indices.emplace_back(4);
//
//
//            model.position.emplace_back(vector3f(START,START,WIDTH)); model.texCoord.emplace_back(vector2f(0.0f,0.0f));
//            model.position.emplace_back(vector3f(START,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));
//
//            model.indices.emplace_back(10);
//            model.indices.emplace_back(9);
//            model.indices.emplace_back(8);
//
//            model.indices.emplace_back(11);
//            model.indices.emplace_back(10);
//            model.indices.emplace_back(8);
//
//            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.0,0.0f));
//            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,HEIGHT,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,1.0f));
//            model.position.emplace_back(vector3f(LENGTH,START,WIDTH)); model.texCoord.emplace_back(vector2f(1.0f,0.0f));
//
//            model.indices.emplace_back(13);
//            model.indices.emplace_back(14);
//            model.indices.emplace_back(15);
//
//            model.indices.emplace_back(12);
//            model.indices.emplace_back(13);
//            model.indices.emplace_back(15);

            mesh.buffer_data(model);
            Material.set_material(animation[0]);
            DEATH_TIME = 0.0;
        }
    }


    void damage(int amt){
        printf("hit!\n");
        if(state == STATE::IDLE)
            state = STATE::ATTACK;

        health -= amt;

        if(health < 0)
            state = STATE::DYING;
    }


    void face_camera(vector3f direction_to_camera){

        float Angle = (float)atan(direction_to_camera.z/direction_to_camera.x) * (180/M_PI);

        if(direction_to_camera.x > 0)
            Angle += 180.0f;

        Transformation.rotation.y = Angle + 90.0f;
    }

    void idle(vector3f& orientation, float distance){

        double time = TIME::time/std::chrono::seconds(1);
        double time_decimals = time - ((int)time);


        if(time_decimals < 0.5){
            can_look = true;
            Transformation.set_scale(1.0f,1.0f,1.0f);
            Material.set_material(animation[0]);
        }else{
            Transformation.set_scale(0.5f,0.8f,1.0f);
            Material.set_material(animation[1]);
            if(can_look){

                line_start.set_xy(Transformation.translation.x, Transformation.translation.z);
                cast_direction.set_xy(-orientation.x, -orientation.z);
                cast_distance = cast_direction * SHOOT_DISTANCE;
                line_end = line_start + cast_distance;

                collision_vector = Level.check_intersection(line_start, line_end);

                cam_pos.set_xy(Transformation.Camera.position.x, Transformation.Camera.position.z);
                //player_size.set_xy(Player.player_size, Player.player_size);

                player_intersect_vec = Level.line_intersect_rect(line_start, line_end, cam_pos, player_size);

                if((player_intersect_vec.length() != 0) && ((collision_vector.length() == 0) ||
                    (player_intersect_vec - line_start).length() < (collision_vector - line_start).length())){

                    printf("Enemy has seen the player!\n");
                    state = STATE::ATTACK;
                    }
                    can_look = false;
            }
        }

    }

    void chase(vector3f& orientation, float distance){

        double time = TIME::time/std::chrono::seconds(1);
        double time_decimals = time - ((int)time);


        if(time_decimals < 0.25){
            Transformation.set_scale(1.0f,1.0f,1.0f);
            Material.set_material(animation[0]);
        }else if(time_decimals < 0.5){
            Transformation.set_scale(0.5f,0.8f,1.0f);
            Material.set_material(animation[1]);
        }else if(time_decimals < 0.75){
            Transformation.set_scale(0.5f,0.8f,1.0f);
            Material.set_material(animation[2]);
        }else{
            Transformation.set_scale(0.5f,0.8f,1.0f);
            Material.set_material(animation[3]);
        }



        if(distance > MIN_CHASE_DISTANCE){

            float move_amt = move_speed/-2.0f;

            vector3f oldpos = Transformation.translation;
            vector3f newpos = Transformation.translation + orientation * move_amt;

            vector3f collision_vector = Level.check_collisions(oldpos, newpos, enemy_width, enemy_length);

            movement_vector = collision_vector * orientation;
            //movement_vector.add(Transformation.translation);

            if(movement_vector.length() > 0){
                Transformation.translation.add(movement_vector * move_amt);
            }
        }else{
            state = STATE::ATTACK;
        }
    }

    void attack(vector3f& orientation, float distance){

        double time = TIME::time/std::chrono::seconds(1);
        double time_decimals = time - ((int)time);




        if(time_decimals < 0.25){
            Transformation.set_scale(1.0f,1.0f,1.0f);
//            Material.set_material(animation[4]);
        }else if(time_decimals < 0.5){
            Transformation.set_scale(1.0f,1.0f,1.0f);
            Material.set_material(animation[5]);
        }else if(time_decimals < 0.75){
            Transformation.set_scale(1.0f,1.0f,1.0f);
            Material.set_material(animation[6]);
            if(can_attack){

                line_start.set_xy(Transformation.translation.x, Transformation.translation.z);
                cast_direction.set_xy(-orientation.x, -orientation.z);
                cast_distance = cast_direction * SHOOT_DISTANCE;
                line_end = line_start + cast_distance;

                collision_vector = Level.check_intersection(line_start, line_end);

                cam_pos.set_xy(Transformation.Camera.position.x, Transformation.Camera.position.z);
                //player_size.set_xy(Player.player_size, Player.player_size);

                player_intersect_vec = Level.line_intersect_rect(line_start, line_end, cam_pos, player_size);

                if((player_intersect_vec.length() != 0) && ((collision_vector.length() == 0) ||
                    (player_intersect_vec - line_start).length() < (collision_vector - line_start).length())){

                    printf("Enemy shot the player!\n");
                    //state = STATE::CHASE;
                }

//                if(collision_vector.length() == 0){
//                    printf("we've missed everything!\n");
//                }else{
//                    printf("we've hit something!\n");
//                }
                can_attack = false;
                state = STATE::CHASE;
            }
        }else{
            can_attack = true;
            Transformation.set_scale(1.0f,1.0f,1.0f);
           Material.set_material(animation[5]);
        }
    }


    void dying(vector3f& orientation, float distance){

        double time = TIME::time/std::chrono::seconds(1);

        if(DEATH_TIME == 0){
            DEATH_TIME = time;
        }

        float time1 = 0.1f;
        float time2 = 0.3f;
        float time3 = 0.45f;
        float time4 = 0.6f;

        if(time < DEATH_TIME + time1){
            Material.set_material(animation[8]);
        }else if(time < DEATH_TIME + time2){
            Material.set_material(animation[9]);
        }else if(time < DEATH_TIME + time3){
            Material.set_material(animation[10]);
        }else if(time < DEATH_TIME + time4){
            Material.set_material(animation[11]);
        }else{
            state = STATE::DEAD;
        }

        //printf("Enemy is DEAD!!\n");
    }


    void dead(vector3f& orientation, float distance){
        Material.set_material(animation[12]);
        Transformation.set_scale(1.5f,0.21f,1.0f);
    }

    void update(){

        Position = Transformation.Camera.get_position();
        Direction_to_camera = Transformation.get_translation() - Position;

        Distance = Direction_to_camera.length();

        Orientation = Direction_to_camera/Distance;

        face_camera(Orientation);

        switch(state){

            case STATE::IDLE : idle(Orientation, Distance);
                break;

            case STATE::CHASE : chase(Orientation, Distance);
                break;

            case STATE::ATTACK : attack(Orientation, Distance);
                break;

            case STATE::DYING : dying(Orientation, Distance);
                break;

            case STATE::DEAD : dead(Orientation, Distance);
            break;
        }

        for(door& i : doors){
            if((Transformation.translation - i.Transformation.translation).length() < 1.5f)
                i.open();

            if((Transformation.translation - i.Transformation.translation).length() > 2.0f && (Transformation.Camera.position - i.Transformation.translation).length() > 2.0f)
                i.close();
        }

    }

    void render(){
        //glDisable(GL_CULL_FACE);
        Material.bind();
        Shader->bind();
        (*Shader).set_uniform_mat4f("u_mvp", Transformation.get_projected_transformation());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        mesh.draw((*Shader));
    }

    ~enemy(){
        free(animation);
    }
};

#endif // ENEMIES_H_INCLUDED
