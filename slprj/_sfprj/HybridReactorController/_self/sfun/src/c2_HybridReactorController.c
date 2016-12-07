/* Include files */

#include <stddef.h>
#include "blas.h"
#include "HybridReactorController_sfun.h"
#include "c2_HybridReactorController.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HybridReactorController_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_NoRod                    ((uint8_T)1U)
#define c2_IN_Rod1                     ((uint8_T)2U)
#define c2_IN_Rod2                     ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void initialize_params_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void enable_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void disable_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void set_sim_state_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void c2_set_sim_state_side_effects_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void finalize_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void sf_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void c2_chartstep_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void initSimStructsc2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void registerMessagesc2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_timer1(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, real_T c2_b_y11, real_T c2_b_i);
static real_T c2_timer2(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, real_T c2_b_y22, real_T c2_b_i);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static uint32_T c2_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_b_add1EventCounter, const char_T
  *c2_identifier);
static uint32_T c2_b_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct *
  chartInstance, const mxArray *c2_b_tp_Rod1, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_f_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_y1, const char_T *c2_identifier);
static real_T c2_g_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static boolean_T c2_h_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_Start, const char_T *c2_identifier);
static boolean_T c2_i_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *c2_j_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_k_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  real_T *c2_y1;
  real_T *c2_y2;
  boolean_T *c2_add1;
  boolean_T *c2_add2;
  boolean_T *c2_remove1;
  boolean_T *c2_remove2;
  boolean_T *c2_Start;
  c2_Start = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_remove2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_remove1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_add2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_add1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_NoRod = 0U;
  chartInstance->c2_tp_Rod1 = 0U;
  chartInstance->c2_tp_Rod2 = 0U;
  chartInstance->c2_is_active_c2_HybridReactorController = 0U;
  chartInstance->c2_is_c2_HybridReactorController = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_i = 0.0;
  chartInstance->c2_y11 = 0.0;
  chartInstance->c2_y22 = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c2_y1 = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c2_y2 = 0.0;
  }

  chartInstance->c2_add1EventCounter = 0U;
  *c2_add1 = FALSE;
  chartInstance->c2_add2EventCounter = 0U;
  *c2_add2 = FALSE;
  chartInstance->c2_remove1EventCounter = 0U;
  *c2_remove1 = FALSE;
  chartInstance->c2_remove2EventCounter = 0U;
  *c2_remove2 = FALSE;
  chartInstance->c2_StartEventCounter = 0U;
  *c2_Start = FALSE;
}

static void initialize_params_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
}

static void enable_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "timer1", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "timer2", 0);
}

static void disable_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "timer1", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "timer2", 0);
}

