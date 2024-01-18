// Linear Search
#include <iostream>
using namespace std;
int main() {
   int len =5,n=4;
   int a[len]={1,2,3,4,5};
   bool flag=false;
   for (int i=0;i<len;i++){
       if(a[i]==n){
           flag = true;
           cout<<"At "<<i;
           break;
       }
   }
   if(!flag){
       cout<<"Not Found";
   }
    return 0;
}
