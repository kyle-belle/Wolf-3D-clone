#include <stdio.h>
#include <string.h>
#include "call.h"
#include "resource_loader.h"
#include "GL/glew.h"
#include <unistd.h>


mesh::mesh(){}
mesh::~mesh(){}

void mesh::load_mesh(const char* filename){
    c_filename = (char*)filename;
    unsigned int i=0;

    char cwd[100];
   if (getcwd(cwd, sizeof(cwd)) != NULL)
       fprintf(stdout, "Current working dir: %s\n", cwd);
   else
       perror("getcwd() error");


    while(filename[i]!= '.' || i==0){
        if(i>=strlen(filename)){
            printf("filename not valid!\n");
            return ;
        }
        i++;
    }
       if(filename[i+1] != 'o' || filename[i+2] != 'b' || filename[i+3] != 'j'){
            printf("file format (\".%c%c%c\") not supported!\n",filename[i+1],filename[i+2],filename[i+3]);
            return ;
       }
       float x,y,z;
       unsigned int i1,i2,i3;
       FILE* model;
       char ffilename[strlen(cwd)+strlen(filename)+1];

       strcpy(ffilename,cwd);
       strcat(ffilename,filename);
       printf("%s\n", ffilename);
       //ffilename[0]='.';
       //unsigned int q;
       //for( q=0;q<strlen(filename);q++)
            //ffilename[q+1]=filename[q];

        //ffilename[q+1]='\0';
       char token;
       printf("%s\n",ffilename);
       model = fopen(ffilename,"r");
       if(model==nullptr){
        printf("faled to open file!\n");
        return;
       }

       while(!feof(model)){
            token = fgetc(model);

            if(token != 'v' && token != 'f'){
                while(token != '\n'){
                    token = fgetc(model);
                    if(feof(model))
                        break;
                }
               continue;
            }
            if(token == 'v'){
                fscanf(model,"%f%f%f",&x, &y, &z);
                printf("\n%f\t%f\t%f\n",x,y,z);
                positions.emplace_back(glm::vec3(x,y,z));
            }
            if(token == 'f'){
                fscanf(model,"%d%d%d",&i1, &i2, &i3);
                printf("\n%d\t%d\t%d\n",i1,i2,i3);

                indices.emplace_back(i1-1);
                indices.emplace_back(i2-1);
                indices.emplace_back(i3-1);
            }
       }
    glGenVertexArrays(1, &c_renderer_id);
    glBindVertexArray(c_renderer_id);

    glGenBuffers(2, c_vb_id);

    glBindBuffer(GL_ARRAY_BUFFER, c_vb_id[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * positions.size(), &positions[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, c_vb_id[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    }

    void mesh::draw(shader& shader){
    //shader.binder();
    glBindVertexArray(c_renderer_id);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }



