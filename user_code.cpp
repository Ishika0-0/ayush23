class Solution {
public:
    #define ll long long
    ll dp[20][2][2][20][20][50];
    int k;
    ll solve(string &s,int n,bool tight,bool isleading,int cnteven,int cntodd,int rem)
    {
        if(n==0)
        {
            if(cnteven==cntodd && rem==0)
            {
                return 1;
            }
            else return 0;
        }
        if(dp[n][tight][isleading][cnteven][cntodd][rem]!=-1) return dp[n][tight][isleading][cnteven][cntodd][rem];
        int lim=tight?s[s.size()-n]-'0':9;
        ll ans=0;
        for(int dig=0;dig<=lim;dig++)
        {
            if(isleading && dig==0)
            {
                ans+=solve(s,n-1,0,isleading&(dig==0),0,0,0);
            }
            else
            {
                if(dig%2==0)
                {
                    ans+=solve(s,n-1,tight&(dig==lim),0,cnteven+1,cntodd,(rem*10+dig)%k);
                }
                else
                {
                    ans+=solve(s,n-1,tight&(dig==lim),0,cnteven,cntodd+1,(rem*10+dig)%k);
                }
            }
        }
        return dp[n][tight][isleading][cnteven][cntodd][rem]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int K) {
        k=K;
        memset(dp,-1,sizeof(dp));
        low--;
        string lower=to_string(low);
        ll ansleft=solve(lower,lower.size(),1,1,0,0,0);
        memset(dp,-1,sizeof(dp));
        string higher=to_string(high);
        ll ansright=solve(higher,higher.size(),1,1,0,0,0);
        return ansright-ansleft;
    }
};
