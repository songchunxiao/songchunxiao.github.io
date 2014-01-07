struct node{
    int ow;
    double val;
    node(const int& o, const double& v){
        ow = o;
        val = v;
    }
    bool operator<(const node &b)const{
        return this->val > b.val;
    }
};

    vector<node> buy;
    buy.push_back(node(i,val[i]));
    sort(buy.begin(),buy.end());
