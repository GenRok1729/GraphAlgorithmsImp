class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct trie{
        bool end;
        int mp[26];
        trie()
        {
            end=false;
            memset(mp,-1,sizeof(mp));
        }
    };
    vector<trie> tree;
    void insert(string s)
    {
        int pos=0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[pos].mp[s[i]-'a']==-1)
            {
                tree[pos].mp[s[i]-'a']=tree.size();
                tree.push_back(trie());
            }
            pos=tree[pos].mp[s[i]-'a'];
        }
        tree[pos].end=true;
        return ;
    }
    bool find(string s)
    {
        int pos=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[pos].mp[s[i]-'a']==-1)
            {
                return false;
            }
            pos=tree[pos].mp[s[i]-'a'];
        }
        
        return tree[pos].end==true;
    }
    MagicDictionary()
    {
        trie root=trie();
        tree.push_back(root);
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word:dictionary)
            insert(word);
    }
    
    bool search(string word) {
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            for(char p='a';p<='z';p++)
            {
                if(p!=ch)
                {
                    word[i]=p;
                    if(find(word))
                        return true;
                }
            }
            word[i]=ch;
        }
        return false;
        
    }
};

//https://leetcode.com/problems/implement-magic-dictionary/
