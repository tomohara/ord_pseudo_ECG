#include <string>
using namespace std;

class human
{
public:

human();
human(char argv1[],char argv2[], char argv3[],char argv4[]);
humandata *p,*l,*r;
FILE *ecg_file,*apd_file,*voltages,*one,*two,*three,*four,*five;
char ecg_path[250],apd_path[250],voltages_path[250],one_path[250],two_path[250],three_path[250],four_path[250],five_path[250];
void ECG(int x),ecg_heading(),ecg_save(),apd_heading(),apd_save(int x),revpots(),rates(int x),gates(int x),currents(int x),stim(int x, int stim_here),voltage(int x),dvdt(int x),update(int x),fluxbuf(int x),concentrations(int x),save_heading(int strandlength),save(int x, int strandlength);	

string extra;

double t,dt,ft;
double tsave;
int strandlength;
double CL,start,amp,duration;
int beats,beatssave;
int n,stim_here,skip;
int save_flag;
double radius,gj,Rmyo,dX;
double nao,cao,ko;
double C,R,T,F;
double L,rad,vcell,Ageo,Acap,vmyo,vmito,vsr,vnsr,vjsr,vss;

double ENa,EK,EKs;
double mss,tm,hss,thf,ths,Ahf,Ahs,h,jss,tjf,tjs,Ajf,Ajs,j;
double mLss,tmL,hLss,thL;
double ass,ta,iss,tiF,tiS,AiF,AiS,i;
double dss,td,fss,tff,tfs,Aff,Afs,f,fcass,tfcaf,tfcas,Afcaf,Afcas,fca,tjca;
double xrss,txrf,txrs,Axrf,Axrs,xr,rkr;
double xs1ss,txs1,xs2ss,txs2;
double xk1ss,txk1,rk1;
double xkb;
double INa,INaL,Ito,ICaL,ICaNa,ICaK,IKr,IKs,IK1,INaCa_i,INaCa_ss,INaK,INab,ICab,IpCa,IKb,Ist;
double Jup,Jtr,Jdiff,JdiffNa,JdiffK,Jleak;
double cmdn,trpn,csqn,BSR,BSL;
double CaMKa,CaMKb;

double hssp,thsp,tjfp,tjsp,hp,jp;
double hLssp,thLp;
double incomplete;
double assp,tiFp,tiSp,dti_develop,dti_recover,ip;
double tffp,fcassp,tfcafp,fp,fcap;
double Jrel,Jupnp,Jupp;

double ICaL_max,ICaNa_max,ICaK_max;

double BSRmax,KmBSR,BSLmax,KmBSL;
double cmdnmax,kmcmdn,trpnmax,kmtrpn,csqnmax,kmcsqn;
double aCaMK,bCaMK,CaMKo,KmCaM,KmCaMK;

int endo,M,epi;
double Phi,gradV;
double tvdotmax_start,tvdotmax_end,CV;
};
