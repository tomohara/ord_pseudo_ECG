#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::stim(int x, int stim_here)
{
if ((fabs(t-(start+n*CL))<1e-6 || fabs(t-(start+duration+n*CL-dt))<1e-6 || (t>(start+n*CL) && t<(start+duration+n*CL-dt))))
	{
		if (Ist==0.0)
		{
			if (CL!=1e6)
			{
			p->vrest=p->v;
			}
		}
 
		if (x==stim_here)
		{
			Ist=amp;
		}
		else
		{
			Ist=0.0;
		}
	}    
else if (t>(start+duration+n*CL-dt))
	{   
	Ist=0.0;
	n++;
	}
else
	{
	Ist=0.0;
	}
}
