#include "game.h"
#include "material.h"
#include "shaders.h"
#include "terrain.h"
#include "stdio.h"
#include "thread"
#include "bitmap.h"
#include "level.h"
#include "player.h"
#include "enemies.h"
#include <vector>

level Level;
player Player;
std::vector<enemy> Enemy;
enemy eee;
shader Shader;

game::game(display& display){

    Enemy.reserve(1);

    transformation.Camera.set_position(7.0f,0.4f,15.0f);



    eee.create(10.0f,0.0f,20.0f, Shader);

    Enemy.push_back(eee);
    //Enemy.emplace_back(enemy(10.0f,0.0f,20.0f, Shader));

    Level.load_level("levelTest2.png", "wolfCollection.png");

    Player.set_player(transformation.Camera.position, &Shader);

    //printf("%s\n",glfwGetKeyName(GLFW_KEY_END,0));

    //level.load_level("levelTest2.png","wolfcollection.png");
    //bitmap bitmap("levelTest2.png");
    //bitmap.generate_level(model);
    //object.buffer_data(model);

    //Texture.load_texture("wolfcollection.png");
    //Texture.binder(0);

    //Shader.load_shaders(basic_vertex_shader, basic_fragment_shader);
    //Shader.binder();

//    material.set_material(Texture,colour);
//    Shader.set_uniform_material(material);

    //bitmap.print_pixels();

    //bitmap.generate_level(model);


    //model = OBJModel("box1.obj").ToIndexedModel();
    //Texture.unbinder();
    //object.buffer_data(model);

    //}

//    model = OBJModel("C:\\Users\\stuppzzzz\\Desktop\\game\\monkey3.obj").ToIndexedModel();
//    tree_model = OBJModel("C:\\Users\\stuppzzzz\\Desktop\\game\\tree.obj").ToIndexedModel();
//
//    mesh.load_mesh("\\box1.obj");
//
//    tree_object.buffer_data(tree_model);
//    object.buffer_data(model);
//
//    Texture.load_texture("flat_map1.jpg");
//    Texture2.load_texture("bricks.jpg");
//    //Texture3.load_texture("grass.jpg");
//
//    vector3f position(0,0,0);
//    vector3f forward(0,0,1);
//    vector3f up(0,1,0);
//
//    Camera.set_camera(position, forward, up);
//    transformation.set_camera(Camera);
//
//    transformation.set_projection(70.0f, display.get_window_height(), display.get_window_width(), 0.1f, 1000.0f);
//
////    p_base1.colour = glm::vec4(0.5f,0.5f,0.5f,0.5f);
////    p_base1.intensity = 0.8f;
//
//    p_atten1.set_attenuation(1.0f,0.0f,0.0f);
//
//    p_atten2.set_attenuation(0.0f,0.0f,0.01f);
//
//    p_base2.colour = glm::vec4(1.0f,0.0f,0.0f,1.0f);
//    p_base2.intensity = 0.8f;
//
//    point_light1.set_point_light(p_base1, p_atten1, glm::vec3(2.0f,0.0f,-1.0f),10);
////
//    point_light2.set_point_light(p_base2, p_atten2, cam,10);
////
//    spot_light1.set_spot_light(point_light2,glm::vec3(0,0,1),0.7f);
////
//    //spot_light1.set_direction_and_pos(transformation.Camera.get_forward(), transformation.Camera.get_position());
//
// //   point_light point_light[Shader.MAX_POINT_LIGHTS];
//
////    spot_light spot_light[Shader.MAX_SPOT_LIGHTS];
//
//    //spot_light2.set_spot_light
//
//    spot_light[0] = spot_light1;
//
//    //point_light[0] = point_light1;
//
//    //point_light[1] = point_light2;
//
//    Shader.load_shaders(vertex_shader, fragment_shader);
//    Shader.binder();
//
//    //terrainshader.load_shaders(vertex_shadert, fragment_shadert);
//    //terrainshader.binder();
//    //Shader.set_point_lights(point_light);
//    //Shader.set_uniform_point_light();
//
//    Shader.set_spot_lights(spot_light);
//    Shader.set_uniform_spot_light();
//
//    d_light.base.colour = glm::vec4(0.5f,0.5f,0.5f,1.0f);
//    d_light.base.intensity = 0.8f;
//    d_light.direction = glm::vec4(1.0f,1.0f,-1.0f,1.0f);
//
//    Shader.set_uniform_4f("Directional_light.base.colour", d_light.base.colour.x, d_light.base.colour.y, d_light.base.colour.z, d_light.base.colour.w);
//    Shader.set_uniform_1f("Directional_light.base.intensity", d_light.base.intensity);
//    Shader.set_uniform_4f("Directional_light.direction", d_light.direction.x, d_light.direction.y, d_light.direction.z, d_light.direction.w);

//
//    material.set_material(Texture, colour);
//    Shader.set_uniform_1f("u_specular_intensity",material.c_specular_intensity);
//    Shader.set_uniform_1f("u_specular_exponent",material.c_specular_exponent);
//
//    Shader.set_uniform_4f("u_colour",material.c_colour.r, material.c_colour.g, material.c_colour.b, material.c_colour.a);
//    Shader.set_uniform_4f("ambient_light", 0.2f, 0.2f, 0.2f, 1.0f);
//
//    terrain terrain(1,-1);
//    terrain.generate_terrain();
//
//    transformation.set_scale(1,1,1);
//    transformation.Camera.set_position(0,0,-5);
//    transformation.set_translation(0,0,0);
//
//    terrains.buffer_data(terrain.model);
//    //Shader.update("u_mvp",transformation);
//    temp = 0.0f;
//    temp2 = 0.0f;
//    //transformation.Camera.rotate_y(0.5f);
}

