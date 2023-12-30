#include <time.h>

typedef struct {
	struct timespec begin;
} Chrono(Timer);

void chrono(timer_reset)(Chrono(Timer) *timer);
uint64_t chrono(timer_finish)(Chrono(Timer) *timer);
void chrono(timer_print)(Chrono(Timer) *timer, char *buf);
void chrono(sleep)(uint64_t t);
