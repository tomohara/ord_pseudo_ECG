#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::update(int x)	
{
fluxbuf(x);
stim(x,stim_here);
revpots();
rates(x);
gates(x);
currents(x);
voltage(x);
dvdt(x);
concentrations(x);
ECG(x);
}
