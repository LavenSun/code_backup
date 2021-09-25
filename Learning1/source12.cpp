#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool myCompare(int i, int j)
{
	return i < j;
}
class Cmp
{
public: 
	bool operator()(int i, int j)
	{
		return i < j;
	}
};
int main()
{
	int arr[5] = { 45, 7, 12, 99, 36 };
	vector<int> nums(arr, arr + 5);
	//sort(nums.begin(), nums.end(), myCompare);
	//sort(nums.begin(), nums.end(), Cmp());
	sort(nums.begin(), nums.end(), [=](int i, int j) {return i > j; }); //·Âº¯Êı
	//sort(nums.begin(), nums.end());
	//reverse(nums.begin(), nums.end());
	for (int k = 0; k < nums.size(); k++)
		cout << nums[k] << endl;
	//[&](){
	//cout << "hello" << endl;
    //};
	//[&](){
	//cout << "hello" << endl;
	//}();
	return 0;
}
#endif