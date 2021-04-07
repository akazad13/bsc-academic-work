clear all;
clc;
%New = imfilter(noisy,a);
%a = fspecial('average',[3 3]);

im = imread('coins.png');
[row,col] = size(im);
figure(); imshow(im);

noisy = imnoise(im,'salt & pepper',0.01);
New = double(zeros(row,col));


v = [-1,-1,-1,0,0,0,1,1,1];
w = [-1,0,1,-1,0,1,-1,0,1];

for i=1:row
    for j=1:col
         arr = [];
         cnt=1;
        for k=1:9
            xx = i+v(k);
            yy = j+w(k);
            
            if(xx>0 && xx<=row && yy>0 && yy<=col)
                arr(cnt)=noisy(xx,yy);
                cnt = cnt+1;
            end
            
        end
        New(i,j) = median(arr);
    end
end




figure(), imshow(noisy);
figure(), imshow(uint8(New))