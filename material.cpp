#include "material.h"



material::material(glm::vec4& colour){
    this->c_colour = colour;
}

material::material(texture& Texture):tex(Texture){
    this->c_colour = glm::vec4(1.0f,1.0f,1.0f,1.0f);
}

material::material(texture& Texture, glm::vec4& Colour):tex(Texture), c_colour(Colour){
    this->c_specular_intensity = 2.0f;
    this->c_specular_exponent = 4.0f;
}


material::material(texture& Texture, glm::vec4& Colour, float specular_intensity, float specular_exponent)
:tex(Texture), c_colour(Colour),c_specular_intensity(specular_intensity),c_specular_exponent(specular_exponent){}


void material::bind(int slot){
    tex.bind(slot);
}


void material::set_colour(glm::vec4& colour){
    this->c_colour = colour;
}

void material::set_material(texture& Texture){
    this->tex = Texture;
}

void material::set_material(texture& Texture, glm::vec4& colour){
    this->tex = Texture;
    this->c_colour = colour;
    this->c_specular_intensity = 2;
    this->c_specular_exponent = 32;
}

void material::set_material(texture& Texture, glm::vec4& colour, float specular_intensity, float specular_exponent){
    this->tex = Texture;
    this->c_colour = colour;
    this->c_specular_intensity = specular_intensity;
    this->c_specular_exponent = specular_exponent;
}

void material::load_texture(const char* filename){
    tex.load_texture(filename);
}





