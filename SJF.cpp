#include<stdio.h>         //  %\=+
#include<algorithm>
using namespace std;

int main(){
    int i,j, n, arv[20], ser[20], start[20], finish[20],wt[20],trn[20],copy[20];
    float wait,turn,avg_turn,avg_wait;

    freopen("fcfs.txt","r",stdin);

    printf("\nnumber of jobs: ");
    scanf("%d",&n);
    printf("%d\n",n);

    printf("\n  job   ArrivalTime   ServiceTime\n");
    printf(" _____ _____________ _____________\n");
    for(i=1;i<=n;i++){
        printf("| %3d ",i);
        scanf("%d%d",&arv[i],&ser[i]);
        copy[i]=ser[i];
        printf("| %7d     | %7d     |\n",arv[i],ser[i]);
    }
    printf(" _____ _____________ _____________\n");

    sort(copy+2,copy+n);


    start[1] = arv[1];
    finish[1] = start[1]+ser[1];
    for(i=2;i<=n;i++){
        j=2;
        while(j<=n){
            if(ser[j] == copy[i]&&arv[j]<=finish[i-1]){
               start[i] = finish[i-1];
               copy[i] = -1;
               finish[i] = start[i]+ser[j];
               break;
            }

            j++;
        }

    }


    printf("\n\nGANTTChart\n");
    printf("_________________________________________________________________\n|");
    for(i=1;i<=n;i++){
        printf("   job %d   ||",i);
    }
    printf("\n_________________________________________________________________\n");


    for(i=1;i<=n;i++){
        if(finish[i-1]!=start[i])printf("|%d",start[i]);
        else printf("  ");
        printf("%11d",finish[i]);
    }
    wait=0;
    turn=0;
    for(i=1;i<=n;i++){
        wt[i]=start[i]-arv[i];
        trn[i]=finish[i]-arv[i];
        wait=wait+wt[i];
        turn=turn+trn[i];

    }


    printf("\n\n\n  job      A.T     F.T     W.T     T.A  \n");
    printf(" _______ _______ _______ _______ _______\n");
    for(i=1;i<=n;i++){
        printf("\n|  %2d   |  %2d   |  %2d   |  %2d   |  %2d   |",i,arv[i],finish[i],wt[i],trn[i]);
    }

    avg_wait=wait/n;
    avg_turn=turn/n;
    printf("\n\naverage waiting time: %.2f",avg_wait);
    printf("\n\naverage Turn Around time: %.2f\n",avg_turn);

return 0;
}
