/* Include files */

#include <stddef.h>
#include "blas.h"
#include "HybridSystem_sfun.h"
#include "c1_HybridSystem.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HybridSystem_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_add1                  (0)
#define c1_event_add2                  (1)
#define c1_event_remove1               (2)
#define c1_event_remove2               (3)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_HybridSystem             ((uint8_T)1U)
#define c1_IN_NoRod                    ((uint8_T)1U)
#define c1_IN_Rod1                     ((uint8_T)2U)
#define c1_IN_Rod2                     ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance);
static void initialize_params_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance);
static void enable_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance);
static void disable_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_HybridSystem
  (SFc1_HybridSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_HybridSystem
  (SFc1_HybridSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_HybridSystem
  (SFc1_HybridSystemInstanceStruct *chartInstance);
static void finalize_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance);
static void sf_c1_HybridSystem(SFc1_HybridSystemInstanceStruct *chartInstance);
static void initSimStructsc1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance);
static void registerMessagesc1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance);
static void c1_HybridSystem(SFc1_HybridSystemInstanceStruct *chartInstance);
static void c1_Controller(SFc1_HybridSystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_increment(SFc1_HybridSystemInstanceStruct *chartInstance,
  real_T c1_b_x1, real_T c1_b_cnt);
static real_T c1_timer1(SFc1_HybridSystemInstanceStruct *chartInstance, real_T
  c1_b_y11);
static real_T c1_timer2(SFc1_HybridSystemInstanceStruct *chartInstance, real_T
  c1_b_y22);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_b_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_HybridSystem, const char_T
  *c1_identifier);
static uint8_T c1_c_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_d_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_x, const char_T *c1_identifier);
static real_T c1_e_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_g_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_HybridSystemInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance)
{
  real_T *c1_x;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_HybridSystem = 0U;
  chartInstance->c1_is_active_Controller = 0U;
  chartInstance->c1_is_Controller = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Controller = 0U;
  chartInstance->c1_b_tp_NoRod = 0U;
  chartInstance->c1_b_tp_Rod1 = 0U;
  chartInstance->c1_b_tp_Rod2 = 0U;
  chartInstance->c1_is_active_Reactor = 0U;
  chartInstance->c1_is_Reactor = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_Reactor = 0U;
  chartInstance->c1_tp_NoRod = 0U;
  chartInstance->c1_tp_Rod1 = 0U;
  chartInstance->c1_tp_Rod2 = 0U;
  chartInstance->c1_is_active_c1_HybridSystem = 0U;
  chartInstance->c1_is_c1_HybridSystem = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_cnt = 0.0;
  chartInstance->c1_x1 = 0.0;
  chartInstance->c1_y1 = 0.0;
  chartInstance->c1_y11 = 0.0;
  chartInstance->c1_y2 = 0.0;
  chartInstance->c1_y22 = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_x = 0.0;
  }
}

static void initialize_params_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance)
{
}

static void enable_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c1_is_active_Reactor == 1U) {
    sf_call_output_fcn_enable(chartInstance->S, 0, "increment", 0);
  }

  if (chartInstance->c1_is_active_Controller == 1U) {
    sf_call_output_fcn_enable(chartInstance->S, 1, "timer1", 0);
    sf_call_output_fcn_enable(chartInstance->S, 2, "timer2", 0);
  }
}

static void disable_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c1_is_active_Reactor == 1U) {
    sf_call_output_fcn_disable(chartInstance->S, 0, "increment", 0);
  }

  if (chartInstance->c1_is_active_Controller == 1U) {
    sf_call_output_fcn_disable(chartInstance->S, 1, "timer1", 0);
    sf_call_output_fcn_disable(chartInstance->S, 2, "timer2", 0);
  }
}

