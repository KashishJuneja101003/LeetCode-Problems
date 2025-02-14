class ProductOfNumbers {
    vector<int> product;
public:
    ProductOfNumbers() {
        product.push_back(1); // Initialize with 1 for easier multiplication.
    }
    
    void add(int num) {
        if (num == 0) {
            product.clear();
            product.push_back(1); // Reset prefix product on zero
        } else {
            product.push_back(product.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= product.size()) {
            return 0; // If k exceeds available numbers, return 0
        }
        return product.back() / product[product.size() - 1 - k];
    }
};
