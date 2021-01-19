/*
    原题链接：https://www.acwing.com/solution/content/705/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//我的写法
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        stack<int>t ;
        ListNode*p=head;
        while(p){
            t.push(p->val);
            p=p->next;
        }
        vector<int>ans;
        while(!t.empty()){
            ans.push_back(t.top());
            t.pop();
        }
        return ans;
    }
};

//acwing y总的写法
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};