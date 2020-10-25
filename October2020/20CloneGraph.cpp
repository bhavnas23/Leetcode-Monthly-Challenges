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
    
    Node* traverse(Node *node, map<Node*, Node*> &mp){
        vector<Node*> neighbors;
        Node* newN = new Node(node->val);
        mp[node] = newN;
        for(int i=0; i<node->neighbors.size(); ++i){
            if(mp.find(node->neighbors[i])==mp.end()){
                
                neighbors.push_back(traverse(node->neighbors[i], mp));
            }
            else{
                neighbors.push_back(mp[node->neighbors[i]]);
            }
        }
        
        newN->neighbors = neighbors;
        return newN;
    }
    
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        map<Node*, Node*> mp;
        Node* newG = traverse(node, mp);
        return newG;
    }
};
