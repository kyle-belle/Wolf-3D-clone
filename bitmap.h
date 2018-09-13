#ifndef BITMAP_H_INCLUDED
#define BITMAP_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"
//#include "graphics.h"
//#include "fuck_conio.h"
#include "stb_image.h"
#include "obj_loader.h"

class bitmap{

public :
    float SPOT_WIDTH  = 1.0f;
    float SPOT_LENGTH = 1.0f;
    float SPOT_HEIGHT = 1.0f;

    int NUM_TEX_EXP = 4;
    int NUM_TEXTURE = (int)pow(2,NUM_TEX_EXP);

    char* file_path;
    unsigned char* pixels;
    int width, height, bpp;

    bitmap():pixels(nullptr){}

    bitmap(char* File_path):file_path(File_path), pixels(nullptr),width(0),height(0),bpp(0){
        pixels = stbi_load(File_path,&width,&height,&bpp, 4);
    }

    void load_level(const char* File_path){
        stbi_set_flip_vertically_on_load(0);
        pixels = stbi_load(File_path,&width,&height,&bpp, 4);
    }


void print_pixels(){
//    int dont_care;
//    for(int i = 0; i < width * height; i++){
//        dont_care = (pixels[i*4] + pixels[(i*4) + 1] + pixels[(i*4) + 2] + pixels[(i*4) + 3])/255/4;
//        textcolor(BLACK);
//        textbackground(WHITE);
//        if(dont_care == 1){
//            textcolor(YELLOW);
//            textbackground(BLUE);
//            cprintf("%d ",dont_care);
//        }else{
//        cprintf("%d ",dont_care);
//        }
//        if((i-(width-1)) % width == 0 && i != 0){
//            printf("\n");
//        }
//    }
//    textbackground(BLACK);
//    textcolor(WHITE);
}


~bitmap(){}


int get_pixel(int x, int y){
    return ((pixels[y*4 + x*width*4] + pixels[y*4 + x*width*4 + 1] + pixels[y*4 + x*width*4 + 2] + pixels[y*4 + x*width*4 + 3])/255);
}


int get_red_pixel(int x, int y){
    return pixels[y*4 + x*width*4];
}


int get_green_pixel(int x, int y){
    return pixels[(y*4 + x*width*4) + 1];
}


int get_blue_pixel(int x, int y){
    return pixels[(y*4 + x*width*4) + 2];
}

int get_alpha_pixel(int x, int y){
    return pixels[(y*4 + x*width*4) + 3];
}

void get_pixel_components(int x, int y,unsigned int* pixel_){
    pixel_[0] = pixels[y*4 + x*width*4];
    pixel_[1] = pixels[(y*4 + x*width*4) + 1];
    pixel_[2] = pixels[(y*4 + x*width*4) + 2];
    pixel_[3] = pixels[(y*4 + x*width*4) + 3];
}

void get_pixel_components_n(int x, int y,unsigned int* pixel_){
    pixel_[0] = pixels[y*4 + x*width*4]/255;
    pixel_[1] = pixels[(y*4 + x*width*4) + 1]/255;
    pixel_[2] = pixels[(y*4 + x*width*4) + 2]/255;
    pixel_[3] = pixels[(y*4 + x*width*4) + 3]/255;
}

void flip_y(){
    unsigned char temp[width * height * 4];
    int k = width*height;
    int j = 0;

    for(int i = width*height; i > 0; i--){

        temp[j*4]   = pixels[k*4-4];
        temp[j*4+1] = pixels[k*4-3];
        temp[j*4+2] = pixels[k*4-2];
        temp[j*4+3] = pixels[k*4-1];

            j++;
            k--;
    }

//    temp[(j)*4]   = pixels[0];
//    temp[(j)*4+1] = pixels[1];
//    temp[(j)*4+2] = pixels[2];
//    temp[(j)*4+3] = pixels[3];

    pixels = temp;
}


void generate_level(IndexedModel& model){
//    printf("\n\n\n");
//    for(int i = 0; i<height; i++){
//        for(int j = 0; j<width; j++){
//            textcolor(WHITE);
//            unsigned int dont_care[4];
//            get_pixel_components_n(i,j,dont_care);
//            if((dont_care[0]+dont_care[1]+dont_care[2]+dont_care[3]) > 1){
//                textbackground(YELLOW);
//                textcolor(YELLOW);
//                cprintf("%d ", dont_care[0]/255);
//            }else{
//                textbackground(WHITE);
//                cprintf("%d ", dont_care[0]/255);
//            }
//        }
//        textbackground(BLACK);
//        printf("\n");
//    }

    //unsigned int pixel[4];
    model.positions.clear();
    model.texCoords.clear();
    model.indices.clear();
    model.normals.clear();

    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){

            int dont_care = get_pixel(i,j);
            if(dont_care > 1){
               // get_pixel_components_n(i,j,pixel);
                int texx = (NUM_TEXTURE*6)/NUM_TEXTURE;
                int texy = texx % NUM_TEX_EXP;
                texx /= NUM_TEX_EXP;

                float xhigher = 1.0f - (float)texx/(float)NUM_TEX_EXP;
                float xlower = xhigher - 1.0f/(float)NUM_TEX_EXP;
                float yhigher = 1.0f - (float)texy/(float)NUM_TEX_EXP;
                float ylower = yhigher - 1.0f/(float)NUM_TEX_EXP;;


                ///generates floor :

                model.indices.emplace_back(model.positions.size() + 2);
                model.indices.emplace_back(model.positions.size() + 1);
                model.indices.emplace_back(model.positions.size() + 0);
                model.indices.emplace_back(model.positions.size() + 3);
                model.indices.emplace_back(model.positions.size() + 2);
                model.indices.emplace_back(model.positions.size() + 0);

                model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, 0, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,ylower));
                model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, 0, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,ylower));
                model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, 0, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,yhigher));
                model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, 0, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,yhigher));

                ///generates ceiling :

                texx = (NUM_TEXTURE*12)/NUM_TEXTURE;
                texy = texx % NUM_TEX_EXP;
                texx /= NUM_TEX_EXP;

                xhigher = 1.0f - (float)texx/(float)NUM_TEX_EXP;
                xlower = xhigher - 1.0f/(float)NUM_TEX_EXP;
                yhigher = 1.0f - (float)texy/(float)NUM_TEX_EXP;
                ylower = yhigher - 1.0f/(float)NUM_TEX_EXP;

                model.indices.emplace_back(model.positions.size() + 0);
                model.indices.emplace_back(model.positions.size() + 1);
                model.indices.emplace_back(model.positions.size() + 2);
                model.indices.emplace_back(model.positions.size() + 0);
                model.indices.emplace_back(model.positions.size() + 2);
                model.indices.emplace_back(model.positions.size() + 3);

                model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, SPOT_HEIGHT, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,ylower));
                model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, SPOT_HEIGHT, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,ylower));
                model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,yhigher));
                model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,yhigher));

                ///generates walls :
                if(get_pixel(i,j-1) == 1){
                    texx = (NUM_TEXTURE*12)/NUM_TEXTURE;
                    texy = texx % NUM_TEX_EXP;
                    texx /= NUM_TEX_EXP;

                    xhigher = 1.0f - (float)texx/(float)NUM_TEX_EXP;
                    xlower = xhigher - 1.0f/(float)NUM_TEX_EXP;
                    yhigher = 1.0f - (float)texy/(float)NUM_TEX_EXP;
                    ylower = yhigher - 1.0f/(float)NUM_TEX_EXP;

                    model.indices.emplace_back(model.positions.size() + 0);
                    model.indices.emplace_back(model.positions.size() + 1);
                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 0);
                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 3);

                    model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, 0, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,ylower));
                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, 0, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,ylower));
                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, SPOT_HEIGHT, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,yhigher));
                    model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, SPOT_HEIGHT, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,yhigher));

                }

                if(get_pixel(i,j+1) == 1){
                    texx = (NUM_TEXTURE*12)/NUM_TEXTURE;
                    texy = texx % NUM_TEX_EXP;
                    texx /= NUM_TEX_EXP;

                    xhigher = 1.0f - (float)texx/(float)NUM_TEX_EXP;
                    xlower = xhigher - 1.0f/(float)NUM_TEX_EXP;
                    yhigher = 1.0f - (float)texy/(float)NUM_TEX_EXP;
                    ylower = yhigher - 1.0f/(float)NUM_TEX_EXP;

                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 1);
                    model.indices.emplace_back(model.positions.size() + 0);
                    model.indices.emplace_back(model.positions.size() + 3);
                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 0);

                    model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, 0, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,ylower));
                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, 0, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,ylower));
                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,yhigher));
                    model.positions.emplace_back(    glm::vec3(i*SPOT_WIDTH, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,yhigher));

                }

                 if(get_pixel(i-1,j) == 1){

                    texx = (NUM_TEXTURE*12)/NUM_TEXTURE;
                    texy = texx % NUM_TEX_EXP;
                    texx /= NUM_TEX_EXP;

                    xhigher = 1.0f - (float)texx/(float)NUM_TEX_EXP;
                    xlower = xhigher - 1.0f/(float)NUM_TEX_EXP;
                    yhigher = 1.0f - (float)texy/(float)NUM_TEX_EXP;
                    ylower = yhigher - 1.0f/(float)NUM_TEX_EXP;

                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 1);
                    model.indices.emplace_back(model.positions.size() + 0);
                    model.indices.emplace_back(model.positions.size() + 3);
                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 0);

                    model.positions.emplace_back(glm::vec3(i*SPOT_WIDTH, 0, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,ylower));
                    model.positions.emplace_back(glm::vec3(i*SPOT_WIDTH, 0, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,ylower));
                    model.positions.emplace_back(glm::vec3(i*SPOT_WIDTH, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,yhigher));
                    model.positions.emplace_back(glm::vec3(i*SPOT_WIDTH, SPOT_HEIGHT, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,yhigher));

                }

                if(get_pixel(i+1,j) == 1){

                    texx = (NUM_TEXTURE*12)/NUM_TEXTURE;
                    texy = texx % NUM_TEX_EXP;
                    texx /= NUM_TEX_EXP;

                    xhigher = 1.0f - (float)texx/(float)NUM_TEX_EXP;
                    xlower = xhigher - 1.0f/(float)NUM_TEX_EXP;
                    yhigher = 1.0f - (float)texy/(float)NUM_TEX_EXP;
                    ylower = yhigher - 1.0f/(float)NUM_TEX_EXP;

                    model.indices.emplace_back(model.positions.size() + 0);
                    model.indices.emplace_back(model.positions.size() + 1);
                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 0);
                    model.indices.emplace_back(model.positions.size() + 2);
                    model.indices.emplace_back(model.positions.size() + 3);

                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, 0, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,ylower));
                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, 0, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,ylower));
                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, SPOT_HEIGHT, (j+1)*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xhigher,yhigher));
                    model.positions.emplace_back(glm::vec3((i+1)*SPOT_WIDTH, SPOT_HEIGHT, j*SPOT_LENGTH));    model.texCoords.emplace_back(glm::vec2(xlower,yhigher));

                }

            }
        }
    }
}

};

#endif // BITMAP_H_INCLUDED
