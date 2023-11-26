#ifndef INCLUDEGUARD_CHRONO_CHRONOH
#define INCLUDEGUARD_CHRONO_CHRONOH

#include <stdint.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
struct timespec begin;
} ChronoTimer;

void chrono_timer_reset(ChronoTimer *timer);
uint64_t chrono_timer_finish(ChronoTimer *timer);
void chrono_timer_print(ChronoTimer *timer, char *buf);
void chrono_sleep(uint64_t t);

#endif
