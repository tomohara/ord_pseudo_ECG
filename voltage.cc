#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::voltage(int x)
{
double gj_use=gj;
double gj_epi_factor=0.4;
/*if (x>=106)
{
gj_use=gj*gj_epi_factor;
}*/

p->vold=p->v;
double Rg=3.14159*pow(radius*1e-4,2)/(gj_use*1.0e-6);
double Itot=INa+INaL+Ito+ICaL+ICaNa+ICaK+IKr+IKs+IK1+INaCa_i+INaCa_ss+INaK+INab+IKb+IpCa+ICab;
p->v+=dt*(0.1*(radius*1e-4)/(4.0*(Rmyo+Rg/(dX*1.0e-4))*pow(dX*1.0e-6,2.0))*(p->veast-2.0*p->v+p->vwest)-(Itot+Ist));
}
