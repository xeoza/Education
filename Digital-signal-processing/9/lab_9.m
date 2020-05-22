function lab_9()
I=double(imread('Lab1_3_5.bmp')) / 255;
PSF=fspecial('motion', 54, 65);
[J,psfr]=deconvblind(I, PSF);

figure;

subplot(1,2,1);
imshow(I);
title('Source image');

subplot(1,2,2);
imshow(J);
title('Result image'); 
end