static void c2_update_debugger_state_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_HybridReactorController == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_HybridReactorController == c2_IN_Rod1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_HybridReactorController == c2_IN_NoRod) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_HybridReactorController == c2_IN_Rod2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  boolean_T c2_f_hoistedGlobal;
  boolean_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  boolean_T c2_g_hoistedGlobal;
  boolean_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  boolean_T c2_h_hoistedGlobal;
  boolean_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  boolean_T c2_i_hoistedGlobal;
  boolean_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  boolean_T c2_j_hoistedGlobal;
  boolean_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  uint32_T c2_k_hoistedGlobal;
  uint32_T c2_k_u;
  const mxArray *c2_l_y = NULL;
  uint32_T c2_l_hoistedGlobal;
  uint32_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  uint32_T c2_m_hoistedGlobal;
  uint32_T c2_m_u;
  const mxArray *c2_n_y = NULL;
  uint32_T c2_n_hoistedGlobal;
  uint32_T c2_n_u;
  const mxArray *c2_o_y = NULL;
  uint32_T c2_o_hoistedGlobal;
  uint32_T c2_o_u;
  const mxArray *c2_p_y = NULL;
  uint8_T c2_p_hoistedGlobal;
  uint8_T c2_p_u;
  const mxArray *c2_q_y = NULL;
  uint8_T c2_q_hoistedGlobal;
  uint8_T c2_q_u;
  const mxArray *c2_r_y = NULL;
  real_T *c2_y1;
  real_T *c2_y2;
  boolean_T *c2_Start;
  boolean_T *c2_add1;
  boolean_T *c2_add2;
  boolean_T *c2_remove1;
  boolean_T *c2_remove2;
  c2_Start = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_remove2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_remove1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_add2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_add1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(17), FALSE);
  c2_hoistedGlobal = *c2_y1;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_y2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_i;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_y11;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_y22;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *c2_Start;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = *c2_add1;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = *c2_add2;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = *c2_remove1;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = *c2_remove2;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_k_hoistedGlobal = chartInstance->c2_StartEventCounter;
  c2_k_u = c2_k_hoistedGlobal;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_k_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_l_hoistedGlobal = chartInstance->c2_add1EventCounter;
  c2_l_u = c2_l_hoistedGlobal;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_m_hoistedGlobal = chartInstance->c2_add2EventCounter;
  c2_m_u = c2_m_hoistedGlobal;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_m_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  c2_n_hoistedGlobal = chartInstance->c2_remove1EventCounter;
  c2_n_u = c2_n_hoistedGlobal;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_n_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 13, c2_o_y);
  c2_o_hoistedGlobal = chartInstance->c2_remove2EventCounter;
  c2_o_u = c2_o_hoistedGlobal;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_o_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 14, c2_p_y);
  c2_p_hoistedGlobal = chartInstance->c2_is_active_c2_HybridReactorController;
  c2_p_u = c2_p_hoistedGlobal;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_p_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 15, c2_q_y);
  c2_q_hoistedGlobal = chartInstance->c2_is_c2_HybridReactorController;
  c2_q_u = c2_q_hoistedGlobal;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_q_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 16, c2_r_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_y1;
  real_T *c2_y2;
  boolean_T *c2_Start;
  boolean_T *c2_add1;
  boolean_T *c2_add2;
  boolean_T *c2_remove1;
  boolean_T *c2_remove2;
  c2_Start = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_remove2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_remove1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_add2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_add1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_y1 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "y1");
  *c2_y2 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "y2");
  chartInstance->c2_i = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "i");
  chartInstance->c2_y11 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "y11");
  chartInstance->c2_y22 = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "y22");
  *c2_Start = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 5)), "Start");
  *c2_add1 = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    6)), "add1");
  *c2_add2 = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    7)), "add2");
  *c2_remove1 = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 8)), "remove1");
  *c2_remove2 = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 9)), "remove2");
  chartInstance->c2_StartEventCounter = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 10)), "StartEventCounter");
  chartInstance->c2_add1EventCounter = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 11)), "add1EventCounter");
  chartInstance->c2_add2EventCounter = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 12)), "add2EventCounter");
  chartInstance->c2_remove1EventCounter = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 13)), "remove1EventCounter");
  chartInstance->c2_remove2EventCounter = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 14)), "remove2EventCounter");
  chartInstance->c2_is_active_c2_HybridReactorController = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 15)),
     "is_active_c2_HybridReactorController");
  chartInstance->c2_is_c2_HybridReactorController = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 16)),
     "is_c2_HybridReactorController");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 17)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_HybridReactorController(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_HybridReactorController == c2_IN_NoRod) {
      chartInstance->c2_tp_NoRod = 1U;
    } else {
      chartInstance->c2_tp_NoRod = 0U;
    }

    if (chartInstance->c2_is_c2_HybridReactorController == c2_IN_Rod1) {
      chartInstance->c2_tp_Rod1 = 1U;
    } else {
      chartInstance->c2_tp_Rod1 = 0U;
    }

    if (chartInstance->c2_is_c2_HybridReactorController == c2_IN_Rod2) {
      chartInstance->c2_tp_Rod2 = 1U;
    } else {
      chartInstance->c2_tp_Rod2 = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  boolean_T *c2_add1;
  boolean_T *c2_add2;
  boolean_T *c2_remove1;
  boolean_T *c2_remove2;
  boolean_T *c2_Start;
  c2_Start = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_remove2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_remove1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_add2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_add1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_set_sim_state_side_effects_c2_HybridReactorController(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_HybridReactorController(chartInstance);
  if (chartInstance->c2_add1EventCounter > 0U) {
    *c2_add1 = !*c2_add1;
    chartInstance->c2_add1EventCounter--;
  }

  if (chartInstance->c2_add2EventCounter > 0U) {
    *c2_add2 = !*c2_add2;
    chartInstance->c2_add2EventCounter--;
  }

  if (chartInstance->c2_remove1EventCounter > 0U) {
    *c2_remove1 = !*c2_remove1;
    chartInstance->c2_remove1EventCounter--;
  }

  if (chartInstance->c2_remove2EventCounter > 0U) {
    *c2_remove2 = !*c2_remove2;
    chartInstance->c2_remove2EventCounter--;
  }

  if (chartInstance->c2_StartEventCounter > 0U) {
    *c2_Start = !*c2_Start;
    chartInstance->c2_StartEventCounter--;
  }

  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_HybridReactorControllerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
  boolean_T c2_temp;
  boolean_T c2_b_temp;
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_temp;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  real_T *c2_x;
  real_T *c2_y1;
  real_T *c2_y2;
  c2_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_HybridReactorController == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_HybridReactorController = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    *c2_y1 = 50.0;
    *c2_y2 = 50.0;
    chartInstance->c2_StartEventCounter++;
    chartInstance->c2_is_c2_HybridReactorController = c2_IN_NoRod;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_NoRod = 1U;
    chartInstance->c2_y11 = *c2_y1;
    chartInstance->c2_y22 = *c2_y2;
    chartInstance->c2_i = 1.0;
  } else {
    switch (chartInstance->c2_is_c2_HybridReactorController) {
     case c2_IN_NoRod:
      CV_CHART_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c2_sfEvent);
      c2_temp = (_SFD_CCP_CALL(1U, 0, *c2_x >= 510.0 != 0U,
                  chartInstance->c2_sfEvent) != 0);
      if (c2_temp) {
        c2_temp = (_SFD_CCP_CALL(1U, 1, *c2_y1 >= 50.0 != 0U,
                    chartInstance->c2_sfEvent) != 0);
      }

      c2_b_temp = c2_temp;
      if (c2_b_temp) {
        c2_b_temp = (_SFD_CCP_CALL(1U, 2, *c2_y2 < 50.0 != 0U,
          chartInstance->c2_sfEvent) != 0);
      }

      c2_out = (CV_TRANSITION_EVAL(1U, (int32_T)c2_b_temp) != 0);
      if (c2_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 1;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c2_b_out = ((*c2_x >= 550.0) && (*c2_y2 >= 50.0));
          if (c2_b_out) {
            transitionList[numTransitions] = 3;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_NoRod = 0U;
        chartInstance->c2_is_c2_HybridReactorController = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 1U,
                     chartInstance->c2_sfEvent);
        chartInstance->c2_add1EventCounter++;
        chartInstance->c2_is_c2_HybridReactorController = c2_IN_Rod1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Rod1 = 1U;
        chartInstance->c2_y11 = *c2_y1;
        chartInstance->c2_y22 = *c2_y2;
        chartInstance->c2_i = 1.0;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c2_sfEvent);
        c2_c_temp = (_SFD_CCP_CALL(3U, 0, *c2_x >= 550.0 != 0U,
          chartInstance->c2_sfEvent) != 0);
        if (c2_c_temp) {
          c2_c_temp = (_SFD_CCP_CALL(3U, 1, *c2_y2 >= 50.0 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_c_out = (CV_TRANSITION_EVAL(3U, (int32_T)c2_c_temp) != 0);
        if (c2_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_NoRod = 0U;
          chartInstance->c2_is_c2_HybridReactorController =
            c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 3U,
                       chartInstance->c2_sfEvent);
          chartInstance->c2_add2EventCounter++;
          chartInstance->c2_is_c2_HybridReactorController = c2_IN_Rod2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Rod2 = 1U;
          chartInstance->c2_y11 = *c2_y1;
          chartInstance->c2_y22 = *c2_y2;
          chartInstance->c2_i = 1.0;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                       chartInstance->c2_sfEvent);
          *c2_y1 = c2_timer1(chartInstance, chartInstance->c2_y11,
                             chartInstance->c2_i);
          *c2_y2 = c2_timer2(chartInstance, chartInstance->c2_y22,
                             chartInstance->c2_i);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_Rod1:
      CV_CHART_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c2_sfEvent);
      c2_d_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0, *c2_x <=
        510.0 != 0U, chartInstance->c2_sfEvent)) != 0);
      if (c2_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Rod1 = 0U;
        chartInstance->c2_is_c2_HybridReactorController = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 2U,
                     chartInstance->c2_sfEvent);
        chartInstance->c2_remove1EventCounter++;
        *c2_y1 = 0.0;
        chartInstance->c2_is_c2_HybridReactorController = c2_IN_NoRod;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_NoRod = 1U;
        chartInstance->c2_y11 = *c2_y1;
        chartInstance->c2_y22 = *c2_y2;
        chartInstance->c2_i = 1.0;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c2_sfEvent);
        *c2_y1 = c2_timer1(chartInstance, chartInstance->c2_y11,
                           chartInstance->c2_i);
        *c2_y2 = c2_timer2(chartInstance, chartInstance->c2_y22,
                           chartInstance->c2_i);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_Rod2:
      CV_CHART_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c2_sfEvent);
      c2_e_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0, *c2_x <=
        510.0 != 0U, chartInstance->c2_sfEvent)) != 0);
      if (c2_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Rod2 = 0U;
        chartInstance->c2_is_c2_HybridReactorController = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 4U,
                     chartInstance->c2_sfEvent);
        chartInstance->c2_remove2EventCounter++;
        *c2_y2 = 0.0;
        chartInstance->c2_is_c2_HybridReactorController = c2_IN_NoRod;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_NoRod = 1U;
        chartInstance->c2_y11 = *c2_y1;
        chartInstance->c2_y22 = *c2_y2;
        chartInstance->c2_i = 1.0;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c2_sfEvent);
        *c2_y1 = c2_timer1(chartInstance, chartInstance->c2_y11,
                           chartInstance->c2_i);
        *c2_y2 = c2_timer2(chartInstance, chartInstance->c2_y22,
                           chartInstance->c2_i);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      chartInstance->c2_is_c2_HybridReactorController = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_HybridReactorController
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_HybridReactorController_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static real_T c2_timer1(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, real_T c2_b_y11, real_T c2_b_i)
{
  real_T c2_y1;
  real_T *c2_c_y11;
  real_T *c2_c_i;
  real_T *c2_b_y1;
  c2_c_i = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_c_y11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_b_y1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SET_DATA_VALUE_PTR(6U, &c2_y1);
  _SFD_SET_DATA_VALUE_PTR(8U, &c2_b_i);
  _SFD_SET_DATA_VALUE_PTR(7U, &c2_b_y11);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(3U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y11", &c2_b_y11, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("i", &c2_b_i, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y1", &c2_y1, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
  *c2_c_y11 = c2_b_y11;
  *c2_c_i = c2_b_i;
  sf_call_output_fcn_call(chartInstance->S, 0, "timer1", 0);
  c2_y1 = *c2_b_y1;
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(6U);
  _SFD_UNSET_DATA_VALUE_PTR(8U);
  _SFD_UNSET_DATA_VALUE_PTR(7U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
  return c2_y1;
}

static real_T c2_timer2(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, real_T c2_b_y22, real_T c2_b_i)
{
  real_T c2_y2;
  real_T *c2_c_y22;
  real_T *c2_c_i;
  real_T *c2_b_y2;
  c2_c_i = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_b_y2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_c_y22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  _SFD_SET_DATA_VALUE_PTR(10U, &c2_y2);
  _SFD_SET_DATA_VALUE_PTR(11U, &c2_b_i);
  _SFD_SET_DATA_VALUE_PTR(9U, &c2_b_y22);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(3U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y22", &c2_b_y22, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("i", &c2_b_i, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("y2", &c2_y2, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
  *c2_c_y22 = c2_b_y22;
  *c2_c_i = c2_b_i;
  sf_call_output_fcn_call(chartInstance->S, 1, "timer2", 0);
  c2_y2 = *c2_b_y2;
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(10U);
  _SFD_UNSET_DATA_VALUE_PTR(11U);
  _SFD_UNSET_DATA_VALUE_PTR(9U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
  return c2_y2;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint32_T c2_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_b_add1EventCounter, const char_T
  *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_add1EventCounter),
    &c2_thisId);
  sf_mex_destroy(&c2_b_add1EventCounter);
  return c2_y;
}

static uint32_T c2_b_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 7, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_add1EventCounter;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint32_T c2_y;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_b_add1EventCounter = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_add1EventCounter),
    &c2_thisId);
  sf_mex_destroy(&c2_b_add1EventCounter);
  *(uint32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct *
  chartInstance, const mxArray *c2_b_tp_Rod1, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Rod1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Rod1);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u1, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_Rod1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_b_tp_Rod1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Rod1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Rod1);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_f_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_y1, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y1), &c2_thisId);
  sf_mex_destroy(&c2_y1);
  return c2_y;
}

