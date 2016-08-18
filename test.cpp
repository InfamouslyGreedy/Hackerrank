#include <bits/stdc++.h>
using namespace std ;
#define LL long long int
#define ft first
#define sd second
#define PII pair<int,int >
#define MAXN 222222
#define MAXM 10000001
#define mp make_pair
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define pb push_back
#define MOD 1000000007
#define ULL unsigned long long
#define all(x) x.begin(),x.end()
int T,N,K,A[MAXN] ,totalN;

int main(){

    cin >> T ;
    assert(T <= 100000 && T >= 1) ;
    while(T--){
        cin >> N >> K ;
        assert(N <= 200000 && N >= 1) ;
        assert(K <= 1000000000 && K >= 0) ;
        totalN += N ;
        for(int i=1;i<=N;i++){
            cin >> A[i] ;
            assert( A[i] <= 1000000000 && A[i] >= 1 ) ;
        }
        LL need = (1LL * N * (N+1) / 2) , notneeded;
        notneeded = 0 ;
        int i = 1;
        while(i<=N){
            if(A[i] > K){
                i ++ ;
                continue ;
            }
            int cnt = 0 ;
            while(i <= N && A[i] <= K){  
                i ++ ;
                cnt ++ ;
            }
            notneeded += (1LL * cnt * (cnt+1) / 2) ;
        }
        cout << need-notneeded << endl ;
    }
    assert(totalN <= 1000000 && totalN >= 1) ;
    return 0 ;
}
