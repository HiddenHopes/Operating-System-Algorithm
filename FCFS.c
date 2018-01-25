#include<stdio.h>

void main(){
    int i, n, arv[20], ser[20], start[20], finish[20],wt[20],trn[20];
    float wait,turn,avg_turn,avg_wait;

    freopen("fcfs.txt","r",stdin);

    printf("\nnumber of jobs: ");
    scanf("%d",&n);
    printf("%d\n",n);

    printf("\n  job   \ArrivalTime   \ServiceTime\n");
    printf(" _____ _____________ _____________\n");
    for(i=1;i<=n;i++){
        printf("| %3d ",i);
        scanf("%d%d",&arv[i],&ser[i]);
        printf("| %7d     | %7d     |\n",arv[i],ser[i]);
    }
    printf(" _____ _____________ _____________\n");


    printf("\n\nGANTTChart\n");
    printf("_________________________________________________________________\n|");
    for(i=1;i<=n;i++){
        printf("   job %d   ||",i);
    }
    printf("\n_________________________________________________________________\n");

    start[1] = arv[1];
    for(i=1;i<=n;i++){
        finish[i] = start[i]+ser[i];
        if(arv[i+1]<=finish[i])start[i+1] = finish[i];
        else start[i+1] = arv[i+1];

    }


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


    printf("\n\n\n  job   \   A.T  \  F.T  \   W.T   \  T.A  \n");
    printf(" _______ _______ _______ _______ _______\n");
    for(i=1;i<=n;i++){
        printf("\n|  %2d   |  %2d   |  %2d   |  %2d   |  %2d   |",i,arv[i],finish[i],wt[i],trn[i]);
    }

    avg_wait=wait/n;
    avg_turn=turn/n;
    printf("\n\naverage waiting time: %.2f",avg_wait);
    printf("\n\naverage Turn Around time: %.2f\n",avg_turn);
}
