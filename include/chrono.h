#ifndef INCLUDEGUARD_CHRONO
#define INCLUDEGUARD_CHRONO

#include <time.h>
#include <sys/time.h>
#define StdTimespec struct timespec
#define NS_NAME(symbol) com_6e5d_chrono_##symbol
#define NS_TYPE(symbol) Com_6e5dChrono##symbol

typedef struct {
	StdTimespec begin;
} NS_TYPE(Timer);

void NS_NAME(timer_reset)(NS_TYPE(Timer) *timer);
uint64_t NS_NAME(timer_finish)(NS_TYPE(Timer) *timer);
void NS_NAME(timer_print)(NS_TYPE(Timer) *timer, char *buf);
void NS_NAME(sleep)(uint64_t t);

#undef NS_TYPE
#undef NS_NAME
#endif
