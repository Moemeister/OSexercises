#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
void childs(int x,int count){
   int child = fork();
   if(count == 0) return;
   else{
       if(child == 0){
           for(int i = x; i>=count;i--)
               printf("\t");
           printf("PID: %ld\n",(long)getppid());
           for(int i = x; i>=count;i--)
               printf("\t");
           printf("PID: %ld\n",(long)getpid());
          
       }else{
           wait(NULL);
       }
           childs(x,--count);
  
   }
}
int main(){
   int x;
   printf("Ingrese cantidad: ");
   scanf("%d",&x);
   printf("PID: %ld\n",(long)getpid());
//    if(fork()==0){
//        printf("\t");
//        printf("PID: %ld\n",(long)getppid());
//        printf("\t");
//        printf("PID: %ld\n",(long)getpid());
//        childs(x-1);
//    }else{
//    }
    childs(x,x);
    return 0;
}
