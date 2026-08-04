class PrefixTree {
public:

    struct Node{
        char ch;
        bool terminal;
        unordered_map<char,Node*> ref;

        Node(char c){
            ch = c;
            terminal = false;
        }

        void maketerminal(){
            terminal = true;
        }

        bool isterminal(){
            if(terminal == true) return true;
            return false;
        }
    };

    Node* root;

    PrefixTree() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* curr = root;

        for(int i=0; i<word.size(); i++){
            char ch = word[i];

            if(curr->ref.find(ch) == curr->ref.end()){
                Node* node = new Node(ch);
                curr->ref[ch] = node;
                curr = curr->ref[ch];
            }
            else{
                curr = curr->ref[ch];
            }
        }
        curr->maketerminal();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(curr->ref.find(ch) != curr->ref.end()){
                curr = curr->ref[ch];
            }
            else return false;
        }
        if(curr->isterminal() == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(curr->ref.find(ch) != curr->ref.end()){
                curr = curr->ref[ch];
            }
            else return false;
        }
        return true;
    }
};
