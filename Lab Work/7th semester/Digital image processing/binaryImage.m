clear all;
clc;

im  = imread('saturn.png');
im  = imresize(im,[256,256]);
im  = rgb2gray(im);
figure(),imshow(im);
figure(), imhist(im);

I = [im(:,:)>50];

figure(), imshow(I);