static real_T c2_g_emlrt_marshallIn(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
    chartInstanceVoid;
  c2_y1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y1), &c2_thisId);
  sf_mex_destroy(&c2_y1);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static boolean_T c2_h_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_Start, const char_T *c2_identifier)
{
  boolean_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Start), &c2_thisId);
  sf_mex_destroy(&c2_Start);
  return c2_y;
}

static boolean_T c2_i_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *c2_j_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), FALSE);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_k_emlrt_marshallIn
  (SFc2_HybridReactorControllerInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_HybridReactorControllerInstanceStruct
  *chartInstance)
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

void sf_c2_HybridReactorController_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3061907317U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1293260066U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2351046852U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(855994155U);
}

mxArray *sf_c2_HybridReactorController_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0EE8kKAZMiIHTaXPtQKyRG");
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_HybridReactorController_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_HybridReactorController(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[6],T\"y1\",},{M[1],M[7],T\"y2\",},{M[3],M[38],T\"i\",},{M[3],M[39],T\"y11\",},{M[3],M[40],T\"y22\",},{M[6],M[44],T\"Start\",},{M[6],M[2],T\"add1\",},{M[6],M[3],T\"add2\",},{M[6],M[4],T\"remove1\",},{M[6],M[5],T\"remove2\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[7],M[44],T\"StartEventCounter\",},{M[7],M[2],T\"add1EventCounter\",},{M[7],M[3],T\"add2EventCounter\",},{M[7],M[4],T\"remove1EventCounter\",},{M[7],M[5],T\"remove2EventCounter\",},{M[8],M[0],T\"is_active_c2_HybridReactorController\",},{M[9],M[0],T\"is_c2_HybridReactorController\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_HybridReactorController_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_HybridReactorControllerInstanceStruct *chartInstance;
    chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _HybridReactorControllerMachineNumber_,
           2,
           5,
           5,
           12,
           5,
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
          init_script_number_translation(_HybridReactorControllerMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_HybridReactorControllerMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _HybridReactorControllerMachineNumber_,
            chartInstance->chartNumber,
            5,
            5,
            5);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y2");
          _SFD_SET_DATA_PROPS(3,0,0,0,"i");
          _SFD_SET_DATA_PROPS(4,0,0,0,"y11");
          _SFD_SET_DATA_PROPS(5,0,0,0,"y22");
          _SFD_SET_DATA_PROPS(6,9,0,0,"");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_SET_DATA_PROPS(9,8,0,0,"");
          _SFD_SET_DATA_PROPS(10,9,0,0,"");
          _SFD_SET_DATA_PROPS(11,8,0,0,"");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,2);
          _SFD_EVENT_SCOPE(3,2);
          _SFD_EVENT_SCOPE(4,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
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
          static unsigned int sStartGuardMap[] = { 1, 8, 15 };

          static unsigned int sEndGuardMap[] = { 7, 14, 20 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(1,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 7, 14 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(1,0,3,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8, 15 };

          static unsigned int sEndGuardMap[] = { 7, 14, 20 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,0,3,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,2);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              2,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,2,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 7, 14 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,1,0,2);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              2,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));

        {
          real_T *c2_x;
          real_T *c2_y1;
          real_T *c2_y2;
          c2_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y1);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_y2);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_i);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c2_y11);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c2_y22);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _HybridReactorControllerMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "E9cHNcidlg9Ha0w5qyB2m";
}

static void sf_opaque_initialize_c2_HybridReactorController(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_HybridReactorControllerInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_HybridReactorController
    ((SFc2_HybridReactorControllerInstanceStruct*) chartInstanceVar);
  initialize_c2_HybridReactorController
    ((SFc2_HybridReactorControllerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_HybridReactorController(void *chartInstanceVar)
{
  enable_c2_HybridReactorController((SFc2_HybridReactorControllerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_HybridReactorController(void *chartInstanceVar)
{
  disable_c2_HybridReactorController((SFc2_HybridReactorControllerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_HybridReactorController(void *chartInstanceVar)
{
  sf_c2_HybridReactorController((SFc2_HybridReactorControllerInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_HybridReactorController
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_HybridReactorController
    ((SFc2_HybridReactorControllerInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_HybridReactorController();/* state var info */
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

extern void sf_internal_set_sim_state_c2_HybridReactorController(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_HybridReactorController();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_HybridReactorController
    ((SFc2_HybridReactorControllerInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_HybridReactorController
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_HybridReactorController(S);
}

static void sf_opaque_set_sim_state_c2_HybridReactorController(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_HybridReactorController(S, st);
}

static void sf_opaque_terminate_c2_HybridReactorController(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_HybridReactorControllerInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_HybridReactorController_optimization_info();
    }

    finalize_c2_HybridReactorController
      ((SFc2_HybridReactorControllerInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_HybridReactorController
    ((SFc2_HybridReactorControllerInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_HybridReactorController(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_HybridReactorController
      ((SFc2_HybridReactorControllerInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_HybridReactorController(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_HybridReactorController_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,2,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,11);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=11; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2084277703U));
  ssSetChecksum1(S,(989016448U));
  ssSetChecksum2(S,(1351231374U));
  ssSetChecksum3(S,(2414773892U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_HybridReactorController(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_HybridReactorController(SimStruct *S)
{
  SFc2_HybridReactorControllerInstanceStruct *chartInstance;
  chartInstance = (SFc2_HybridReactorControllerInstanceStruct *)utMalloc(sizeof
    (SFc2_HybridReactorControllerInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_HybridReactorControllerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_HybridReactorController;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_HybridReactorController;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_HybridReactorController;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_HybridReactorController;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_HybridReactorController;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_HybridReactorController;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_HybridReactorController;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_HybridReactorController;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_HybridReactorController;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_HybridReactorController;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_HybridReactorController;
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

void c2_HybridReactorController_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_HybridReactorController(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_HybridReactorController(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_HybridReactorController(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_HybridReactorController_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
