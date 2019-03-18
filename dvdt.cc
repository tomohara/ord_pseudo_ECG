#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::dvdt(int x)
{
p->vdotold=p->vdot;
p->vdot=(p->v-p->vold)/dt;
if (p->APDflag==0 && p->v>-35 && p->vdot<p->vdotold)
	{
	p->vdotmax=p->vdotold;
	p->tvdotmax=t-dt;
	if (x==0)
                {
                tvdotmax_start=p->tvdotmax;
                }
        if (x==strandlength-1)
                {
                tvdotmax_end=p->tvdotmax;
                CV=1.65*1.0e3/(tvdotmax_end-tvdotmax_start);
                }
	p->APDflag=1;
	}
if (p->APDflag==1 && p->v<0.3*p->vrest)
	{
	p->APD30=t-p->tvdotmax;
	p->APDflag=2;
	}
if (p->APDflag==2 && p->v<0.5*p->vrest)
	{
	p->APD50=t-p->tvdotmax;
	p->APDflag=3;
	}
if (p->APDflag==3 && p->v<0.7*p->vrest)
	{
	p->APD70=t-p->tvdotmax;
	p->APDflag=4;
	}
if (p->APDflag==4 && p->v<0.9*p->vrest)
	{
	p->APD90=t-p->tvdotmax;
	p->APDflag=0;
	}
}
