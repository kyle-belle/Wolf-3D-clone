#ifndef RESOURCE_LOADER_H_INCLUDED
#define RESOURCE_LOADER_H_INCLUDED

#include "glm/glm.hpp"
#include <vector>
#include <string.h>
#include "shader.h"

class mesh{
private:

public:
    unsigned int c_renderer_id;
    unsigned int c_vb_id[2];
    char* c_filename;

    std::vector<glm::vec3> positions;
    std::vector<unsigned int> indices;
    mesh();
    ~mesh();

    void load_mesh(const char* filename);
    void draw(shader& shader);

};


#endif // RESOURCE_LOADER_H_INCLUDED
