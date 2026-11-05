% Run Ideal_2ndOrder_StepRep.slx to obtain motor step response

% Plot motor sep response obtained earlier
load Ideal_2ndOrder_StepRes_9v;
plot(tsim,motor_speed,'b'); hold on

% Plot proportional only control results
load Ideal_2ndOrder_PI_Prop_only;
Ideal_P = plot(tsim,motor_speed,'m');
control_P = plot(tsim,control_input,'m--');
Veloref_P = plot([0 tsim(end)],[Veloref Veloref],'r');

% Set controller parameters
Kp = 0.9;
Ki = 38;
Kd = 0;

% Run Simulink model
sim('Ideal_2ndOrder_PI');

% Plot PI control results
Ideal_PI = plot(tsim,motor_speed,'g');
control_PI = plot(tsim,control_input,'g--');
xlabel('Time (second)');
ylabel('Motor Speed (rad/s)');
title('Ideal 2nd Oder, PI controller, Kp=0.9, Ki=38');
legend('Step response (rad/s)',...
       'P-control response (rad/s)',...
       'P-control input (volts)',...
       'Reference speed (rad/s)',...
       'PI-control response (rad/s)',...
       'PI-control input (volts)');hold off



