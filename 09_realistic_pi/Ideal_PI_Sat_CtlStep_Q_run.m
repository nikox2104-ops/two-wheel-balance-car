% Run Ideal_2ndOrder_PI_Sat_Q.slx to obtain motor response

% Reference velocity/speed
Veloref = 12; % rad/s
Vref = 9;     % volts
LoopGain = 0.12;

% Controller parameters
Kp = 0.9;
Ki = 38;
Kd = 0;

% Simulation parameters
sim_stop_time = 1; %0.5;
sim_step_size = 0.0001;
ctl_step_size = 0.03;

% Run Simulink model
sim('Ideal_2ndOrder_PI_Sat_CtlStep_Q');
save Ideal_2ndOrder_PI_Sat_CtlStep_Q;

% Plot motor speed control results
control_response = plot(tsim,motor_speed,'b');hold on;
Veloref_PI = plot([0 tsim(end)],[Veloref Veloref],'r');
control_desire = plot(tsim,ctl_desire,'m--');
control_actual = plot(tsim,ctl_actual,'g--');
control_PWM = plot(tsim,ctl_PWM/10,'c--');
speed_encoder = plot(tsim,speed_Q,'k');
xlabel('Time (second)');
ylabel('Motor Speed (rad/s)');
title('Ideal 2nd Oder, Ctl step=0.03, Kp=0.9, Ki = 38');
legend('Motor response (rad/s)',...
       'Reference speed (rad/s)',...
       'control desired (volts)',...
       'control actual (volts)', ...
       'control PWM /10',...
       'speed from encoder (rad/s)');hold off




