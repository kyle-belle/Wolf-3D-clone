#ifndef SHADERS_H_INCLUDED
#define SHADERS_H_INCLUDED

//static char vertex_shader[ ] = (
//                             "      #version 440 core\n                                                                     "
//
//                             "      layout(location = 0) in vec3 position;\n                                                "
//
//                             "      layout(location = 1) in vec2 texcoord;\n                                                "
//
//                             "      layout(location = 2) in vec3 normals;\n                                                 "
//
//                             "      out vec3 normal0;\n                                                                     "
//
//                             "      out vec4 Icolour;\n                                                                     "
//
//                             "      out vec3 worldpos;\n                                                                    "
//
//                             "      uniform mat4 translate;\n                                                               "
//
//                             "      out vec2 texcoord0;\n                                                                   "
//
//                             "      uniform mat4 u_mvp;\n                                                                   "
//
//
//
//                             "      void main(){ \n                                                                         "
//
//                             "      normal0 = (vec4(normals,1.0) * translate).xyz;\n                                        "
//
//                             "      vec4 objpos = translate * vec4(position,1.0);\n                                         "
//
//                             "      Icolour = clamp(vec4(position,1.0),0.1,1.0);\n                                          "
//
//                             "      texcoord0 = texcoord;\n                                                                 "
//
//                             "      worldpos = (vec4(position,1.0) * translate).xyz;\n                                      "
//
//                             "      gl_Position =  vec4(position,1.0)* u_mvp;//\n;\n                                                       "
//
//                             "      }\n                                                                                     "
//                             );


static char basic_vertex_shader[ ] = (
                             "      #version 330 core\n                                                                     "

                             "      layout(location = 0) in vec3 position;\n                                                "

                             "      layout(location = 1) in vec2 texcoord;\n                                                "

                             "      out vec4 Icolour;\n                                                                     "

                             "      out vec2 texcoord0;\n                                                                   "

                             "      uniform mat4 u_mvp;\n                                                                   "


                             "      void main(){ \n                                                                         "

                             "      Icolour = clamp(vec4(position,1.0),0.1,1.0);\n                                          "

                             "      texcoord0 = texcoord;\n                                                                 "

                             "      gl_Position =  vec4(position,1.0) * u_mvp;//\n;\n                                        "

                             "      }\n                                                                                     "
                             );


//static char vertex_shadert[ ] = (
//                             "      #version 440 core\n                                                                     "
//
//                             "      layout(location = 0) in vec3 position;\n                                                "
//
//                             "      layout(location = 1) in vec2 texcoord;\n                                                "
//
//                             "      layout(location = 2) in vec3 normals;\n                                                 "
//
//                             "      out vec3 normal0;\n                                                                     "
//
//                             "      out vec4 Icolour;\n                                                                     "
//
//                             "      out vec3 worldpos;\n                                                                    "
//
//                             "      uniform mat4 translate;\n                                                               "
//
//                             "      out vec2 texcoord0;\n                                                                   "
//
//                             "      uniform mat4 u_mvp;\n                                                                   "
//
//
//
//                             "      void main(){ \n                                                                         "
//
//                             "      normal0 = vec4(normals,1.0)).xyz;\n                                                     "
//
//                             "      vec4 objpos = translate * vec4(position,1.0);\n                                         "
//
//                             "      Icolour = clamp(vec4(position,1.0),0.1,1.0);\n                                          "
//
//                             "      texcoord0 = texcoord;\n                                                                 "
//
//                             "      worldpos = (translate * vec4(position,1.0)).xyz;\n                                      "
//
//                             "      gl_Position =  u_mvp*vec4(position,1.0)\n //objpos;\n;\n                                "
//
//                             "      }\n                                                                                     "
//                             );
//


