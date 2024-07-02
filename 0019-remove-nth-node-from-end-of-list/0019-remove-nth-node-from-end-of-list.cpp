class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        ListNode* temp=head;int count=0,TargetPos;
       //calculating count
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        if(n>count) return head;
        //calculate TargetPos
        TargetPos=count-n;
        if(TargetPos==0){
            ListNode* newHead=head;
            head=head->next;
            delete newHead;
            return head;
        }
        temp=head;
        for(int i=0;i<TargetPos-1;i++){
            temp=temp->next;
        }
        //delete target Node
       ListNode* toDelete=temp->next;
       temp->next=temp->next->next;
       delete toDelete;
       return head;
    }
};