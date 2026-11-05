% Define a set of motor parameters

% Basic SI units:
% m - length in meter
% kg- mass in kilogram
% s - time in second
% A - electric current in ampere

% Derived units: . is used below to separate between units
% rad - angle in radian
% N   - weight/force in newton
% J   - energy/heat in joule = N.m = kg.m^2.s^-2
% W   - power = J/s = kg.m^2.s^-3
% V   - voltage = W/A = kg.m^2.s^?3.A^?1
% Wb  - magnetic flux = V.s=kg.m^2.s^?2.A^?1
% H   - inductance = Wb/A 

R  = 5.262773292;    % ohms
Kb = 0.4952900056;   % V.s/rad
Kt = 0.3233728703;   % N.m/A
b  = 0.0006001689451;  % N.m.s/rad
L  = 0.0047;         % H
J  = 0.001321184025;
Tf = 0.02;  % N.m
encoder_counts = 720; % for quad encoding
Vref = 4.5;        % supply voltage
RADSEC2RPM = 60/(2*pi); % rad/s to RPM conversion

RAD2Counts = 720/(2*pi);
Counts2RAD = 1/RAD2Counts;






            