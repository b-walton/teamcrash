//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: teamcrash.h
//
// Code generated for Simulink model 'teamcrash'.
//
// Model version                  : 1.5
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Nov 28 10:52:09 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_teamcrash_h_
#define RTW_HEADER_teamcrash_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "teamcrash_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block states (default storage) for system '<S7>/Dead Man's Switch'
struct DW_DeadMansSwitch_teamcrash_T {
  real_T sinceLastMsg;                 // '<S12>/timeout set to 0 output'
  boolean_T sinceLastMsg_not_empty;    // '<S12>/timeout set to 0 output'
};

// Block signals (default storage)
struct B_teamcrash_T {
  real_T Add;                          // '<S8>/Add'
  real_T ProportionalGain;             // '<S51>/Proportional Gain'
  real_T DerivativeGain;               // '<S40>/Derivative Gain'
  real_T FilterCoefficient;            // '<S49>/Filter Coefficient'
  real_T Add1;                         // '<S8>/Add1'
  real_T Switch2;                      // '<S63>/Switch2'
  real_T IntegralGain;                 // '<S43>/Integral Gain'
  real_T safeValue;                    // '<S64>/timeout set to 0 output'
  SL_Bus_teamcrash_std_msgs_Float64 In1;// '<S11>/In1'
  SL_Bus_teamcrash_std_msgs_Float64 In1_i;// '<S10>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_teamcrash_T {
  ros_slroscpp_internal_block_P_T obj; // '<S4>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_e;// '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S6>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S5>/SourceBlock'
  real_T Memory1_PreviousInput;        // '<S8>/Memory1'
  DW_DeadMansSwitch_teamcrash_T DeadMansSwitch_h;// '<S9>/Dead Man's Switch'
  DW_DeadMansSwitch_teamcrash_T DeadMansSwitch;// '<S7>/Dead Man's Switch'
};

// Continuous states (default storage)
struct X_teamcrash_T {
  real_T Integrator_CSTATE;            // '<S46>/Integrator'
  real_T Filter_CSTATE;                // '<S41>/Filter'
};

// State derivatives (default storage)
struct XDot_teamcrash_T {
  real_T Integrator_CSTATE;            // '<S46>/Integrator'
  real_T Filter_CSTATE;                // '<S41>/Filter'
};

// State disabled
struct XDis_teamcrash_T {
  boolean_T Integrator_CSTATE;         // '<S46>/Integrator'
  boolean_T Filter_CSTATE;             // '<S41>/Filter'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_teamcrash_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S40>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S43>/Integral Gain'

  real_T PIDController_InitialConditionF;
                              // Mask Parameter: PIDController_InitialConditionF
                                 //  Referenced by: '<S41>/Filter'

  real_T PIDController_InitialConditio_p;
                              // Mask Parameter: PIDController_InitialConditio_p
                                 //  Referenced by: '<S46>/Integrator'

  real_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by: '<S53>/Saturation'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S49>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S51>/Proportional Gain'

  real_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by: '<S53>/Saturation'

  real_T DeadMansSwitch_stepSize;     // Mask Parameter: DeadMansSwitch_stepSize
                                         //  Referenced by: '<S7>/Dead Man's Switch'

  real_T DeadMansSwitch_stepSize_o; // Mask Parameter: DeadMansSwitch_stepSize_o
                                       //  Referenced by: '<S9>/Dead Man's Switch'

  real_T DeadMansSwitch_timeout;       // Mask Parameter: DeadMansSwitch_timeout
                                          //  Referenced by: '<S7>/Dead Man's Switch'

  real_T DeadMansSwitch_timeout_b;   // Mask Parameter: DeadMansSwitch_timeout_b
                                        //  Referenced by: '<S9>/Dead Man's Switch'

  SL_Bus_teamcrash_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S1>/Constant'

  SL_Bus_teamcrash_std_msgs_Float64 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                        //  Referenced by: '<S2>/Constant'

  SL_Bus_teamcrash_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                               //  Referenced by: '<S10>/Out1'

