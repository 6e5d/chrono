#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "../include/chrono.h"

static const long E9 = 1000000000;

void chrono_timer_reset(ChronoTimer *timer) {
	timespec_get(&timer->begin, TIME_UTC);
}

static void print_ftime(uint64_t dt, char *buf) {
	fprintf(stderr, "chrono(%s): %lu\n", buf, dt / 1000);
}

uint64_t chrono_timer_finish(ChronoTimer *timer) {
	struct timespec end;
	timespec_get(&end, TIME_UTC);
	assert(timer->begin.tv_sec < end.tv_sec ||
		timer->begin.tv_sec == end.tv_sec &&
		timer->begin.tv_nsec <= end.tv_nsec);
	long dt = (end.tv_sec - timer->begin.tv_sec) * E9 +
		end.tv_nsec - timer->begin.tv_nsec;
	return (uint64_t)dt;
}

void chrono_timer_print(ChronoTimer *timer, char *buf) {
	uint64_t dt = chrono_timer_finish(timer);
	print_ftime(dt, buf);
}

void chrono_sleep(uint64_t t) {
	long t2 = (long)t;
	struct timespec ts = {
		.tv_sec = t2 / E9,
		.tv_nsec = t2 % E9,
	};
	nanosleep(&ts, 0);
}
