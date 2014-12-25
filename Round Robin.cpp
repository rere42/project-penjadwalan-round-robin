#include<iostream.h>
#include<iomanip.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
void main(){
	system ("color 1a");

cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<"#\t\t Penjadwalan CPU Round Robin  \t\t#"<<endl;
cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl;

int tmslice,i,j,m,wt[10],st[10],et[10],n,tat[10],bt[10],a[10],twt=0,ttat=0;
float ratawt,ratatat;
char p[10][10];
cout<<"\n Masukkan Angka Untuk Proses Round Robin : ";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\n Silahkan Masukkan Nama Untuk Proses : ";
cin>> p[i];
cout<<"\n Silahkan Masukkan Angka Untuk Burst Time : ";
cin>>bt[i];
}
cout<<endl;
cout<<"\n Silahkan Masukkan Angka Untuk Time Slice : ";
cin>>tmslice;
cout<<endl;
st[0]=0;
i=0;
do{
if(bt[i]<=tmslice)
{et[i]=st[i]+bt[i];
bt[i]=0;
tat[i]=et[i];}
else
{et[i]=st[i]+tmslice;
bt[i]=bt[i]-tmslice;}
wt[i]=st[i];
st[i+1]=et[i];
i=i+1;
}while(i<n);
 m=n-1;
j=0;
a[m]=1234;
do{ for(i=0;i<n;i++){
if(bt[i]==0)
{tat[i]=tat[i];}
else
{st[m+1]=et[m];
 a[m+1]=i;
if(bt[i]<=tmslice)
{et[m+1]=st[m+1]+bt[i];
bt[i]=0;
tat[i]=et[m+1];}
else
{et[m+1]=st[m+1]+tmslice;
bt[i]=bt[i]-tmslice;}
if(a[m]==a[m+1])
{wt[i]=wt[i]+0;}
else
{wt[i]+=st[m+1]-et[i];}
m=m+1;} }
if(bt[j]!=0)continue;
j=j+1;
}while(j<n);
cout<<"\n Name"<<"\t Turn Aroun Time"<<"\t Waiting Time";
for(i=0;i<n;i++)
{cout<<"\n" <<p[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<wt[i]<<"\n";
twt+=wt[i];
ttat+=tat[i];
}
ratawt=(float) (twt)/n;
ratatat= (float)(ttat)/n;
cout<<"\n Rata-Rata Turn Around Time : "<<ratatat;
cout<<"\n Rata-Rata Waiting Time     : "<<ratawt;
cout<<endl<<endl;
getch();
ofstream cout("nota.txt", ios::app);
cout<<"\n Name"<<"\t Turn Aroun Time"<<"\t Waiting Time";
for(i=0;i<n;i++)
{cout<<"\n" <<p[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<wt[i]<<"\n";
twt+=wt[i];
ttat+=tat[i];
}
ratawt=(float) (twt)/n;
ratatat= (float)(ttat)/n;
cout<<"\n Rata-Rata Turn Around Time : "<<ratatat/2;
cout<<"\n Rata-Rata Waiting Time     : "<<ratawt/2<<endl<<endl;
cout<<"####################################################"<<endl<<endl;
getch();
}