  SL_Bus_teamcrash_std_msgs_Float64 Constant_Value_ha;// Computed Parameter: Constant_Value_ha
                                                         //  Referenced by: '<S5>/Constant'

  SL_Bus_teamcrash_std_msgs_Float64 Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                 //  Referenced by: '<S11>/Out1'

  SL_Bus_teamcrash_std_msgs_Float64 Constant_Value_h2;// Computed Parameter: Constant_Value_h2
                                                         //  Referenced by: '<S6>/Constant'

  real_T Constant_Value_o;             // Expression: .05
                                          //  Referenced by: '<S8>/Constant'

  real_T Gain3_Gain;                   // Expression: 2
                                          //  Referenced by: '<S8>/Gain3'

  real_T Memory1_InitialCondition;     // Expression: 1
                                          //  Referenced by: '<S8>/Memory1'

  real_T Gain2_Gain;                   // Expression: -100000000
                                          //  Referenced by: '<S8>/Gain2'

  real_T Constant1_Value;              // Expression: .05
                                          //  Referenced by: '<Root>/Constant1'

  real_T Gain_Gain;                    // Expression: 1
                                          //  Referenced by: '<Root>/Gain'

  real_T Gain1_Gain;                   // Expression: .01
                                          //  Referenced by: '<Root>/Gain1'

};

// Real-time Model Data Structure
struct tag_RTM_teamcrash_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_teamcrash_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_teamcrash_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_teamcrash_T teamcrash_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_teamcrash_T teamcrash_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_teamcrash_T teamcrash_X;

// Disabled states (default storage)
extern XDis_teamcrash_T teamcrash_XDis;

// Block states (default storage)
extern struct DW_teamcrash_T teamcrash_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void teamcrash_initialize(void);
  extern void teamcrash_step(void);
  extern void teamcrash_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_teamcrash_T *const teamcrash_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S63>/Data Type Duplicate' : Unused code path elimination
