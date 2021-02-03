    
class Node {
    private:
        int pos;
        int val;
        bool valid;
    public:
        Node(int p, int v) {
            this->pos = p;
            this->val = v;
            this->valid = true;
        } 
    
        void invalid(){
            valid = false;
        }
    
        bool isValid() {
            return valid;
        }
    
        int value() {
            return val;
        }
    };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        auto comp = []( Node* a, Node* b ) { return a->value() < b->value(); };
        priority_queue<Node*, vector<Node*>, decltype(comp)> q(comp); 
        map<int, Node*> ptrMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            if (i >= k) {

                while(!q.empty() && !q.top()->isValid())
                    q.pop();
                
                int top = q.top()->value();
                ans.push_back(top);
                //invalidate earlier element
                ptrMap[i - k]->invalid();
            }
            
            //add new element 
            Node *node = new Node(i, nums[i]);
            q.push(node);
            ptrMap[i] = node;
        }
        
        while(!q.empty() && !q.top()->isValid())
                    q.pop();
        
        if (!q.empty())
            ans.push_back(q.top()->value());
        
        return ans;
    }

};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);