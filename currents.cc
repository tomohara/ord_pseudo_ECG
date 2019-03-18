#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::currents(int x)
{
double GNa=75;

double GNaL=0.0075;
double GNaLp=1.0*GNaL;//CaMK affects GNaL
if (x>M)
{
GNaL*=0.6;
GNaLp*=0.6;
}
else if (x>endo)
{
GNaL*=1.0;
GNaLp*=1.0;
}

double Gto=0.02;
if (x>M)
{
Gto*=4.0;
}
else if (x>endo)
{
Gto*=4.0;
}

double PCa=0.0001;
double PCap=1.1*PCa;  //CaMK affects PCa
if (x>M)
{
PCa*=1.2;
PCap*=1.2;
}
else if (x>endo)
{
PCa*=2.5;
PCap*=2.5;
}

double PCaNa=0.00125*PCa;
double PCaK=3.574e-4*PCa;
double PCaNap=0.00125*PCap;
double PCaKp=3.574e-4*PCap;

double GKr=0.046;
if (x>M)
{
GKr*=1.3;
}
else if (x>endo)
{
GKr*=0.8;
}

double GKs=0.0034;
if (x>M)
{
GKs*=1.4;
}
else if (x>endo)
{
GKs*=1.0;
}

double GK1=0.1908;
if (x>M)
{
GK1*=1.2;
}
else if (x>endo)
{
GK1*=1.3;
}

double Gncx=0.0008;
if (x>M)
{
Gncx*=1.1;
}
else if (x>endo)
{
Gncx*=1.4;
}

double Gnak=30;
if (x>M)
{
Gnak*=0.9;
}
else if (x>endo)
{
Gnak*=0.7;
}

double GKb=0.003;
if (x>M)
{
GKb*=0.6;
}

double GpCa=0.0005;

double PNab=0.5*7.5e-10;
double PCab=0.5*5e-8;

double fINap=(1.0/(1.0+0.15/CaMKa));//CaMK affects
INa=GNa*(p->v-ENa)*pow(p->m,3.0)*((1.0-fINap)*h*j+fINap*hp*jp);

double fINaLp=(1.0/(1.0+0.15/CaMKa));//CaMK affects
INaL=p->mL*(p->v-ENa)*((1.0-fINaLp)*GNaL*p->hL+GNaLp*fINaLp*p->hLp);

double fItop=(1.0/(1.0+0.15/CaMKa));//CaMK affects
Ito=Gto*(p->v-EK)*((1.0-fItop)*p->a*i+fItop*p->ap*ip);

double gamaCai=1.0;
double gamaCao=0.341;
double zca=2.0;
double vffrt=p->v*F*F/(R*T);
double vfrt=p->v*F/(R*T);
ICaL_max=4.0*vffrt*(p->cass*exp(2.0*vfrt)-0.341*cao)/(exp(2.0*vfrt)-1.0);
ICaNa_max=1.0*vffrt*(0.75*p->nass*exp(1.0*vfrt)-0.75*nao)/(exp(1.0*vfrt)-1.0);
ICaK_max=1.0*vffrt*(0.75*p->kss*exp(1.0*vfrt)-0.75*ko)/(exp(1.0*vfrt)-1.0);
double fICaLp=(1.0/(1.0+0.15/CaMKa));//CaMK affects
ICaL=(1.0-fICaLp)*PCa*ICaL_max*p->d*(f*(1.0-p->nca)+p->jca*fca*p->nca)+fICaLp*PCap*ICaL_max*p->d*(fp*(1.0-p->nca)+p->jca*fcap*p->nca);
ICaNa=(1.0-fICaLp)*PCaNa*ICaNa_max*p->d*(f*(1.0-p->nca)+p->jca*fca*p->nca)+fICaLp*PCaNap*ICaNa_max*p->d*(fp*(1.0-p->nca)+p->jca*fcap*p->nca);
ICaK=(1.0-fICaLp)*PCaK*ICaK_max*p->d*(f*(1.0-p->nca)+p->jca*fca*p->nca)+fICaLp*PCaKp*ICaK_max*p->d*(fp*(1.0-p->nca)+p->jca*fcap*p->nca);

IKr=GKr*xr*rkr*(p->v-EK);

double KsCa=1.0+0.6/(1.0+pow((3.8e-5)/p->cai,1.4));
IKs=GKs*KsCa*p->xs1*p->xs2*(p->v-EKs);

IK1=GK1*sqrt(ko)*rk1*p->xk1*(p->v-EK);

double kna1=15.0;
double kna2=5.0;
double kna3=88.12;
double kasymm=12.5;
double wna=6.0e4;
double wca=6.0e4;
double wnaca=5.0e3;
double kcaon=1.5e6;
double kcaoff=5.0e3;
double qna=0.5224;
double qca=0.1670;
double hca=exp((qca*p->v*F)/(R*T));
double hna=exp((qna*p->v*F)/(R*T));
double h1=1+p->nai/kna3*(1+hna);
double h2=(p->nai*hna)/(kna3*h1);
double h3=1.0/h1;
double h4=1.0+p->nai/kna1*(1+p->nai/kna2);
double h5=p->nai*p->nai/(h4*kna1*kna2);
double h6=1.0/h4;
double h7=1.0+nao/kna3*(1.0+1.0/hna);
double h8=nao/(kna3*hna*h7);
double h9=1.0/h7;
double h10=kasymm+1.0+nao/kna1*(1+nao/kna2);
double h11=nao*nao/(h10*kna1*kna2);
double h12=1.0/h10;
double k1=h12*cao*kcaon;
double k2=kcaoff;
double k3p=h9*wca;
double k3pp=h8*wnaca;
double k3=k3p+k3pp;
double k4p=h3*wca/hca;
double k4pp=h2*wnaca;
double k4=k4p+k4pp;
double k5=kcaoff;
double k6=h6*p->cai*kcaon;
double k7=h5*h2*wna;
double k8=h8*h11*wna;
double x1=k2*k4*(k7+k6)+k5*k7*(k2+k3);
double x2=k1*k7*(k4+k5)+k4*k6*(k1+k8);
double x3=k1*k3*(k7+k6)+k8*k6*(k2+k3);
double x4=k2*k8*(k4+k5)+k3*k5*(k1+k8);
double E1=x1/(x1+x2+x3+x4);
double E2=x2/(x1+x2+x3+x4);
double E3=x3/(x1+x2+x3+x4);
double E4=x4/(x1+x2+x3+x4);
double KmCaAct=150.0e-6;
double allo=1.0/(1.0+pow(KmCaAct/p->cai,2.0));
double zna=1.0;
double JncxNa=3.0*(E4*k7-E1*k8)+E3*k4pp-E2*k3pp;
double JncxCa=E2*k2-E1*k1;
INaCa_i=0.8*Gncx*allo*(zna*JncxNa+zca*JncxCa);

h1=1+p->nass/kna3*(1+hna);
h2=(p->nass*hna)/(kna3*h1);
h3=1.0/h1;
h4=1.0+p->nass/kna1*(1+p->nass/kna2);
h5=p->nass*p->nass/(h4*kna1*kna2);
h6=1.0/h4;
h7=1.0+nao/kna3*(1.0+1.0/hna);
h8=nao/(kna3*hna*h7);
h9=1.0/h7;
h10=kasymm+1.0+nao/kna1*(1+nao/kna2);
h11=nao*nao/(h10*kna1*kna2);
h12=1.0/h10;
k1=h12*cao*kcaon;
k2=kcaoff;
k3p=h9*wca;
k3pp=h8*wnaca;
k3=k3p+k3pp;
k4p=h3*wca/hca;
k4pp=h2*wnaca;
k4=k4p+k4pp;
k5=kcaoff;
k6=h6*p->cass*kcaon;
k7=h5*h2*wna;
k8=h8*h11*wna;
x1=k2*k4*(k7+k6)+k5*k7*(k2+k3);
x2=k1*k7*(k4+k5)+k4*k6*(k1+k8);
x3=k1*k3*(k7+k6)+k8*k6*(k2+k3);
x4=k2*k8*(k4+k5)+k3*k5*(k1+k8);
E1=x1/(x1+x2+x3+x4);
E2=x2/(x1+x2+x3+x4);
E3=x3/(x1+x2+x3+x4);
E4=x4/(x1+x2+x3+x4);
KmCaAct=150.0e-6;
allo=1.0/(1.0+pow(KmCaAct/p->cass,2.0));
JncxNa=3.0*(E4*k7-E1*k8)+E3*k4pp-E2*k3pp;
JncxCa=E2*k2-E1*k1;
INaCa_ss=0.2*Gncx*allo*(zna*JncxNa+zca*JncxCa);

double k1p=949.5;
double k1m=182.4;
double k2p=687.2;
double k2m=39.4;
k3p=1899.0;
double k3m=79300.0;
k4p=639.0;
double k4m=40.0;
double Kpnai0=9.073;
double Knao0=27.78;
double delta=-0.1550;
double Kpnai=Kpnai0*exp((delta*p->v*F)/(3.0*R*T));
double Knao=Knao0*exp(((1.0-delta)*p->v*F)/(3.0*R*T));
double Kpki=0.5;
double Kko=0.3582;
double MgADP=0.05;
double MgATP=9.8;
double Kmgatp=1.698e-7;
double H=1.0e-7;
double eP=4.2;
double Khp=1.698e-7;
double Knap=224.0;
double Kxkur=292.0;
double P=eP/(1.0+H/Khp+p->nai/Knap+p->ki/Kxkur);
double a1=(k1p*pow(p->nai/Kpnai,3.0))/(pow(1.0+p->nai/Kpnai,3.0)+pow(1.0+p->ki/Kpki,2.0)-1.0);
double b1=k1m*MgADP;
double a2=k2p;
double b2=(k2m*pow(nao/Knao,3.0))/(pow(1.0+nao/Knao,3.0)+pow(1.0+ko/Kko,2.0)-1.0);
double a3=(k3p*pow(ko/Kko,2.0))/(pow(1.0+nao/Knao,3.0)+pow(1.0+ko/Kko,2.0)-1.0);
double b3=(k3m*P*H)/(1.0+MgATP/Kmgatp);
double a4=(k4p*MgATP/Kmgatp)/(1.0+MgATP/Kmgatp);
double b4=(k4m*pow(p->ki/Kpki,2.0))/(pow(1.0+p->nai/Kpnai,3.0)+pow(1.0+p->ki/Kpki,2.0)-1.0);
x1=a4*a1*a2+b2*b4*b3+a2*b4*b3+b3*a1*a2;
x2=b2*b1*b4+a1*a2*a3+a3*b1*b4+a2*a3*b4;
x3=a2*a3*a4+b3*b2*b1+b2*b1*a4+a3*a4*b1;
x4=b4*b3*b2+a3*a4*a1+b2*a4*a1+b3*b2*a1;
E1=x1/(x1+x2+x3+x4);
E2=x2/(x1+x2+x3+x4);
E3=x3/(x1+x2+x3+x4);
E4=x4/(x1+x2+x3+x4);
double zk=1.0;
double JnakNa=3.0*(E1*a3-E2*b3);
double JnakK=2.0*(E4*b1-E3*a1);
INaK=Gnak*(zna*JnakNa+zk*JnakK);

INab=PNab*vffrt*(p->nai*exp(vfrt)-nao)/(exp(vfrt)-1.0);

IKb=GKb*xkb*(p->v-EK);

IpCa=GpCa*p->cai/(0.0005+p->cai);

ICab=PCab*4.0*vffrt*(p->cai*exp(2.0*vfrt)-0.341*cao)/(exp(2.0*vfrt)-1.0);
}