//  Block '<S63>/Data Type Propagation' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'teamcrash'
//  '<S1>'   : 'teamcrash/Blank Message'
//  '<S2>'   : 'teamcrash/Blank Message1'
//  '<S3>'   : 'teamcrash/Publish'
//  '<S4>'   : 'teamcrash/Publish1'
//  '<S5>'   : 'teamcrash/Subscribe1'
//  '<S6>'   : 'teamcrash/Subscribe2'
//  '<S7>'   : 'teamcrash/Subsystem'
//  '<S8>'   : 'teamcrash/Subsystem1'
//  '<S9>'   : 'teamcrash/Subsystem2'
//  '<S10>'  : 'teamcrash/Subscribe1/Enabled Subsystem'
//  '<S11>'  : 'teamcrash/Subscribe2/Enabled Subsystem'
//  '<S12>'  : 'teamcrash/Subsystem/Dead Man's Switch'
//  '<S13>'  : 'teamcrash/Subsystem/PID Controller'
//  '<S14>'  : 'teamcrash/Subsystem/Dead Man's Switch/timeout set to 0 output'
//  '<S15>'  : 'teamcrash/Subsystem/PID Controller/Anti-windup'
//  '<S16>'  : 'teamcrash/Subsystem/PID Controller/D Gain'
//  '<S17>'  : 'teamcrash/Subsystem/PID Controller/Filter'
//  '<S18>'  : 'teamcrash/Subsystem/PID Controller/Filter ICs'
//  '<S19>'  : 'teamcrash/Subsystem/PID Controller/I Gain'
//  '<S20>'  : 'teamcrash/Subsystem/PID Controller/Ideal P Gain'
//  '<S21>'  : 'teamcrash/Subsystem/PID Controller/Ideal P Gain Fdbk'
//  '<S22>'  : 'teamcrash/Subsystem/PID Controller/Integrator'
//  '<S23>'  : 'teamcrash/Subsystem/PID Controller/Integrator ICs'
//  '<S24>'  : 'teamcrash/Subsystem/PID Controller/N Copy'
//  '<S25>'  : 'teamcrash/Subsystem/PID Controller/N Gain'
//  '<S26>'  : 'teamcrash/Subsystem/PID Controller/P Copy'
//  '<S27>'  : 'teamcrash/Subsystem/PID Controller/Parallel P Gain'
//  '<S28>'  : 'teamcrash/Subsystem/PID Controller/Reset Signal'
//  '<S29>'  : 'teamcrash/Subsystem/PID Controller/Saturation'
//  '<S30>'  : 'teamcrash/Subsystem/PID Controller/Saturation Fdbk'
//  '<S31>'  : 'teamcrash/Subsystem/PID Controller/Sum'
//  '<S32>'  : 'teamcrash/Subsystem/PID Controller/Sum Fdbk'
//  '<S33>'  : 'teamcrash/Subsystem/PID Controller/Tracking Mode'
//  '<S34>'  : 'teamcrash/Subsystem/PID Controller/Tracking Mode Sum'
//  '<S35>'  : 'teamcrash/Subsystem/PID Controller/Tsamp - Integral'
//  '<S36>'  : 'teamcrash/Subsystem/PID Controller/Tsamp - Ngain'
//  '<S37>'  : 'teamcrash/Subsystem/PID Controller/postSat Signal'
//  '<S38>'  : 'teamcrash/Subsystem/PID Controller/preSat Signal'
//  '<S39>'  : 'teamcrash/Subsystem/PID Controller/Anti-windup/Passthrough'
//  '<S40>'  : 'teamcrash/Subsystem/PID Controller/D Gain/Internal Parameters'
//  '<S41>'  : 'teamcrash/Subsystem/PID Controller/Filter/Cont. Filter'
//  '<S42>'  : 'teamcrash/Subsystem/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S43>'  : 'teamcrash/Subsystem/PID Controller/I Gain/Internal Parameters'
//  '<S44>'  : 'teamcrash/Subsystem/PID Controller/Ideal P Gain/Passthrough'
//  '<S45>'  : 'teamcrash/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S46>'  : 'teamcrash/Subsystem/PID Controller/Integrator/Continuous'
//  '<S47>'  : 'teamcrash/Subsystem/PID Controller/Integrator ICs/Internal IC'
//  '<S48>'  : 'teamcrash/Subsystem/PID Controller/N Copy/Disabled'
//  '<S49>'  : 'teamcrash/Subsystem/PID Controller/N Gain/Internal Parameters'
//  '<S50>'  : 'teamcrash/Subsystem/PID Controller/P Copy/Disabled'
//  '<S51>'  : 'teamcrash/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S52>'  : 'teamcrash/Subsystem/PID Controller/Reset Signal/Disabled'
//  '<S53>'  : 'teamcrash/Subsystem/PID Controller/Saturation/Enabled'
//  '<S54>'  : 'teamcrash/Subsystem/PID Controller/Saturation Fdbk/Disabled'
//  '<S55>'  : 'teamcrash/Subsystem/PID Controller/Sum/Sum_PID'
//  '<S56>'  : 'teamcrash/Subsystem/PID Controller/Sum Fdbk/Disabled'
//  '<S57>'  : 'teamcrash/Subsystem/PID Controller/Tracking Mode/Disabled'
//  '<S58>'  : 'teamcrash/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S59>'  : 'teamcrash/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S60>'  : 'teamcrash/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S61>'  : 'teamcrash/Subsystem/PID Controller/postSat Signal/Forward_Path'
//  '<S62>'  : 'teamcrash/Subsystem/PID Controller/preSat Signal/Forward_Path'
//  '<S63>'  : 'teamcrash/Subsystem1/Saturation Dynamic'
//  '<S64>'  : 'teamcrash/Subsystem2/Dead Man's Switch'
//  '<S65>'  : 'teamcrash/Subsystem2/Dead Man's Switch/timeout set to 0 output'

#endif                                 // RTW_HEADER_teamcrash_h_

//
// File trailer for generated code.
//
// [EOF]
//
