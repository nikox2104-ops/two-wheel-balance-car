% Run Ideal_2ndOrder_PI_Sat_Q.slx to obtain 
% motor spped cpontrol response

% Reference velocity/speed
Veloref = 6; % rad/s
Vref = 4.5;     % volts
LoopGain = 0.12;

% Controller parameters
Kp = 0.9;
Ki = 38;
Kd = 0;

% Simulation parameters
sim_stop_time = 2; %0.5;
sim_step_size = 0.01;
ctl_step_size = 0.01;

% Run Simulink model
sim('Ideal_2ndOrder_PI_Sat_CtlStep_Q');
save Ideal_2ndOrder_PI_Sat_CtlStep_Q_verify_deploy;

% Plot motor speed control results
control_response = plot(tsim,motor_speed,'b');hold on;
Veloref_PI = plot([0 tsim(end)],[Veloref Veloref],'r');
speed_d = plot(tsim(1:end-4),speed_Q(5:end),'k');
xlabel('Time (second)');
ylabel('Motor Speed (rad/s)');
title('Ctl step=0.03, Kp=0.9, Ki = 38');

load Model_verification_deploy_run;
speed_encoder = WindowDat;
tsim_deploy = (0:100)*sim_step_size;
speed_actual = plot(tsim_deploy,speed_encoder,'g--');

legend('Idear motor response (rad/s)',...
       'Reference speed (rad/s)',...
       'Simulated motor response (rad/s)',...
       'Actual motor response (rad/s)');hold off
axis([0 1 0 8]);  