//static char fragment_shader[ ] = (
//                             "      #version 440 core\n                                                                     "
//
//                             "      const int MAX_POINT_LIGHTS = 4;\n                                                       "
//
//                             "      const int MAX_SPOT_LIGHTS = 4;\n                                                        "
//
//                             "      out vec4 colour;\n                                                                      "
//
//                             "      in vec3 normal0;\n                                                                      "
//
//                             "      in vec2 texcoord0;\n                                                                    "
//
//                             "      in vec4 Icolour;\n                                                                      "
//
//                             "      in vec3 worldpos;\n                                                                     "
//
//                             "      uniform vec4 u_colour;\n                                                                "
//
//                             "      uniform sampler2D sampler;\n                                                            "
//
//                             "      uniform vec4 ambient_light;\n                                                           "
//
//                             "      uniform float u_specular_intensity;\n                                                   "
//
//                             "      uniform float u_specular_exponent;\n                                                    "
//
//                             "      uniform vec4 eyepos;\n                                                                  "
//
//                             "      struct base_light{ \n                                                                   "
//                             "          vec4 colour;\n                                                                      "
//                             "          float intensity;\n                                                                  "
//                             "      };\n                                                                                    "
//
//                             "      struct directional_light{ \n                                                            "
//                             "          base_light base;\n                                                                  "
//                             "          vec4 direction;\n                                                                   "
//                             "      };\n                                                                                    "
//
//                             "      struct attenuation{ \n                                                                  "
//                             "          float constant;\n                                                                   "
//                             "          float linear;\n                                                                     "
//                             "          float exponent;\n                                                                   "
//                             "      };\n                                                                                    "
//
//                             "      struct point_light{ \n                                                                  "
//                             "          base_light base;\n                                                                  "
//                             "          attenuation atten;\n                                                                "
//                             "          vec4 position;\n                                                                    "
//                             "          float range;\n"
//                             "      };\n                                                                                    "
//
//                             "      struct spot_light{ \n                                                                   "
//                             "          point_light Point_light;\n                                                          "
//                             "          vec4 direction;\n                                                                   "
//                             "          float cutoff;                                                                       "
//                             "     };\n                                                                                     "
//
//                             "      uniform directional_light Directional_light;\n                                          "
//
//                             "      uniform point_light Point_light[MAX_POINT_LIGHTS];\n                                    "
//
//                             "      uniform spot_light Spot_light[MAX_SPOT_LIGHTS];\n                                       "
//
//                             "      vec4 calc_light(base_light base, vec4 direction, vec3 normal){ \n                       "
//
//                             "          float diffuse_factor = dot(normal, -(direction).xyz);\n                             "
//
//                             "          vec4 diffuse_colour = vec4(0,0,0,0);\n                                              "
//                             "          vec4 specular_colour = vec4(0,0,0,0);\n                                             "
//
//                             "          if(diffuse_factor > 0){ \n                                                          "
//                             "              diffuse_colour = base.colour * base.intensity * diffuse_factor;\n               "
//                             "                                                                                              "
//                             "              vec3 direction_to_eye = normalize(eyepos.xyz - worldpos);\n                     "
//                             "              vec3 reflect_direction = normalize(reflect(direction.xyz, normal));\n           "
//                             "                                                                                              "
//                             "              float specular_factor = dot(direction_to_eye, reflect_direction);\n             "
//                             "              specular_factor = pow(specular_factor, u_specular_exponent);\n                  "
//                             "                                                                                              "
//                             "              if(specular_factor > 0){ \n                                                     "
//                             "                  specular_colour = base.colour * u_specular_intensity * specular_factor;\n   "
//                             "              }\n                                                                             "
//                             "          }\n                                                                                 "
//                             "          return diffuse_colour + specular_colour;\n                                          "
//                             "      }\n                                                                                     "
//
//                             "      vec4 calc_directional_light(directional_light Directional_light0, vec3 normal){ \n      "
//                             "          return calc_light(Directional_light0.base,-Directional_light0.direction, normal);\n "
//                             "      }\n                                                                                     "
//
//                             "      vec4 calc_point_light(point_light p_light, vec3 normal){ \n                             "
//                             "          vec3 light_direction = worldpos - p_light.position.xyz;\n                           "
//                             "          float distance = length(light_direction);\n                                         "
//
//                             "          if(p_light.range < distance){ \n                                                    "
//                             "              return vec4(0,0,0,0);\n                                                         "
//                             "          }\n                                                                                 "
//
//                             "          light_direction = normalize(light_direction);\n                                     "
//                             "                                                                                              "
//                             "          vec4 colour = calc_light(p_light.base, vec4(light_direction,1.0), normal);\n        "
//                             "                                                                                              "
//                             "          float attenuation = p_light.atten.constant + p_light.atten.linear * distance +      "
//                             "                              p_light.atten.exponent * distance * distance + 0.0001;\n        "
//                             "                                                                                              "
//                             "          return colour/attenuation;\n                                                        "
//                             "      }\n                                                                                     "
//
//                             "      vec4 calc_spot_light(spot_light spot_light, vec3 normal){ \n                            "
//                             "          vec3 light_direction = worldpos - spot_light.Point_light.position.xyz;\n            "
//                             "          light_direction = normalize(light_direction);\n                                     "
//                             "          float spot_factor = dot(light_direction, normalize(spot_light.direction).xyz);\n    "
//                             "          vec4 colour = vec4(0,0,0,0);\n                                                      "
//
//                             "          if(spot_factor > spot_light.cutoff){ \n                                             "
//                             "              colour = calc_point_light(spot_light.Point_light, normal) *                     "
//                             "                      ( 1.0 - (1.0 - spot_factor)/(1.0 - spot_light.cutoff));\n               "
//                             "          }\n                                                                                 "
//
//                             "          return colour;\n                                                                    "
//                             "      }\n                                                                                     "
//
//
//
//                             "      void main(){ \n                                                                         "
//
//                             "      vec4 texture_colour = texture(sampler, texcoord0);\n                                    "
//
//                             "      vec4 total_light = ambient_light;\n                                                     "
//
//                             "      vec3 normal = normalize(normal0);\n                                                     "
//
//                             "      for(int i = 0; i < MAX_POINT_LIGHTS; i++){ \n                                           "
//                             "          if(Point_light[i].base.intensity > 0){ \n                                           "
//                             "              total_light += calc_point_light(Point_light[i], normal);\n                      "
//                             "          }\n                                                                                 "
//                             "      }\n                                                                                     "
//
//                             "      for(int i = 0; i < MAX_SPOT_LIGHTS; i++){ \n                                            "
//                             "          if(Spot_light[i].Point_light.base.intensity > 0){ \n                                "
//                             "              total_light += calc_spot_light(Spot_light[i], normal);\n                        "
//                             "          }\n                                                                                 "
//                             "      }\n                                                                                     "
//
//                             "      //u_colour = Icolour;\n                                                                 "
//
//                             "      total_light += calc_directional_light(Directional_light, normal);\n                     "
//
//                             "      vec4 obj_colour = u_colour;\n                                                           "
//
//                             "      if(texture_colour != vec4(0,0,0,1)){ \n                                                 "
//                             "          obj_colour *= texture_colour ;\n                                                    "
//                             "      }\n                                                                                     "
//
//                             "      colour = obj_colour * total_light * Icolour;\n                                     "
//
//                             "      }\n                                                                                     "
//                             );


