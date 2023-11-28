//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: teamcrash.cpp
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
#include "teamcrash.h"
#include "rtwtypes.h"
#include "teamcrash_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "teamcrash_types.h"

// Block signals (default storage)
B_teamcrash_T teamcrash_B;

// Continuous states
X_teamcrash_T teamcrash_X;

// Disabled State Vector
XDis_teamcrash_T teamcrash_XDis;

// Block states (default storage)
DW_teamcrash_T teamcrash_DW;

// Real-time model
RT_MODEL_teamcrash_T teamcrash_M_ = RT_MODEL_teamcrash_T();
RT_MODEL_teamcrash_T *const teamcrash_M = &teamcrash_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  teamcrash_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  teamcrash_step();
  teamcrash_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  teamcrash_step();
  teamcrash_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// Output and update for atomic system:
//    '<S7>/Dead Man's Switch'
//    '<S9>/Dead Man's Switch'
//
void teamcrash_DeadMansSwitch(boolean_T rtu_IsNew, real_T rtu_value, real_T
  *rty_safeValue, boolean_T *rty_timedOut, real_T rtp_stepSize, real_T
  rtp_timeout, DW_DeadMansSwitch_teamcrash_T *localDW)
{
  boolean_T timedOut;

  // MATLAB Function: '<S12>/timeout set to 0 output' incorporates:
  //   Constant: '<S12>/Simulate step size'
  //   Constant: '<S12>/Timeout in seconds'

  if (!localDW->sinceLastMsg_not_empty) {
    localDW->sinceLastMsg = rtp_timeout / rtp_stepSize + 1.0;
    localDW->sinceLastMsg_not_empty = true;
  }

  *rty_safeValue = 0.0;
  if (rtu_IsNew) {
    localDW->sinceLastMsg = 0.0;
  } else {
    localDW->sinceLastMsg++;
  }

  timedOut = !(localDW->sinceLastMsg < rtp_timeout / rtp_stepSize);
  if (!timedOut) {
    *rty_safeValue = rtu_value;
  }

  *rty_timedOut = timedOut;

  // End of MATLAB Function: '<S12>/timeout set to 0 output'
}

