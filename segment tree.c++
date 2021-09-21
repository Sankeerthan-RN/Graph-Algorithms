
#include <bits/stdc++.h>
using namespace std;
void buildst(int arr[],int sarr[],int ss,int se, int si)
{
    if(se==ss)
    {
         
        sarr[si]=arr[ss];
         
        return;
    }
    int mid=(ss+se)/2;
    buildst(arr,sarr,ss,mid,(2*si) + 1);
    buildst(arr,sarr,mid+1,se,(2*si) + 2);
   
    sarr[si]=sarr[2*si + 1]+sarr[2*si + 2];
     
    return;
}
int range(int ql,int  qr,int s,int e,int idx,int st[])
{
    if(ql<=s && qr>=e)
    {
         
        return st[idx];
       
    }
    
    if(qr<s ||ql>e)return 0;
    int mid=(s+e)/2;
    int left=range(ql,qr,s,mid,(2*idx)+1,st);
    int right=range(ql,qr,mid+1,e,(2*idx)+2,st);
    return left+right;
}

void update(int s,int e,int stidx,int idx ,int val,int st[])
{
    if(s==e)
    {
        
        
        st[stidx]=val;
        return;
       
    }
    int mid=(s+e)/2;
   
   if(idx>mid){
        update(mid+1,e,(2*stidx)+2,idx,val,st);
     
    }
    else{
        update(s,mid,(2*stidx)+1,idx,val,st);
        
    }
    st[stidx]=st[(2*stidx)+1]+st[(2*stidx)+2];
}
int main()
{
    int n=6;
    int arr[n]={1,3,6,0,10,7};
    
    int st[4*n];//maximum size
    memset(st,0,sizeof(st));
    buildst(arr,st,0,n-1,0);
    int ql,qr,index ,val;
    cout<<"enter a range  ";
    cin>>ql>>qr;
    cout<<range( ql,qr,0,n-1,0,st)<<"\n"; //range query
    cout<<"enter index and value for update ";
    cin>>index>>val;
    update(0,n-1,0,index,val,st); //updation query
    
   

    return 0;
}