static void c1_update_debugger_state_c1_HybridSystem
  (SFc1_HybridSystemInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_HybridSystem == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_HybridSystem == c1_IN_HybridSystem) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Reactor == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Reactor == c1_IN_Rod1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Reactor == c1_IN_NoRod) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Reactor == c1_IN_Rod2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Controller == c1_IN_Rod1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Controller == c1_IN_NoRod) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_Controller == c1_IN_Rod2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_HybridSystem
  (SFc1_HybridSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  uint8_T c1_h_hoistedGlobal;
  uint8_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  uint8_T c1_i_hoistedGlobal;
  uint8_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  uint8_T c1_j_hoistedGlobal;
  uint8_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  uint8_T c1_k_hoistedGlobal;
  uint8_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  uint8_T c1_l_hoistedGlobal;
  uint8_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  uint8_T c1_m_hoistedGlobal;
  uint8_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  real_T *c1_x;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(13), FALSE);
  c1_hoistedGlobal = *c1_x;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_cnt;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_x1;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_y1;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_y11;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_y2;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = chartInstance->c1_y22;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_is_active_c1_HybridSystem;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = chartInstance->c1_is_active_Reactor;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_is_active_Controller;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = chartInstance->c1_is_c1_HybridSystem;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = chartInstance->c1_is_Reactor;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = chartInstance->c1_is_Controller;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_x;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_x = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "x");
  chartInstance->c1_cnt = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "cnt");
  chartInstance->c1_x1 = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "x1");
  chartInstance->c1_y1 = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "y1");
  chartInstance->c1_y11 = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "y11");
  chartInstance->c1_y2 = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "y2");
  chartInstance->c1_y22 = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "y22");
  chartInstance->c1_is_active_c1_HybridSystem = c1_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
     "is_active_c1_HybridSystem");
  chartInstance->c1_is_active_Reactor = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 8)), "is_active_Reactor");
  chartInstance->c1_is_active_Controller = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 9)), "is_active_Controller");
  chartInstance->c1_is_c1_HybridSystem = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 10)), "is_c1_HybridSystem");
  chartInstance->c1_is_Reactor = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "is_Reactor");
  chartInstance->c1_is_Controller = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 12)), "is_Controller");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 13)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_HybridSystem(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_HybridSystem
  (SFc1_HybridSystemInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_HybridSystem == c1_IN_HybridSystem) {
      chartInstance->c1_tp_HybridSystem = 1U;
    } else {
      chartInstance->c1_tp_HybridSystem = 0U;
    }

    if (chartInstance->c1_is_active_Reactor == 1U) {
      chartInstance->c1_tp_Reactor = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        sf_call_output_fcn_enable(chartInstance->S, 0, "increment", 0);
      }
    } else {
      chartInstance->c1_tp_Reactor = 0U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) > 0.0) {
        sf_call_output_fcn_disable(chartInstance->S, 0, "increment", 0);
      }
    }

    if (chartInstance->c1_is_Reactor == c1_IN_NoRod) {
      chartInstance->c1_tp_NoRod = 1U;
    } else {
      chartInstance->c1_tp_NoRod = 0U;
    }

    if (chartInstance->c1_is_Reactor == c1_IN_Rod1) {
      chartInstance->c1_tp_Rod1 = 1U;
    } else {
      chartInstance->c1_tp_Rod1 = 0U;
    }

    if (chartInstance->c1_is_Reactor == c1_IN_Rod2) {
      chartInstance->c1_tp_Rod2 = 1U;
    } else {
      chartInstance->c1_tp_Rod2 = 0U;
    }

    if (chartInstance->c1_is_active_Controller == 1U) {
      chartInstance->c1_tp_Controller = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        sf_call_output_fcn_enable(chartInstance->S, 1, "timer1", 0);
        sf_call_output_fcn_enable(chartInstance->S, 2, "timer2", 0);
      }
    } else {
      chartInstance->c1_tp_Controller = 0U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) > 0.0) {
        sf_call_output_fcn_disable(chartInstance->S, 1, "timer1", 0);
        sf_call_output_fcn_disable(chartInstance->S, 2, "timer2", 0);
      }
    }

    if (chartInstance->c1_is_Controller == c1_IN_NoRod) {
      chartInstance->c1_b_tp_NoRod = 1U;
    } else {
      chartInstance->c1_b_tp_NoRod = 0U;
    }

    if (chartInstance->c1_is_Controller == c1_IN_Rod1) {
      chartInstance->c1_b_tp_Rod1 = 1U;
    } else {
      chartInstance->c1_b_tp_Rod1 = 0U;
    }

    if (chartInstance->c1_is_Controller == c1_IN_Rod2) {
      chartInstance->c1_b_tp_Rod2 = 1U;
    } else {
      chartInstance->c1_b_tp_Rod2 = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_HybridSystem(SFc1_HybridSystemInstanceStruct *chartInstance)
{
  real_T *c1_x;
  real_T *c1_c;
  c1_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_HybridSystem(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_HybridSystem == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_HybridSystem = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_HybridSystem = c1_IN_HybridSystem;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_HybridSystem = 1U;
    chartInstance->c1_cnt = 0.0;
    if (chartInstance->c1_is_active_Reactor == 1U) {
    } else {
      chartInstance->c1_is_active_Reactor = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Reactor = 1U;
      chartInstance->c1_x1 = 0.0;
      sf_call_output_fcn_enable(chartInstance->S, 0, "increment", 0);
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    *c1_x = 510.0;
    if (chartInstance->c1_is_Reactor == c1_IN_NoRod) {
    } else {
      chartInstance->c1_is_Reactor = c1_IN_NoRod;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_NoRod = 1U;
      chartInstance->c1_x1 = *c1_x;
      chartInstance->c1_cnt = 50.0;
    }

    if (chartInstance->c1_is_active_Controller == 1U) {
    } else {
      chartInstance->c1_is_active_Controller = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Controller = 1U;
      chartInstance->c1_y1 = 0.0;
      chartInstance->c1_y11 = 0.0;
      chartInstance->c1_y2 = 0.0;
      chartInstance->c1_y22 = 0.0;
      sf_call_output_fcn_enable(chartInstance->S, 1, "timer1", 0);
      sf_call_output_fcn_enable(chartInstance->S, 2, "timer2", 0);
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_y1 = *c1_c;
    chartInstance->c1_y2 = *c1_c;
    if (chartInstance->c1_is_Controller == c1_IN_NoRod) {
    } else {
      chartInstance->c1_is_Controller = c1_IN_NoRod;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_NoRod = 1U;
      chartInstance->c1_y11 = chartInstance->c1_y1;
      chartInstance->c1_y22 = chartInstance->c1_y2;
    }
  } else if (chartInstance->c1_is_c1_HybridSystem != c1_IN_HybridSystem) {
  } else {
    c1_HybridSystem(chartInstance);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_HybridSystemMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_HybridSystem(SFc1_HybridSystemInstanceStruct
  *chartInstance)
{
}

static void c1_HybridSystem(SFc1_HybridSystemInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  real_T *c1_x;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_Reactor == 0U) {
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_Reactor) {
     case c1_IN_NoRod:
      CV_STATE_EVAL(7, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c1_sfEvent);
      c1_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
                  chartInstance->c1_sfEvent == c1_event_add1 != 0U,
                  chartInstance->c1_sfEvent)) != 0);
      if (c1_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 3;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c1_b_out = (chartInstance->c1_sfEvent == c1_event_add2);
          if (c1_b_out) {
            transitionList[numTransitions] = 5;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_NoRod = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_Reactor = c1_IN_Rod1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Rod1 = 1U;
        chartInstance->c1_x1 = *c1_x;
        chartInstance->c1_cnt = 56.0;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c1_sfEvent);
        c1_c_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
          chartInstance->c1_sfEvent == c1_event_add2 != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_NoRod = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_Reactor = c1_IN_Rod2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_Rod2 = 1U;
          chartInstance->c1_x1 = *c1_x;
          chartInstance->c1_cnt = 60.0;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                       chartInstance->c1_sfEvent);
          *c1_x = c1_increment(chartInstance, chartInstance->c1_x1,
                               chartInstance->c1_cnt);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_Rod1:
      CV_STATE_EVAL(7, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c1_sfEvent);
      c1_d_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
        chartInstance->c1_sfEvent == c1_event_remove1 != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Rod1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_Reactor = c1_IN_NoRod;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_NoRod = 1U;
        chartInstance->c1_x1 = *c1_x;
        chartInstance->c1_cnt = 50.0;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                     chartInstance->c1_sfEvent);
        *c1_x = c1_increment(chartInstance, chartInstance->c1_x1,
                             chartInstance->c1_cnt);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_Rod2:
      CV_STATE_EVAL(7, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c1_sfEvent);
      c1_e_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0,
        chartInstance->c1_sfEvent == c1_event_remove2 != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Rod2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_Reactor = c1_IN_NoRod;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_NoRod = 1U;
        chartInstance->c1_x1 = *c1_x;
        chartInstance->c1_cnt = 50.0;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     chartInstance->c1_sfEvent);
        *c1_x = c1_increment(chartInstance, chartInstance->c1_x1,
                             chartInstance->c1_cnt);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(7, 0, 0);
      chartInstance->c1_is_Reactor = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_Controller == 0U) {
  } else {
    c1_Controller(chartInstance);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void c1_Controller(SFc1_HybridSystemInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  boolean_T c1_out;
  boolean_T c1_b_out;
  int32_T c1_previousEvent;
  boolean_T c1_c_temp;
  boolean_T c1_c_out;
  int32_T c1_b_previousEvent;
  boolean_T c1_d_out;
  int32_T c1_c_previousEvent;
  boolean_T c1_e_out;
  int32_T c1_d_previousEvent;
  real_T *c1_x;
  real_T *c1_c;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_Controller) {
   case c1_IN_NoRod:
    CV_STATE_EVAL(1, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c1_sfEvent);
    c1_temp = (_SFD_CCP_CALL(7U, 0, *c1_x >= 550.0 != 0U,
                chartInstance->c1_sfEvent) != 0);
    if (c1_temp) {
      c1_temp = (_SFD_CCP_CALL(7U, 1, chartInstance->c1_y1 >= *c1_c != 0U,
                  chartInstance->c1_sfEvent) != 0);
    }

    c1_b_temp = c1_temp;
    if (c1_b_temp) {
      c1_b_temp = (_SFD_CCP_CALL(7U, 2, chartInstance->c1_y2 < *c1_c != 0U,
        chartInstance->c1_sfEvent) != 0);
    }

    c1_out = (CV_TRANSITION_EVAL(7U, (int32_T)c1_b_temp) != 0);
    guard3 = FALSE;
    if (c1_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 7;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        c1_b_out = ((*c1_x >= 550.0) && (chartInstance->c1_y2 >= *c1_c));
        if (c1_b_out) {
          transitionList[numTransitions] = 9;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_NoRod = 0U;
      chartInstance->c1_is_Controller = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 7U,
                   chartInstance->c1_sfEvent);
      c1_previousEvent = chartInstance->c1_sfEvent;
      chartInstance->c1_sfEvent = c1_event_add1;
      _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_add1,
                   chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_c1_HybridSystem != c1_IN_HybridSystem) {
      } else {
        c1_HybridSystem(chartInstance);
      }

      _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_add1,
                   chartInstance->c1_sfEvent);
      chartInstance->c1_sfEvent = c1_previousEvent;
      if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c1_is_active_Controller == 0U) {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
        }
      } else {
        _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      }

      if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c1_is_active_Controller == 0U) {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
        } else {
          chartInstance->c1_is_Controller = c1_IN_Rod1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
          chartInstance->c1_b_tp_Rod1 = 1U;
          chartInstance->c1_y11 = chartInstance->c1_y1;
          chartInstance->c1_y22 = chartInstance->c1_y2;
          guard3 = TRUE;
        }
      } else {
        _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c1_sfEvent);
      c1_c_temp = (_SFD_CCP_CALL(9U, 0, *c1_x >= 550.0 != 0U,
        chartInstance->c1_sfEvent) != 0);
      if (c1_c_temp) {
        c1_c_temp = (_SFD_CCP_CALL(9U, 1, chartInstance->c1_y2 >= *c1_c != 0U,
          chartInstance->c1_sfEvent) != 0);
      }

      c1_c_out = (CV_TRANSITION_EVAL(9U, (int32_T)c1_c_temp) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        chartInstance->c1_b_tp_NoRod = 0U;
        chartInstance->c1_is_Controller = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 9U,
                     chartInstance->c1_sfEvent);
        c1_b_previousEvent = chartInstance->c1_sfEvent;
        chartInstance->c1_sfEvent = c1_event_add2;
        _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_add2,
                     chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_c1_HybridSystem != c1_IN_HybridSystem) {
        } else {
          c1_HybridSystem(chartInstance);
        }

        _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_add2,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_sfEvent = c1_b_previousEvent;
        if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
          if (chartInstance->c1_is_active_Controller == 0U) {
            _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        }

        if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
          if (chartInstance->c1_is_active_Controller == 0U) {
            _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
          } else {
            chartInstance->c1_is_Controller = c1_IN_Rod2;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
            chartInstance->c1_b_tp_Rod2 = 1U;
            chartInstance->c1_y11 = chartInstance->c1_y1;
            chartInstance->c1_y22 = chartInstance->c1_y2;
            guard3 = TRUE;
          }
        } else {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        }
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_y1 = c1_timer1(chartInstance, chartInstance->c1_y11);
        chartInstance->c1_y2 = c1_timer2(chartInstance, chartInstance->c1_y22);
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    }
    break;

   case c1_IN_Rod1:
    CV_STATE_EVAL(1, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c1_sfEvent);
    c1_d_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0, *c1_x <=
      510.0 != 0U, chartInstance->c1_sfEvent)) != 0);
    guard2 = FALSE;
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Rod1 = 0U;
      chartInstance->c1_is_Controller = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 8U,
                   chartInstance->c1_sfEvent);
      c1_c_previousEvent = chartInstance->c1_sfEvent;
      chartInstance->c1_sfEvent = c1_event_remove1;
      _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_remove1,
                   chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_c1_HybridSystem != c1_IN_HybridSystem) {
      } else {
        c1_HybridSystem(chartInstance);
      }

      _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_remove1,
                   chartInstance->c1_sfEvent);
      chartInstance->c1_sfEvent = c1_c_previousEvent;
      if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c1_is_active_Controller == 0U) {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
        } else {
          chartInstance->c1_y1 = 0.0;
        }
      } else {
        _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      }

      if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c1_is_active_Controller == 0U) {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
        } else {
          chartInstance->c1_is_Controller = c1_IN_NoRod;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_b_tp_NoRod = 1U;
          chartInstance->c1_y11 = chartInstance->c1_y1;
          chartInstance->c1_y22 = chartInstance->c1_y2;
          guard2 = TRUE;
        }
      } else {
        _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c1_sfEvent);
      chartInstance->c1_y1 = c1_timer1(chartInstance, chartInstance->c1_y11);
      chartInstance->c1_y2 = c1_timer2(chartInstance, chartInstance->c1_y22);
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    }
    break;

   case c1_IN_Rod2:
    CV_STATE_EVAL(1, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c1_sfEvent);
    c1_e_out = (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10U, 0, *c1_x <=
      510.0 != 0U, chartInstance->c1_sfEvent)) != 0);
    guard1 = FALSE;
    if (c1_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Rod2 = 0U;
      chartInstance->c1_is_Controller = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 10U,
                   chartInstance->c1_sfEvent);
      c1_d_previousEvent = chartInstance->c1_sfEvent;
      chartInstance->c1_sfEvent = c1_event_remove2;
      _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_remove2,
                   chartInstance->c1_sfEvent);
      if (chartInstance->c1_is_c1_HybridSystem != c1_IN_HybridSystem) {
      } else {
        c1_HybridSystem(chartInstance);
      }

      _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_remove2,
                   chartInstance->c1_sfEvent);
      chartInstance->c1_sfEvent = c1_d_previousEvent;
      if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c1_is_active_Controller == 0U) {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        } else {
          chartInstance->c1_y2 = 0.0;
        }
      } else {
        _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      }

      if (chartInstance->c1_is_Controller == c1_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c1_is_active_Controller == 0U) {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        } else {
          chartInstance->c1_is_Controller = c1_IN_NoRod;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_b_tp_NoRod = 1U;
          chartInstance->c1_y11 = chartInstance->c1_y1;
          chartInstance->c1_y22 = chartInstance->c1_y2;
          guard1 = TRUE;
        }
      } else {
        _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c1_sfEvent);
      chartInstance->c1_y1 = c1_timer1(chartInstance, chartInstance->c1_y11);
      chartInstance->c1_y2 = c1_timer2(chartInstance, chartInstance->c1_y22);
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
    }
    break;

   default:
    CV_STATE_EVAL(1, 0, 0);
    chartInstance->c1_is_Controller = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_HybridSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static real_T c1_increment(SFc1_HybridSystemInstanceStruct *chartInstance,
  real_T c1_b_x1, real_T c1_b_cnt)
{
  real_T c1_x;
  real_T *c1_c_x1;
  real_T *c1_c_cnt;
  real_T *c1_b_x;
  c1_c_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_c_x1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SET_DATA_VALUE_PTR(4U, &c1_x);
  _SFD_SET_DATA_VALUE_PTR(6U, &c1_b_cnt);
  _SFD_SET_DATA_VALUE_PTR(5U, &c1_b_x1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(3U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("x1", &c1_b_x1, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("cnt", &c1_b_cnt, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("x", &c1_x, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  *c1_c_x1 = c1_b_x1;
  *c1_c_cnt = c1_b_cnt;
  sf_call_output_fcn_call(chartInstance->S, 0, "increment", 0);
  c1_x = *c1_b_x;
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(4U);
  _SFD_UNSET_DATA_VALUE_PTR(6U);
  _SFD_UNSET_DATA_VALUE_PTR(5U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  return c1_x;
}

static real_T c1_timer1(SFc1_HybridSystemInstanceStruct *chartInstance, real_T
  c1_b_y11)
{
  real_T c1_b_y1;
  real_T *c1_c_y11;
  real_T *c1_c_y1;
  c1_c_y1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_c_y11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  _SFD_SET_DATA_VALUE_PTR(12U, &c1_b_y1);
  _SFD_SET_DATA_VALUE_PTR(11U, &c1_b_y11);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(2U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y11", &c1_b_y11, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y1", &c1_b_y1, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  *c1_c_y11 = c1_b_y11;
  sf_call_output_fcn_call(chartInstance->S, 1, "timer1", 0);
  c1_b_y1 = *c1_c_y1;
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(12U);
  _SFD_UNSET_DATA_VALUE_PTR(11U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  return c1_b_y1;
}

static real_T c1_timer2(SFc1_HybridSystemInstanceStruct *chartInstance, real_T
  c1_b_y22)
{
  real_T c1_b_y2;
  real_T *c1_c_y22;
  real_T *c1_c_y2;
  c1_c_y2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_c_y22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  _SFD_SET_DATA_VALUE_PTR(14U, &c1_b_y2);
  _SFD_SET_DATA_VALUE_PTR(13U, &c1_b_y22);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(2U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y22", &c1_b_y22, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y2", &c1_b_y2, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
  *c1_c_y22 = c1_b_y22;
  sf_call_output_fcn_call(chartInstance->S, 2, "timer2", 0);
  c1_b_y2 = *c1_c_y2;
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(14U);
  _SFD_UNSET_DATA_VALUE_PTR(13U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
  return c1_b_y2;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_HybridSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_HybridSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_HybridSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_HybridSystemInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_HybridSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_HybridSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_HybridSystem, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_HybridSystem),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_HybridSystem);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_HybridSystem;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_HybridSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_HybridSystemInstanceStruct *)chartInstanceVoid;
  c1_b_tp_HybridSystem = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_HybridSystem),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_HybridSystem);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_HybridSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_HybridSystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_d_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_x, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_x), &c1_thisId);
  sf_mex_destroy(&c1_x);
  return c1_y;
}

static real_T c1_e_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_x;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_HybridSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_HybridSystemInstanceStruct *)chartInstanceVoid;
  c1_x = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_x), &c1_thisId);
  sf_mex_destroy(&c1_x);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_g_emlrt_marshallIn(SFc1_HybridSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_HybridSystemInstanceStruct *chartInstance)
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

void sf_c1_HybridSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1879516476U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2073187215U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3378118762U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3974662544U);
}

mxArray *sf_c1_HybridSystem_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("pxSZFSjfSTLL3XZpiUz1oF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_HybridSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_HybridSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[15],T\"x\",},{M[3],M[38],T\"cnt\",},{M[3],M[19],T\"x1\",},{M[3],M[25],T\"y1\",},{M[3],M[26],T\"y11\",},{M[3],M[27],T\"y2\",},{M[3],M[28],T\"y22\",},{M[8],M[0],T\"is_active_c1_HybridSystem\",},{M[8],M[1],T\"is_active_Reactor\",},{M[8],M[2],T\"is_active_Controller\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[9],M[0],T\"is_c1_HybridSystem\",},{M[9],M[1],T\"is_Reactor\",},{M[9],M[2],T\"is_Controller\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_HybridSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_HybridSystemInstanceStruct *chartInstance;
    chartInstance = (SFc1_HybridSystemInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _HybridSystemMachineNumber_,
           1,
           12,
           11,
           15,
           4,
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
          init_script_number_translation(_HybridSystemMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_HybridSystemMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _HybridSystemMachineNumber_,
            chartInstance->chartNumber,
            4,
            4,
            4);
          _SFD_SET_DATA_PROPS(0,2,0,1,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"c");
          _SFD_SET_DATA_PROPS(2,0,0,0,"cnt");
          _SFD_SET_DATA_PROPS(3,0,0,0,"x1");
          _SFD_SET_DATA_PROPS(4,9,0,0,"");
          _SFD_SET_DATA_PROPS(5,8,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,0,0,0,"y1");
          _SFD_SET_DATA_PROPS(8,0,0,0,"y11");
          _SFD_SET_DATA_PROPS(9,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(10,0,0,0,"y22");
          _SFD_SET_DATA_PROPS(11,8,0,0,"");
          _SFD_SET_DATA_PROPS(12,9,0,0,"");
          _SFD_SET_DATA_PROPS(13,8,0,0,"");
          _SFD_SET_DATA_PROPS(14,9,0,0,"");
          _SFD_EVENT_SCOPE(0,0);
          _SFD_EVENT_SCOPE(1,0);
          _SFD_EVENT_SCOPE(2,0);
          _SFD_EVENT_SCOPE(3,0);
          _SFD_STATE_INFO(0,1,0);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(7,0,1);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(11,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,7);
          _SFD_ST_SUBSTATE_INDEX(0,1,1);
          _SFD_ST_SUBSTATE_COUNT(7,3);
          _SFD_ST_SUBSTATE_INDEX(7,0,8);
          _SFD_ST_SUBSTATE_INDEX(7,1,9);
          _SFD_ST_SUBSTATE_INDEX(7,2,10);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 4 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 4 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 8, 14 };

          static unsigned int sEndGuardMap[] = { 7, 13, 18 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(7,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 7, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_TRANS_COV_WTS(3,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 4 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 4 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,3,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8, 14 };

          static unsigned int sEndGuardMap[] = { 7, 13, 18 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,0,2,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,1,0,2);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              2,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,2,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 7, 13 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,1,0,2);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              2,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(12,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));

        {
          real_T *c1_x;
          real_T *c1_c;
          c1_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_c);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c1_cnt);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c1_x1);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_y1);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c1_y11);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c1_y2);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c1_y22);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _HybridSystemMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "vjAi5lLI4w7q3ntugUzMeC";
}

