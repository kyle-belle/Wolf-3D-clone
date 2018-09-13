#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "material.h"
#include "shader.h"
#include "shaders.h"
#include "bitmap.h"
#include "mesh.h"
#include "obj_loader.h"
#include "transform.h"
#include "camera.h"
#include "doors.h"
//#include "enemies.h"

//IndexedModel door::model;
//shader* door::Shader = nullptr;
//material door::Material = Material;
//mesh3DD door::mesh;

//IndexedModel enemy::model;
//shader* enemy::Shader = nullptr;
//mesh3DD enemy::mesh;

//std::vector<int> k;

//float door::LENGTH = 1.0f;
//float door::HEIGHT = 1.0f;
//float door::WIDTH = 0.125f;
//float door::START = 0.0f;
//
//float door::opening_amt = 0.0002f;

static std::vector<door> doors;

class enemy;

class level{
public :

    //enemy Enemy;

    //door soors[10];

    enemy* Enemy;

    door* soors;

//    std::vector<door> doors;

    //unsigned int num_doors = 0;

    shader Shader;
    material Material;
    bitmap level_image;
    IndexedModel model;
    texture Texture;
    mesh3DD level_obj;
    transformation Transformation;
    glm::vec4 color = glm::vec4(1,1,1,1);
    door Door;

    std::vector<vector2f> collision_start;
    std::vector<vector2f> collision_end;

    int NUM_TEX_EXP = level_image.NUM_TEX_EXP;
    int NUM_TEXTURE = level_image.NUM_TEXTURE;
    int SPOT_WIDTH = level_image.SPOT_WIDTH;
    int SPOT_HEIGHT = level_image.SPOT_HEIGHT;
    int SPOT_LENGTH = level_image.SPOT_LENGTH;

    struct texture_coords{
        float xhigher;
        float xlower;
        float yhigher;
        float ylower;
    }tex_coords;

    level(){}

    ~level(){}

    vector3f check_collisions(vector3f& old_pos, vector3f& new_pos, float& object_width, float& object_length){
        vector2f collision_vector(1,1);
        vector3f movement_vector = new_pos - old_pos;

        if(movement_vector.length() > 0){
            vector2f block_size(1, 1);
            vector2f object_size(object_length, object_width);

            vector2f old_pos2(old_pos.x, old_pos.z);
            vector2f new_pos2(new_pos.x, new_pos.z);




            for(int i = 0; i < level_image.height; i++){
                for(int j = 0; j < level_image.width; j++){
                    if(level_image.get_pixel(i,j) == 1){
                        vector2f ij(i,j);
                        ij = block_size * ij;
                        collision_vector.mult(rect_collide(old_pos2, new_pos2, object_size, ij, block_size));
                    }
                }
            }
            for(door& Door : doors){
                vector2f door_size = Door.get_size();
                vector2f door_position(Door.Transformation.translation.x, Door.Transformation.translation.z);
                collision_vector.mult(rect_collide(old_pos2, new_pos2, object_size, door_position, door_size));
            }
        }

        return vector3f(collision_vector.x, 0, collision_vector.y);
    }


    vector2f rect_collide(vector2f& old_pos, vector2f& new_pos, vector2f& size1, vector2f& pos2, vector2f& size2){

        vector2f result(0,0);

        if(new_pos.x + size1.x < pos2.x || new_pos.x - size1.x > pos2.x + size2.x * size2.x ||
           old_pos.y + size1.y < pos2.y || old_pos.y - size1.y > pos2.y + size2.y * size2.y ){

           result.x = 1.0f;

           }

        if(old_pos.x + size1.x < pos2.x || old_pos.x - size1.x > pos2.x + size2.x * size2.x ||
           new_pos.y + size1.y < pos2.y || new_pos.y - size1.y > pos2.y + size2.y * size2.y ){

           result.y = 1.0f;

           }

        return result;
    }


    vector2f check_intersection(vector2f& line_start, vector2f& line_end/*, bool hurt_monster = false*/){

        vector2f nearest_intersection(0,0);

        vector2f collision_vector;
        for(unsigned int i = 0; i < collision_start.size(); i++){
            collision_vector = line_intersect(line_start, line_end, collision_start[i], collision_end[i]);

            if(((collision_vector.length() != 0) && (nearest_intersection.length() == 0))
               || (nearest_intersection - line_start).length() > (collision_vector - line_start).length()){

                nearest_intersection = collision_vector;
               }
        }

//        if(hurt_monster){
//
//        }

        return nearest_intersection;
    }


