#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::revpots()
{
ENa=(R*T/F)*log(nao/p->nai);
EK=(R*T/F)*log(ko/p->ki);
EKs=(R*T/F)*log((ko+0.01833*nao)/(p->ki+0.01833*p->nai));
}
