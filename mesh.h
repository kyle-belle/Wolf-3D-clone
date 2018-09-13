#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include "GL/glew.h"
#include "obj_loader.h"
#include "shader.h"
#include "call.h"

class mesh3D{
public:

    unsigned int p_vb_id[4];
    unsigned int p_va_id;
    unsigned int p_num_indices;

mesh3D(const IndexedModel& model){

    p_num_indices = model.indices.size();

    glGenVertexArrays(1, &p_va_id);
    glBindVertexArray(p_va_id);

    glGenBuffers(4, p_vb_id);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.positions[0]) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[0]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_vb_id[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void buffer_data(const IndexedModel& model){

    p_num_indices = model.indices.size();

    glGenVertexArrays(1, &p_va_id);
    glBindVertexArray(p_va_id);

    glGenBuffers(4, p_vb_id);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.positions[0]) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[0]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_vb_id[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

mesh3D(){}

~mesh3D(){}

void draw(const shader& shader){
    //shader.binder();
    glBindVertexArray(p_va_id);
    glDrawElements(GL_TRIANGLES, p_num_indices, GL_UNSIGNED_INT, 0);
    //glBindVertexArray(0);
}


};


class mesh3DD{
public:

    unsigned int p_vb_id[4];
    unsigned int p_va_id;
    unsigned int p_num_indices;

    bool buffered = false;

mesh3DD(const IndexedModel& model){

    p_num_indices = model.indices.size();

    glGenVertexArrays(1, &p_va_id);
    glBindVertexArray(p_va_id);

    glGenBuffers(4, p_vb_id);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.position[0]) * model.position.size(), &model.position[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoord[0]) * model.texCoord.size(), &model.texCoord[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.normal[0]) * model.normal.size(), &model.normal[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_vb_id[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);

    buffered = true;
}

void buffer_data(const IndexedModel& model){

    p_num_indices = model.indices.size();

    glGenVertexArrays(1, &p_va_id);
    glBindVertexArray(p_va_id);

    glGenBuffers(4, p_vb_id);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.position[0]) * model.position.size(), &model.position[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoord[0]) * model.texCoord.size(), &model.texCoord[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, p_vb_id[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.normal[0]) * model.normal.size(), &model.normal[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_vb_id[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
    buffered = true;
}

mesh3DD(){}

~mesh3DD(){}

void draw(const shader& shader){
    //shader.bind();
    glBindVertexArray(p_va_id);
    glDrawElements(GL_TRIANGLES, p_num_indices, GL_UNSIGNED_INT, 0);
    //glBindVertexArray(0);
}


};


#endif // MESH_H_INCLUDED
