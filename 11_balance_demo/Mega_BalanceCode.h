/*
 * File: Mega_BalanceCode.h
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

#ifndef RTW_HEADER_Mega_BalanceCode_h_
#define RTW_HEADER_Mega_BalanceCode_h_
#ifndef Mega_BalanceCode_COMMON_INCLUDES_
# define Mega_BalanceCode_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_serialwrite_lct.h"
#include "arduino_analoginput_lct.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* Mega_BalanceCode_COMMON_INCLUDES_ */

#include "Mega_BalanceCode_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Fcn;                          /* '<Root>/Fcn' */
  real_T DataTypeConversion1;          /* '<Root>/Data Type  Conversion1' */
  real_T Gain2;                        /* '<S4>/Gain2' */
  real_T DiscreteTimeIntegrator;       /* '<S3>/Discrete-Time  Integrator' */
  real_T Sum2;                         /* '<S6>/Sum2' */
  real_T convertoradianssed;           /* '<S3>/conver to radians//sed' */
  real_T Sum2_h;                       /* '<S5>/Sum2' */
  real_T TSamp;                        /* '<S7>/TSamp' */
  real_T TmpSignalConversionAtLQRInport1[4];
  int16_T GyroDriverSFunction_o1;      /* '<Root>/Gyro Driver SFunction' */
  int16_T GyroDriverSFunction_o2;      /* '<Root>/Gyro Driver SFunction' */
  int16_T GyroDriverSFunction_o3;      /* '<Root>/Gyro Driver SFunction' */
  int16_T Encoder1;                    /* '<S3>/Encoder1' */
  uint8_T DataTypeConversion1_m;       /* '<S8>/Data Type  Conversion1' */
  uint8_T DataTypeConversion5;         /* '<S8>/Data Type  Conversion5' */
  boolean_T Compare;                   /* '<S2>/Compare' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
  boolean_T DataTypeConversion;        /* '<S1>/Data Type Conversion' */
} BlockIO_Mega_BalanceCode;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T GyroDriverSFunction_DSTATE;   /* '<Root>/Gyro Driver SFunction' */
  real_T DiscreteFIRFilter_states[99]; /* '<S4>/Discrete FIR Filter' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time  Integrator' */
  real_T Delay_DSTATE;                 /* '<S5>/Delay' */
  real_T Encoder1_DSTATE;              /* '<S3>/Encoder1' */
  real_T UD_DSTATE;                    /* '<S7>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE[4];/* '<S3>/Discrete-Time  Integrator1' */
  real_T SFunctionBuilder1_DSTATE;     /* '<S8>/S-Function Builder1' */
  real_T SFunctionBuilder2_DSTATE;     /* '<S8>/S-Function Builder2' */
  real_T SFunctionBuilder1_DSTATE_o;   /* '<S1>/S-Function Builder1' */
  struct {
    void *LoggedData;
  } Angles_PWORK;                      /* '<S3>/Angles' */

  int32_T DiscreteFIRFilter_circBuf;   /* '<S4>/Discrete FIR Filter' */
  int8_T Clear13_SubsysRanBC;          /* '<Root>/Clear 13 ' */
  int8_T GyroCalibration_SubsysRanBC;  /* '<Root>/Gyro Calibration' */
  int8_T FSBController_SubsysRanBC;    /* '<Root>/FSB Controller' */
} D_Work_Mega_BalanceCode;

