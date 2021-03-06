#ifndef __PPC_DYNCOM_RUN_H__
#define __PPC_DYNCOM_RUN_H__

#include <skyeye_types.h>
#include <skyeye_dyncom.h>

#include "ppc_dyncom.h"
#ifdef __cplusplus
 extern "C" {
#endif

void ppc_dyncom_stop(e500_core_t* core);
exception_t init_ppc_dyncom ();
void ppc_dyncom_run(cpu_t* cpu);

void ppc_dyncom_init(e500_core_t* core);

e500_core_t* get_core_from_dyncom_cpu(cpu_t* cpu);

#ifdef __cplusplus
}
#endif

#endif