static void sf_opaque_initialize_c1_HybridSystem(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_HybridSystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*)
    chartInstanceVar);
  initialize_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_HybridSystem(void *chartInstanceVar)
{
  enable_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_HybridSystem(void *chartInstanceVar)
{
  disable_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_HybridSystem(void *chartInstanceVar)
{
  sf_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_HybridSystem(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_HybridSystem
    ((SFc1_HybridSystemInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_HybridSystem();/* state var info */
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

extern void sf_internal_set_sim_state_c1_HybridSystem(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_HybridSystem();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_HybridSystem(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_HybridSystem(S);
}

static void sf_opaque_set_sim_state_c1_HybridSystem(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c1_HybridSystem(S, st);
}

static void sf_opaque_terminate_c1_HybridSystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_HybridSystemInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_HybridSystem_optimization_info();
    }

    finalize_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_HybridSystem((SFc1_HybridSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_HybridSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_HybridSystem((SFc1_HybridSystemInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_HybridSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_HybridSystem_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,1,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3238811798U));
  ssSetChecksum1(S,(1930327185U));
  ssSetChecksum2(S,(1418187361U));
  ssSetChecksum3(S,(2197774119U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_HybridSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_HybridSystem(SimStruct *S)
{
  SFc1_HybridSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_HybridSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_HybridSystemInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_HybridSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_HybridSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_HybridSystem;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_HybridSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_HybridSystem;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_HybridSystem;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_HybridSystem;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_HybridSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_HybridSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_HybridSystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_HybridSystem;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_HybridSystem;
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

void c1_HybridSystem_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_HybridSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_HybridSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_HybridSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_HybridSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
