#ifndef TIME_H
#define TIME_H

void time_init(void);
void time_update(void);

float time_delta(void);
float time_fixed_step(void);

#endif