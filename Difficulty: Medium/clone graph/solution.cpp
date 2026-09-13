/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        Node* newnode = new Node(node->val);

        unordered_map<Node*,Node*>created_node;
        created_node[node]=newnode;

        queue<Node*>q;
        q.push(node);

        while(!q.empty()){
            Node * original = q.front();
            q.pop();

            for(auto &neighbor :original->neighbors){
                if(created_node.find(neighbor)!=created_node.end()){
                   created_node[original]->neighbors.push_back(created_node[neighbor]);
                }else{
                    Node* newneighbor = new Node(neighbor->val);
                    created_node[neighbor] = newneighbor;
                    
                    // Link it to the current clone
                    created_node[original]->neighbors.push_back(newneighbor);
                    
                    // Push original neighbor to queue to explore its neighbors later
                    q.push(neighbor);

                    
                }
            }
        }
        return newnode;
    }
};
