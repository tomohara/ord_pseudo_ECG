#include <math.h>
#include <stdio.h>
#include <iostream>
#include "humandata.h"
#include "human.h"

void human::save_heading(int strandlength)
{
one=fopen(one_path,"w");
fprintf(one,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","nai","nass","ki","kss","cai","cass","cansr","cajsr","Jrel","CaMKt","Jup","Jtr","Jdiff","JdiffNa","JdiffK","Jleak","INa","INaL","Ito","ICaL","ICaNa","ICaK","IKr","IKs","IK1","INaCa_i","INaCa_ss","INaK","INab","IKb","IpCa","ICab","Ist","dt","APD90","APD70","APD50","APD30");
fclose(one);

if (strandlength>=5)
	{
	two=fopen(two_path,"w");
	fprintf(two,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","nai","nass","ki","kss","cai","cass","cansr","cajsr","Jrel","CaMKt","Jup","Jtr","Jdiff","JdiffNa","JdiffK","Jleak","INa","INaL","Ito","ICaL","ICaNa","ICaK","IKr","IKs","IK1","INaCa_i","INaCa_ss","INaK","INab","IKb","IpCa","ICab","Ist","dt","APD90","APD70","APD50","APD30");
	fclose(two);
	
	three=fopen(three_path,"w");
	fprintf(three,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","nai","nass","ki","kss","cai","cass","cansr","cajsr","Jrel","CaMKt","Jup","Jtr","Jdiff","JdiffNa","JdiffK","Jleak","INa","INaL","Ito","ICaL","ICaNa","ICaK","IKr","IKs","IK1","INaCa_i","INaCa_ss","INaK","INab","IKb","IpCa","ICab","Ist","dt","APD90","APD70","APD50","APD30");
	fclose(three);

	four=fopen(four_path,"w");
	fprintf(four,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","nai","nass","ki","kss","cai","cass","cansr","cajsr","Jrel","CaMKt","Jup","Jtr","Jdiff","JdiffNa","JdiffK","Jleak","INa","INaL","Ito","ICaL","ICaNa","ICaK","IKr","IKs","IK1","INaCa_i","INaCa_ss","INaK","INab","IKb","IpCa","ICab","Ist","dt","APD90","APD70","APD50","APD30");
	fclose(four);
	
	five=fopen(five_path,"w");
	fprintf(five,"%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\t%-07s\n",
"variables=","t","v","nai","nass","ki","kss","cai","cass","cansr","cajsr","Jrel","CaMKt","Jup","Jtr","Jdiff","JdiffNa","JdiffK","Jleak","INa","INaL","Ito","ICaL","ICaNa","ICaK","IKr","IKs","IK1","INaCa_i","INaCa_ss","INaK","INab","IKb","IpCa","ICab","Ist","dt","APD90","APD70","APD50","APD30");
	fclose(five);
	}
}

void human::save(int x, int strandlength)
{
if (x==0 && save_flag==0 && strandlength==1)
	{
	voltages=fopen(voltages_path,"w");
	fprintf(voltages,"%-07g\t%-07g\n",
	t-tsave,p->v);
	fclose(voltages);
	save_flag=1;
	}
else if (x==0 && save_flag==1 && strandlength==1)
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-07g\t%-07g\n",
	t-tsave,p->v);
	fclose(voltages);
	}
else if (x==0 && save_flag==0)
	{
	voltages=fopen(voltages_path,"w");
	fprintf(voltages,"%-07g\t%-07g\t",
	t-tsave,p->v);
	fclose(voltages);
	save_flag=1;
	}
else if (x==0 && save_flag==1)
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-07g\t%-07g\t",
	t-tsave,p->v);
	fclose(voltages);
	}
else if (x==(strandlength-1))
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-07g\n",
	p->v);
	fclose(voltages);
	}
else
	{
	voltages=fopen(voltages_path,"a");
	fprintf(voltages,"%-07g\t",
	p->v);
	fclose(voltages);
	}
	
double here=(double)x/(double)strandlength;
double there=(double)(x+1)/(double)strandlength;

if (x==0)
	{
	one=fopen(one_path,"a");
	fprintf(one,"%-012e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
	t-tsave,p->v,p->nai,p->nass,p->ki,p->kss,p->cai,p->cass,p->cansr,p->cajsr,Jrel,p->CaMKt,Jup,Jtr,Jdiff,JdiffNa,JdiffK,Jleak,INa,INaL,Ito,ICaL,ICaNa,ICaK,IKr,IKs,IK1,INaCa_i,INaCa_ss,INaK,INab,IKb,IpCa,ICab,Ist,dt,p->APD90,p->APD70,p->APD50,p->APD30);
	fclose(one);
	}	
else if (strandlength>=5 && here<=0.2 && there>0.2)
	{
	two=fopen(two_path,"a");
	fprintf(two,"%-012e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t-tsave,p->v,p->nai,p->nass,p->ki,p->kss,p->cai,p->cass,p->cansr,p->cajsr,Jrel,p->CaMKt,Jup,Jtr,Jdiff,JdiffNa,JdiffK,Jleak,INa,INaL,Ito,ICaL,ICaNa,ICaK,IKr,IKs,IK1,INaCa_i,INaCa_ss,INaK,INab,IKb,IpCa,ICab,Ist,dt,p->APD90,p->APD70,p->APD50,p->APD30);
	fclose(two);
	}
else if (strandlength>=5 && here<=0.4 && there>0.4)	
	{
	three=fopen(three_path,"a");
	fprintf(three,"%-012e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t-tsave,p->v,p->nai,p->nass,p->ki,p->kss,p->cai,p->cass,p->cansr,p->cajsr,Jrel,p->CaMKt,Jup,Jtr,Jdiff,JdiffNa,JdiffK,Jleak,INa,INaL,Ito,ICaL,ICaNa,ICaK,IKr,IKs,IK1,INaCa_i,INaCa_ss,INaK,INab,IKb,IpCa,ICab,Ist,dt,p->APD90,p->APD70,p->APD50,p->APD30);
	fclose(three);
	}
else if (strandlength>=5 && here<=0.6 && there>0.6)
	{
	four=fopen(four_path,"a");
	fprintf(four,"%-012e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t-tsave,p->v,p->nai,p->nass,p->ki,p->kss,p->cai,p->cass,p->cansr,p->cajsr,Jrel,p->CaMKt,Jup,Jtr,Jdiff,JdiffNa,JdiffK,Jleak,INa,INaL,Ito,ICaL,ICaNa,ICaK,IKr,IKs,IK1,INaCa_i,INaCa_ss,INaK,INab,IKb,IpCa,ICab,Ist,dt,p->APD90,p->APD70,p->APD50,p->APD30);
	fclose(four);
	}
else if (strandlength>=5 && here<=0.8 && there>0.8)
	{
	five=fopen(five_path,"a");
	fprintf(five,"%-012e\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\t%-07g\n",
        t-tsave,p->v,p->nai,p->nass,p->ki,p->kss,p->cai,p->cass,p->cansr,p->cajsr,Jrel,p->CaMKt,Jup,Jtr,Jdiff,JdiffNa,JdiffK,Jleak,INa,INaL,Ito,ICaL,ICaNa,ICaK,IKr,IKs,IK1,INaCa_i,INaCa_ss,INaK,INab,IKb,IpCa,ICab,Ist,dt,p->APD90,p->APD70,p->APD50,p->APD30);
	fclose(five);
	}
}