static char basic_fragment_shader[ ] = (
                             "      #version 330 core\n                                                                     "

                             "      out vec4 colour;\n                                                                      "

                             "      in vec2 texcoord0;\n                                                                    "

                             "      in vec4 Icolour;\n                                                                      "

                             "      uniform vec4 u_colour;\n                                                                "

                             "      uniform sampler2D sampler;\n                                                            "


                             "      void main(){ \n                                                                         "

                             "      vec4 texture_colour = texture(sampler, texcoord0);\n                                    "

                             "      vec4 obj_colour = u_colour;\n                                                           "

                             "      if(texture_colour != vec4(0,0,0,0)){ \n                                                 "
                             "          obj_colour = vec4(obj_colour.xyz,1) * texture_colour ;\n                                                    "
                             "      }\n                                                                                     "

                             "      colour = obj_colour;\n // * Icolour;\n                                                  "

                             "      }\n                                                                                     "
                             );



//static char fragment_shadert[ ] = (
//                             "      #version 440 core\n                                                                     "
//
//                             "      const int MAX_POINT_LIGHTS = 4;\n                                                       "
//
//                             "      const int MAX_SPOT_LIGHTS = 4;\n                                                        "
//
//                             "      out vec4 colour;\n                                                                      "
//
//                             "      in vec3 normal0;\n                                                                      "
//
//                             "      in vec2 texcoord0;\n                                                                    "
//
//                             "      in vec4 Icolour;\n                                                                      "
//
//                             "      in vec3 worldpos;\n                                                                     "
//
//                             "      uniform vec4 u_colour;\n                                                                "
//
//                             "      uniform sampler2D sampler;\n                                                            "
//
//                             "      uniform vec4 ambient_light;\n                                                           "
//
//                             "      uniform float u_specular_intensity;\n                                                   "
//
//                             "      uniform float u_specular_exponent;\n                                                    "
//
//                             "      uniform vec4 eyepos;\n                                                                  "
//
//                             "      struct base_light{ \n                                                                   "
//                             "          vec4 colour;\n                                                                      "
//                             "          float intensity;\n                                                                  "
//                             "      };\n                                                                                    "
//
//                             "      struct directional_light{ \n                                                            "
//                             "          base_light base;\n                                                                  "
//                             "          vec4 direction;\n                                                                   "
//                             "      };\n                                                                                    "
//
//                             "      struct attenuation{ \n                                                                  "
//                             "          float constant;\n                                                                   "
//                             "          float linear;\n                                                                     "
//                             "          float exponent;\n                                                                   "
//                             "      };\n                                                                                    "
//
//                             "      struct point_light{ \n                                                                  "
//                             "          base_light base;\n                                                                  "
//                             "          attenuation atten;\n                                                                "
//                             "          vec4 position;\n                                                                    "
//                             "          float range;\n"
//                             "      };\n                                                                                    "
//
//                             "      struct spot_light{ \n                                                                   "
//                             "          point_light Point_light;\n                                                          "
//                             "          vec4 direction;\n                                                                   "
//                             "          float cutoff;                                                                       "
//                             "     };\n                                                                                     "
//
//                             "      uniform directional_light Directional_light;\n                                          "
//
//                             "      uniform point_light Point_light[MAX_POINT_LIGHTS];\n                                    "
//
//                             "      uniform spot_light Spot_light[MAX_SPOT_LIGHTS];\n                                       "
//
//                             "      vec4 calc_light(base_light base, vec4 direction, vec3 normal){ \n                       "
//
//                             "          float diffuse_factor = dot(normal, -(direction).xyz);\n                             "
//
//                             "          vec4 diffuse_colour = vec4(0,0,0,0);\n                                              "
//                             "          vec4 specular_colour = vec4(0,0,0,0);\n                                             "
//
//                             "          if(diffuse_factor > 0){ \n                                                          "
//                             "              diffuse_colour = base.colour * base.intensity * diffuse_factor;\n               "
//                             "                                                                                              "
//                             "              vec3 direction_to_eye = normalize(eyepos.xyz - worldpos);\n                     "
//                             "              vec3 reflect_direction = normalize(reflect(direction.xyz,normal));\n            "
//                             "                                                                                              "
//                             "              float specular_factor = dot(direction_to_eye,reflect_direction);\n              "
//                             "              specular_factor = pow(specular_factor, u_specular_exponent);\n                  "
//                             "                                                                                              "
//                             "              if(specular_factor > 0){ \n                                                     "
//                             "                  specular_colour = base.colour * u_specular_intensity * specular_factor;\n   "
//                             "              }\n                                                                             "
//                             "          }\n                                                                                 "
//                             "          return diffuse_colour;\n                                                            "
//                             "      }\n                                                                                     "
//
//                             "      vec4 calc_directional_light(directional_light Directional_light0, vec3 normal){ \n      "
//                             "          return calc_light(Directional_light0.base,-Directional_light0.direction, normal);\n "
//                             "      }\n                                                                                     "
//
//                             "      vec4 calc_point_light(point_light p_light, vec3 normal){ \n                             "
//                             "          vec3 light_direction = worldpos - p_light.position.xyz;\n                           "
//                             "          float distance = length(light_direction);\n                                         "
//
//                             "          if(p_light.range < distance){ \n                                                    "
//                             "              return vec4(0,0,0,0);\n                                                         "
//                             "          }\n                                                                                 "
//
//                             "          light_direction = normalize(light_direction);\n                                     "
//                             "                                                                                              "
//                             "          vec4 colour = calc_light(p_light.base, vec4(light_direction,1.0), normal);\n        "
//                             "                                                                                              "
//                             "          float attenuation = p_light.atten.constant + p_light.atten.linear * distance +      "
//                             "                              p_light.atten.exponent * distance * distance + 0.0001;\n        "
//                             "                                                                                              "
//                             "          return colour/attenuation;\n                                                        "
//                             "      }\n                                                                                     "
//
//                             "      vec4 calc_spot_light(spot_light spot_light, vec3 normal){ \n                            "
//                             "          vec3 light_direction = worldpos - spot_light.Point_light.position.xyz;\n            "
//                             "          light_direction = normalize(light_direction);\n                                     "
//                             "          float spot_factor = dot(light_direction, normalize(spot_light.direction).xyz);\n                   "
//                             "          vec4 colour = vec4(0,0,0,0);\n                                                      "
//
//                             "          if(spot_factor > spot_light.cutoff){ \n                                             "
//                             "              colour = calc_point_light(spot_light.Point_light, normal) *                     "
//                             "                      ( 1.0 - (1.0 - spot_factor)/(1.0 - spot_light.cutoff));\n               "
//                             "          }\n                                                                                 "
//
//                             "          return colour;\n                                                                    "
//                             "      }\n                                                                                     "
//
//
//
//                             "      void main(){ \n                                                                         "
//
//                             "      vec4 total_light = ambient_light;\n                                                     "
//
//                             "      vec3 normal = normal0;\n                                                                "
//
//                             "      for(int i = 0; i < MAX_POINT_LIGHTS; i++){ \n                                           "
//                             "          if(Point_light[i].base.intensity > 0){ \n                                           "
//                             "              total_light += calc_point_light(Point_light[i], normal);\n                      "
//                             "          }\n                                                                                 "
//                             "      }\n                                                                                     "
//
//                             "      for(int i = 0; i < MAX_SPOT_LIGHTS; i++){ \n                                            "
//                             "          if(Spot_light[i].Point_light.base.intensity > 0){ \n                                "
//                             "              total_light += calc_spot_light(Spot_light[i], normal);\n                        "
//                             "          }\n                                                                                 "
//                             "      }\n                                                                                     "
//
//                             "      //u_colour = Icolour;\n                                                                 "
//
//                             "      total_light += calc_directional_light(Directional_light, normal);\n                     "
//
//                             "      vec4 obj_colour = texture2D(sampler, texcoord0.xy) * u_colour;\n                        "
//
//                             "      colour = obj_colour * total_light;\n                                                    "
//
//                             "      }\n                                                                                     "
//                             );

#endif  //SHADERS_H_INCLUDED
