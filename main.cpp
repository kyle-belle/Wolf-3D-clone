#include "display.h"
#include "engine.h"
#include "mesh.h"
#include "obj_loader.h"

int  WIDTH = 600;
int HEIGHT = 450;
char NAME[] = "WOLF 3D";
double FRAME_CAP = 5000.0;


int main(){
    display display(NAME, WIDTH, HEIGHT, FRAME_CAP);
    gameloop gameloop(display);
}
