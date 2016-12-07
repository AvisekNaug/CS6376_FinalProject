#ifndef __c1_HybridSystem_h__
#define __c1_HybridSystem_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_HybridSystemInstanceStruct
#define typedef_SFc1_HybridSystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_HybridSystem;
  uint8_T c1_tp_Reactor;
  uint8_T c1_tp_Rod1;
  uint8_T c1_tp_NoRod;
  uint8_T c1_tp_Rod2;
  uint8_T c1_tp_Controller;
  uint8_T c1_b_tp_Rod1;
  uint8_T c1_b_tp_NoRod;
  uint8_T c1_b_tp_Rod2;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_HybridSystem;
  uint8_T c1_is_c1_HybridSystem;
  uint8_T c1_is_Reactor;
  uint8_T c1_is_active_Reactor;
  uint8_T c1_is_Controller;
  uint8_T c1_is_active_Controller;
  real_T c1_cnt;
  real_T c1_x1;
  real_T c1_y1;
  real_T c1_y11;
  real_T c1_y2;
  real_T c1_y22;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_HybridSystemInstanceStruct;

#endif                                 /*typedef_SFc1_HybridSystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_HybridSystem_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_HybridSystem_get_check_sum(mxArray *plhs[]);
extern void c1_HybridSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
