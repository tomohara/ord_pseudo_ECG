#include <iostream>
#include <math.h>
#include <stdio.h>
#include "humandata.h"
#include "human.h"

void human::apd_heading()
{
apd_file=fopen(apd_path,"w");
fprintf(apd_file,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","cell#","APD90","APD70","APD50","APD30");
fclose(apd_file);
}

void human::apd_save(int x)
{
apd_file=fopen(apd_path,"a");
fprintf(apd_file,"%-07i\t%-07g\t%-07g\t%-07g\t%-07g\n",
x,p->APD90,p->APD70,p->APD50,p->APD30);
fclose(apd_file);
}
