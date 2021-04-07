im = imread('cameraman.tif');
[r,c] = size(im);
figure(); imshow(im);
 
 
%% power transformation
ad = im2double(im);
 
factor = 2;
gamma =.2;
 
for i=1:r,
    for j=1:c,
       I(i,j)=(factor*ad(i,j).^gamma);
    end
end

im1 = im2uint8(I);

figure(), imhist(im1);
 
figure();
imshowpair(im,im1,'montage')
title('original image            power transform');
 
figure(), plot(im,im1,'b');
xlabel('Input gray level, r');
ylabel('Output gray level, s');
