/*
 * File: Mega_BalanceCode.c
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
#include "Mega_BalanceCode_dt.h"

/* Block signals (auto storage) */
BlockIO_Mega_BalanceCode Mega_BalanceCode_B;

/* Block states (auto storage) */
D_Work_Mega_BalanceCode Mega_BalanceCode_DWork;

/* Real-time model */
RT_MODEL_Mega_BalanceCode Mega_BalanceCode_M_;
RT_MODEL_Mega_BalanceCode *const Mega_BalanceCode_M = &Mega_BalanceCode_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u;
  int16_T u_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u = 1;
    } else {
      u = -1;
    }

    if (u1 > 0.0) {
      u_0 = 1;
    } else {
      u_0 = -1;
    }

    y = atan2(u, u_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void Mega_BalanceCode_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  uint16_T rtb_GainAdjust;
  int32_T cff;
  int32_T j;
  real_T rtb_ManualSwitch;
  real_T rtb_Fcn;
  int16_T rtb_conversiontodutycycleconver;
  uint8_T rtb_DataTypeConversion;
  real_T rtb_Switch;
  int16_T rtb_conversiontodutycycleconv_0;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mega_BalanceCode_DWork.Clear13_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mega_BalanceCode_DWork.FSBController_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mega_BalanceCode_DWork.GyroCalibration_SubsysRanBC);

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Mega_BalanceCode_M->Timing.t[0];

  /* Fcn: '<Root>/Fcn' */
  Mega_BalanceCode_B.Fcn = ((rtb_Clock > 0.55) && (rtb_Clock < 0.65));

  /* Outputs for Enabled SubSystem: '<Root>/Clear 13 ' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (Mega_BalanceCode_B.Fcn > 0.0) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<S1>/Constant'
     */
    Mega_BalanceCode_B.DataTypeConversion = (Mega_BalanceCode_P.Constant_Value
      != 0.0);

    /* S-Function (sfcn_Digital_Out_3): '<S1>/S-Function Builder1' */
    sfcn_Digital_Out_3_Outputs_wrapper(&Mega_BalanceCode_B.DataTypeConversion,
      &Mega_BalanceCode_DWork.SFunctionBuilder1_DSTATE_o,
      &Mega_BalanceCode_P.SFunctionBuilder1_P1, 1);
    srUpdateBC(Mega_BalanceCode_DWork.Clear13_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/Clear 13 ' */

  /* S-Function (sf_MPU6050_Driver_GxAyz): '<Root>/Gyro Driver SFunction' */
  sf_MPU6050_Driver_GxAyz_Outputs_wrapper
    ( &Mega_BalanceCode_B.GyroDriverSFunction_o1,
     &Mega_BalanceCode_B.GyroDriverSFunction_o2,
     &Mega_BalanceCode_B.GyroDriverSFunction_o3,
     &Mega_BalanceCode_DWork.GyroDriverSFunction_DSTATE);

  /* DataTypeConversion: '<Root>/Data Type  Conversion1' */
  Mega_BalanceCode_B.DataTypeConversion1 =
    Mega_BalanceCode_B.GyroDriverSFunction_o1;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Mega_BalanceCode_B.Compare = (rtb_Clock > Mega_BalanceCode_P.Constant_Value_o);

  /* Logic: '<Root>/Logical Operator' */
  Mega_BalanceCode_B.LogicalOperator = !Mega_BalanceCode_B.Compare;

  /* Outputs for Enabled SubSystem: '<Root>/Gyro Calibration' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (Mega_BalanceCode_B.LogicalOperator) {
    /* DiscreteFir: '<S4>/Discrete FIR Filter' */
    rtb_Fcn = Mega_BalanceCode_B.DataTypeConversion1 *
      Mega_BalanceCode_P.DiscreteFIRFilter_Coefficients[0];
    cff = 1L;
    for (j = Mega_BalanceCode_DWork.DiscreteFIRFilter_circBuf; j < 99L; j++) {
      rtb_Fcn += Mega_BalanceCode_DWork.DiscreteFIRFilter_states[j] *
        Mega_BalanceCode_P.DiscreteFIRFilter_Coefficients[cff];
      cff++;
    }

    for (j = 0L; j < Mega_BalanceCode_DWork.DiscreteFIRFilter_circBuf; j++) {
      rtb_Fcn += Mega_BalanceCode_DWork.DiscreteFIRFilter_states[j] *
        Mega_BalanceCode_P.DiscreteFIRFilter_Coefficients[cff];
      cff++;
    }

    /* End of DiscreteFir: '<S4>/Discrete FIR Filter' */

    /* Gain: '<S4>/Gain2' */
    Mega_BalanceCode_B.Gain2 = Mega_BalanceCode_P.Gain2_Gain * rtb_Fcn;
    srUpdateBC(Mega_BalanceCode_DWork.GyroCalibration_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/Gyro Calibration' */

  /* Outputs for Enabled SubSystem: '<Root>/FSB Controller' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (Mega_BalanceCode_B.Compare) {
    /* DiscreteIntegrator: '<S3>/Discrete-Time  Integrator' */
    Mega_BalanceCode_B.DiscreteTimeIntegrator =
      Mega_BalanceCode_DWork.DiscreteTimeIntegrator_DSTATE;

    /* Sum: '<S6>/Sum2' incorporates:
     *  Constant: '<S6>/Y Bias'
     *  Constant: '<S6>/Z Bias'
     *  Constant: '<S6>/Z Bias1'
     *  Gain: '<S6>/Gain1'
     *  Gain: '<S6>/Gain2'
     *  Sum: '<S6>/Sum'
     *  Sum: '<S6>/Sum1'
     *  Trigonometry: '<S6>/Trigonometric Function'
     */
    Mega_BalanceCode_B.Sum2 = rt_atan2d_snf((real_T)((int32_T)
      Mega_BalanceCode_P.Gain2_Gain_k *
      Mega_BalanceCode_B.GyroDriverSFunction_o3) * 3.0517578125E-5 -
      Mega_BalanceCode_P.ZBias_Value, (real_T)((int32_T)
      Mega_BalanceCode_P.Gain1_Gain * Mega_BalanceCode_B.GyroDriverSFunction_o2)
      * 3.0517578125E-5 - Mega_BalanceCode_P.YBias_Value) +
      Mega_BalanceCode_P.ZBias1_Value;

    /* Gain: '<S3>/conver to radians//sed' incorporates:
     *  Sum: '<S3>/Sum'
     */
    Mega_BalanceCode_B.convertoradianssed =
      (Mega_BalanceCode_B.DataTypeConversion1 - Mega_BalanceCode_B.Gain2) *
      Mega_BalanceCode_P.convertoradianssed_Gain;

    /* Sum: '<S5>/Sum2' incorporates:
     *  Delay: '<S5>/Delay'
     *  Gain: '<S5>/convert to  radians1'
     *  Gain: '<S5>/convert to  radians2'
     *  Gain: '<S5>/convert to  radians6'
     *  Sum: '<S5>/Sum1'
     */
    Mega_BalanceCode_B.Sum2_h = (Mega_BalanceCode_P.converttoradians2_Gain *
      Mega_BalanceCode_B.convertoradianssed +
      Mega_BalanceCode_DWork.Delay_DSTATE) *
      Mega_BalanceCode_P.converttoradians1_Gain +
      Mega_BalanceCode_P.converttoradians6_Gain * Mega_BalanceCode_B.Sum2;

    /* DataTypeConversion: '<S3>/Data Type  Conversion4' incorporates:
     *  Fcn: '<S3>/Fcn2'
     */
    rtb_ManualSwitch = floor((Mega_BalanceCode_B.DiscreteTimeIntegrator * 180.0 /
      3.1415926535897931 + 10.0) / 20.0 * 255.0);
    if (rtIsNaN(rtb_ManualSwitch) || rtIsInf(rtb_ManualSwitch)) {
      rtb_ManualSwitch = 0.0;
    } else {
      rtb_ManualSwitch = fmod(rtb_ManualSwitch, 256.0);
    }

    /* S-Function (arduinoserialwrite_sfcn): '<S3>/Serial Transmit1' incorporates:
     *  DataTypeConversion: '<S3>/Data Type  Conversion4'
     */
    rtb_DataTypeConversion = (uint8_T)(rtb_ManualSwitch < 0.0 ? (int16_T)
      (uint8_T)-(int8_T)(uint8_T)-rtb_ManualSwitch : (int16_T)(uint8_T)
      rtb_ManualSwitch);
    Serial_write(Mega_BalanceCode_P.SerialTransmit1_p1, &rtb_DataTypeConversion,
                 1UL);

    /* Fcn: '<S3>/Fcn' */
    rtb_Fcn = (fabs(Mega_BalanceCode_B.Sum2_h) < 0.75);

    /* S-Function (sf_Encoder_18_19): '<S3>/Encoder1' */
    sf_Encoder_18_19_Outputs_wrapper( &Mega_BalanceCode_B.Encoder1,
      &Mega_BalanceCode_DWork.Encoder1_DSTATE, &Mega_BalanceCode_P.Encoder1_P1,
      1, &Mega_BalanceCode_P.Encoder1_P2, 1, &Mega_BalanceCode_P.Encoder1_P3, 1);

    /* Gain: '<S3>/convert to  radians' incorporates:
     *  DataTypeConversion: '<S3>/Data Type  Conversion2'
     */
    rtb_ManualSwitch = Mega_BalanceCode_P.converttoradians_Gain * (real_T)
      Mega_BalanceCode_B.Encoder1;

    /* SampleTimeMath: '<S7>/TSamp'
     *
     * About '<S7>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    Mega_BalanceCode_B.TSamp = rtb_ManualSwitch * Mega_BalanceCode_P.TSamp_WtEt;

    /* SignalConversion: '<S3>/TmpSignal ConversionAtLQRInport1' incorporates:
     *  Sum: '<S3>/Sum3'
     *  Sum: '<S3>/Sum4'
     *  Sum: '<S7>/Diff'
     *  UnitDelay: '<S7>/UD'
     */
    Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[0] =
      Mega_BalanceCode_B.Sum2_h + rtb_ManualSwitch;
    Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[1] =
      (Mega_BalanceCode_B.TSamp - Mega_BalanceCode_DWork.UD_DSTATE) +
      Mega_BalanceCode_B.convertoradianssed;
    Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[2] =
      Mega_BalanceCode_B.Sum2_h;
    Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[3] =
      Mega_BalanceCode_B.convertoradianssed;

    /* Gain: '<S3>/LQR' */
    rtb_Switch = ((Mega_BalanceCode_P.LQR_Gain[0] *
                   Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[0] +
                   Mega_BalanceCode_P.LQR_Gain[1] *
                   Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[1]) +
                  Mega_BalanceCode_P.LQR_Gain[2] *
                  Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[2]) +
      Mega_BalanceCode_P.LQR_Gain[3] *
      Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[3];

    /* Fcn: '<S3>/Fcn3' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    rtb_ManualSwitch = (Mega_BalanceCode_P.Constant1_Value_k - 100.0) *
      0.00073313782991202346 + 0.25;

    /* S-Function (arduinoanaloginput_sfcn): '<S3>/Gain Adjust1' */
    rtb_GainAdjust = MW_analogRead(Mega_BalanceCode_P.GainAdjust1_p1);

    /* ManualSwitch: '<S3>/Manual Switch' incorporates:
     *  DataTypeConversion: '<S3>/Data Type  Conversion3'
     *  Fcn: '<S3>/Fcn1'
     *  S-Function (arduinoanaloginput_sfcn): '<S3>/Gain Adjust1'
     */
    if (Mega_BalanceCode_P.ManualSwitch_CurrentSetting != 1) {
      rtb_ManualSwitch = ((real_T)rtb_GainAdjust - 75.0) *
        0.00073313782991202346 + 0.25;
    }

    /* End of ManualSwitch: '<S3>/Manual Switch' */

    /* Gain: '<S8>/conversion to duty cycle (convert to int)' incorporates:
     *  DiscreteIntegrator: '<S3>/Discrete-Time  Integrator1'
     *  Gain: '<S3>/LQR'
     *  Gain: '<S3>/LQR1'
     *  Product: '<S3>/Product'
     *  Product: '<S3>/Product1'
     *  Sum: '<S3>/Sum5'
     */
    rtb_ManualSwitch = floor(((((Mega_BalanceCode_P.LQR1_Gain[0] *
      Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[0] +
      Mega_BalanceCode_P.LQR1_Gain[1] *
      Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[1]) +
      Mega_BalanceCode_P.LQR1_Gain[2] *
      Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[2]) +
      Mega_BalanceCode_P.LQR1_Gain[3] *
      Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[3]) + rtb_Switch *
      rtb_ManualSwitch) * rtb_Fcn *
      Mega_BalanceCode_P.conversiontodutycycleconverttoi);
    if (rtIsNaN(rtb_ManualSwitch) || rtIsInf(rtb_ManualSwitch)) {
      rtb_ManualSwitch = 0.0;
    } else {
      rtb_ManualSwitch = fmod(rtb_ManualSwitch, 65536.0);
    }

    rtb_conversiontodutycycleconver = rtb_ManualSwitch < 0.0 ? -(int16_T)
      (uint16_T)-rtb_ManualSwitch : (int16_T)(uint16_T)rtb_ManualSwitch;

    /* End of Gain: '<S8>/conversion to duty cycle (convert to int)' */

    /* Abs: '<S8>/Abs1' */
    if (rtb_conversiontodutycycleconver < 0) {
      rtb_conversiontodutycycleconv_0 = -rtb_conversiontodutycycleconver;
    } else {
      rtb_conversiontodutycycleconv_0 = rtb_conversiontodutycycleconver;
    }

    /* Sum: '<S8>/Sum' incorporates:
     *  Abs: '<S8>/Abs1'
     *  Constant: '<S8>/Constant1'
     */
    rtb_Fcn = Mega_BalanceCode_P.Constant1_Value + (real_T)
      rtb_conversiontodutycycleconv_0;

    /* Saturate: '<S8>/Saturation 0 to 1' */
    if (rtb_Fcn >= Mega_BalanceCode_P.Saturation0to1_UpperSat) {
      rtb_Fcn = Mega_BalanceCode_P.Saturation0to1_UpperSat;
    } else {
      if (rtb_Fcn <= Mega_BalanceCode_P.Saturation0to1_LowerSat) {
        rtb_Fcn = Mega_BalanceCode_P.Saturation0to1_LowerSat;
      }
    }

    /* End of Saturate: '<S8>/Saturation 0 to 1' */

    /* Switch: '<S8>/Switch1' */
    if (rtb_conversiontodutycycleconver >= Mega_BalanceCode_P.Switch1_Threshold)
    {
      /* DataTypeConversion: '<S8>/Data Type  Conversion1' */
      rtb_ManualSwitch = floor(rtb_Fcn);
      if (rtIsNaN(rtb_ManualSwitch) || rtIsInf(rtb_ManualSwitch)) {
        rtb_ManualSwitch = 0.0;
      } else {
        rtb_ManualSwitch = fmod(rtb_ManualSwitch, 256.0);
      }

      Mega_BalanceCode_B.DataTypeConversion1_m = (uint8_T)(rtb_ManualSwitch <
        0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_ManualSwitch : (int16_T)
        (uint8_T)rtb_ManualSwitch);
    } else {
      /* DataTypeConversion: '<S8>/Data Type  Conversion1' incorporates:
       *  Constant: '<S8>/Constant4'
       */
      rtb_ManualSwitch = floor(Mega_BalanceCode_P.Constant4_Value);
      if (rtIsNaN(rtb_ManualSwitch) || rtIsInf(rtb_ManualSwitch)) {
        rtb_ManualSwitch = 0.0;
      } else {
        rtb_ManualSwitch = fmod(rtb_ManualSwitch, 256.0);
      }

      Mega_BalanceCode_B.DataTypeConversion1_m = (uint8_T)(rtb_ManualSwitch <
        0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_ManualSwitch : (int16_T)
        (uint8_T)rtb_ManualSwitch);
    }

    /* End of Switch: '<S8>/Switch1' */

    /* S-Function (sfcn_PWM45): '<S8>/S-Function Builder1' */
    sfcn_PWM45_Outputs_wrapper(&Mega_BalanceCode_B.DataTypeConversion1_m,
      &Mega_BalanceCode_DWork.SFunctionBuilder1_DSTATE,
      &Mega_BalanceCode_P.SFunctionBuilder1_P1_p, 1);

    /* Switch: '<S8>/Switch2' incorporates:
     *  Constant: '<S8>/Constant4'
     */
    if (rtb_conversiontodutycycleconver >= Mega_BalanceCode_P.Switch2_Threshold)
    {
      rtb_Fcn = Mega_BalanceCode_P.Constant4_Value;
    }

    /* End of Switch: '<S8>/Switch2' */

    /* DataTypeConversion: '<S8>/Data Type  Conversion5' */
    rtb_ManualSwitch = floor(rtb_Fcn);
    if (rtIsNaN(rtb_ManualSwitch) || rtIsInf(rtb_ManualSwitch)) {
      rtb_ManualSwitch = 0.0;
    } else {
      rtb_ManualSwitch = fmod(rtb_ManualSwitch, 256.0);
    }

    Mega_BalanceCode_B.DataTypeConversion5 = (uint8_T)(rtb_ManualSwitch < 0.0 ?
      (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_ManualSwitch : (int16_T)(uint8_T)
      rtb_ManualSwitch);

    /* End of DataTypeConversion: '<S8>/Data Type  Conversion5' */

    /* S-Function (sfcn_PWM44): '<S8>/S-Function Builder2' */
    sfcn_PWM44_Outputs_wrapper(&Mega_BalanceCode_B.DataTypeConversion5,
      &Mega_BalanceCode_DWork.SFunctionBuilder2_DSTATE,
      &Mega_BalanceCode_P.SFunctionBuilder2_P1, 1);
    srUpdateBC(Mega_BalanceCode_DWork.FSBController_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/FSB Controller' */
}

/* Model update function */
void Mega_BalanceCode_update(void)
{
  /* Update for Enabled SubSystem: '<Root>/Clear 13 ' incorporates:
   *  Update for EnablePort: '<S1>/Enable'
   */
  if (Mega_BalanceCode_B.Fcn > 0.0) {
    /* S-Function "sfcn_Digital_Out_3_wrapper" Block: <S1>/S-Function Builder1 */
    sfcn_Digital_Out_3_Update_wrapper(&Mega_BalanceCode_B.DataTypeConversion,
      &Mega_BalanceCode_DWork.SFunctionBuilder1_DSTATE_o,
      &Mega_BalanceCode_P.SFunctionBuilder1_P1, 1);
  }

  /* End of Update for SubSystem: '<Root>/Clear 13 ' */

  /* S-Function "sf_MPU6050_Driver_GxAyz_wrapper" Block: <Root>/Gyro Driver SFunction */
  sf_MPU6050_Driver_GxAyz_Update_wrapper
    ( &Mega_BalanceCode_B.GyroDriverSFunction_o1,
     &Mega_BalanceCode_B.GyroDriverSFunction_o2,
     &Mega_BalanceCode_B.GyroDriverSFunction_o3,
     &Mega_BalanceCode_DWork.GyroDriverSFunction_DSTATE);

  /* Update for Enabled SubSystem: '<Root>/Gyro Calibration' incorporates:
   *  Update for EnablePort: '<S4>/Enable'
   */
  if (Mega_BalanceCode_B.LogicalOperator) {
    /* Update for DiscreteFir: '<S4>/Discrete FIR Filter' */
    Mega_BalanceCode_DWork.DiscreteFIRFilter_circBuf--;
    if (Mega_BalanceCode_DWork.DiscreteFIRFilter_circBuf < 0L) {
      Mega_BalanceCode_DWork.DiscreteFIRFilter_circBuf = 98L;
    }

    Mega_BalanceCode_DWork.DiscreteFIRFilter_states[Mega_BalanceCode_DWork.DiscreteFIRFilter_circBuf]
      = Mega_BalanceCode_B.DataTypeConversion1;

    /* End of Update for DiscreteFir: '<S4>/Discrete FIR Filter' */
  }

  /* End of Update for SubSystem: '<Root>/Gyro Calibration' */

  /* Update for Enabled SubSystem: '<Root>/FSB Controller' incorporates:
   *  Update for EnablePort: '<S3>/Enable'
   */
  if (Mega_BalanceCode_B.Compare) {
    /* Update for DiscreteIntegrator: '<S3>/Discrete-Time  Integrator' */
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator_DSTATE +=
      Mega_BalanceCode_P.DiscreteTimeIntegrator_gainval *
      Mega_BalanceCode_B.convertoradianssed;

    /* Update for Delay: '<S5>/Delay' */
    Mega_BalanceCode_DWork.Delay_DSTATE = Mega_BalanceCode_B.Sum2_h;

    /* S-Function "sf_Encoder_18_19_wrapper" Block: <S3>/Encoder1 */
    sf_Encoder_18_19_Update_wrapper( &Mega_BalanceCode_B.Encoder1,
      &Mega_BalanceCode_DWork.Encoder1_DSTATE, &Mega_BalanceCode_P.Encoder1_P1,
      1, &Mega_BalanceCode_P.Encoder1_P2, 1, &Mega_BalanceCode_P.Encoder1_P3, 1);

    /* Update for UnitDelay: '<S7>/UD' */
    Mega_BalanceCode_DWork.UD_DSTATE = Mega_BalanceCode_B.TSamp;

    /* Update for DiscreteIntegrator: '<S3>/Discrete-Time  Integrator1' */
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[0] +=
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_gainval *
      Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[0];
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[1] +=
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_gainval *
      Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[1];
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[2] +=
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_gainval *
      Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[2];
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[3] +=
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_gainval *
      Mega_BalanceCode_B.TmpSignalConversionAtLQRInport1[3];

    /* S-Function "sfcn_PWM45_wrapper" Block: <S8>/S-Function Builder1 */
    sfcn_PWM45_Update_wrapper(&Mega_BalanceCode_B.DataTypeConversion1_m,
      &Mega_BalanceCode_DWork.SFunctionBuilder1_DSTATE,
      &Mega_BalanceCode_P.SFunctionBuilder1_P1_p, 1);

    /* S-Function "sfcn_PWM44_wrapper" Block: <S8>/S-Function Builder2 */
    sfcn_PWM44_Update_wrapper(&Mega_BalanceCode_B.DataTypeConversion5,
      &Mega_BalanceCode_DWork.SFunctionBuilder2_DSTATE,
      &Mega_BalanceCode_P.SFunctionBuilder2_P1, 1);
  }

  /* End of Update for SubSystem: '<Root>/FSB Controller' */

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Mega_BalanceCode_M)!=-1) &&
        !((rtmGetTFinal(Mega_BalanceCode_M)-Mega_BalanceCode_M->Timing.t[0]) >
          Mega_BalanceCode_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Mega_BalanceCode_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Mega_BalanceCode_M)) {
      rtmSetErrorStatus(Mega_BalanceCode_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Mega_BalanceCode_M->Timing.t[0] =
    (++Mega_BalanceCode_M->Timing.clockTick0) *
    Mega_BalanceCode_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Mega_BalanceCode_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Mega_BalanceCode_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Mega_BalanceCode_M, 0,
                sizeof(RT_MODEL_Mega_BalanceCode));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Mega_BalanceCode_M->solverInfo,
                          &Mega_BalanceCode_M->Timing.simTimeStep);
    rtsiSetTPtr(&Mega_BalanceCode_M->solverInfo, &rtmGetTPtr(Mega_BalanceCode_M));
    rtsiSetStepSizePtr(&Mega_BalanceCode_M->solverInfo,
                       &Mega_BalanceCode_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Mega_BalanceCode_M->solverInfo, (&rtmGetErrorStatus
      (Mega_BalanceCode_M)));
    rtsiSetRTModelPtr(&Mega_BalanceCode_M->solverInfo, Mega_BalanceCode_M);
  }

  rtsiSetSimTimeStep(&Mega_BalanceCode_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Mega_BalanceCode_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Mega_BalanceCode_M, &Mega_BalanceCode_M->Timing.tArray[0]);
  rtmSetTFinal(Mega_BalanceCode_M, 10.0);
  Mega_BalanceCode_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  Mega_BalanceCode_M->Sizes.checksums[0] = (1146736985U);
  Mega_BalanceCode_M->Sizes.checksums[1] = (2323680255U);
  Mega_BalanceCode_M->Sizes.checksums[2] = (967475723U);
  Mega_BalanceCode_M->Sizes.checksums[3] = (1060849694U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Mega_BalanceCode_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Mega_BalanceCode_DWork.Clear13_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Mega_BalanceCode_DWork.FSBController_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Mega_BalanceCode_DWork.GyroCalibration_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Mega_BalanceCode_M->extModeInfo,
      &Mega_BalanceCode_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Mega_BalanceCode_M->extModeInfo,
                        Mega_BalanceCode_M->Sizes.checksums);
    rteiSetTPtr(Mega_BalanceCode_M->extModeInfo, rtmGetTPtr(Mega_BalanceCode_M));
  }

  /* block I/O */
  (void) memset(((void *) &Mega_BalanceCode_B), 0,
                sizeof(BlockIO_Mega_BalanceCode));

  /* states (dwork) */
  (void) memset((void *)&Mega_BalanceCode_DWork, 0,
                sizeof(D_Work_Mega_BalanceCode));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Mega_BalanceCode_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  {
    int16_T i;

    /* InitializeConditions for Enabled SubSystem: '<Root>/Clear 13 ' */

    /* S-Function Block: <S1>/S-Function Builder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Mega_BalanceCode_DWork.SFunctionBuilder1_DSTATE_o = initVector[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<Root>/Clear 13 ' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/Gyro Calibration' */
    /* InitializeConditions for DiscreteFir: '<S4>/Discrete FIR Filter' */
    Mega_BalanceCode_DWork.DiscreteFIRFilter_circBuf = 0L;
    for (i = 0; i < 99; i++) {
      Mega_BalanceCode_DWork.DiscreteFIRFilter_states[i] =
        Mega_BalanceCode_P.DiscreteFIRFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S4>/Discrete FIR Filter' */
    /* End of InitializeConditions for SubSystem: '<Root>/Gyro Calibration' */
    /* Start for S-Function (arduinoanaloginput_sfcn): '<S3>/Gain Adjust1' */
    MW_pinModeInput(Mega_BalanceCode_P.GainAdjust1_p1);

    /* End of Start for SubSystem: '<Root>/FSB Controller' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/FSB Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time  Integrator' */
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator_DSTATE =
      Mega_BalanceCode_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for Delay: '<S5>/Delay' */
    Mega_BalanceCode_DWork.Delay_DSTATE =
      Mega_BalanceCode_P.Delay_InitialCondition;

    /* S-Function Block: <S3>/Encoder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Mega_BalanceCode_DWork.Encoder1_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S7>/UD' */
    Mega_BalanceCode_DWork.UD_DSTATE = Mega_BalanceCode_P.UD_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time  Integrator1' */
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[0] =
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_IC;
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[1] =
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_IC;
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[2] =
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_IC;
    Mega_BalanceCode_DWork.DiscreteTimeIntegrator1_DSTATE[3] =
      Mega_BalanceCode_P.DiscreteTimeIntegrator1_IC;

    /* S-Function Block: <S8>/S-Function Builder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Mega_BalanceCode_DWork.SFunctionBuilder1_DSTATE = initVector[0];
        }
      }
    }

    /* S-Function Block: <S8>/S-Function Builder2 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Mega_BalanceCode_DWork.SFunctionBuilder2_DSTATE = initVector[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<Root>/FSB Controller' */
  }

  /* S-Function Block: <Root>/Gyro Driver SFunction */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Mega_BalanceCode_DWork.GyroDriverSFunction_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void Mega_BalanceCode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
