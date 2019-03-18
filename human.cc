#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "humandata.h"
#include "human.h"
#include <string>
using namespace std;

human::human(char argv1[],char argv2[], char argv3[],char argv4[])
{
CL=atof(argv1);
beats=atoi(argv2);
beatssave=atoi(argv3);
extra=argv4;

strandlength=165;
stim_here=0;

ft=beats*CL;
dt=0.005;
skip=200;

tsave=ft-beatssave*CL;

start=1.0;
amp=-200.0;
duration=1.0;

endo=60;
M=105;
epi=strandlength-1;

nao=140.0;
cao=1.8;
ko=5.4;
BSRmax=0.047;
KmBSR=0.00087;
BSLmax=1.124;
KmBSL=0.0087;
cmdnmax=0.05;
kmcmdn=0.00238;
trpnmax=0.07;
kmtrpn=0.0005;
csqnmax=10.0;
kmcsqn=0.8;
aCaMK=0.05;
bCaMK=0.00068;
CaMKo=0.05;
KmCaM=0.0015;
KmCaMK=0.15;

C=1.0;
R=8314.0;
T=310.0;
F=96485.0;
L=0.01;
rad=0.0011;
vcell=1000*3.14*rad*rad*L;
Ageo=2*3.14*rad*rad+2*3.14*rad*L;
Acap=2*Ageo;
vmyo=0.68*vcell;
vmito=0.26*vcell;
vsr=0.06*vcell;
vnsr=0.0552*vcell;
vjsr=0.0048*vcell;
vss=0.02*vcell;
gj=2.5;//1.73;// //uS
Rmyo=150.0;       //ohm*cm
radius=11.0;  //um
dX=100.0; //um

t=0.0;
n=0;
save_flag=0;

sprintf(apd_path,"./output/apd_file_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
sprintf(voltages_path,"./output/voltages_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
sprintf(one_path,"./output/one_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
sprintf(two_path,"./output/two_file_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
sprintf(three_path,"./output/three_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
sprintf(four_path,"./output/four_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
sprintf(five_path,"./output/five_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
sprintf(ecg_path,"./output/ecg_%s_%s_%s_%s.txt",argv1,argv2,argv3,argv4);
}
