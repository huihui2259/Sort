// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

class Test
{
public:
	Test();
	~Test();
    int a[3][2] = { 0 };
    void Init(int(*a)[2]) {
        memcpy(this->a, a, sizeof(a));
    }
private:

};

Test::Test()
{
}

Test::~Test()
{
}

void test(int (*a)[2]) {
    cout << a[0][0] << endl;
}


void print(vector<int>& a) {
    for (int i = 0; i < a.size();i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}



void Quick(vector<int>& res, int left, int right) {
    //if (left < right) {
    if (left >= right) return;
        int temNum = res[left];
        int nl = left, nr = right;
        while (nl < nr) {
            while (nl < nr && res[nr] >= temNum) nr--;
            if (nl < nr) {
                res[nl] = res[nr];
                nl++;
            }
            while (nl < nr && res[nl] <= temNum) nl++;
            if (nl < nr) {
                res[nr] = res[nl];
                nr--;
            }
        }
        res[nl] = temNum;
        Quick(res, left, nl - 1);
        Quick(res, nl + 1, right);
    //}
}


void fun(vector<int>& data, int low, int high) {
    if (low >= high) return;
    int key = data[low], begin = low, end = high;
    while (begin < end) {
        while (begin<end && data[end]>key) end--;
        if (begin < end) data[begin++] = data[end];
        while (begin < end && data[begin] <= key) begin++;
        if (begin < end) data[end--] = data[begin];
    }
    data[begin] = key;
    fun(data, low, begin - 1);
    fun(data, begin + 1, high);
}


void merge(vector<int>& copy, vector<int>& num, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    int low1 = left, high1 = mid, low2 = mid + 1, high2 = right,index=left;
    merge(num, copy, low1, high1);
    merge(num, copy, low2, high2);
    while (low1 <= high1 && low2 <= high2) {
        copy[index++] = num[low1] < num[low2] ? num[low1++] : num[low2++];
    }
    while (low1 <= high1) copy[index++] = num[low1++];
    while (low2 <= high2) copy[index++] = num[low2++];
}
int main()
{
   /* int b[2][2] = { 1 };
    Test A;
    A.Init(b);
    cout << A.a[0][0] << endl;*/
    vector<int>a = { 2,3,6,5,4,8,7,1,9 };
    vector<int>b(a);
    merge(b, a, 0, a.size() - 1);
    //Quick(a, 0, a.size() - 1);
    //fun(a, 0, a.size() - 1);
    print(b);
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
