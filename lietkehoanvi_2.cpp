#include <iostream>
#include <vector>
using namespace std;

// Đệ quy để sinh hoán vị thoả mãn yêu cầu
void generatePermutations(vector<int>& nums, int start, int M) {
    if (start == nums.size() - 1) {
        // Kiểm tra nếu số M luôn đứng cuối trong hoán vị
        if (nums[nums.size() - 1] == M) {
            for (int num : nums) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, M);
        swap(nums[start], nums[i]);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nums;
    for (int i = 1; i <= N; i++) {
        nums.push_back(i);
    }
    generatePermutations(nums, 0, M);

    return 0;
}
