#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::rates(int x)
{
mss=1.0/(1.0+exp((-(p->v+39.57))/9.871));//full temp dep shift
tm=1.0/(6.765*exp((p->v+11.64)/34.77)+8.552*exp(-(p->v+77.42)/5.955));
hss=1.0/(1+exp((p->v+82.90)/6.086));//full temp dep shift
thf=1.0/(1.432e-5*exp(-(p->v+1.196)/6.285)+6.149*exp((p->v+0.5096)/20.27));
ths=1.0/(0.009794*exp(-(p->v+17.95)/28.05)+0.3343*exp((p->v+5.730)/56.66));

Ahf=0.99;
Ahs=1.0-Ahf;

jss=hss;
tjf=2.038+1.0/(0.02136*exp(-(p->v+100.6)/8.281)+0.3052*exp((p->v+0.9941)/38.45));
tjs=10.16+1.0/(15.53*exp(-(p->v+288.2)/25.10)+0.002111*exp((p->v+91.89)/17.73));

Ajf=1.0;
Ajs=1.0-Ajf;

hssp=1.0/(1+exp((p->v+87.60-4.7+6.2)/6.086)); ////full temp dep shift, Wagner says 6.2 mV left shift with CaMKIIdc overexpression
thsp=3.0*ths;//Wagner says ~3.0 times slower slow component of inactiv with CaMKIIdc overexpression
tjfp=1.46*tjf;//Wagner says 1.46 slower recovery with CaMKIIdc overexpression
tjsp=1.46*tjs;//Wagner says 1.46 slower recovery with CaMKIIdc overexpression

mLss=1.0/(1.0+exp((-(p->v+42.85))/5.264));
tmL=0.1146+1/(17.67*exp((p->v+22.08)/14.13)+2.532*exp((-(p->v+70.84))/9.930));
hLss=1.0/(1.0+exp((p->v+87.61)/7.488));
thL=200.0;
hLssp=1.0/(1.0+exp((p->v+87.61+6.2)/7.488)); //Wagner says 6.2 mV left shift with CaMKIIdc overexpression
thLp=3.0*thL;//Wagner says ~3.0 times slower slow component of inactiv with CaMKIIdc overexpression

ass=1.0/(1.0+exp((-(p->v-14.34))/14.82));
ta=1.0515/(1.0/(1.2089*(1.0+exp((p->v-18.4099)/-29.3814)))+3.5/(1.0+exp((p->v+100.0)/29.3814)));
iss=1.0/(1.0+exp((p->v+43.94)/5.711));
tiF=4.562+1/(0.3933*exp((-(p->v+100.0))/100.0)+0.08004*exp((p->v+50.0)/16.59));
tiS=23.62+1/(0.001416*exp((-(p->v+96.52))/59.05)+1.780e-8*exp((p->v+114.1)/8.079));
AiF=1.0/(1.0+exp((p->v-213.6)/151.2));
AiS=1.0-AiF;
if (x>M)
{
double factor=1.0-0.95/(1.0+exp((p->v+70.0)/5.0));
tiF*=factor;/////////////////////////////////////EPI
tiS*=factor;/////////////////////////////////////EPI
}

assp=1.0/(1.0+exp((-(p->v-14.34-10.0))/14.82));//Tessier et al. 1999, ~10mV right shift
dti_develop=1.354+1.0/(10000.0*exp((p->v-167.4)/15.89)+10000.0*exp(-(p->v-12.23)/0.2154)); //Tessier et al. 1999, based on fract inc
dti_recover=1.0-0.5/(1.0+exp((p->v+70.0)/20.0));  //from Wagner et al.  Assume recover accelerates by 100% in CamKII
tiFp=dti_develop*dti_recover*tiF;
tiSp=dti_develop*dti_recover*tiS;

dss=1.0/(1.0+exp((-(p->v+3.940))/4.230));
td=0.6+1.0/(exp(-0.05*(p->v+6.0))+exp(0.09*(p->v+14.0)));
fss=1.0/(1.0+exp((p->v+19.58)/3.696));
tff=7.0+1.0/(0.0045*exp(-(p->v+20.0)/10.0)+0.0045*exp((p->v+20.0)/10.0));
tfs=1000.0+1.0/(0.000035*exp(-(p->v+5.0)/4.0)+0.000035*exp((p->v+5.0)/6.0));
fcass=fss;
tfcaf=7.0+1.0/(0.04*exp(-(p->v-4.0)/7.0)+0.04*exp((p->v-4.0)/7.0));
tfcas=100.0+1.0/(0.00012*exp(-(p->v+0.0)/3.0)+0.00012*exp((p->v+0.0)/7.0));
Aff=0.6;
Afcaf=0.3+0.6/(1.0+exp((p->v-10.0)/10.0));
Afs=1.0-Aff;
Afcas=1.0-Afcaf;
tjca=75.0;
tffp=2.5*tff;///  CaMKa affects tff
fcassp=fss;
tfcafp=2.5*tfcaf;/////  CaMKa affects tfca

xrss=1.0/(1.0+exp((-(p->v+8.337))/6.789));
txrf=12.98+1.0/(0.3652*exp((p->v-31.66)/3.869)+4.123e-5*exp((-(p->v-47.78))/20.38));
txrs=1.865+1.0/(0.06629*exp((p->v-34.70)/7.355)+1.128e-5*exp((-(p->v-29.74))/25.94));
Axrf=1.0/(1.0+exp((p->v+54.81)/38.21));
Axrs=1.0-Axrf;

xs1ss=1.0/(1.0+exp((-(p->v+11.60))/8.932));
txs1=817.3+1.0/(0.0002326*exp((p->v+48.28)/17.80)+0.001292*exp((-(p->v+210.0))/230.0));
xs2ss=xs1ss;
txs2=1.0/(0.01*exp((p->v-50.0)/20.0)+0.0193*exp((-(p->v+66.54))/31.0));

xk1ss=1.0/(1.0+exp(-(p->v+2.5538*ko+144.59)/(1.5692*ko+3.8115)));
txk1=122.2/(exp((-(p->v+127.2))/20.36)+exp((p->v+236.8)/69.33));
}
