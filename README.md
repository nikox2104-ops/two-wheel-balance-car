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

### 调试与实测
- **电机辨识**：1 / 2 / 3 V 阶跃下稳态转速约 22.4 / 57.7 / 70.1 RPM；2 V、20 s 开环位置预测约 13848 counts，实测约 14942 counts，误差约 7.9%。
- **速度 PI**：在 Simulink 中加入 ±9 V 饱和、0.03 s 采样、720 线编码器与 0–255 PWM 量化、一步延迟后重新整定速度环。
- **传感器标定**：MPU6050 上电静置采集约 100 个样本做陀螺零偏校准（约 0.55 s 后才使能输出）；HMC5883L 用最大最小值法校准磁场。
- **姿态估计**：5 ms 周期递推互补滤波 `θ = 0.98·(θ + Ts·ω) + 0.02·θ_acc`。
- **平衡控制**：状态 [车轮位移, 速度, 倾角, 角速度] 的 LQR 状态反馈；针对 43 mm 车轮实物调试零位、轮径与输出极性，最终增益 `K = [18.0000, 70.3023, −152.6693, −23.4192]`。
- **安全保护**：PWM 限幅；倾角超过约 0.75 rad（≈43°）立即关闭电机。
- **结果**：小车可在平坦桌面保持竖直平衡。
- **数据链路**：串口按 uint8 / int16 / float32 传输，蓝牙走 UART3（HC-06）；RealTerm（921600 baud, 8N1）捕获二进制数据，MATLAB `fread` 解析绘图。

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

### Tuning & test results
- Motor identification: steady-state speed ≈ 22.4 / 57.7 / 70.1 RPM at 1 / 2 / 3 V; 2 V / 20 s open-loop position prediction 13848 vs measured 14942 counts (≈7.9% error).
- Speed PI re-tuned with ±9 V saturation, 0.03 s sampling, 720-count encoder and 0–255 PWM quantization, and one-step delay.
- Gyro bias calibration from ~100 samples at power-up (output enabled after ~0.55 s); HMC5883L min/max calibration.
- Attitude: 5 ms recursive complementary filter `θ = 0.98·(θ + Ts·ω) + 0.02·θ_acc`.
- Balance: LQR on [wheel position, velocity, tilt, tilt rate]; zero offset, wheel radius (43 mm) and output polarity calibrated on hardware, final `K = [18.0000, 70.3023, −152.6693, −23.4192]`.
- Safety: PWM limiting; motors cut when tilt exceeds ~0.75 rad (≈43°).
- Result: the car stays upright on a flat desk.

### How to run
Install MATLAB/Simulink Arduino support, open a `.slx` in a module folder, wire as noted in the model, then run External mode or Deploy. Mind Serial0 conflicts when logging data. Read `NXT_Parameters.m` before running the balance controller.

## License
Third-party libraries (I2Cdev, MPU6050, Wire, HMC58X3) keep their original licenses.
