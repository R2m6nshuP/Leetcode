class StockSpanner {
public:
    stack<pair<int,int>> st;
    int prev=-1;
    int cnt=0; 
    StockSpanner() {
       
    }
    
    int next(int price) {
        while(!st.empty() && price>=st.top().second){
            st.pop();
        }
        if(st.empty()) prev=-1;
        else prev=st.top().first;
        st.push({cnt,price});
        cnt++;
        return (cnt-1-prev);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = objnext(price);
 */