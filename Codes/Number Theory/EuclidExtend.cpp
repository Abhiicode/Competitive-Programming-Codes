#include<iostream>
using namespace std;
class Triplet{
    public:
    int gcd;
    int x; int y;
};
Triplet EuclidExtendgcd(int a , int b){
    if(b==0){
        Triplet ans;
        ans.gcd=a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    Triplet temp = EuclidExtendgcd(b,a%b);
    Triplet ans;
    ans.gcd = temp.gcd;
    ans.x = temp.y;
    ans.y = (temp.x-((a/b)*temp.y));
    return ans;

}
int main(){
   Triplet t =  EuclidExtendgcd(5,17);
//    cout<<t.gcd<<endl;
   cout<<t.x<<endl;
//    cout<<t.y<<endl;

}