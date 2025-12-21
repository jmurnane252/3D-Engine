#ifndef WINDOW_H
#define WINDOW_H

void window_init(int width, int height, const char* title);
void window_poll_events(void);
int  window_is_open(void);
int  window_should_close(void);
void window_shutdown(void);

#endif