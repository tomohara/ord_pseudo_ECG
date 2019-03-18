#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::concentrations(int x)
{
p->nai+=dt*(-(INa+INaL+3.0*INaCa_i+3.0*INaK+INab)*Acap/(F*vmyo)+JdiffNa*vss/vmyo);
p->nass+=dt*(-(ICaNa+3.0*INaCa_ss)*Acap/(F*vss)-JdiffNa);
p->ki+=dt*(-(Ito+IKr+IKs+IK1-2.0*INaK+IKb+Ist)*Acap/(F*vmyo)+JdiffK*vss/vmyo);
p->kss+=dt*(-(ICaK)*Acap/(F*vss)-JdiffK);

double cmdn_epi=cmdnmax*1.3;
double Bcai;
if (x>M)
{
Bcai=1.0/(1.0+cmdn_epi*kmcmdn/pow(kmcmdn+p->cai,2.0)+trpnmax*kmtrpn/pow(kmtrpn+p->cai,2.0));
}
else
{
Bcai=1.0/(1.0+cmdnmax*kmcmdn/pow(kmcmdn+p->cai,2.0)+trpnmax*kmtrpn/pow(kmtrpn+p->cai,2.0));
}
double dcai=Bcai*(-(-2.0*INaCa_i+IpCa+ICab)*Acap/(2.0*F*vmyo)-Jup*vnsr/vmyo+Jdiff*vss/vmyo);
p->cai+=dt*dcai;

double Bcass;
Bcass=1.0/(1.0+BSRmax*KmBSR/pow(KmBSR+p->cass,2.0)+BSLmax*KmBSL/pow(KmBSL+p->cass,2.0));
double dcass=Bcass*(-(ICaL-2.0*INaCa_ss)*Acap/(vss*2.0*F)+Jrel*vjsr/vss+Jleak*vjsr/vss-Jdiff);
p->cass+=dt*dcass;

p->cansr+=dt*(Jup-Jtr*vjsr/vnsr);

double Bcajsr=1.0/(1.0+csqnmax*kmcsqn/pow(kmcsqn+p->cajsr,2.0));
double dcajsr=Bcajsr*(Jtr-Jrel-Jleak);
p->cajsr+=dt*dcajsr;
if (p->cajsr<0)
{
p->cajsr=0;
}
}
