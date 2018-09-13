#include "input.h"

input::input(){}

input::~input(){}


bool input::key_released(display& display, int KEY){
    if(key_was_pressed){
        if(!key_press(display,KEY)){
            key_was_pressed = false;
             //printf("up key released!\n");
            return true;
    }
}
    return false;
}


bool input::key_press(display& display, int KEY){

    if(glfwGetKey(display.get_window(),KEY)){
            //if(!key_was_pressed){
                //printf("up key has been pressed!\n");
            //}
        key_was_pressed=true;
        return true;
    }
    return false;
}

bool input::mouse_press(display& display, int button){
    if(glfwGetMouseButton(display.get_window(), button)){
        if(!button_was_pressed){
            //printf("left mouse button has been pressed!\n");
            position pos;
            mouse_pos(display,pos);
        }
        button_was_pressed = true;
        return true;
    }
    return false;
}

bool input::mouse_release(display& display, int button){
    if(button_was_pressed){
        if(!mouse_press(display,button)){
            button_was_pressed = false;
            //printf("left mouse button released!\n");
            return true;
    }
}
    return false;
}

void input::mouse_pos(display& display,position& pos){
    glfwGetCursorPos(display.get_window(), &pos.x, &pos.y);
    printf("\tX: %.0f   Y: %.0f\n", pos.x, pos.y);
}
