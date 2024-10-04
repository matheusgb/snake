#ifndef MAIN_H
#define MAIN_H

#include <deque>
#include "raylib.h"

bool EventTriggered(double interval);
bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);



#endif
