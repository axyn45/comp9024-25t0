#include <stdio.h>
#include <math.h>

int main(){
    int a=10000,b=100;
    int i=a;
    int p=0,m=0;
    while(i<99999){
        p=have9(i);
        // if(e){
        //     printf("%d %d\n",i,e);
        // }
        // p=(int)pow(10,e-1);
        m=i%p;
        i+=(p-m);

        
        int j=b;
        while(j<999){
            p=have9(j);
            // if(e){
            //     printf("%d %d\n",j,e);
            // }
            // p=(int)pow(10,e-1);
            m=j%p;
            j+=(p-m);

            if(validate(i,j))
                printf("%d %d\n",i,j);
            j++;
        }
        i++;
    }
    // for(int i=0;i<10;i++){
    //     if(i%2){
    //         continue;
    //     }
    //     printf("%d\n",i);
    // }
}

int validate(int a,int b){
    if(a%b==0){
        if((a+1)%(b+1)==0){
            int t=(a%b)-((a+1)%(b+1));
            if(t==100||t==-100)
                return 1;
        }
    }
    return 0;
}

int have9(int a){
    int b=a;
    int index=-1;
    while(b){
        if(b%10==9){
            // index++;
            break;
        }
        b/=10;
        index++;
    }
    if(index<0)return 0;
    return pow(10,index);
}