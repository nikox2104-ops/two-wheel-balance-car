/*
 * File: Mega_BalanceCode_data.c
 *
 * Code generated for Simulink model 'Mega_BalanceCode'.
 *
 * Model version                  : 1.526
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * TLC version                    : 8.5 (Aug  6 2013)
 * C/C++ source code generated on : Tue May 30 11:47:51 2017
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mega_BalanceCode.h"
#include "Mega_BalanceCode_private.h"

/* Block parameters (auto storage) */
Parameters_Mega_BalanceCode Mega_BalanceCode_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S3>/Discrete-Time  Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time  Integrator'
                                        */
  0.04,                                /* Expression: .04
                                        * Referenced by: '<S6>/Z Bias1'
                                        */
  1430.0,                              /* Expression: 1430
                                        * Referenced by: '<S6>/Z Bias'
                                        */
  101.0,                               /* Expression: 101
                                        * Referenced by: '<S6>/Y Bias'
                                        */
  0.02,                                /* Expression: .02
                                        * Referenced by: '<S5>/convert to  radians6'
                                        */
  -0.00013323124061025415,             /* Expression: -GS
                                        * Referenced by: '<S3>/conver to radians//sed'
                                        */
  0.005,                               /* Expression: TS
                                        * Referenced by: '<S5>/convert to  radians2'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  0.98,                                /* Expression: .98
                                        * Referenced by: '<S5>/convert to  radians1'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S8>/Constant1'
                                        */
  -0.0087266462599716477,              /* Expression: ES
                                        * Referenced by: '<S3>/convert to  radians'
                                        */
  200.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S7>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S7>/UD'
                                        */

  /*  Expression: KLQRC
   * Referenced by: '<S3>/LQR'
   */
  { -0.21600000000000003, -1.11537216, -78.2912, -12.555 },
  251.0,                               /* Expression: 251
                                        * Referenced by: '<S3>/Constant1'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S3>/Discrete-Time  Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time  Integrator1'
                                        */

  /*  Expression: Ki
   * Referenced by: '<S3>/LQR1'
   */
  { -0.0216, -0.0, 1.0, 0.0 },
  28.333333333333332,                  /* Expression: V2DCB
                                        * Referenced by: '<S8>/conversion to duty cycle (convert to int)'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S8>/Saturation 0 to 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Saturation 0 to 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Discrete FIR Filter'
                                        */

  /*  Expression: ones(1,100)
   * Referenced by: '<S4>/Discrete FIR Filter'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },
  0.01,                                /* Expression: 1/100
                                        * Referenced by: '<S4>/Gain2'
                                        */
  0.55,                                /* Expression: const
                                        * Referenced by: '<S2>/Constant'
                                        */
  3U,                                  /* Computed Parameter: SerialTransmit1_p1
                                        * Referenced by: '<S3>/Serial Transmit1'
                                        */
  13U,                                 /* Computed Parameter: GainAdjust1_p1
                                        * Referenced by: '<S3>/Gain Adjust1'
                                        */
  0,                                   /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S8>/Switch1'
                                        */
  0,                                   /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S8>/Switch2'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S5>/Delay'
                                        */
  -32768,                              /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S6>/Gain2'
                                        */
  -32768,                              /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S6>/Gain1'
                                        */
  13U,                                 /* Expression: uint8(13)
                                        * Referenced by: '<S1>/S-Function Builder1'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  18U,                                 /* Expression: uint8(18)
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  19U,                                 /* Expression: uint8(19)
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S3>/Manual Switch'
                                        */
  45U,                                 /* Expression: uint8(45)
                                        * Referenced by: '<S8>/S-Function Builder1'
                                        */
  44U                                  /* Expression: uint8(44)
                                        * Referenced by: '<S8>/S-Function Builder2'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
