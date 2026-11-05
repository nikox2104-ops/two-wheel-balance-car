% Run Ideal_2ndOrder_StepRep.slx to obtain motor step response

% Motor parameters
R  = 5.262773292;    % ohms
Kb = 0.4952900056;   % V.s/rad
Kt = 0.3233728703;   % N.m/A
b  = 0.0006001689451;  % N.m.s/rad
L  = 0.0047;         % H
J  = 0.001321184025; % kg.m^2
%Tf = 0.02;  % N.m

% Reference voltage
Vref = 9;

% Simulation parameters
sim_stop_time = 0.3;
sim_step_size = 0.0001;

% Run Simulink model
sim('Ideal_2ndOrder_StepRes');
save Ideal_2ndOrder_StepRes_9v;

% Plot motor step response
Ideal_StepRes = plot(tsim,motor_speed*RADSEC2RPM);
xlabel('Time (second)');
ylabel('Motor Speed (RPM)');
title('Ideal 2nd Oder Step Response');grid on;


