#include "../include/chrono.h"
const static long e9 = 1000000000;

void chrono(timer_reset)(Chrono(Timer) *timer) {
	clock_gettime(CLOCK_REALTIME, &timer->begin);
}

static void print_ftime(uint64_t dt, char *buf) {
	fprintf(stderr, "chrono(%s): %lu\n", buf, dt / 1000);
}

uint64_t chrono(timer_finish)(Chrono(Timer) *timer) {
	struct timespec end;
	clock_gettime(CLOCK_REALTIME, &end);
	// make sure time does not go back
	assert(timer->begin.tv_sec < end.tv_sec || (
		timer->begin.tv_sec == end.tv_sec &&
		timer->begin.tv_nsec <= end.tv_nsec));
	long dt = (end.tv_sec - timer->begin.tv_sec) * e9 +
		end.tv_nsec - timer->begin.tv_nsec;
	return (uint64_t)dt;
}

void chrono(timer_print)(Chrono(Timer) *timer, char *buf) {
	uint64_t dt = chrono(timer_finish)(timer);
	print_ftime(dt, buf);
}

void chrono(sleep)(uint64_t t) {
	long t2 = (long)t;
	struct timespec ts = {
		.tv_sec = t2 / e9,
		.tv_nsec = t2 % e9,
	};
	nanosleep(&ts, 0);
}