    vector2f nearest_vector(vector2f& a, vector2f& b, vector2f& pos){

        if(((b.length() != 0) && (a.length() == 0))
            ||(a - pos).length() > (b - pos).length()){
                return b;
            }
        return a;
    }


    vector2f line_intersect_rect(vector2f& line_start, vector2f& line_end, vector2f& pos, vector2f& size){
        vector2f result(0,0);

        vector2f side(pos.x + size.x, pos.y);

        vector2f collision_vector = line_intersect(line_start, line_end, pos, side);
        result = nearest_vector(result, collision_vector, line_start);

        side.set_xy(pos.x, pos.y + size.y);

        collision_vector = line_intersect(line_start, line_end, pos, side);
        result = nearest_vector(result, collision_vector, line_start);

        side = pos + size;
        vector2f side2(pos.x, pos.y + size.y);

        collision_vector = line_intersect(line_start, line_end, side2, side);
        result = nearest_vector(result, collision_vector, line_start);

        side = pos + size;
        side2.set_xy(pos.x + size.x, pos.y);

        collision_vector = line_intersect(line_start, line_end, side2, side);
        result = nearest_vector(result, collision_vector, line_start);

        return result;
    }

    float vector2fcross(vector2f& a, vector2f& b){

        return a.x * b.y - a.y * b.x;
    }

    vector2f line_intersect(vector2f& line_start1, vector2f& line_end1, vector2f& line_start2, vector2f& line_end2){

        vector2f line1 = line_end1 - line_start1;
        vector2f line2 = line_end2 - line_start2;

        float cross = vector2fcross(line1, line2);

        if(cross == 0)
            return vector2f(0,0);

        vector2f lines_start_distance = line_start2 - line_start1;

        float a = vector2fcross(lines_start_distance, line2)/cross;
        float b = vector2fcross(lines_start_distance, line1)/cross;

        line1.mult(a);

        if(0.0f <= a && a <= 1.0f && 0.0f <= b && b <= 1.0f)
            return line_start1 + line1;

        return vector2f(0,0);
    }

    void add_face(std::vector<unsigned int>& indices, unsigned int start_point, bool clockwise){
        if(clockwise){
        indices.emplace_back(start_point + 2);
        indices.emplace_back(start_point + 1);
        indices.emplace_back(start_point + 0);
        indices.emplace_back(start_point + 3);
        indices.emplace_back(start_point + 2);
        indices.emplace_back(start_point + 0);
        }else{
        indices.emplace_back(start_point + 0);
        indices.emplace_back(start_point + 1);
        indices.emplace_back(start_point + 2);
        indices.emplace_back(start_point + 0);
        indices.emplace_back(start_point + 2);
        indices.emplace_back(start_point + 3);
        }
    }

    void calc_tex_coords(texture_coords& tex_coord, int value){
            int texx = value/NUM_TEXTURE;
            int texy = texx % NUM_TEX_EXP;
            texx /= NUM_TEX_EXP;

            tex_coord.xhigher = 1.0f - (float)texx/(float)NUM_TEX_EXP;
            tex_coord.xlower  = tex_coord.xhigher - 1.0f/(float)NUM_TEX_EXP;
            tex_coord.yhigher = 1.0f - (float)texy/(float)NUM_TEX_EXP;
            tex_coord.ylower  = tex_coord.yhigher - 1.0f/(float)NUM_TEX_EXP;
    }


