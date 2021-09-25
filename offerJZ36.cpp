//输入两个链表，找出它们的第一个公共结点。
//（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *ta = pHead1, *tb = pHead2;
        while (ta != tb) {
            ta = ta ? ta->next : pHead2;
            tb = tb ? tb->next : pHead1;
        }
        return ta;
    }
};
