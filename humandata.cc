#include <iostream>
#include <math.h>
#include <stdio.h>
#include "humandata.h"
#include "human.h"

#include <fstream>
using std::ifstream;

humandata::humandata()
{
int x;
ifstream countin;
countin.open("count.txt");
countin>>x;
countin.close();

FILE*count;
count=fopen("count.txt","w");
fprintf(count,"%-07i\t",x+1);
fclose(count);

ifstream CLin;
CLin.open("CLfile.txt");
CLin >> CL;
CLin.close();

ifstream transin;
transin.open("transfile.txt");
transin >> endo;
transin >> M;
transin.close();

sprintf(load_path_endo,"./endo/states%g.txt",CL);
sprintf(load_path_M,"./M/states%g.txt",CL);
sprintf(load_path_epi,"./epi/states%g.txt",CL);

ifstream statesin;
if (x>M)
{
statesin.open(load_path_epi);
}
else if (x>endo)
{
statesin.open(load_path_M);
}
else
{
statesin.open(load_path_endo);
}

double states[44];
for (int i = 0; i < 44; i ++)
{
statesin >> states[i];
}
statesin.close();

v=states[0];
vwest=v;
veast=v;
vrest=v;

nai=states[1];
nass=states[2];
ki=states[3];
kss=states[4];
cai=states[5];
cass=states[6];
cansr=states[7];
cajsr=states[8];
m=states[9];
hf=states[10];
hs=states[11];
jf=states[12];
js=states[13];
mL=states[14];
hL=states[15];
a=states[16];
iF=states[17];
iS=states[18];
d=states[19];
ff=states[20];
fs=states[21];
fcaf=states[22];
fcas=states[23];
jca=states[24];
nca=states[25];
xrf=states[26];
xrs=states[27];
xs1=states[28];
xs2=states[29];
xk1=states[30];
Jrelnp=states[31];
Jrelp=states[32];
CaMKt=states[33];

hsp=states[34];
jfp=states[35];
jsp=states[36];
hLp=states[37];
ap=states[38];
iFp=states[39];
iSp=states[40];
ffp=states[41];
fcafp=states[42];
fcasp=states[43];

vold=v;
vdot=0;
vdotmax=0;
tvdotmax=0;
vdotold=0;
APD90=0;
APD70=0;
APD50=0;
APD30=0;
APDflag=0;
}
