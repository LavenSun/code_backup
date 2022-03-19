//1.初始化：用指针i指向pushV的第一个位置， 指针j指向popV的第一个位置
//2.如果pushV[i] != popV[j]， 那么应该将pushV[i]放入栈中， ++i
//3.否则，pushV[i]==popV[j], 说明这个元素是放入栈中立马弹出，所以，++i, ++j，然后应该检查popV[j]
//与栈顶元素是否相等，如果相等，++j, 并且弹出栈顶元素
//4，重复2，3， 如果i==pushV.size(), 说明入栈序列访问完，此时检查栈是否为空，如果为空，说明匹配，否则不匹配。
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushV.size()) {
            if (pushV[i] != popV[j]) {
                st.push(pushV[i++]);
            }
            else {
                ++i, ++j;
                while (!st.empty() && st.top() == popV[j]) {
                    st.pop();
                    ++j;
                }
            }
        } // end outer while

        return st.empty();
    }
};