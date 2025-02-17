#ifndef __BEEP_H
#define __BEEP_H

#include "reg.h"
#define ON  1
#define OFF 0

void init_beep(void);
void beep_switch(int status);

#endif