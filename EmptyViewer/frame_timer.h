#pragma once

void init_timer();
void start_timing();
float stop_timing();
void display();  // �Ǵ� display1()

extern float gTotalTimeElapsed;
extern int gTotalFrames;
extern unsigned int gTimer;
