#ifndef __c2_HybridReactorController_h__
#define __c2_HybridReactorController_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc2_HybridReactorControllerInstanceStruct
#define typedef_SFc2_HybridReactorControllerInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c2_add1EventCounter;
  uint32_T c2_add2EventCounter;
  uint32_T c2_remove1EventCounter;
  uint32_T c2_remove2EventCounter;
  uint32_T c2_StartEventCounter;
  int32_T c2_sfEvent;
  uint8_T c2_tp_Rod1;
  uint8_T c2_tp_NoRod;
  uint8_T c2_tp_Rod2;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_HybridReactorController;
  uint8_T c2_is_c2_HybridReactorController;
  real_T c2_i;
  real_T c2_y11;
  real_T c2_y22;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_HybridReactorControllerInstanceStruct;

#endif                                 /*typedef_SFc2_HybridReactorControllerInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_HybridReactorController_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_HybridReactorController_get_check_sum(mxArray *plhs[]);
extern void c2_HybridReactorController_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
