/* Include files */

#include <stddef.h>
#include "blas.h"
#include "doc_edge_triggered_output_event_sfun.h"
#include "c1_doc_edge_triggered_output_event.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "doc_edge_triggered_output_event_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_A                        ((uint8_T)1U)
#define c1_IN_B                        ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void initialize_params_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void enable_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void disable_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void set_sim_state_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void finalize_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void sf_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void initSimStructsc1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void registerMessagesc1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static uint32_T c1_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_e1EventCounter, const char_T *c1_identifier);
static uint32_T c1_b_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_A, const char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_f_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_a, const char_T *c1_identifier);
static real_T c1_g_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static boolean_T c1_h_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_e1, const char_T *c1_identifier);
static boolean_T c1_i_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_k_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  boolean_T *c1_e1;
  c1_e1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_A = 0U;
  chartInstance->c1_tp_B = 0U;
  chartInstance->c1_is_active_c1_doc_edge_triggered_output_event = 0U;
  chartInstance->c1_is_c1_doc_edge_triggered_output_event =
    c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_a = 0.0;
  chartInstance->c1_e1EventCounter = 0U;
  *c1_e1 = FALSE;
}

static void initialize_params_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
}

static void enable_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_doc_edge_triggered_output_event == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_doc_edge_triggered_output_event == c1_IN_A) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_doc_edge_triggered_output_event == c1_IN_B) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_b_hoistedGlobal;
  boolean_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint32_T c1_c_hoistedGlobal;
  uint32_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  boolean_T *c1_e1;
  c1_e1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(5), FALSE);
  c1_hoistedGlobal = chartInstance->c1_a;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_e1;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_e1EventCounter;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal =
    chartInstance->c1_is_active_c1_doc_edge_triggered_output_event;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_is_c1_doc_edge_triggered_output_event;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_e1;
  c1_e1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  chartInstance->c1_a = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "a");
  *c1_e1 = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "e1");
  chartInstance->c1_e1EventCounter = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "e1EventCounter");
  chartInstance->c1_is_active_c1_doc_edge_triggered_output_event =
    c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "is_active_c1_doc_edge_triggered_output_event");
  chartInstance->c1_is_c1_doc_edge_triggered_output_event =
    c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
    "is_c1_doc_edge_triggered_output_event");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_doc_edge_triggered_output_event(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_doc_edge_triggered_output_event == c1_IN_A) {
      chartInstance->c1_tp_A = 1U;
    } else {
      chartInstance->c1_tp_A = 0U;
    }

    if (chartInstance->c1_is_c1_doc_edge_triggered_output_event == c1_IN_B) {
      chartInstance->c1_tp_B = 1U;
    } else {
      chartInstance->c1_tp_B = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T *c1_e1;
  c1_e1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_doc_edge_triggered_output_event(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_a, 0U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_doc_edge_triggered_output_event == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_doc_edge_triggered_output_event = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_doc_edge_triggered_output_event = c1_IN_A;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_A = 1U;
  } else {
    switch (chartInstance->c1_is_c1_doc_edge_triggered_output_event) {
     case c1_IN_A:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c1_sfEvent);
      c1_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0U, 0,
                  chartInstance->c1_a == 1.0 != 0U, chartInstance->c1_sfEvent))
                != 0);
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_A = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_doc_edge_triggered_output_event = c1_IN_B;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_B = 1U;
        chartInstance->c1_e1EventCounter++;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_a = 1.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_a, 0U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_B:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      c1_b_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
        chartInstance->c1_a == 0.0 != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_B = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_doc_edge_triggered_output_event = c1_IN_A;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_A = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_a = 0.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_a, 0U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c1_is_c1_doc_edge_triggered_output_event =
        c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_e1EventCounter > 0U) {
    *c1_e1 = !*c1_e1;
    chartInstance->c1_e1EventCounter--;
  }

  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_doc_edge_triggered_output_eventMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_doc_edge_triggered_output_event
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray
  *sf_c1_doc_edge_triggered_output_event_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint32_T c1_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_e1EventCounter, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_e1EventCounter),
    &c1_thisId);
  sf_mex_destroy(&c1_b_e1EventCounter);
  return c1_y;
}

