% Run Ideal_2ndOrder_PI_Sat.slx to obtain motor response

% Reference velocity/speed
Veloref = 12; % rad/s
Vref = 9;     % volts
LoopGain = 1;

% Controller parameters
Kp = 0.9;
Ki = 38;
Kd = 0;

% Simulation parameters
sim_stop_time = 0.3;
sim_step_size = 0.0001;

% Run Simulink model
sim('Ideal_2ndOrder_PI_Sat');
save Ideal_2ndOrder_PI_Sat;

% Plot motor speed control results
control_response = plot(tsim,motor_speed,'b');hold on;
Veloref_PI = plot([0 tsim(end)],[Veloref Veloref],'r');
control_desire = plot(tsim,ctl_desire,'m--');
control_actual = plot(tsim,ctl_actual,'g--');
xlabel('Time (second)');
ylabel('Motor Speed (rad/s)');
title('Ideal 2nd Oder with Saturation, Kp=0.9, Ki = 38');
legend('Motor response (rad/s)',...
       'Reference speed (rad/s)',...
       'control desired (volts)',...
       'control actual (volts)'); hold off




