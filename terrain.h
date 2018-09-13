#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include "shader.h"

class terrain{

public:
    const float SIZE = 100.0f;
    const int VERTEX_COUNT = 128;

    IndexedModel model;
    texture Texture;
    float x;
    float z;

    terrain(int x, int y){
        this->x = x * SIZE;
        this->z = z * SIZE;
    }

    void generate_terrain(){
        //int count = VERTEX_COUNT * VERTEX_COUNT;

        //float positions[count * 3];
        //float normals[count * 3];
        //float texcoords[count * 2];
        //unsigned int indices[6 * (VERTEX_COUNT-1)*(VERTEX_COUNT*1)];

        //int vertex_pointer = 0;
        for(int i = 0; i < VERTEX_COUNT; i++){
            for(int j = 0; j < VERTEX_COUNT; j++){
                model.positions.push_back(glm::vec3(-(float)j/((float)VERTEX_COUNT-1)*SIZE,-5,-(float)i/((float)VERTEX_COUNT-1)*SIZE));
//                model.positions[vertex_pointer*3 + 1] = 0;
//                model.positions[vertex_pointer*3 + 2] = -(float)i/((float)VERTEX_COUNT-1)*SIZE;

                model.normals.push_back(glm::vec3(0,1,0));
//                model.normals[vertex_pointer*3] = 1;
//                model.normals[vertex_pointer*3] = 0;

                model.texCoords.push_back(glm::vec2((float)j/((float)VERTEX_COUNT-1)*40,(float)i/((float)VERTEX_COUNT-1)*40));
                //model.texCoords[vertex_pointer*2 + 1] = (float)i/((float)VERTEX_COUNT-1);

                //vertex_pointer++;
            }
        }

        //int pointer = 0;

        for(int gz = 0; gz < (VERTEX_COUNT-1); gz++){
            for(int gx = 0; gx <(VERTEX_COUNT-1); gx++){
                unsigned int topleft = gz*VERTEX_COUNT + gx;
                unsigned int topright = topleft + 1;
                unsigned int bottomleft = (gz+1)*VERTEX_COUNT + gx;
                unsigned int bottomright = bottomleft + 1;

                model.indices.push_back(topleft);
                model.indices.push_back(bottomleft);
                model.indices.push_back(topright);
                model.indices.push_back(topright);
                model.indices.push_back(bottomleft);
                model.indices.push_back(bottomright);
            }
        }
//        model.positions = &positions;
//        model.normals = (glm::vec3*)normals;
//        model.texCoords = (glm::vec2*)texcoords;
//        model.indices = indices;
    }
};

#endif // TERRAIN_H_INCLUDED
