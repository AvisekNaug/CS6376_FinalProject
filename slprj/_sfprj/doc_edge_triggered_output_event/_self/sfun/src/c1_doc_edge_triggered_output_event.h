#ifndef __c1_doc_edge_triggered_output_event_h__
#define __c1_doc_edge_triggered_output_event_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_doc_edge_triggered_output_eventInstanceStruct
#define typedef_SFc1_doc_edge_triggered_output_eventInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c1_e1EventCounter;
  int32_T c1_sfEvent;
  uint8_T c1_tp_A;
  uint8_T c1_tp_B;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_doc_edge_triggered_output_event;
  uint8_T c1_is_c1_doc_edge_triggered_output_event;
  real_T c1_a;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_doc_edge_triggered_output_eventInstanceStruct;

#endif                                 /*typedef_SFc1_doc_edge_triggered_output_eventInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_doc_edge_triggered_output_event_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_doc_edge_triggered_output_event_get_check_sum(mxArray *plhs[]);
extern void c1_doc_edge_triggered_output_event_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
