%%
% Lab 8 - Basic Motor Control
% 
% Neil Ding, 06/14/2015

%% Open Simulink Model
open('Lab8_p1_MotorSystem_13b.slx');
% or
% open('Lab8_p1_PosOpenCtrl_13b.slx');

%% Modify supply voltage if necessary
% USB Power: 4.5v; Battery Power: 9v
Vs = 4.5;
sim_step_size = 0.03;

%%
Vin = 1;

%% Deploy the model to hardware 
% Run 'Plot Data Int16'
% 
%% 
Vel_serial_1v = WindowDat;
save serial_data_USB_1v sim_step_size Vel_serial_1v;

%%
Vin = 2;

%% Deploy the model to hardware 
% Run 'Plot Data Int16'
% 
%%

%% 
Vel_serial_2v = WindowDat;
save serial_data_USB_2v sim_step_size Vel_serial_2v;

%%
Vin = 3;

%% Deploy the model to hardware 
% Run 'Plot Data Int16'
% 
%%

%% 
Vel_serial_3v = WindowDat;
save serial_data_USB_3v sim_step_size Vel_serial_3v;

%%
