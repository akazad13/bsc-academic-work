clear all;
clc

im = imread('rice.png');
[row,col] = size(im);
figure(),imshow(im);

times = 2;

for i=1:row*times
    for j=1:col*times
       xx = round( ((i-1)*(row-1))/(row*times-1)+1);
       yy = round( ((j-1)*(row-1))/(row*times-1)+1);
       
       new(i,j) = im(xx,yy);
    end
end

figure(),imshow(new);
figure(),imhist(im);
figure(),imhist(new);