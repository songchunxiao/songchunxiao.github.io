#define MAXN 10000
struct segtree{
    int n,cnt[MAXN],len[MAXN];
    segtree(int t):n(t){
        for (int i=1;i<=t;i++)
            cnt[i]=len[i]=0;
    };
    void update(int t,int l,int r);
    void inc_seg(int t,int l0,int r0,int l,int r);
    void dec_seg(int t,int l0,int r0,int l,int r);
    int seg_len(int t,int l0,int r0,int l,int r);
};

void segtree::update(int t,int l,int r){
    if (cnt[t]||r-l==1)
        len[t]=length(l,r);
    else
        len[t]=len[t+t]+len[t+t+1];
}

void segtree::inc_seg(int t,int l0,int r0,int l,int r){
    if (l0==l && r0==r)
        cnt[t]++;
    else{
        int m0 = (l0+r0)>>1;
        if (l<m0)
            inc_seg(t+t, l0, m0, l, m0<r?m0:r);
        if (r>m0)
            inc_seg(t+t+1,m0,r0,m0>l?m0:l,r);
        if (cnt[t+t]&&cnt[t+t+1]){
            cnt[t+t]--;
            update(t+t,l0,m0);
            cnt[t+t+1]--;
            update(t+t+1,m0,r0);
            cnt[t]++;
        }
    }
    update(t,l0,r0);
}
