class ProductOfNumbers {
    public:
        vector<long long> vc={1};
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            if(num==0) vc={1};
            else vc.push_back(vc.back()*num);
        }
        
        int getProduct(int k) {
            int n=vc.size();
            if(n<k) return 0;
            n--;
            return vc[n]/vc[n-k];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */