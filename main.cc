#include <iostream>
#include <math.h>
#include <stdio.h>
#include "humandata.h"
#include "human.h"

#include <fstream>
using std::ifstream;

int main(int argc,char *argv[])
{
int x=1;
FILE*count;
count=fopen("count.txt","w");
fprintf(count,"%-07i\t",x);
fclose(count);

human cell(argv[1],argv[2],argv[3],argv[4]);

FILE*CLfile;
CLfile=fopen("CLfile.txt","w");
fprintf(CLfile,"%-07g\t",cell.CL);
fclose(CLfile);

FILE*transfile;
transfile=fopen("transfile.txt","w");
fprintf(transfile,"%-07i\t%-07i\t",cell.endo,cell.M);
fclose(transfile);

humandata *stranddata;					
stranddata = new humandata[cell.strandlength];

cell.save_heading(cell.strandlength);
cell.ecg_heading();

if (cell.stim_here>(cell.strandlength-1))
	{
	perror("stim_here is greater than strandlength");
	}

int i=1;

while (cell.t <= cell.ft)		
	{
	for (int x=0;x<cell.strandlength;x++)
		{
		cell.p=&(stranddata[x]);
		
		if (x==0)
			{
			cell.p->vwest=cell.p->v;
			}
		else
			{
			cell.l=&(stranddata[x-1]);
			cell.p->vwest=cell.l->v;	
			}
			
		if (x==(cell.strandlength-1))
			{
			cell.p->veast=cell.p->v;
			}
		else
			{
			cell.r=&(stranddata[x+1]);
			cell.p->veast=cell.r->v;
			}

		cell.update(x);	
			
		if (i%cell.skip==0 && cell.t>=cell.tsave)
			{
			cell.save(x,cell.strandlength);
			}							
		}

        if (i%cell.skip==0 && cell.t>=cell.tsave)
                {
                cell.ecg_save();
                }
	
	if (i%(500000/cell.strandlength)==0)
		{
		cout<<cell.t/cell.ft*100<<"% complete"<<endl;
		}
		
	if (isnan(cell.p->v) && cell.t>(cell.ft-cell.CL))
		{
		cout<<"t = "<<cell.t<<endl;
		perror("v is nan");
		break;
		}
	
	cell.t=cell.t+cell.dt;

	i++;

	}

cell.apd_heading();
for (int x=0;x<cell.strandlength;x++)
	{
	cell.p=&(stranddata[x]);
	cell.apd_save(x);
	}
return(0);
}
