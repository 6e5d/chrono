#include "../include/chrono.h"
#define e9 1000000000
#define NS_NAME(symbol) com_6e5d_chrono_##symbol
#define NS_TYPE(symbol) Com_6e5dChrono##symbol

void NS_NAME(timer_reset)(NS_TYPE(Timer) *timer) {
	clock_gettime(CLOCK_REALTIME, &timer->begin);
}

static void print_ftime(uint64_t dt, char *buf) {
	fprintf(stderr, "chrono(%s): %lu\n", buf, dt / 1000);
}

uint64_t NS_NAME(timer_finish)(NS_TYPE(Timer) *timer) {
	StdTimespec end;
	clock_gettime(CLOCK_REALTIME, &end);
	// make sure time does not go back
	assert(timer->begin.tv_sec < end.tv_sec || (
		timer->begin.tv_sec == end.tv_sec &&
		timer->begin.tv_nsec <= end.tv_nsec));
	long dt = (end.tv_sec - timer->begin.tv_sec) * e9 +
		end.tv_nsec - timer->begin.tv_nsec;
	return (uint64_t)dt;
}

void NS_NAME(timer_print)(NS_TYPE(Timer) *timer, char *buf) {
	uint64_t dt = NS_NAME(timer_finish)(timer);
	print_ftime(dt, buf);
}

void NS_NAME(sleep)(uint64_t t) {
	long t2 = (long)t;
	StdTimespec ts = {
		.tv_sec = t2 / e9,
		.tv_nsec = t2 % e9,
	};
	nanosleep(&ts, 0);
}

#undef NS_TYPE
#undef NS_NAME
