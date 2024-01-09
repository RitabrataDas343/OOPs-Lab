#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rockPaperScissor(char you,char comp){
  if(you==comp)
    return 0;

  if(you=='r'){
      if(comp=='s')
        return 1;
      if(comp=='p')
         return -1;
  }
  
  if(you=='p'){
      if(comp=='s')
        return -1;
      if(comp=='r')
         return 1;
  }

  if(you=='s'){
      if(comp=='p')
        return 1;
      if(comp=='r')
         return -1;
  }
  if(you!='p'||you!='r'||you!='s')
     return 2;

  return 0;
}

int main(){
  char comp,you;int ch,n;
  while(1){
    srand(time(0));
    n=(rand()%100)+1;

    if(n<33)
        comp='r';
    if(n>=33 && n<66)
        comp='s';
    if(n>66)
        comp='p';

    printf("Enter 'r' for rock,'s' for scissor and 'p' for paper:\n");
    scanf("%c",&you);
    printf("You chose %c and computer chose %c\n",you,comp);

    int result=rockPaperScissor(you,comp);

    if(result==1)
        printf("You Win!!!\n");
    if(result==0)
        printf("It's a Draw!!!\n");
    if(result==-1)
        printf("Computer wins!! Better luck next time....\n");
    if(result==2)
        printf("Wrong Choice entered!!!..Please enter correctly next time..\n");

    printf("If you want to exit type 0(zero) else type 1:\n");
    scanf("%d",&ch);
    getchar();
    
    if(ch==0){
      printf("Thank you for playing the game!!!");
      exit(0);
    }
  }
  return 1;
}