void game::init_game(display& display){
    Enemy.reserve(1);

    transformation.Camera.set_position(7.0f,0.4f,15.0f);



    eee.create(10.0f,0.0f,20.0f, Shader);

    Enemy.push_back(eee);
    //Enemy.emplace_back(enemy(10.0f,0.0f,20.0f, Shader));

    Level.load_level("levelTest2.png", "wolfCollection.png");

    Player.set_player(transformation.Camera.position, &Shader);

    //printf("%s\n",glfwGetKeyName(GLFW_KEY_END,0));

    //level.load_level("levelTest2.png","wolfcollection.png");
    //bitmap bitmap("levelTest2.png");
    //bitmap.generate_level(model);
    //object.buffer_data(model);

    //Texture.load_texture("wolfcollection.png");
    //Texture.binder(0);

    //Shader.load_shaders(basic_vertex_shader, basic_fragment_shader);
    //Shader.binder();

//    material.set_material(Texture,colour);
//    Shader.set_uniform_material(material);

    //bitmap.print_pixels();

    //bitmap.generate_level(model);


    //model = OBJModel("box1.obj").ToIndexedModel();
    //Texture.unbinder();
    //object.buffer_data(model);

    //}

//    model = OBJModel("C:\\Users\\stuppzzzz\\Desktop\\game\\monkey3.obj").ToIndexedModel();
//    tree_model = OBJModel("C:\\Users\\stuppzzzz\\Desktop\\game\\tree.obj").ToIndexedModel();
//
//    mesh.load_mesh("\\box1.obj");
//
//    tree_object.buffer_data(tree_model);
//    object.buffer_data(model);
//
//    Texture.load_texture("flat_map1.jpg");
//    Texture2.load_texture("bricks.jpg");
//    //Texture3.load_texture("grass.jpg");
//
//    vector3f position(0,0,0);
//    vector3f forward(0,0,1);
//    vector3f up(0,1,0);
//
//    Camera.set_camera(position, forward, up);
//    transformation.set_camera(Camera);
//
//    transformation.set_projection(70.0f, display.get_window_height(), display.get_window_width(), 0.1f, 1000.0f);
//
////    p_base1.colour = glm::vec4(0.5f,0.5f,0.5f,0.5f);
////    p_base1.intensity = 0.8f;
//
//    p_atten1.set_attenuation(1.0f,0.0f,0.0f);
//
//    p_atten2.set_attenuation(0.0f,0.0f,0.01f);
//
//    p_base2.colour = glm::vec4(1.0f,0.0f,0.0f,1.0f);
//    p_base2.intensity = 0.8f;
//
//    point_light1.set_point_light(p_base1, p_atten1, glm::vec3(2.0f,0.0f,-1.0f),10);
////
//    point_light2.set_point_light(p_base2, p_atten2, cam,10);
////
//    spot_light1.set_spot_light(point_light2,glm::vec3(0,0,1),0.7f);
////
//    //spot_light1.set_direction_and_pos(transformation.Camera.get_forward(), transformation.Camera.get_position());
//
// //   point_light point_light[Shader.MAX_POINT_LIGHTS];
//
////    spot_light spot_light[Shader.MAX_SPOT_LIGHTS];
//
//    //spot_light2.set_spot_light
//
//    spot_light[0] = spot_light1;
//
//    //point_light[0] = point_light1;
//
//    //point_light[1] = point_light2;
//
//    Shader.load_shaders(vertex_shader, fragment_shader);
//    Shader.binder();
//
//    //terrainshader.load_shaders(vertex_shadert, fragment_shadert);
//    //terrainshader.binder();
//    //Shader.set_point_lights(point_light);
//    //Shader.set_uniform_point_light();
//
//    Shader.set_spot_lights(spot_light);
//    Shader.set_uniform_spot_light();
//
//    d_light.base.colour = glm::vec4(0.5f,0.5f,0.5f,1.0f);
//    d_light.base.intensity = 0.8f;
//    d_light.direction = glm::vec4(1.0f,1.0f,-1.0f,1.0f);
//
//    Shader.set_uniform_4f("Directional_light.base.colour", d_light.base.colour.x, d_light.base.colour.y, d_light.base.colour.z, d_light.base.colour.w);
//    Shader.set_uniform_1f("Directional_light.base.intensity", d_light.base.intensity);
//    Shader.set_uniform_4f("Directional_light.direction", d_light.direction.x, d_light.direction.y, d_light.direction.z, d_light.direction.w);

//
//    material.set_material(Texture, colour);
//    Shader.set_uniform_1f("u_specular_intensity",material.c_specular_intensity);
//    Shader.set_uniform_1f("u_specular_exponent",material.c_specular_exponent);
//
//    Shader.set_uniform_4f("u_colour",material.c_colour.r, material.c_colour.g, material.c_colour.b, material.c_colour.a);
//    Shader.set_uniform_4f("ambient_light", 0.2f, 0.2f, 0.2f, 1.0f);
//
//    terrain terrain(1,-1);
//    terrain.generate_terrain();
//
//    transformation.set_scale(1,1,1);
//    transformation.Camera.set_position(0,0,-5);
//    transformation.set_translation(0,0,0);
//
//    terrains.buffer_data(terrain.model);
//    //Shader.update("u_mvp",transformation);
//    temp = 0.0f;
//    temp2 = 0.0f;
}

