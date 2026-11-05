
% Open the file: 'r' means read, 'b' 
% meands it is big-endian
fid = fopen('capture.bin','r','b')

% read all the lines of data 'int16' lets the command 
% fread know that the data to expect is int16
% and it will properly combine the separate bytes

 dat = fread(fid, 600, 'int16');
 dat_mat = (reshape(dat, 10, 60))'