// Model step function
void teamcrash_step(void)
{
  // local block i/o variables
  real_T rtb_safeValue;
  SL_Bus_teamcrash_std_msgs_Float64 b_varargout_2;
  SL_Bus_teamcrash_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_teamcrash_std_msgs_Float64 rtb_BusAssignment1;
  real_T rtb_Saturation;
  real_T u1;
  boolean_T b_varargout_1;
  boolean_T rtb_timedOut_l;
  if (rtmIsMajorTimeStep(teamcrash_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&teamcrash_M->solverInfo,
                          ((teamcrash_M->Timing.clockTick0+1)*
      teamcrash_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(teamcrash_M)) {
    teamcrash_M->Timing.t[0] = rtsiGetT(&teamcrash_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(teamcrash_M)) {
    // Sum: '<S8>/Add' incorporates:
    //   Constant: '<S8>/Constant'
    //   Gain: '<S8>/Gain3'
    //   Memory: '<S8>/Memory1'

    teamcrash_B.Add = teamcrash_P.Gain3_Gain * teamcrash_P.Constant_Value_o +
      teamcrash_DW.Memory1_PreviousInput;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = Sub_teamcrash_16.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S10>/In1'
      teamcrash_B.In1_i = b_varargout_2;
    }

    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

    // Outputs for Atomic SubSystem: '<S7>/Dead Man's Switch'
    // Outputs for Atomic SubSystem: '<S7>/Dead Man's Switch'
    teamcrash_DeadMansSwitch(b_varargout_1, teamcrash_B.In1_i.Data,
      &rtb_safeValue, &rtb_timedOut_l, teamcrash_P.DeadMansSwitch_stepSize,
      teamcrash_P.DeadMansSwitch_timeout, &teamcrash_DW.DeadMansSwitch);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Dead Man's Switch'
    // End of Outputs for SubSystem: '<S7>/Dead Man's Switch'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Gain: '<S51>/Proportional Gain'
    teamcrash_B.ProportionalGain = teamcrash_P.PIDController_P * rtb_safeValue;

    // Gain: '<S40>/Derivative Gain'
    teamcrash_B.DerivativeGain = teamcrash_P.PIDController_D * rtb_safeValue;
  }

  // Gain: '<S49>/Filter Coefficient' incorporates:
  //   Integrator: '<S41>/Filter'
  //   Sum: '<S41>/SumD'

  teamcrash_B.FilterCoefficient = (teamcrash_B.DerivativeGain -
    teamcrash_X.Filter_CSTATE) * teamcrash_P.PIDController_N;

  // Sum: '<S55>/Sum' incorporates:
  //   Integrator: '<S46>/Integrator'

  rtb_Saturation = (teamcrash_B.ProportionalGain + teamcrash_X.Integrator_CSTATE)
    + teamcrash_B.FilterCoefficient;

  // Saturate: '<S53>/Saturation'
  if (rtb_Saturation > teamcrash_P.PIDController_UpperSaturationLi) {
    rtb_Saturation = teamcrash_P.PIDController_UpperSaturationLi;
  } else if (rtb_Saturation < teamcrash_P.PIDController_LowerSaturationLi) {
    rtb_Saturation = teamcrash_P.PIDController_LowerSaturationLi;
  }

  // End of Saturate: '<S53>/Saturation'
  if (rtmIsMajorTimeStep(teamcrash_M)) {
    // Sum: '<S8>/Add1' incorporates:
    //   Constant: '<S8>/Constant'
    //   Gain: '<S8>/Gain2'

    teamcrash_B.Add1 = teamcrash_P.Gain2_Gain * teamcrash_P.Constant_Value_o +
      teamcrash_DW.Memory1_PreviousInput;
  }

  // Switch: '<S63>/Switch2' incorporates:
  //   RelationalOperator: '<S63>/LowerRelop1'
  //   RelationalOperator: '<S63>/UpperRelop'
  //   Switch: '<S63>/Switch'

  if (rtb_Saturation > teamcrash_B.Add) {
    // Switch: '<S63>/Switch2'
    teamcrash_B.Switch2 = teamcrash_B.Add;
  } else if (rtb_Saturation < teamcrash_B.Add1) {
    // Switch: '<S63>/Switch' incorporates:
    //   Switch: '<S63>/Switch2'

    teamcrash_B.Switch2 = teamcrash_B.Add1;
  } else {
    // Switch: '<S63>/Switch2' incorporates:
    //   Switch: '<S63>/Switch'

    teamcrash_B.Switch2 = rtb_Saturation;
  }

  // End of Switch: '<S63>/Switch2'
  if (rtmIsMajorTimeStep(teamcrash_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S6>/SourceBlock'
    b_varargout_1 = Sub_teamcrash_17.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S11>/Enable'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S11>/In1'
      teamcrash_B.In1 = b_varargout_2;
    }

    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

    // Outputs for Atomic SubSystem: '<S9>/Dead Man's Switch'
    // Outputs for Atomic SubSystem: '<S9>/Dead Man's Switch'
    teamcrash_DeadMansSwitch(b_varargout_1, teamcrash_B.In1.Data,
      &teamcrash_B.safeValue, &rtb_timedOut_l,
      teamcrash_P.DeadMansSwitch_stepSize_o,
      teamcrash_P.DeadMansSwitch_timeout_b, &teamcrash_DW.DeadMansSwitch_h);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S9>/Dead Man's Switch'
    // End of Outputs for SubSystem: '<S9>/Dead Man's Switch'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'
  }

  // Product: '<Root>/Product1' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Gain: '<Root>/Gain'
  //   Gain: '<Root>/Gain1'
  //   Product: '<Root>/Product'
  //   Sum: '<Root>/Subtract'
  //   Sum: '<Root>/Sum'

  u1 = (teamcrash_B.safeValue - (teamcrash_B.Switch2 *
         teamcrash_P.Constant1_Value + rtb_Saturation) * teamcrash_P.Gain_Gain) *
    teamcrash_P.Gain1_Gain * teamcrash_B.Switch2;

  // MinMax: '<Root>/MinMax'
  if ((teamcrash_B.Switch2 <= u1) || rtIsNaN(u1)) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = teamcrash_B.Switch2;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = u1;
  }

  // End of MinMax: '<Root>/MinMax'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_teamcrash_13.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // BusAssignment: '<Root>/Bus Assignment1'
  rtb_BusAssignment1.Data = rtb_Saturation;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_teamcrash_14.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
  if (rtmIsMajorTimeStep(teamcrash_M)) {
    // Gain: '<S43>/Integral Gain'
    teamcrash_B.IntegralGain = teamcrash_P.PIDController_I * rtb_safeValue;
  }

  if (rtmIsMajorTimeStep(teamcrash_M)) {
    if (rtmIsMajorTimeStep(teamcrash_M)) {
      // Update for Memory: '<S8>/Memory1'
      teamcrash_DW.Memory1_PreviousInput = teamcrash_B.Switch2;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(teamcrash_M)) {
    rt_ertODEUpdateContinuousStates(&teamcrash_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++teamcrash_M->Timing.clockTick0;
    teamcrash_M->Timing.t[0] = rtsiGetSolverStopTime(&teamcrash_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      teamcrash_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void teamcrash_derivatives(void)
{
  XDot_teamcrash_T *_rtXdot;
  _rtXdot = ((XDot_teamcrash_T *) teamcrash_M->derivs);

  // Derivatives for Integrator: '<S46>/Integrator'
  _rtXdot->Integrator_CSTATE = teamcrash_B.IntegralGain;

  // Derivatives for Integrator: '<S41>/Filter'
  _rtXdot->Filter_CSTATE = teamcrash_B.FilterCoefficient;
}

// Model initialize function
void teamcrash_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&teamcrash_M->solverInfo,
                          &teamcrash_M->Timing.simTimeStep);
    rtsiSetTPtr(&teamcrash_M->solverInfo, &rtmGetTPtr(teamcrash_M));
    rtsiSetStepSizePtr(&teamcrash_M->solverInfo, &teamcrash_M->Timing.stepSize0);
    rtsiSetdXPtr(&teamcrash_M->solverInfo, &teamcrash_M->derivs);
    rtsiSetContStatesPtr(&teamcrash_M->solverInfo, (real_T **)
                         &teamcrash_M->contStates);
    rtsiSetNumContStatesPtr(&teamcrash_M->solverInfo,
      &teamcrash_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&teamcrash_M->solverInfo,
      &teamcrash_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&teamcrash_M->solverInfo,
      &teamcrash_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&teamcrash_M->solverInfo,
      &teamcrash_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&teamcrash_M->solverInfo, (boolean_T**)
      &teamcrash_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&teamcrash_M->solverInfo, (&rtmGetErrorStatus
      (teamcrash_M)));
    rtsiSetRTModelPtr(&teamcrash_M->solverInfo, teamcrash_M);
  }

  rtsiSetSimTimeStep(&teamcrash_M->solverInfo, MAJOR_TIME_STEP);
  teamcrash_M->intgData.y = teamcrash_M->odeY;
  teamcrash_M->intgData.f[0] = teamcrash_M->odeF[0];
  teamcrash_M->intgData.f[1] = teamcrash_M->odeF[1];
  teamcrash_M->intgData.f[2] = teamcrash_M->odeF[2];
  teamcrash_M->contStates = ((X_teamcrash_T *) &teamcrash_X);
  teamcrash_M->contStateDisabled = ((XDis_teamcrash_T *) &teamcrash_XDis);
  teamcrash_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&teamcrash_M->solverInfo, static_cast<void *>
                    (&teamcrash_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&teamcrash_M->solverInfo, false);
  rtsiSetSolverName(&teamcrash_M->solverInfo,"ode3");
  rtmSetTPtr(teamcrash_M, &teamcrash_M->Timing.tArray[0]);
  teamcrash_M->Timing.stepSize0 = 0.05;

  {
    int32_T i;
    char_T b_zeroDelimTopic_1[11];
    char_T b_zeroDelimTopic_0[10];
    char_T b_zeroDelimTopic[8];
    static const char_T b_zeroDelimTopic_2[8] = "rel_vel";
    static const char_T b_zeroDelimTopic_3[10] = "lead_dist";
    static const char_T b_zeroDelimTopic_4[11] = "/cmd_accel";
    static const char_T b_zeroDelimTopic_5[11] = "/accel_raw";

    // InitializeConditions for Memory: '<S8>/Memory1'
    teamcrash_DW.Memory1_PreviousInput = teamcrash_P.Memory1_InitialCondition;

    // InitializeConditions for Integrator: '<S46>/Integrator'
    teamcrash_X.Integrator_CSTATE = teamcrash_P.PIDController_InitialConditio_p;

    // InitializeConditions for Integrator: '<S41>/Filter'
    teamcrash_X.Filter_CSTATE = teamcrash_P.PIDController_InitialConditionF;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    teamcrash_B.In1_i = teamcrash_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    teamcrash_DW.obj_p.matlabCodegenIsDeleted = false;
    teamcrash_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_teamcrash_16.createSubscriber(&b_zeroDelimTopic[0], 1);
    teamcrash_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    teamcrash_B.In1 = teamcrash_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    teamcrash_DW.obj_j.matlabCodegenIsDeleted = false;
    teamcrash_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_teamcrash_17.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    teamcrash_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    teamcrash_DW.obj_e.matlabCodegenIsDeleted = false;
    teamcrash_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Pub_teamcrash_13.createPublisher(&b_zeroDelimTopic_1[0], 1);
    teamcrash_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    teamcrash_DW.obj.matlabCodegenIsDeleted = false;
    teamcrash_DW.obj.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Pub_teamcrash_14.createPublisher(&b_zeroDelimTopic_1[0], 1);
    teamcrash_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void teamcrash_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!teamcrash_DW.obj_p.matlabCodegenIsDeleted) {
    teamcrash_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!teamcrash_DW.obj_j.matlabCodegenIsDeleted) {
    teamcrash_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!teamcrash_DW.obj_e.matlabCodegenIsDeleted) {
    teamcrash_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!teamcrash_DW.obj.matlabCodegenIsDeleted) {
    teamcrash_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
