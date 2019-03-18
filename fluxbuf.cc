#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::fluxbuf(int x)
{
CaMKb=CaMKo*(1.0-p->CaMKt)/(1.0+KmCaM/p->cass);
CaMKa=CaMKb+p->CaMKt;
p->CaMKt=(exp(-bCaMK*dt)/(bCaMK-aCaMK*CaMKb))*(p->CaMKt*bCaMK*exp(aCaMK*CaMKb*dt)+aCaMK*CaMKb*(CaMKb*exp(bCaMK*dt)-(CaMKb+p->CaMKt)*exp(aCaMK*CaMKb*dt)));

JdiffNa=(p->nass-p->nai)/2.0;
JdiffK=(p->kss-p->ki)/2.0;

double thresh=10.0;//CaJSR gets up to 2.72 at 300 ms CL
double brel;
if (p->cajsr>=thresh)
{
        brel=(p->cajsr-thresh);
}
else
{
        brel=0;
}
double arel=-ICaL;//
if (arel<0)
{
        arel=0;
}
double drive=arel+brel;
double alpha=0.5;//
double Khalf=1.5;//
double power=8.0;//
double rel_fact=1.0/(1.0+pow(Khalf/p->cajsr,power));//
double bt=4.75;
double a_rel=alpha*bt;
double Jrel_inf=a_rel*(drive)*rel_fact;
if (x>M)
{
Jrel_inf*=1.0;
}
else if (x>endo)
{
Jrel_inf*=1.7;
}
double tau_rel=bt/(1.0+0.0123/p->cajsr);
p->Jrelnp=Jrel_inf-(Jrel_inf-p->Jrelnp)*exp(-dt/tau_rel);
double btp=4.75*1.25;
double a_relp=alpha*btp;
double Jrel_infp=a_relp*(drive)*rel_fact;
if (x>M)
{
Jrel_infp*=1.0;
}
else if (x>endo)
{
Jrel_infp*=1.7;
}
double tau_relp=btp/(1.0+0.0123/p->cajsr);
p->Jrelp=Jrel_infp-(Jrel_infp-p->Jrelp)*exp(-dt/tau_relp);
double fJrelp=(1.0/(1.0+KmCaMK/CaMKa)); //CaMK effects
Jrel=(1.0-fJrelp)*p->Jrelnp+fJrelp*p->Jrelp;

Jupnp=0.004375*p->cai/(p->cai+0.00092);//
Jupp=2.75*0.004375*p->cai/(p->cai+0.00092-0.00017);//
if (x>M)
{
Jupnp*=1.3;
Jupp*=1.3;
}
double fJupp=(1.0/(1.0+KmCaMK/CaMKa));//CaMK effects
double Jleak_old=0.9*0.004375/15.0*p->cansr;//
Jup=(1.0-fJupp)*Jupnp+fJupp*Jupp-Jleak_old;

Jleak=0;

Jtr=(p->cansr-p->cajsr)/100.0;//

Jdiff=(p->cass-p->cai)/0.2;
}
