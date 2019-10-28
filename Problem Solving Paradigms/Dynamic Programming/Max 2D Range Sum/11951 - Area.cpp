#include <bits/stdc++.h>

using namespace std;

int t,n,m,c;
long long k,arr[105][105],sum,area;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
                arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            }
        }
       /* x1=x2=y11=y2=0;
        while(x1<n){
            x1++;
            x2=0;
            while(y11<m){
                y11++;
                while(x2<n){
                    x2++;
                    y2=1;
                    while(y2<=m){
                        if(k>=arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1] && (x2-x1+1)*(y2-y11+1)>=area){
                            if((x2-x1+1)*(y2-y11+1)==area && sum<arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1])sum=arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1];
                            else if((x2-x1+1)*(y2-y11+1)!=area){
                                area=(x2-x1+1)*(y2-y11+1);
                                sum=arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1];
                            }
                        }
                        else if(k<arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1]){
                            y11=y2+1;
                            y2++;
                            continue;
                        }
                        y2++;
                    }
                    cout<<x1<<' '<<x2<<' '<<y11<<' '<<x2<<' '<<area<<' '<<sum<<'\n';
                }
            }
        }*/
        for(int x1=1;x1<=n;x1++){
            for(int x2=x1;x2<=n;x2++){
                for(int y11=1;y11<=m;y11++){
                    for(int y2=y11;y2<=m;y2++){
                        if(k>=arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1] && (x2-x1+1)*(y2-y11+1)>=area){
                            if((x2-x1+1)*(y2-y11+1)==area && sum>arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1])sum=arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1];
                            else if((x2-x1+1)*(y2-y11+1)!=area){
                                area=(x2-x1+1)*(y2-y11+1);
                                sum=arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1];
                            }
                        }
                        else if(k<arr[x2][y2]-arr[x2][y11-1]-arr[x1-1][y2]+arr[x1-1][y11-1]){
                            break;
                        }
                        //cout<<x1<<' '<<x2<<' '<<y11<<' '<<x2<<' '<<area<<' '<<sum<<'\n';
                    }
                }
            }
        }
        cout<<"Case #"<<++c<<": "<<area<<' '<<sum<<'\n';
        area=0;
        sum=0;
    }
}
