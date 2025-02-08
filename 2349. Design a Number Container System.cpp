class NumberContainers {
    unordered_map<int, int> index_number;
    unordered_map<int, set<int>> number_indices;
    
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        // If the index is already in use
        if(index_number.find(index) != index_number.end()){
            number_indices[index_number[index]].erase(index);

            // If no indices are present for a number, remove it from the set
            if(number_indices[index_number[index]].size() == 0){
                number_indices.erase(index_number[index]);
            }
        }

        // Insert new number
        index_number[index] = number;
        number_indices[number].insert(index);
    }
    
    int find(int number) {
        // If number is found in the hashmap number_indices, return smallest index
        if(number_indices.find(number) != number_indices.end()){
            return *(number_indices[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
