#ifndef DOORS_H_INCLUDED
#define DOORS_H_INCLUDED

#include "transform.h"
#include "obj_loader.h"
#include "mesh.h"
#include "material.h"
#include "shader.h"

class door{
public :
    static IndexedModel model;
    static mesh3DD mesh;
    static material Material;
    static shader* Shader;

    static float opening_amt;
    static float LENGTH;
    static float HEIGHT;
    static float WIDTH;

    static float START;

    transformation Transformation;

    float open_position;
    float close_position;
    bool closing = false;
    bool opening = false;


    door(){}

    door(transformation& transformation, material& material, shader& shader): Transformation(transformation){

        if(Transformation.rotation.y == 90){
            close_position = Transformation.translation.z;
            open_position = Transformation.translation.z - (LENGTH - 0.1f);
        }else{
            close_position = Transformation.translation.x;
            open_position = Transformation.translation.x - (LENGTH - 0.1f);
        }

        Material = material;

        if(Shader == nullptr){
            Shader = &shader;
        }

        if(model.position.size() == 0){
            model.position.reserve(16);
            model.texCoord.reserve(16);
            model.indices.reserve(96);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.75f,0.0f));

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
        }
    }

    door(float x, float y, float z, vector3f& rotation, material& material, shader& shader){

        Transformation.set_translation(x,y,z);
        Transformation.rotation = rotation;

        if(Transformation.rotation.y == 90){
            close_position = Transformation.translation.z;
            open_position = Transformation.translation.z - (LENGTH - 0.1f);
        }else{
            close_position = Transformation.translation.x;
            open_position = Transformation.translation.x - (LENGTH - 0.1f);
        }

        Material = material;

        if(Shader == nullptr){
            Shader = &shader;
        }

        if(model.position.size() == 0){
            model.position.reserve(16);
            model.texCoord.reserve(16);
            model.indices.reserve(96);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.75f,0.0f));

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
        }
    }

    void set_door(transformation& transformation, material& material, shader& shader){

        Transformation.translation = transformation.translation;
        Transformation.rotation = transformation.rotation;

        if(Transformation.rotation.y == 90){
            close_position = Transformation.translation.z;
            open_position = Transformation.translation.z - (LENGTH - 0.1f);
        }else{
            close_position = Transformation.translation.x;
            open_position = Transformation.translation.x - (LENGTH - 0.1f);
        }

        Material = material;

        if(Shader == nullptr){
            Shader = &shader;
        }

        if(model.position.size() == 0){
            model.position.reserve(16);
            model.texCoord.reserve(16);
            model.indices.reserve(96);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.75f,0.0f));

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
        }
    }


    void set_door(float x, float y, float z, vector3f& rotation, material& material, shader& shader){

        Transformation.set_translation(x,y,z);
        Transformation.rotation = rotation;

        if(Transformation.rotation.y == 90){
            close_position = Transformation.translation.z;
            open_position = Transformation.translation.z - (LENGTH - 0.1f);
        }else{
            close_position = Transformation.translation.x;
            open_position = Transformation.translation.x - (LENGTH - 0.1f);
        }

        Material = material;

        if(Shader == nullptr){
            Shader = &shader;
        }

        if(model.position.size() == 0){
            model.position.reserve(16);
            model.texCoord.reserve(16);
            model.indices.reserve(96);

            model.position.emplace_back(vector3f(START,START,START)); model.texCoord.emplace_back(vector2f(0.5f,0.0f));
            model.position.emplace_back(vector3f(START,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.5f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,HEIGHT,START)); model.texCoord.emplace_back(vector2f(0.75f,0.25f));
            model.position.emplace_back(vector3f(LENGTH,START,START)); model.texCoord.emplace_back(vector2f(0.75f,0.0f));

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
        }
    }

    void open(){
        if(opening || closing)
            return;

        opening = true;

    }

    void close(){

        if(closing || opening)
            return;

        closing = true;
    }


    vector2f get_size(){
        if(Transformation.rotation.y == 90){
            return vector2f(WIDTH, LENGTH);
        }else{
            return vector2f(LENGTH, WIDTH);
        }
    }


    void update(){

    /// opening
        if(Transformation.rotation.y == 90){
            if(Transformation.translation.z <= open_position){
                opening = false;
            }
        }else{
            if(Transformation.translation.x <= open_position){
                opening = false;
            }
        }

    /// closing
        if(Transformation.rotation.y == 90){
            if(Transformation.translation.z >= close_position){
                closing = false;
            }
        }else{
            if(Transformation.translation.x >= close_position){
                closing = false;
            }
        }

    /// opening
        if(opening){
            if(Transformation.rotation.y == 90.0f){
                Transformation.translation.z -= opening_amt;
            }else{
                Transformation.translation.x -= opening_amt;
            }
        }

    /// closing
        if(closing){
            if(Transformation.rotation.y == 90.0f){
                Transformation.translation.z += opening_amt;
            }else{
                Transformation.translation.x += opening_amt;
            }
        }

    }

    void render(){
        (*Shader).set_uniform_mat4f("u_mvp", Transformation.get_projected_transformation());
        mesh.draw((*Shader));
    }

};

#endif // DOORS_H_INCLUDED
