#include<stdio.h>

int main (void){
    int temp1,temp2,c,pl,lastp[3],count=0;
    printf("輸入柱子數、盤子數(上限柱子26盤子100)\n");
    scanf("%d %d",&c,&pl);
    int k[c];
    char p[pl],temp3,temp4,lastc[3];
    for(temp2=1;temp2<=c;temp2++) k[temp2-1]=0;
    for(temp2=1;temp2<=pl;temp2++) p[temp2-1]='a';
    printf("1-->柱子式移動\n2-->盤子式移動\n3-->列出柱子上的盤子編號\n4-->尋找盤子\n\n");
    do{ 
       for(temp1=1;temp1<=c;temp1++){
        for(temp2=1;temp2<=pl;temp2++){
         if('a'+temp1-1==p[temp2-1]){
          k[temp1-1]=temp2;
          temp2=pl+1;
          }
		  else k[temp1-1]=0;         
         }
        } 
       printf("輸出每柱子上最高的盤子編號(0表示沒東東)\n");
       for(temp1=1;temp1<=c;temp1++)printf("%c-->%d\n",temp1-1+'a',k[temp1-1]); 
       printf("\n\n\n輸入指令(1~4)");      
       scanf("%d",&temp1);
       switch (temp1){
        case 1:
				 printf("輸入兩柱編號\n");
				 scanf(" %c",&temp3);
				 scanf(" %c",&temp4);
				 if(k[temp3-'a']<k[temp4-'a']||k[temp4-'a']==0){
                  p[k[temp3-'a']-1]=temp4;
                  count++;
                  }                  
				 else printf("柱子上怪怪的\n");
				 printf("已移動幾次%d\n",count); 
          		 break;
		case 2:
                 printf("輸入盤子柱子編號\n");
				 scanf("%d  %c",&temp1,&temp3);
                 if((temp1<k[temp3-'a']&&k[p[temp1-1]-'a']==temp1)||k[temp3-'a']==0){
                  p[temp1-1]=temp3;
                  count++;
                  }
                 else printf("柱子上怪怪的\n");
                 printf("已移動幾次%d\n",count); 
				 break;
        case 3:
				 printf("輸入第柱子編號");
				 scanf(" %c",&temp3);
				 for(temp1=1;temp1<=pl;temp1++)	if(temp3==p[temp1-1]) printf("%d\n",temp1);
				 printf("Are you ready? (按1)");
                 scanf("%d",&temp1);
				 break;
        case 4:
				 printf("輸入尋找的盤子編號？\n");
				 scanf("%d",&temp1);
				 if(temp1<=pl) printf("在%c柱\n",p[temp1-1]);
                 else printf("ㄜ....有這個盤子嗎?\n");			 
				 printf("Are you ready? (按1)");
                 scanf("%d",&temp1);
				 break;
		default:
				 printf("別開我玩笑\n不給你用了喔?(結束按4)(否則按5)");
				 scanf("%d",&temp1);
				 if(temp1==4) return 0;
				 break;
              }
     }while(1);
     return 0;
          }
                 