    void add_vertices(std::vector<glm::vec3>& positions, std::vector<glm::vec2>& texCoords, int i, int j, float offset, bool x, bool y, bool z){
        if(x && y && z){
            printf("invalid plane used!!\n");
        }

        positions.reserve(32*32);

        if(x && z){
        positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, offset, j*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xlower, tex_coords.ylower));
        positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, offset, j*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xhigher, tex_coords.ylower));
        positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, offset, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xhigher, tex_coords.yhigher));
        positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, offset, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xlower, tex_coords.yhigher));
        }else if(x && y){
        positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, 0, offset));    texCoords.emplace_back(glm::vec2(tex_coords.xlower, tex_coords.ylower));
        positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, 0, offset));    texCoords.emplace_back(glm::vec2(tex_coords.xhigher, tex_coords.ylower));
        positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, SPOT_HEIGHT, offset));    texCoords.emplace_back(glm::vec2(tex_coords.xhigher, tex_coords.yhigher));
        positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, SPOT_HEIGHT, offset));    texCoords.emplace_back(glm::vec2(tex_coords.xlower, tex_coords.yhigher));
        }else if(y && z){
        positions.emplace_back(glm::vec3(offset, 0, j*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xlower, tex_coords.ylower));
        positions.emplace_back(glm::vec3(offset, 0, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xhigher, tex_coords.ylower));
        positions.emplace_back(glm::vec3(offset, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xhigher, tex_coords.yhigher));
        positions.emplace_back(glm::vec3(offset, SPOT_HEIGHT, j*SPOT_LENGTH));    texCoords.emplace_back(glm::vec2(tex_coords.xlower, tex_coords.yhigher));
        }else{
            printf("invalid plane used!!\n");
        }
    }


    void add_monsters(){

    }

     void add_vertices_v(std::vector<vector3f>& positions, std::vector<vector2f>& texCoords, int i, int j, float offset, bool x, bool y, bool z){
        if(x && y && z){
            printf("invalid plane used!!\n");
        }

        positions.reserve(32*32);

        if(x && z){
        positions.emplace_back(    vector3f(i*SPOT_WIDTH, offset, j*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xlower, tex_coords.ylower));
        positions.emplace_back(vector3f((i+1)*SPOT_WIDTH, offset, j*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xhigher, tex_coords.ylower));
        positions.emplace_back(vector3f((i+1)*SPOT_WIDTH, offset, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xhigher, tex_coords.yhigher));
        positions.emplace_back(    vector3f(i*SPOT_WIDTH, offset, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xlower, tex_coords.yhigher));
        }else if(x && y){
        positions.emplace_back(    vector3f(i*SPOT_WIDTH, 0, offset));    texCoords.emplace_back(vector2f(tex_coords.xlower, tex_coords.ylower));
        positions.emplace_back(vector3f((i+1)*SPOT_WIDTH, 0, offset));    texCoords.emplace_back(vector2f(tex_coords.xhigher, tex_coords.ylower));
        positions.emplace_back(vector3f((i+1)*SPOT_WIDTH, SPOT_HEIGHT, offset));    texCoords.emplace_back(vector2f(tex_coords.xhigher, tex_coords.yhigher));
        positions.emplace_back(    vector3f(i*SPOT_WIDTH, SPOT_HEIGHT, offset));    texCoords.emplace_back(vector2f(tex_coords.xlower, tex_coords.yhigher));
        }else if(y && z){
        positions.emplace_back(vector3f(offset, 0, j*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xlower, tex_coords.ylower));
        positions.emplace_back(vector3f(offset, 0, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xhigher, tex_coords.ylower));
        positions.emplace_back(vector3f(offset, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xhigher, tex_coords.yhigher));
        positions.emplace_back(vector3f(offset, SPOT_HEIGHT, j*SPOT_LENGTH));    texCoords.emplace_back(vector2f(tex_coords.xlower, tex_coords.yhigher));
        }else{
            printf("invalid plane used!!\n");
        }
    }


    void add_door(int x, int y){
        transformation door_transformation;

        bool xdoor = level_image.get_pixel(x, y-1) == 1 && level_image.get_pixel(x, y+1) == 1;
        bool ydoor = level_image.get_pixel(x-1, y) == 1 && level_image.get_pixel(x+1, y) == 1;

        if(xdoor && ydoor){
            printf("invalid location!!!\n");
            return;
        }

        if(ydoor){
            door_transformation.set_translation(x, 0, y + SPOT_WIDTH/2.0f);
            //door_transformation.set_projection(Transformation);
        }

        if(xdoor){
            door_transformation.set_translation(x + SPOT_LENGTH/2.0f, 0, y);
            door_transformation.set_rotation(0,90,0);
            //door_transformation.set_projection(Transformation);
        }
        door(door_transformation, Material, Shader);
        //soors[num_doors] = Door;
        //doors = &Door;
        //num_doors++;
        doors.emplace_back(door(door_transformation, Material, Shader));
    }


    void add_special(int blue_value, int x, int y){

        if(blue_value == 16){
            add_door(x,y);
        }

    }

    void load_level(const char* level, const char* texture){

///    k.reserve(5);
///    printf("%d\n",k.size());

        doors.reserve(10);

        Shader.load_shaders(basic_vertex_shader, basic_fragment_shader);
        Shader.bind();

        //Transformation.set_translation(0.0f, 0.0f, 0.0f);

        Material.load_texture(texture);
        Shader.set_uniform_4f("u_colour",Material.c_colour.r, Material.c_colour.g, Material.c_colour.b, Material.c_colour.a);


        calc_tex_coords(tex_coords, 7);

        //Enemy.create(6.0f,0.0f,14.0f, Shader);

        level_image.load_level(level);
        //level_image.flip_y();

//        int height = level_image.height;
//        int width = level_image.width;
        printf("%d\n",sizeof(door));
//        printf("\n\n\n");
//        for(int i = 0; i<height; i++){
//            for(int j = 0; j<width; j++){
//                textcolor(WHITE);
//                unsigned int dont_care[4];
//                level_image.get_pixel_components(i,j,dont_care);
//                if((dont_care[0]+dont_care[1]+dont_care[2]+dont_care[3]) > 255){
//                    textbackground(YELLOW);
//                    textcolor(YELLOW);
//                    cprintf("%d ", dont_care[0]/255);
//                }else{
//                    textbackground(WHITE);
//                    cprintf("%d ", dont_care[0]/255);
//                }
//            }
//            textbackground(BLACK);
//            printf("\n");
//        }

        soors = (door*)malloc(5 * sizeof(door));

//        if(doors == nullptr){
//            printf("nullpointer.\n");
//            return;
//        }

        for(int i = 0; i<level_image.height; i++){

            for(int j = 0; j<level_image.width; j++){

                int dont_care = level_image.get_pixel(i,j);
                if(dont_care > 1){

                    ///generates floor :
                    calc_tex_coords(tex_coords, level_image.get_green_pixel(i,j));
                    add_face(model.indices, model.position.size(), true);
                    add_vertices_v(model.position, model.texCoord, i, j, 0, true,false,true);

                    ///generates ceiling :
                    calc_tex_coords(tex_coords, level_image.get_green_pixel(i,j)/2);
                    add_face(model.indices, model.position.size(), false);
                    add_vertices_v(model.position, model.texCoord, i, j, SPOT_HEIGHT, true,false,true);


                    add_special(level_image.get_blue_pixel(i,j),i,j);


                    ///generates walls :

                    calc_tex_coords(tex_coords, level_image.get_red_pixel(i,j));

                    if(level_image.get_pixel(i,j-1) == 1){

                        collision_start.emplace_back(vector2f(i * SPOT_WIDTH, j * SPOT_LENGTH));
                        collision_end.emplace_back(vector2f((i+1) * SPOT_WIDTH, j * SPOT_LENGTH));

                        add_face(model.indices, model.position.size(), false);
                        add_vertices_v(model.position, model.texCoord, i, j, j*SPOT_HEIGHT, true, true, false);
                    }

                    if(level_image.get_pixel(i,j+1) == 1){

                        collision_start.emplace_back(vector2f(i * SPOT_WIDTH, (j+1) * SPOT_LENGTH));
                        collision_end.emplace_back(vector2f((i+1) * SPOT_WIDTH, (j+1) * SPOT_LENGTH));

                        add_face(model.indices, model.position.size(), true);
                        add_vertices_v(model.position, model.texCoord, i, j, (j+1)*SPOT_HEIGHT, true, true, false);
                    }

                    if(level_image.get_pixel(i-1,j) == 1){

                        collision_start.emplace_back(vector2f(i * SPOT_WIDTH, j * SPOT_LENGTH));
                        collision_end.emplace_back(vector2f(i * SPOT_WIDTH, (j+1) * SPOT_LENGTH));

                        add_face(model.indices, model.position.size(), true);
                        add_vertices_v(model.position, model.texCoord, i, j, i*SPOT_HEIGHT, false, true, true);
                    }

                    if(level_image.get_pixel(i+1,j) == 1){

                        collision_start.emplace_back(vector2f((i+1) * SPOT_WIDTH, j * SPOT_LENGTH));
                        collision_end.emplace_back(vector2f((i+1) * SPOT_WIDTH, (j+1) * SPOT_LENGTH));

                        add_face(model.indices, model.position.size(), false);
                        add_vertices_v(model.position, model.texCoord, i, j, (i+1)*SPOT_HEIGHT, false, true, true);
                    }
                }
            }
        }
        level_obj.buffer_data(model);
    }


    void update(){

        for(door& i : doors){
            if((Transformation.Camera.position - i.Transformation.translation).length() < 1.5f)
                i.open();

//            if((Transformation.Camera.position.sub_m(i.Transformation.translation)).length() > 2.5f)
//                i.close();

            i.update();
        }

    }


    void render(){

        Material.bind();
        Shader.bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        Shader.set_uniform_mat4f("u_mvp", Transformation.get_projected_transformation());
        //glEnable(GL_CULL_FACE);
        level_obj.draw(Shader);

        for(door& i : doors){
            i.render();
        }
    }

};


#endif // LEVEL_H_INCLUDED
