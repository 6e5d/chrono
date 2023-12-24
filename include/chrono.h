#ifndef INCLUDEGUARD_CHRONO
#define INCLUDEGUARD_CHRONO
#define StdTimespec struct timespec

#include <time.h>
#include <sys/time.h>

typedef struct {
StdTimespec begin;
} ChronoTimer;

void chrono_timer_reset(ChronoTimer *timer);
uint64_t chrono_timer_finish(ChronoTimer *timer);
void chrono_timer_print(ChronoTimer *timer, char *buf);
void chrono_sleep(uint64_t t);

#endif