/* Parameters (auto storage) */
struct Parameters_Mega_BalanceCode_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S3>/Discrete-Time  Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time  Integrator'
                                        */
  real_T ZBias1_Value;                 /* Expression: .04
                                        * Referenced by: '<S6>/Z Bias1'
                                        */
  real_T ZBias_Value;                  /* Expression: 1430
                                        * Referenced by: '<S6>/Z Bias'
                                        */
  real_T YBias_Value;                  /* Expression: 101
                                        * Referenced by: '<S6>/Y Bias'
                                        */
  real_T converttoradians6_Gain;       /* Expression: .02
                                        * Referenced by: '<S5>/convert to  radians6'
                                        */
  real_T convertoradianssed_Gain;      /* Expression: -GS
                                        * Referenced by: '<S3>/conver to radians//sed'
                                        */
  real_T converttoradians2_Gain;       /* Expression: TS
                                        * Referenced by: '<S5>/convert to  radians2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T converttoradians1_Gain;       /* Expression: .98
                                        * Referenced by: '<S5>/convert to  radians1'
                                        */
  real_T Constant1_Value;              /* Expression: 30
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T converttoradians_Gain;        /* Expression: ES
                                        * Referenced by: '<S3>/convert to  radians'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S7>/TSamp'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S7>/UD'
                                        */
  real_T LQR_Gain[4];                  /* Expression: KLQRC
                                        * Referenced by: '<S3>/LQR'
                                        */
  real_T Constant1_Value_k;            /* Expression: 251
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S3>/Discrete-Time  Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time  Integrator1'
                                        */
  real_T LQR1_Gain[4];                 /* Expression: Ki
                                        * Referenced by: '<S3>/LQR1'
                                        */
  real_T conversiontodutycycleconverttoi;/* Expression: V2DCB
                                          * Referenced by: '<S8>/conversion to duty cycle (convert to int)'
                                          */
  real_T Saturation0to1_UpperSat;      /* Expression: 255
                                        * Referenced by: '<S8>/Saturation 0 to 1'
                                        */
  real_T Saturation0to1_LowerSat;      /* Expression: 0
                                        * Referenced by: '<S8>/Saturation 0 to 1'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T DiscreteFIRFilter_InitialStates;/* Expression: 0
                                          * Referenced by: '<S4>/Discrete FIR Filter'
                                          */
  real_T DiscreteFIRFilter_Coefficients[100];/* Expression: ones(1,100)
                                              * Referenced by: '<S4>/Discrete FIR Filter'
                                              */
  real_T Gain2_Gain;                   /* Expression: 1/100
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint32_T SerialTransmit1_p1;         /* Computed Parameter: SerialTransmit1_p1
                                        * Referenced by: '<S3>/Serial Transmit1'
                                        */
  uint32_T GainAdjust1_p1;             /* Computed Parameter: GainAdjust1_p1
                                        * Referenced by: '<S3>/Gain Adjust1'
                                        */
  int16_T Switch1_Threshold;           /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S8>/Switch1'
                                        */
  int16_T Switch2_Threshold;           /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S8>/Switch2'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S5>/Delay'
                                        */
  int16_T Gain2_Gain_k;                /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S6>/Gain2'
                                        */
  int16_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S6>/Gain1'
                                        */
  uint8_T SFunctionBuilder1_P1;        /* Expression: uint8(13)
                                        * Referenced by: '<S1>/S-Function Builder1'
                                        */
  uint8_T Encoder1_P1;                 /* Expression: uint8(0)
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  uint8_T Encoder1_P2;                 /* Expression: uint8(18)
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  uint8_T Encoder1_P3;                 /* Expression: uint8(19)
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S3>/Manual Switch'
                                        */
  uint8_T SFunctionBuilder1_P1_p;      /* Expression: uint8(45)
                                        * Referenced by: '<S8>/S-Function Builder1'
                                        */
  uint8_T SFunctionBuilder2_P1;        /* Expression: uint8(44)
                                        * Referenced by: '<S8>/S-Function Builder2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Mega_BalanceCode {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_Mega_BalanceCode Mega_BalanceCode_P;

/* Block signals (auto storage) */
extern BlockIO_Mega_BalanceCode Mega_BalanceCode_B;

/* Block states (auto storage) */
extern D_Work_Mega_BalanceCode Mega_BalanceCode_DWork;

/* Model entry point functions */
extern void Mega_BalanceCode_initialize(void);
extern void Mega_BalanceCode_output(void);
extern void Mega_BalanceCode_update(void);
extern void Mega_BalanceCode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mega_BalanceCode *const Mega_BalanceCode_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Mega_BalanceCode'
 * '<S1>'   : 'Mega_BalanceCode/Clear 13 '
 * '<S2>'   : 'Mega_BalanceCode/Compare To Constant'
 * '<S3>'   : 'Mega_BalanceCode/FSB Controller'
 * '<S4>'   : 'Mega_BalanceCode/Gyro Calibration'
 * '<S5>'   : 'Mega_BalanceCode/FSB Controller/ Complimentary Filter'
 * '<S6>'   : 'Mega_BalanceCode/FSB Controller/Angle From Accelerometer (adjust "zero" andle here)'
 * '<S7>'   : 'Mega_BalanceCode/FSB Controller/Discrete  Derivative'
 * '<S8>'   : 'Mega_BalanceCode/FSB Controller/Volts To Adruino PWM (NonLinear LOW) 3388 and Motor'
 */
#endif                                 /* RTW_HEADER_Mega_BalanceCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
