#include<iostream>
#include <bits/stdc++.h>
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
long long modulo(long long A , long long M){
    long long x = EuclidExtendgcd(A , M).x;
    return (x%M + M)%M;
}
int maxOut(int a , int b, int d){
    int t;
    cin>>t;
    while(t--){
        long long a,b,d;
        cin>>a>>b>>d;
        long long g = __gcd(a,b);
        a/=g;
        b/=g;
        d/=g;
        if(d%g){
            cout<<0<<endl;
            continue;
        }
        if(d==0){
            cout<<1<<endl;
            continue;
        }
        long long y1 = ((d%a)*modulo(b,a))%a;
        if(d<y1*b){
            cout<<0<<endl;
            continue;
        }
        long long n = ((d/b)-y1)/a;
        cout<<n+1<<endl;

    }
}
int main(){
    cout<<maxOut(2,3,8);
}