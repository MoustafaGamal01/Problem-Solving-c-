class SmallestInfiniteSet {
public:
    // using Frequency array and set 
    /*
    int cnt = 0;
    bool arr[1001]={false};
    set<int>st;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!st.empty()){
            int a = *st.begin();
            st.erase(st.begin());
            arr[a] = true;
            return a;
        }
        ++cnt;
        arr[cnt] = true;
        return cnt;
    }
    
    void addBack(int num) {
        if(arr[num] == true) st.insert(num), arr[num] = false;

    }
    */
    // using Frequency array and Heap 
    int cnt = 0;
    bool arr[1001]={false};
    priority_queue<int, vector<int>, greater<>> q;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!q.empty()){
            int a = q.top();
            q.pop();
            arr[a] = true;
            return a;
        }
        ++cnt;
        arr[cnt] = true;
        return cnt;
    }
    
    void addBack(int num) {
        if(arr[num] == true) q.push(num), arr[num] = false;

    }

};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */