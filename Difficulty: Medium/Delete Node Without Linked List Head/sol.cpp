class Solution {
  public:
    void deleteNode(Node* x) {
       Node* temp=x->next;
       x->data=temp->data;
       x->next=temp->next;
       delete(temp);
    }
};

/*
 [10]->[20]->[30]->[40]->[50]   delete 30;
 step 1 : [10]->[20]->[40]->[40]->[50]
 step 2 :  [10]->[20]->[40]->---->[50]
                            [40] this is del_node->next;
*/
