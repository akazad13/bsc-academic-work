clear all;
clc;

im  = imread('pout.tif');
im = imresize(im,[256,256]);

figure(),imshow(im);
figure(),imhist(im);

oldMin = double(min(min(im)));
oldMax = double(max(max(im)));

newMin = 0.0;
newMax = 255.0;

temp = double(im);

t1 = ((temp(:,:)-oldMin)/(oldMax-oldMin))*(newMax-newMin);

I = uint8(t1);

figure(), imhist(I);
figure(),imshow(I);

%figure(),imshowpair(im,I,'montage');