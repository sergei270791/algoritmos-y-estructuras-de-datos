#include<iostream>
using namespace std;

int main(){
    for(int i=0;i<300;i++){
        int d,m,y,p;
        p=10+rand()%191;
        y=2015+rand()%6;
        m=1+rand()%3;
        if(m==1 || m==3){
            d=1+rand()%31;
        }
        else{
            if(y==2016 || y==2020){
                d=1+rand()%29;
            }
            else{
                d=1+rand()%28;
            }
        }
		cout<<d<<"\n"<<m<<"\n"<<y<<"\n"<<p<<"\n"<<endl;
    }
}

