clear all;
clc;
im = imread('coins.png');
figure(),imshow(im);
figure(),imhist(im);

im  = double(im);

[row,col] = size(im);

T = 100;
T1 = 0;

while(abs(T-T1)>0.01)
    
    sum1=0;
    sum2=0;
    cnt1=0;
    cnt2=0;
    
    for i=1:row
        for j=1:col
            if(im(i,j)<=T)
                sum1=sum1+im(i,j);
                cnt1 = cnt1+1;
           
            else
                sum2=sum2+im(i,j);
                cnt2 = cnt2+1;
            end
        end
    end
    
    if(cnt1==0)
        break
    end
    
    if(cnt2==0)
        break
    end
    
    m1 = sum1/cnt1;
    m2 = sum2/cnt2;
    
    T1 = T;
    T = (m1+m2)/2.0;
    
end

Res = [im>=T];

Res = uint8(Res)*255;

figure(), imshow(Res);



%T = adaptthresh(I, 0.9);
%BW = imbinarize(I,T);

    