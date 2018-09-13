#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <vector>
#include "display.h"

struct position{
    double x,y;
};

class input{
private :

public :

input();

~input();


bool key_was_pressed = false;

bool button_was_pressed = false;

bool key_released(display& display, int KEY);


bool key_press(display& display, int KEY);

bool mouse_press(display& display, int button);

bool mouse_release(display& display, int button);

void mouse_pos(display& display,position& pos);
};

#endif // INPUT_H_INCLUDED
