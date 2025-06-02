close all
clear variables
clc

%addpath 'C:\Users\Roberta Venturi\Desktop\Test IR\Termografie';
addpath 'D:\Università\Tesi\Umidità\CSV\1394\T05';
%caricamento termografia in una variabile double IR (PRE INTERVENTO)
load('T05.mat');
IR1_R=T05;
%ruotare termografia di 90°
IR1=rot90(IR1_R);
%plot della termografia
createfigure(IR1);
title('Termografia pre intervento');

%creazione finestra dialogo di input (PRE INTERVENTO)
prompt={'Enter minimum value on x-axes','Enter maximum value on x-axes','Enter minimum value on y-axes','Enter maximum value on y-axes'};
dlgtitle='Input - Ranges - axes'; %titolo finestra dialogo
dims=[1 60]; %dimensioni riquadro
definput={'min x','max x','min y','max y'};
answer=inputdlg(prompt,dlgtitle,dims,definput);
xi1=str2num(answer{1})+1;
xf1=str2num(answer{2});
yi1=str2num(answer{3})+1;
yf1=str2num(answer{4});

%conversione pixel a cm (PRE INTERVENTO)
prompt={'Enter distance in pixels','Enter distance in cm'};
dlgtitle='Convert pixels to cm';
dims=[1 60];
definput={'pixels','cm'};
answer=inputdlg(prompt,dlgtitle,dims,definput);
distanceInPixel1=str2num(answer{1});
distanceInCm1=str2num(answer{2});
calibrationFactor1=distanceInPixel1/distanceInCm1;

%caricamento termografia in una variabile double IR (POST INTERVENTO)
load('T05_2.mat');
IR2_R=T052;
%ruotare termografia di 90°
IR2=rot90(IR2_R);
%plot della termografia
createfigure(IR2);
title('Termografia post intervento');

%creazione finestra dialogo di input (POST INTERVENTO)
prompt={'Enter minimum value on x-axes','Enter maximum value on x-axes','Enter minimum value on y-axes','Enter maximum value on y-axes'};
dlgtitle='Input - Ranges - axes'; %titolo finestra dialogo
dims=[1 60]; %dimensioni riquadro
definput={'min x','max x','min y','max y'};
answer=inputdlg(prompt,dlgtitle,dims,definput);
xi2=str2num(answer{1})+1;
xf2=str2num(answer{2});
yi2=str2num(answer{3})+1;
yf2=str2num(answer{4});

%conversione pixel a cm (POST INTERVENTO)
prompt={'Enter distance in pixels','Enter distance in cm'};
digtitle='Convert pixels to cm';
dims=[1 60];
definput={'pixels','cm'};
answer=inputdlg(prompt,dlgtitle,dims,definput);
distanceInPixel2=str2num(answer{1});
distanceInCm2=str2num(answer{2});
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
Tot_AVG1=mean(subIR1,'all');
Tot_AVG2=mean(subIR2,'all');

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
ylabel('Temperatura media [°C]');
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
ylabel('Temperatura media [°C]');
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
ylabel('Temperatura normalizzata [°C]');
title('Temperatura normalizzata profili orizzontali');
legend('\mu pre intervento','\mu+2\sigma','\mu-2\sigma','\mu post intervento');
ytickformat('%.1f')

%Tagliare grafico
%%xlim([0 250]); ylim([15 18]); oppure %%axis([0 250 15 18]);

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
%T_int è un vettore dove il primo elemento è il coeff. angolare della
%retta, il secondo è l'intercetta per x=0. La retta interpolante è:
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
ylabel('Temperatura normalizzata [°C]');
title('Interpolazione lineare temperatura');
legend('interpolazione lineare pre intervento','\mu pre intervento','interpolazione lineare post intervento','\mu post intervento');
ytickformat('%.1f')

R=[V_D1,V_D2,H_D1,H_D2,grad1,grad2,ratioD1,ratioD2,T_int1,T_int2];
disp(R);
% V_dev1_m=mean(V_dev1);
% V_AVG1_m=mean(V_AVG1);

% %curva gaussiana
% figure;
% Tot_AVG=mean(subIR1(:)); %media matrice
% Tot_dev=std(subIR1(:)); %deviazione standard matrice
% y_V=normpdf(V_AVG1,V_AVG1_m,V_dev1_m);
% plot(V_AVG1,y_V);
% hold on
% y_H=normpdf(H_AVG1,Tot_AVG,Tot_dev);
% plot(H_AVG1,y_H);
% xlabel('Temperatura [°C]');
% ylabel('Frequenza');
% title('Distribuzione gaussiana');