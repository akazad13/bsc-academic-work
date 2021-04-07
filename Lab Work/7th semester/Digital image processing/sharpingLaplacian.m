clear all;
clc;

im  = imread('coins.png');


T = padarray(im,[1 1]);
[row,col] = size(T);
T = double(T);

mask = [0 1 0; 1 -4 1; 0 1 0];
%I = zeros(T);

for i=2:row-1
    for j=2:col-1
        new = T(i-1:i+1, j-1:j+1);
        I(i,j) = sum(sum(new.*mask));
    end
end

newMask = uint8(I(2:row-1,2:col-1));

figure(),imshow(newMask);
II = im-newMask;
figure(),imshow(II);