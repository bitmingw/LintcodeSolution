#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        if (colors.size() < 2) return;
        int base_ptr = 0;
        int search_ptr = 0;
        int search_color = 1;
        while (search_color < k) {
            while (colors[base_ptr] == search_color) {
                base_ptr += 1;
            }
            search_ptr = base_ptr + 1;
            while (search_ptr < colors.size()) {
                if (colors[search_ptr] == search_color) {
                    swap(colors, base_ptr, search_ptr);
                    base_ptr += 1;
                }
                search_ptr += 1;
            }
            search_color += 1;
        }
        return;
    }

    void swap(vector<int>& colors, int ptr1, int ptr2) {
        int tmp = colors[ptr1];
        colors[ptr1] = colors[ptr2];
        colors[ptr2] = tmp;
    }
};

int main() {
    Solution s;
    return 0;
}
