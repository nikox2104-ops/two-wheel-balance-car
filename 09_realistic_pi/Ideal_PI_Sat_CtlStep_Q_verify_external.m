% Run Ideal_2ndOrder_PI_Sat_Q.slx to obtain 
% motor spped cpontrol response

% Reference velocity/speed
Veloref = 3.14; % rad/s
Vref = 4.5;     % volts
LoopGain = 0.12;

% Controller parameters
Kp = 0.9;
Ki = 38;
Kd = 0;

% Simulation parameters
sim_stop_time = 1; %0.5;
sim_step_size = 0.01;
ctl_step_size = 0.03;

% Run Simulink model
sim('Ideal_2ndOrder_PI_Sat_CtlStep_Q');
save Ideal_2ndOrder_PI_Sat_CtlStep_Q_verification;

% Plot motor speed control results
control_response = plot(tsim,motor_speed,'b');hold on;
Veloref_PI = plot([0 tsim(end)],[Veloref Veloref],'r');
%control_desire = plot(tsim,ctl_desire,'m--');
%control_actual = plot(tsim,ctl_actual,'g--');
%control_PWM = plot(tsim,ctl_PWM/10,'c--');
speed_Q = plot(tsim,speed_Q,'k');
xlabel('Time (second)');
ylabel('Motor Speed (rad/s)');
title('Ctl step=0.03, Kp=0.9, Ki = 38');

load Model_verification_external_run1;
speed_actual = plot(tsim(200:end)-tsim(200),...
               speed_encoder(200:end),'g--');

legend('Idear motor response (rad/s)',...
       'Reference speed (rad/s)',...
       'Simulated motor response (rad/s)',...
       'Actual motor response (rad/s)');hold off
   
   
%axis([0 1.5 -1 6]);




