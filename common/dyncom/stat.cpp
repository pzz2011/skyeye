#include "skyeye_dyncom.h"
#if HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#else
#include <time.h>
#endif

void update_timing(cpu_t *cpu, int index, bool start)
{
	uint64_t usec;

	if ((cpu->dyncom_engine->flags_debug & CPU_DEBUG_PROFILE) == 0)
		return;

#if HAVE_GETRUSAGE
	struct rusage r_usage;
	getrusage(RUSAGE_SELF, &r_usage);
	usec = ((uint64_t)r_usage.ru_utime.tv_sec * 1000000) + r_usage.ru_utime.tv_usec;
#else
	usec = (uint64_t)clock()/CLOCKS_PER_SEC;
#endif

	if (start)
		cpu->timer_start[index] = usec;
	else
		cpu->timer_total[index] += usec - cpu->timer_start[index];
}
