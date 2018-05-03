#include<stdio.h>
#include <math.h>
#include<pthread.h>
#include <unistd.h>
#include<time.h>
int length,n,a;
int *arr;
float *arr1, *arr2;
float a1=0,var=0;



float variance(int a){
        int i;
           for( i=0;i<length;i++){
        *(arr1+i)=(*(arr1+i))*(*(arr2+i));
        }
           float b=0;
                      for( i=0;i<length;i++){
        b=b+*(arr1+i);
        }

                      return b;

    }



void *variancePower(void *threadid){
     printf("in power");
    double b=pow((double)length,(double) n);
    int length1=(int)b;

int i;
        for( i=0;i<length1;i++){
         *(arr1+i)=(int)pow((double)*(arr1+i),(double) 2);

        }
}




void *message(void *threadid)
 {
 double b=pow((double)length,(double) n);

       int *p=threadid;
printf("thread z=%d",*p);
         double c=pow((double)length,(double) (n-*(p)));
          int d = (int) c;
         int z=d;
          int j=1,i;
          printf("p= %d",*p);
   for( i=0;i<(int)b;i++){
       if(i<d){
           *(arr+(((*(p)-1)*a)+i))=*(p+j);


       }
      else if(i==d){
           d=d+z;
           j++;
           if(j>=length+1){
               j=1;
           }

             *(arr+(((*(p)-1)*a)+i))=*(p+j);

       }

    }

    return arr;
  }







  void *prob(void *threadid){
printf("prb thread");
      int p=(int)threadid;

double b=pow((double)length,(double) n);
int length1=(int)b;

        float *sampling;
        sampling = malloc((length1/2) * sizeof(float));
     int i;
     float c;
    if(p==1){
 for( i=0;i<(length1/2);i++){

                 c=*(arr2+i);
                  *(arr2+i)=c/(float)length1;

            *(sampling+i)= *(arr2+i) * (*(arr1+i));
 }

         for( i=0;i<(length1/2);i++){
            printf("1   ");
            a1 =*(sampling+i)+a1;

       }
     }
     else if(p==2){//half ka kaam karna hay
         //  printf("in t-2");
        for( i=(length1/2);i<length1;i++){

                 c=*(arr2+i);
                 *(arr2+i)=c/(float)length1;

 *(sampling+i)= *(arr2+i) * (*(arr1+i));

        }
     for( i=(length1/2);i<length1;i++){

            a1 =*(sampling+i)+a1;
             printf("2   ");

       }
     }
  }












  void frequency(float *mean,int length1){

        arr1 = malloc(length1 * sizeof(float));

        arr2 = malloc(length1 * sizeof(float));
            float *arr3;
        arr3 = malloc(length1 * sizeof(float));
           int i;
               for( i=0;i<length1;i++){
                    *(arr1+i)=0;
                   *(arr2+i)=0;
                   *(arr3+i)=*(mean+i);

               }
          int j=0;
        for(i=0;i<length1;i++){
           int counter=0;
           int k;
            for( k=0;k<length1;k++){
                if (*(mean+i)<0){
                    break;
                }

           else if(*(mean+i)==*(arr3+k) ){

                counter++;
                *(arr3+k)=-1;

            }

            }

            if(counter!=0){
            *(arr1+j)=*(mean+i);
           *(arr2+j)=counter;
            j++;
                    }
        }
        for( i=0;i<length1;i++){
printf("%f   %f \n",*(arr1+i),*(arr2+i));
        }


}







int main(){

  n=2,length=4;
  int i;
  int ar[length+1];
  ar[0]=1;
  pthread_t threads[n];
 int j=3;
     for(i=1;i<=length;i++){
            ar[i]=j;
     j++;
     }

 double b=pow((double)length,(double) n);
  a=(int) b;
  int c=(a*n);

 arr = (int*) malloc(c * sizeof(int));
float *mean = (float*) malloc(a * sizeof(float));
 clock_t t1,t2;
      t1 = clock();
  for(i=0;i<n;i++){

      pthread_create(&threads[i],0, message,(void *)ar);
pthread_join(threads[i],0);
    ar[0]++;
  }


for(i=0;i<a;i++){
    *(mean+i)=0;
}
int k;
for(i=0;i<a;i++){
    // printf("aaaa %d",*(arr+i));
        for(k=1;k<=n;k++){

    *(mean+i)=*(mean+i)+(float)*(arr+((n-k)*a)+i);
}
*(mean+i)=*(mean+i)/(float)n;
}

frequency(mean,a);

  pthread_t thread1,thread2,thread3,thread4,thread5;

int v=1;

     int l= pthread_create(&thread1,0, prob,(void *)v);
         printf("bilal %d",l);
      v=v+1;
     l= pthread_create(&thread2,0, prob,(void *)v);
         printf("bilal %d",l);
    pthread_join(thread1,0);
    pthread_join(thread2,0);

 printf("a1=%f",a1);
           a1=pow(a1, 2);
           printf("a1=%f",a1);

           pthread_create(&thread3,0, variancePower,(void *)v);
             pthread_join(thread3,0);


printf("mean");
for(i=0;i<a;i++){
    // printf("aaaa %d",*(arr+i));
       printf("     %f",*(arr1+i));
}
/*
  int l=pthread_create(&thread4,0, prob,(void *)v);

             printf("bilal %d",l);
             v=v+10;
              l=  pthread_create(&thread5,0, prob,(void *)v);
              pthread_join(thread4,0);
             pthread_join(thread5,0);
             printf("bilal %d",l);*/
             var=variance(a);
             var=var-a1;
                       printf("var=%f",var);
                        t2 = clock();
                         double t = (double)(t2-t1)/CLOCKS_PER_SEC;
                        printf("%f",t);
}
