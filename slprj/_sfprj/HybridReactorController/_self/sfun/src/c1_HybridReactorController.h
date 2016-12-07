#ifndef __c1_HybridReactorController_h__
#define __c1_HybridReactorController_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_HybridReactorControllerInstanceStruct
#define typedef_SFc1_HybridReactorControllerInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_Rod1;
  uint8_T c1_tp_NoRod;
  uint8_T c1_tp_Rod2;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_HybridReactorController;
  uint8_T c1_is_c1_HybridReactorController;
  real_T c1_x1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_HybridReactorControllerInstanceStruct;

#endif                                 /*typedef_SFc1_HybridReactorControllerInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_HybridReactorController_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_HybridReactorController_get_check_sum(mxArray *plhs[]);
extern void c1_HybridReactorController_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
