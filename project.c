#include<stdio.h>
#include <math.h>
#include<time.h>

int * combination(int N[],int n,int length){

double a=pow((double)length,(double) n);

  int b = (int) a;
 int *arr = (int*) malloc(b * sizeof(int));


     int i;
     for( i=0;i<b;i++){
   *(arr+i)=0;

     }
    int k;
     for( k=1;k<=length-1;k++){

       double c=pow((double)length,(double) n-k);
         int d = (int) c;
         int z=d;
          int j=0;
   for( i=0;i<b;i++){
       if(i<d){
           *(arr+i)=*(arr+i)+N[j];

       }
      else if(i==d){
           d=d+z;
           j++;
           if(j>=length){
               j=0;
           }

              *(arr+i)=*(arr+i)+N[j];

       }

          *(arr+i)=*(arr+i)*10;


    }


     }
      for( i=0;i<b;i++){


    }
     int x=length-n;
     int h=0;
     int l=1;

     while(h<x){
         l=l*10;
         h++;
     }

   for( i=0;i<b;i++){
       *(arr+i)=*(arr+i)/l;

    }

    return arr;
}


  float * mean(int *arr,int Csize,int n){
      double a=pow((double)n,(double) Csize );
      int b=(int)a;
            int *arr2 = (int*) malloc(b * sizeof(int));
      float *arr1;
        arr1 = malloc(b * sizeof(float));
        int i,j;
        for( i=0;i<a;i++){
           *(arr1+i)=0;
            *(arr2+i)=0;
        }
        for( i=0;i<b;i++){
            for( j=0;j<Csize;j++){
                int c=*(arr+i)%10;


          *(arr2+i)+=c;
          int d=c;
          // printf("i=%d j=%d c=%d arr=%d   ",i,j,d,*(arr2+i));
          *(arr+i)=*(arr+i)/10;



            }

           float c=*(arr2+i)/(float)Csize;
           printf("c=%f",c);
           *(arr1+i)=c;

        }

     return arr1;
    }


       float variance(float *arr,float *counter,int length){
        float *a;
        a = malloc(length * sizeof(float));
        int i;
        for( i=0;i<length;i++){
        *(a+i)=pow(*(arr+i), 2);

        }

           for(i=0;i<length;i++){
       *(a+i)=*(a+i)*(*(counter+i));
        }
           float b=0;
                      for( i=0;i<length;i++){
        b=b+*(a+i);
        }

                      return b;

    }

float probability(float *arr,float *counter,int length){

        float *sampling;
        sampling = malloc(length * sizeof(float));
     int i;
        for( i=0;i<length;i++){
                float c=*(counter+i);

            *(counter+i)=c/(float)length;

           *(sampling+i)= *(counter+i) * (*(arr+i));

        }
        float a=0;
         for( i=0;i<length;i++){
            a =*(sampling+i)+a;
       }

         a=pow(a, 2);
       float var=variance(arr,counter,length);
        var=var-a;
        return var;
    }



float frequency(float *arr,int length){
            float *arr1;
        arr1 = malloc(length * sizeof(float));
            float *arr2;
        arr2 = malloc(length * sizeof(float));
            float *arr3;
        arr3 = malloc(length * sizeof(float));
           int i;
               for( i=0;i<length;i++){
                    *(arr1+i)=0;
                   *(arr2+i)=0;
                   *(arr3+i)=*(arr+i);

               }
          int j=0;
        for(i=0;i<length;i++){
           int counter=0;
           int k;
            for( k=0;k<length;k++){
                if (*(arr+i)<0){
                    break;
                }

           else if(*(arr+i)==*(arr3+k) ){

                counter++;
                *(arr3+k)=-1;

            }

            }

            if(counter!=0){
            *(arr1+j)=*(arr+i);
           *(arr2+j)=counter;
            j++;
                    }
        }
        for( i=0;i<length;i++){
printf("%f   %f \n",*(arr1+i),*(arr2+i));
        }
     float var;
     var=probability(arr1,arr2,length);
        return var;
}











int main(){
 int   n=4,a=10;

      int j=3;
      int arr[a];
      int i;
      for( i=0;i<a;i++){
          //arr[i]=obj.nextInt();
          arr[i]=j;
          j++;
         printf("%d ",arr[i]);
      }
      int *res;
      clock_t t1,t2;
      t1 = clock();
	  res=combination(arr, n,a);
	  double b=pow((double)a,(double)n );
	  for( i=0;i<b;i++){
	  	printf("A:%d ",*(res+i));
	  }
	 float *m=mean(res,n,a);


	 for( i=0;i<b;i++){

	  	printf("B:%f ",*(m+i));
	  }
	 float var= frequency(m,b);
     t2 = clock();
     double t = (double)(t2-t1)/CLOCKS_PER_SEC;
	 printf("%f",t);
}
