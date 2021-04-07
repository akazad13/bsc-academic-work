%%enhancement

clear all;
clc;


%% reading image

im = imread('cameraman.tif');

[r,c] = size(im);
g = double(im);


figure(),imhist(im);
%im1 = uint8(zeros(r,c));

%% log transformation

factor = 6;

for i=1:r,
    for j=1:c,
       I(i,j)=factor.*log(1.0+g(i,j));
    end
end

im1 = uint8(I);

figure(),imhist(im1);

figure();
imshowpair(im,im1,'montage')
title('original image            Log transform');

figure(), plot(im,im1,'b');
xlabel('Input gray level, r');
ylabel('Output gray level, s');