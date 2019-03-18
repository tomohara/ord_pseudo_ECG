#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::gates(int x)
{
p->m=mss-(mss-p->m)*exp(-dt/tm);
p->hf=hss-(hss-p->hf)*exp(-dt/thf);
p->hs=hss-(hss-p->hs)*exp(-dt/ths);
h=Ahf*p->hf+Ahs*p->hs;
p->jf=jss-(jss-p->jf)*exp(-dt/tjf);
p->js=jss-(jss-p->js)*exp(-dt/tjs);
j=Ajf*p->jf+Ajs*p->js;
p->hsp=hssp-(hssp-p->hsp)*exp(-dt/thsp);
hp=Ahf*p->hf+Ahs*p->hsp;
p->jfp=jss-(jss-p->jfp)*exp(-dt/tjfp);
p->jsp=jss-(jss-p->jsp)*exp(-dt/tjsp);
jp=Ajf*p->jfp+Ajs*p->jsp;

p->mL=mLss-(mLss-p->mL)*exp(-dt/tmL);
p->hL=hLss-(hLss-p->hL)*exp(-dt/thL);
p->hLp=hLssp-(hLssp-p->hLp)*exp(-dt/thLp);

p->a=ass-(ass-p->a)*exp(-dt/ta);
p->iF=iss-(iss-p->iF)*exp(-dt/tiF);
p->iS=iss-(iss-p->iS)*exp(-dt/tiS);
i=AiF*p->iF+AiS*p->iS;
p->ap=assp-(assp-p->ap)*exp(-dt/ta);
p->iFp=iss-(iss-p->iFp)*exp(-dt/tiFp);
p->iSp=iss-(iss-p->iSp)*exp(-dt/tiSp);
ip=AiF*p->iFp+AiS*p->iSp;

p->d=dss-(dss-p->d)*exp(-dt/td);
p->ff=fss-(fss-p->ff)*exp(-dt/tff);
p->fs=fss-(fss-p->fs)*exp(-dt/tfs);
f=Aff*p->ff+Afs*p->fs;
p->fcaf=fcass-(fcass-p->fcaf)*exp(-dt/tfcaf);
p->fcas=fcass-(fcass-p->fcas)*exp(-dt/tfcas);
fca=Afcaf*p->fcaf+Afcas*p->fcas;
p->jca=fcass-(fcass-p->jca)*exp(-dt/tjca);
double Kmn=0.002;
double k2n=1000.0;
double km2n=p->jca*1.0;
double anca=1.0/(k2n/km2n+pow(1.0+Kmn/p->cass,4.0));
p->nca=anca*k2n/km2n-(anca*k2n/km2n-p->nca)*exp(-km2n*dt);
p->ffp=fss-(fss-p->ffp)*exp(-dt/tffp);
fp=Aff*p->ffp+Afs*p->fs;
p->fcafp=fcassp-(fcassp-p->fcafp)*exp(-dt/tfcafp);
fcap=Afcaf*p->fcafp+Afcas*p->fcas;

p->xrf=xrss-(xrss-p->xrf)*exp(-dt/txrf);
p->xrs=xrss-(xrss-p->xrs)*exp(-dt/txrs);
xr=Axrf*p->xrf+Axrs*p->xrs;
rkr=1.0/(1.0+exp((p->v+55.0)/75.0))*1.0/(1.0+exp((p->v-10.0)/30.0));

p->xs1=xs1ss-(xs1ss-p->xs1)*exp(-dt/txs1);
p->xs2=xs2ss-(xs2ss-p->xs2)*exp(-dt/txs2);

p->xk1=xk1ss-(xk1ss-p->xk1)*exp(-dt/txk1);
rk1=1.0/(1.0+exp((p->v+105.8-2.6*ko)/9.493));

xkb=1.0/(1.0+exp(-(p->v-14.48)/18.34));
}
