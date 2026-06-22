class WordDictionary {
public:
    WordDictionary* children[26];
    bool isCompleteWord;

    WordDictionary() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        isCompleteWord = false;
    }
    
    void addWord(string word) {
        WordDictionary* cur = this;

        for(char c : word){
            int idx = c - 'a';

            if(!cur -> children[idx]) cur -> children[idx] = new WordDictionary();

            cur = cur -> children[idx];
        }

        cur -> isCompleteWord = true;
    }
    
    bool search(string word) {
        if(word.length() == 0) return false;
        return searchHelper(this, word, 0);
    }

    bool searchHelper(WordDictionary* cur, string& word, int i){
        if(i == word.length()){
            return cur -> isCompleteWord;
        }

        if(word[i] == '.'){
            bool ret = false;
            for(auto next : cur -> children){
                if(next != nullptr) ret = ret | searchHelper(next, word, i + 1);
            }
            return ret;
        } else {
            int idx = word[i] - 'a';
            if(!cur -> children[idx]) return false;
            return searchHelper(cur -> children[idx], word, i + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */