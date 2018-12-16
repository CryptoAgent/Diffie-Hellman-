#include <iostream>
#include <string>

unsigned long long int pow(unsigned long long int a,unsigned long long b);
bool Prime(int a);

using namespace std;
int main(){

int p = 0;
int g = 0;
bool t=false;
cout<<"Enter p and q: \r\n";
while(!t){
    cin>>p;
    cin>>g;
    if(Prime(p)&&pow(g,p-1)%p==1){
        t=true;
    }
}
//Alice's private key
int a = 23;
//Bob's private key
int b = 31;
//Alice generate public key
int A = pow(g,a)%p;
//Bob generate public key
int B = pow(g,b)%p;
//Alice gets Bob's public key
int Ak=pow(B,a)%p;
//Bob gets Alice's public key
int Bk=pow(A,b)%p;
if(Bk==Ak){
    cout<<"Common key is : ";
    cout<<Bk;
}
return 0;
}

unsigned long long int pow(unsigned long long int a,unsigned long long b){
unsigned long long int res=a;
for(int i = 1;i<b;i++){
    res*=a;
}
return res;
}

bool Prime(int a){
if(a==1){return 0;}
for(int i = 2;i<a;i++){
    if(a%i==0){
        return 0;
    }
}
return 1;
}
