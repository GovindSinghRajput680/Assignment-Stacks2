#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};
//Q 1->LEETCODE-> 20
bool isValid(string s) {
        stack<char> st;
        for(char i :s){
            if(i == '(' || i == '{' || i == '[') st.push(i);
            else{
                if(i == ')'){
                    if( st.size() && st.top() == '(') st.pop();
                    else return false;
                }
                else if(i == ']'){
                    if( st.size() && st.top() == '[') st.pop();
                    else return false;
                }
                else{
                    if( st.size() && st.top() == '{') st.pop();
                    else return false;
                }
            }
           
        }
        
        return (!st.size());
    }
//Q-2 ->LEETCODE-> 1019
ListNode* reverseList(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *pre = NULL,*curr = head,*Next;
        while(curr){
            Next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = Next;
        }
        return pre;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        stack<int> st;
        ListNode *temp = reverseList(head);
        while(temp){
            while(st.size() && temp->val>=st.top()) st.pop();
            if(st.size()) v.push_back(st.top());
            else v.push_back(0);
            st.push(temp->val);
            temp = temp->next;
        }
        reverse(v.begin(),v.end());
        return v;
    }
    //Q 3->LEETCODE->1475
     vector<int> finalPrices(vector<int>& v) {
        vector<int> ans(v.size());
        stack<int> st;
        for(int i =v.size()-1;i>=0;i--){
            while(st.size() && st.top()>v[i]) st.pop();
            if(st.size())ans[i] = v[i]-st.top();
            else ans[i] = v[i];
            st.push(v[i]);
        }
    return ans;
    }
    //Q-4->LEETCODE->503
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
       vector<int> temp;
       for(int i =0;i<n;i++) temp.push_back(nums[i]);
       for(int i =0;i<n;i++) temp.push_back(nums[i]);
       vector<int> NGI(temp.size(),-1) ;
       for(int i =2*n-1;i>=0;i--){
           while(st.size() && st.top()<=temp[i]) st.pop();
           if(st.size()) NGI[i] = st.top();
           st.push(temp[i]);
           //temp.pop_back();
       }
       vector<int> ans(n);
    for(int i = 2*n-1;i>=n;i--){
        if(NGI[i] == -1) ans[i-n] = NGI[i-n];
        else ans[i-n] = NGI[i];
    }
     return ans;  
    }
int main(){


}