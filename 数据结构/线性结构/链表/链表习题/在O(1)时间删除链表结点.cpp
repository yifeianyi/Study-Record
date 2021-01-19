//原题链接：https://www.acwing.com/problem/content/description/85/
/**
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*t=node->next;
        node->val=t->val;
        node->next = t->next;
        delete t;
    }
};

/*
    分析：
        这题绕了一点点弯。
        由于是单链表，我们没办法找到待删结点的前驱，
        所以利用找到待删结点前驱，去连接待删结点的后驱的思路行不通。
        但我们可以把待删结点的后驱的数据copy到当前节点，然后删掉后驱等效的完成这一操作。
*/