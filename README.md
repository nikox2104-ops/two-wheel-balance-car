# Two-Wheel Balance Car

![cover](cover.png)

基于 Arduino Mega 2560 与 MATLAB/Simulink 的双轮平衡小车：PWM 电机驱动、编码器测速、MPU6050 姿态采集、互补滤波姿态解算、电机 PI 闭环控制，以及蓝牙串口调参与数据回传。

## 中文

### 硬件
- 主控：Arduino Mega 2560
- 电机驱动：DRV8833（双 PWM）
- 传感器：MPU6050（陀螺仪 + 加速度计）、HMC5883L（磁力计）
- 编码器：正交编码约 720 count/rev
- 供电约 9 V；PWM 范围 0–255

### 控制要点
- **电机**：开环增益估计，位置 P / PI 闭环；仿真模型考虑电源饱和、离散步长、编码器/PWM 量化与一步延迟
- **姿态**：陀螺仪短时动态 + 加速度计长期基准的互补滤波  
  `θ[k] = α·(θ[k-1] + ω_gyro[k]·Ts) + (1-α)·θ_acc[k]`
- **平衡控制**：`11_balance_demo` 含完整 Simulink 模型与生成的 C 源码

### 模块目录
| 目录 | 内容 |
|------|------|
| `01_pwm` | LED / PWM 调光 |
| `02_adc_encoder` | ADC 映射与编码器 |
| `03_imu_gyro` | MPU6050 I2C |
| `04_compass` | 磁力计与航向 |
| `05_serial` | 串口多字节传输与捕获 |
| `06_bluetooth` | 蓝牙串口采集 |
| `07_motor_response` | 电机阶跃响应 |
| `08_motor_control` | 开环预测与闭环 P/PI |
| `09_realistic_pi` | 含饱和与量化的速度 PI |
| `10_angle_fusion` | 互补滤波姿态估计 |
| `11_balance_demo` | 平衡控制模型与生成代码 |
| `docs/figures` | 结构图与实验截图 |

### 如何运行
1. 安装 MATLAB/Simulink 与 Arduino 硬件支持包，连接 Mega 2560。
2. 打开对应目录下的 `.slx` 模型，选择 External 或 Deploy to Hardware。
3. 按模型中的引脚说明接好电机驱动、编码器与 MPU6050（I2C）。
4. 串口/蓝牙回传数据时，注意与 External 模式共用串口 0 的冲突。
5. 运行平衡控制前，先阅读 `11_balance_demo/NXT_Parameters.m` 中的参数与安全限幅。

---

## English

Two-wheel self-balancing car on Arduino Mega 2560 with MATLAB/Simulink: PWM motor drive, encoder speed measurement, MPU6050 attitude sensing, complementary-filter tilt estimation, motor PI control, and Bluetooth/serial tuning and data logging.

### Hardware
Arduino Mega 2560, DRV8833 driver, MPU6050, HMC5883L, ~720 count/rev encoder, ~9 V supply, PWM 0–255.

### Control
- Motor: open-loop gain estimate, position P/PI loop; model includes saturation, sampling, quantization and one-step delay
- Attitude: complementary filter fusing gyro and accelerometer
- Balance control model and generated C code in `11_balance_demo/`

### How to run
Install MATLAB/Simulink Arduino support, open a `.slx` in a module folder, wire as noted in the model, then run External mode or Deploy. Mind Serial0 conflicts when logging data. Read `NXT_Parameters.m` before running the balance controller.

## License
Third-party libraries (I2Cdev, MPU6050, Wire, HMC58X3) keep their original licenses.