game::~game(){}


void game::inputs(display& display){

    Player.input(display);
//    input.key_press(display,GLFW_KEY_UP);
//
//    input.key_released(display,GLFW_KEY_UP);
//
//    input.mouse_press(display, GLFW_MOUSE_BUTTON_LEFT);
//
//    input.mouse_release(display, GLFW_MOUSE_BUTTON_LEFT);
}

void game::update(){

   /* if(transformation.Camera.position.x < -12 || transformation.Camera.position.x >10 || transformation.Camera.position.z < -11 || transformation.Camera.position.z > 13){
        glFrontFace(GL_CCW);
    }else{
        glFrontFace(GL_CW);
    }*/


    //for(enemy& enemies: Enemy){
        eee.update();
    //}

    Player.update();

    Level.update();

    //Shader.update("u_mvp", camera);
    //temp += 0.0001f;
    //temp2 += 0.01f;
    //transformation.set_translation(sin(temp),0,5);
    //transformation.set_rotation(temp2,temp2,0);


    //Shader.set_uniform_mat4f("translate", transformation.get_transformation());
}

void game::render(){



        Level.render();

        eee.render();

        Player.render();


    //Enemy.render();
    //object.draw(Shader);
    //Shader.binder();
//
//    Transform.get_position().x = 50;
//    Transform.get_position().z = 50;
//    Transform.get_position().y = 0;
//    Transform.get_rotation().y = 0;
//    transformation.set_scale(0.5f,0.5f,0.5f);
//    Transform.get_scale().y = 1;
//    Transform.get_scale().z = 1;
//
//    Texture3.binder(0);
//    //terrainshader.binder();
//    terrains.draw(Shader);
//    //terrainshader.unbinder();

    //Shader.binder();
    //Shader.update("translate", transform);
    //Shader.set_uniform_mat4f("u_mvp",transformation.get_projected_transformation());
    //Texture.binder(0);
  //  object.draw(Shader);

    //transformation.set_translation(0,0,0);// = -transform.get_position().x;
//    Transform.get_position().y = transform.get_position().y;
//    Transform.get_rotation().y = -transform.get_rotation().y;
//    Transform.get_position().z = transform.get_position().z;
    //transformation.set_scale(2,2,2);
//    Transform.get_scale().y = 0.5;
//    Transform.get_scale().z = 0.5;

//    Texture2.binder(0);
    //Shader.set_uniform_mat4f("u_mvp",transformation.get_projected_transformation());
//    //Shader.update("translate", Transform);
    //object.draw(Shader);
//
//    for(int z = -50; z<51; z+=10){
//    for(int i = -50; i<51;i+=10){
//        Transform.get_position().x = 0+i;
//        Transform.get_position().y = -5;
//        Transform.get_position().z = z;
//        Transform.get_rotation().y = 0;
//        Transform.get_scale().x = 1;
//        Transform.get_scale().y = 1;
//        Transform.get_scale().z = 1;
//        //Shader.update("translate", Transform);
//        tree_object.draw(Shader);
//    }
//    }
//Shader.unbinder();
//temp += 0.001f;
//temp2 += 0.2f;
//transformation.set_scale(sin(temp), sin(temp), sin(temp));
//transformation.set_translation(sin(temp),0,0);
//level.Transformation.set_rotation(0,0,0);

//spot_light1.set_direction_and_pos(transformation.Camera.get_forward(), transformation.Camera.get_position());
//spot_light[0] = spot_light1;
//Shader.set_spot_lights(spot_light);
//Shader.set_uniform_spot_light();
//
//    Shader.set_uniform_mat4f("u_mvp", transformation.get_projected_transformation());
//    Shader.set_uniform_mat4f("translate", transformation.get_transformation());
//    Shader.set_uniform_4f("eyepos",transformation.Camera.get_position().x,transformation.Camera.get_position().y,transformation.Camera.get_position().z,1.0f);

//mesh.draw(Shader);

}

//void game::render(index_buffer& ib,shader& shader){
////   ib.draw();
//}
