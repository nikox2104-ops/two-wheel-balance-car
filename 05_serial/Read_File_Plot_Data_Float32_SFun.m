
% Open the file: 'r' means read, 'b' 
% meands it is big-endian
fid = fopen('capture_float32_sfun.bin','r','b')

% read all the lines of data 'int16' lets the command 
% fread know that the data to expect is int16
% and it will properly combine the separate bytes

dat = fread(fid, 60, 'single');
dat_mat = (reshape(dat, 6, 10))'


