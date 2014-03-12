struct sumSeg{
    elem_t a[MAXN],c[MAXN],ret;
    int n;
    void init(int i){
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        n=i;
    }
    void update(int i,elem_t v){
        for (v-=a[i],a[i]+=v;
                i<=n;
                c[i-1]+=v,i+=lowbit(i));}
    elem_t query(int i){
        for (ret=0;
                i;
                ret+=c[i-1],i^=lowbit(i));
        return ret;
    }
};