static uint32_T c1_b_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_e1EventCounter;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint32_T c1_y;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_b_e1EventCounter = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_e1EventCounter),
    &c1_thisId);
  sf_mex_destroy(&c1_b_e1EventCounter);
  *(uint32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_A, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_A), &c1_thisId);
  sf_mex_destroy(&c1_b_tp_A);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_A;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_b_tp_A = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_A), &c1_thisId);
  sf_mex_destroy(&c1_b_tp_A);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_f_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_a, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_a), &c1_thisId);
  sf_mex_destroy(&c1_b_a);
  return c1_y;
}

static real_T c1_g_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_a;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
    chartInstanceVoid;
  c1_b_a = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_a), &c1_thisId);
  sf_mex_destroy(&c1_b_a);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static boolean_T c1_h_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_e1, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e1), &c1_thisId);
  sf_mex_destroy(&c1_e1);
  return c1_y;
}

static boolean_T c1_i_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_k_emlrt_marshallIn
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_doc_edge_triggered_output_event_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(759178714U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4210500758U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3165153757U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1476432262U);
}

mxArray *sf_c1_doc_edge_triggered_output_event_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("EbmrvnuthMRLDTAqufCu3G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_doc_edge_triggered_output_event_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_doc_edge_triggered_output_event
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[3],M[6],T\"a\",},{M[6],M[7],T\"e1\",},{M[7],M[7],T\"e1EventCounter\",},{M[8],M[0],T\"is_active_c1_doc_edge_triggered_output_event\",},{M[9],M[0],T\"is_c1_doc_edge_triggered_output_event\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_doc_edge_triggered_output_event_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
    chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _doc_edge_triggered_output_eventMachineNumber_,
           1,
           2,
           3,
           1,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_doc_edge_triggered_output_eventMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _doc_edge_triggered_output_eventMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _doc_edge_triggered_output_eventMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"a");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(2,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c1_a);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _doc_edge_triggered_output_eventMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "IsnrZ9eWef7FGCIOOHAcxG";
}

static void sf_opaque_initialize_c1_doc_edge_triggered_output_event(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar);
  initialize_c1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_doc_edge_triggered_output_event(void
  *chartInstanceVar)
{
  enable_c1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_doc_edge_triggered_output_event(void
  *chartInstanceVar)
{
  disable_c1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_doc_edge_triggered_output_event(void
  *chartInstanceVar)
{
  sf_c1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_doc_edge_triggered_output_event(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_doc_edge_triggered_output_event();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_doc_edge_triggered_output_event
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_doc_edge_triggered_output_event();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_doc_edge_triggered_output_event
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_doc_edge_triggered_output_event(S);
}

static void sf_opaque_set_sim_state_c1_doc_edge_triggered_output_event(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_doc_edge_triggered_output_event(S, st);
}

static void sf_opaque_terminate_c1_doc_edge_triggered_output_event(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_doc_edge_triggered_output_eventInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_doc_edge_triggered_output_event_optimization_info();
    }

    finalize_c1_doc_edge_triggered_output_event
      ((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_doc_edge_triggered_output_event
    ((SFc1_doc_edge_triggered_output_eventInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_doc_edge_triggered_output_event(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_doc_edge_triggered_output_event
      ((SFc1_doc_edge_triggered_output_eventInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_doc_edge_triggered_output_event(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_doc_edge_triggered_output_event_optimization_info
      ();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3234071331U));
  ssSetChecksum1(S,(1155236414U));
  ssSetChecksum2(S,(67700656U));
  ssSetChecksum3(S,(844731174U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_doc_edge_triggered_output_event(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_doc_edge_triggered_output_event(SimStruct *S)
{
  SFc1_doc_edge_triggered_output_eventInstanceStruct *chartInstance;
  chartInstance = (SFc1_doc_edge_triggered_output_eventInstanceStruct *)utMalloc
    (sizeof(SFc1_doc_edge_triggered_output_eventInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_doc_edge_triggered_output_eventInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_doc_edge_triggered_output_event;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_doc_edge_triggered_output_event_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_doc_edge_triggered_output_event(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_doc_edge_triggered_output_event(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_doc_edge_triggered_output_event(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_doc_edge_triggered_output_event_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
