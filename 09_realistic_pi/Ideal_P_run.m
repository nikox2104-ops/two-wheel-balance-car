% Run Ideal_2ndOrder_StepRep.slx to obtain motor step response

% Plot motor sep response obtained earlier
load Ideal_2ndOrder_StepRes_9v;
plot(tsim,motor_speed,'b'); hold on

% Reference velocity/speed
Veloref = 12; % rad/s

% Controller parameters
Kp = 0.9;
Ki = 0;
Kd = 0;

% Run Simulink model
sim('Ideal_2ndOrder_PI');
save Ideal_2ndOrder_PI_Prop_only;

% Plot motor speed control results
Ideal_P = plot(tsim,motor_speed,'m');
control_P = plot(tsim,control_input,'m--');
Veloref_P = plot([0 tsim(end)],[Veloref Veloref],'r');
xlabel('Time (second)');
ylabel('Motor Speed (rad/s)');
title('Ideal 2nd Oder, Proportional Only, Kp=0.9');
legend('Step response (rad/s)',...
       'P-control response (rad/s)',...
       'P-control input (volts)',...
       'Reference speed (rad/s)'); hold off




