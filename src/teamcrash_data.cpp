//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: teamcrash_data.cpp
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

// Block parameters (default storage)
P_teamcrash_T teamcrash_P = {
  // Mask Parameter: PIDController_D
  //  Referenced by: '<S40>/Derivative Gain'

  0.0,

  // Mask Parameter: PIDController_I
  //  Referenced by: '<S43>/Integral Gain'

  0.05,

  // Mask Parameter: PIDController_InitialConditionF
  //  Referenced by: '<S41>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_p
  //  Referenced by: '<S46>/Integrator'

  0.0,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by: '<S53>/Saturation'

  -3.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S49>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S51>/Proportional Gain'

  0.5,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by: '<S53>/Saturation'

  1.5,

  // Mask Parameter: DeadMansSwitch_stepSize
  //  Referenced by: '<S7>/Dead Man's Switch'

  0.05,

  // Mask Parameter: DeadMansSwitch_stepSize_o
  //  Referenced by: '<S9>/Dead Man's Switch'

  0.05,

  // Mask Parameter: DeadMansSwitch_timeout
  //  Referenced by: '<S7>/Dead Man's Switch'

  0.4,

  // Mask Parameter: DeadMansSwitch_timeout_b
  //  Referenced by: '<S9>/Dead Man's Switch'

  0.4,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S2>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S10>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_ha
  //  Referenced by: '<S5>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S11>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_h2
  //  Referenced by: '<S6>/Constant'

  {
    0.0                                // Data
  },

  // Expression: .05
  //  Referenced by: '<S8>/Constant'

  0.05,

  // Expression: 2
  //  Referenced by: '<S8>/Gain3'

  2.0,

  // Expression: 1
  //  Referenced by: '<S8>/Memory1'

  1.0,

  // Expression: -100000000
  //  Referenced by: '<S8>/Gain2'

  -1.0E+8,

  // Expression: .05
  //  Referenced by: '<Root>/Constant1'

  0.05,

  // Expression: 1
  //  Referenced by: '<Root>/Gain'

  1.0,

  // Expression: .01
  //  Referenced by: '<Root>/Gain1'

  0.01
};

//
// File trailer for generated code.
//
// [EOF]
//
