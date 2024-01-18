//Transpose
#include <iostream>
using namespace std;
int main() {
    int r=2,c=3;
    int a[r][c]={{1,2,3},{4,5,6}};
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
