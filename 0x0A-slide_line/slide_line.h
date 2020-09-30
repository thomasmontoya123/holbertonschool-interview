#ifndef _SLIDE_H_
#define _SLIDE_H_

#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0

#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);



#endif /* _SLIDE_H_ */
