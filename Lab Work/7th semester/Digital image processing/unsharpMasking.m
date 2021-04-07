clear all;
clc;

im  = imread('coins.png');


T = padarray(im,[1 1]);
[row,col] = size(T);
T = double(T);

mask = (1/9).*ones(3,3);

for i=2:row-1
    for j=2:col-1
        new = T(i-1:i+1, j-1:j+1);
        I(i,j) = sum(sum(new.*mask));
    end
end

avgIm = uint8(I(2:row-1,2:col-1));

figure(),imshow(avgIm);
II = im-avgIm;
figure(),imshow(II);
II2 = im+II;
figure(),imshow(II2);