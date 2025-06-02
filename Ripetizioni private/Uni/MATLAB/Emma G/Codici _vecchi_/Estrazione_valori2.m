close all
clear variables
clc

addpath 'D:\Universit�\Tesi\Umidit�\CSV\1971\T01';
load('T01.mat');
IR1_R=T01;
IR1=rot90(IR1_R);
% createfigure(IR1);
% title('Termografia pre intervento');

Vettori
T=T01_1971;
xi1=T(1)+1;
xf1=T(2);
yi1=T(3)+1;
yf1=T(4);
distanceInPixel1=T(5);
distanceInCm1=T(6);
calibrationFactor1=distanceInPixel1/distanceInCm1;

%caricamento termografia in una variabile double IR (POST INTERVENTO)
load('T01_2.mat');
IR2_R=T012;
IR2=rot90(IR2_R);
% createfigure(IR2);
% title('Termografia post intervento');

%creazione finestra dialogo di input (POST INTERVENTO)
xi2=T(7)+1;
xf2=T(8);
yi2=T(9)+1;
yf2=T(10);

%conversione pixel a cm (POST INTERVENTO)
distanceInPixel2=T(11);
distanceInCm2=T(12);
calibrationFactor2=distanceInPixel2/distanceInCm2;

%taglio della termografia
subIR1=(IR1(yi1:yf1,xi1:xf1));
%createfigure(subIR1);
subIR2=(IR2(yi2:yf2,xi2:xf2));
%createfigure(subIR2);

%media verticale
V_AVG1=mean(subIR1);
V_AVG2=mean(subIR2);

%media orizzontale
tsubIR1=subIR1';
H_AVG1=mean(tsubIR1);
tsubIR2=subIR2';
H_AVG2=mean(tsubIR2);

%media totale sottomatrice
Tot_AVG1=mean(subIR1,'all')
Tot_AVG2=mean(subIR2,'all')

%termografie con colorbar giusta
createfigure2(IR1);
c = colorbar;
c.Label.String = '�C';
caxis([Tot_AVG1-1 Tot_AVG1+1]);
title('Termografia pre intervento');

createfigure2(IR2);
c = colorbar;
c.Label.String = '�C';
caxis([Tot_AVG2-1 Tot_AVG2+1]);
title('Termografia post intervento');

%deviazione standard verticale
V_dev1=std(subIR1);
V_dev2=std(subIR2);

%deviazione standard orizzonale
H_dev1=std(tsubIR1);
H_dev2=std(tsubIR2);

%dimensioni sottomatrice
sz1=size(subIR1);
h_subIR1=sz1(1); %altezza
b_subIR1=sz1(2); %base
sz2=size(subIR2);
h_subIR2=sz2(1);
b_subIR2=sz2(2);

%grafico profili verticali
dH1=linspace(0,(xf1-xi1)/calibrationFactor1,b_subIR1); %cambio intervallo asse x
dH2=linspace(0,(xf2-xi2)/calibrationFactor2,b_subIR2);
figure;
plot(dH1,V_AVG1,'r','linewidth',0.7);
hold on
plot(dH1,V_AVG1+2*V_dev1,'k--');
hold on
plot(dH1,V_AVG1-2*V_dev1,'k--');
hold on
plot(dH2,V_AVG2,'g','linewidth',0.7);
hold on
plot(dH2,V_AVG2+2*V_dev2,'k--');
hold on
plot(dH2,V_AVG2-2*V_dev2,'k--');
xlabel('Posizione X [cm]'); %posizione H
ylabel('Temperatura media [�C]');
title('Temperatura profili verticali');
legend('\mu pre intervento','\mu+2\sigma','\mu-2\sigma','\mu post intervento');
ytickformat('%.1f')

%grafico profili orizzontali - profili orizzontali temperature
dV1=linspace(0,(yf1-yi1)/calibrationFactor1,h_subIR1); %cambio intervallo asse x
dV2=linspace(0,(yf2-yi2)/calibrationFactor2,h_subIR2);
figure;
plot(dV1,H_AVG1,'r','linewidth',0.7);
hold on
plot(dV1,H_AVG1+2*H_dev1,'k--');
hold on
plot(dV1,H_AVG1-2*H_dev1,'k--');
hold on
plot(dV2,H_AVG2,'g','linewidth',0.7);
hold on
plot(dV2,H_AVG2+2*H_dev2,'k--');
hold on
plot(dV2,H_AVG2-2*H_dev2,'k--');
xlabel('Posizione Y [cm]'); %posizione V
ylabel('Temperatura media [�C]');
title('Temperatura profili orizzontali');
legend('\mu pre intervento','\mu+2\sigma','\mu-2\sigma','\mu post intervento');
ytickformat('%.1f')

%temperatura normalizzata profili orizzontali
DH_AVG1=H_AVG1-Tot_AVG1;
DH_AVG2=H_AVG2-Tot_AVG2;
figure;
plot(dV1,DH_AVG1,'r','linewidth',0.7);
hold on
plot(dV1,DH_AVG1+2*H_dev1,'k--');
hold on
plot(dV1,DH_AVG1-2*H_dev1,'k--');
hold on
plot(dV2,DH_AVG2,'g','linewidth',0.7);
hold on
plot(dV2,DH_AVG2+2*H_dev2,'k--');
hold on
plot(dV2,DH_AVG2-2*H_dev2,'k--');
xlabel('Posizione Y [cm]');
ylabel('Temperatura normalizzata [�C]');
title('Temperatura normalizzata profili orizzontali');
legend('\mu pre intervento','\mu+2\sigma','\mu-2\sigma','\mu post intervento');
ytickformat('%.1f')

%Rapporto deviazione standard verticale e orizzontale
H_D1=mean(H_dev1);
V_D1=mean(V_dev1);
ratioD1=V_D1/H_D1;
H_D2=mean(H_dev2);
V_D2=mean(V_dev2);
ratioD2=V_D2/H_D2;

%Calcolo gradiente dei profili orizzontali
L_1=max(dV1);
L_2=max(dV2);
max_DH1=max(DH_AVG1);
min_DH1=min(DH_AVG1);
max_DH2=max(DH_AVG2);
min_DH2=min(DH_AVG2);
grad1=(max_DH1-min_DH1)/L_1;
grad2=(max_DH2-min_DH2)/L_2;

%Interpolazione dei dati con una retta
figure;
T_int1=polyfit(dV1,DH_AVG1,1);
%T_int � un vettore dove il primo elemento � il coeff. angolare della
%retta, il secondo � l'intercetta per x=0. La retta interpolante �:
r_int1=T_int1(2)+T_int1(1)*dV1;
plot(dV1,r_int1,'r','linewidth',0.7)
hold on
plot(dV1,DH_AVG1,'r--')
hold on
T_int2=polyfit(dV2,DH_AVG2,1);
r_int2=T_int2(2)+T_int2(1)*dV2;
plot(dV2,r_int2,'g','linewidth',0.7)
hold on
plot(dV2,DH_AVG2,'g--')
xlabel('Posizione Y [cm]');
ylabel('Temperatura normalizzata [�C]');
title('Interpolazione lineare temperatura');
legend('interpolazione lineare pre intervento','\mu pre intervento','interpolazione lineare post intervento','\mu post intervento');
ytickformat('%.1f')

R=[V_D1,V_D2,H_D1,H_D2,grad1,grad2,ratioD1,ratioD2,T_int1,T_int2]