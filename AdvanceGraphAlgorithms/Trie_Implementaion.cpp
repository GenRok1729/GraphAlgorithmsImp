struct TrieNode{
  char val;
  int count; //Length of word
  int endsHere; //To indicate the ending of a string
  TrieNode *child[26];
};

    Trienode *root; // Declared the root of the trie :)
    
Trienode *getNode(int index)
{
    Trienode *newnode = new Trienode; //allocationg a new trie node as new node 
    newnode->val = 'a'+index; // to taken value 
    newnode->count = newnode->endsHere = 0; //to 0
    for(int i = 0;i<26;i++)
    {
        newnode->child[i] = NULL;  //pointer to null 
    }
      return newnode;
}

Trie() {
    root = getNode('/' - 'a');
}

/** Inserts a word into the trie. */
void insert(string word) {

  //The first thhing you have to do is point to root value thus create a temperory curr node 

  Trienode *curr = root;
  int preIndex;
  for(int i = 0;word[i] != '\0';i++)//Check all adjacent to it 
  {
      preIndex = word[i] - 'a';
      if(curr->child[preIndex] == NULL)//if its null ok then crete nodethere
      {
          curr->child[preIndex] = getNode(preIndex);
      }
      curr->child[preIndex]->count++;//increment length of word by 1
      curr = curr->child[preIndex];//Now we have to follow from here for the remaining things..
  }
  curr->endsHere++; 
}
    
/** Returns if the word is in the trie. */
bool search(string word) {

    Trienode *curr = root;
    int preIndex;
    for(int i = 0;word[i] != '\0';i++)//Check all adjacent to it 
    {
        preIndex = word[i] - 'a';
        if(curr->child[preIndex] == NULL)//if its null ok then crete node th
        {
            return false;
        }
        curr = curr->child[preIndex];//Now we have to follow from here for the remaining things..
    }
    return (curr->endsHere > 0);  
}


/** Returns if there is any word in the trie that starts with the given prefix. */
bool startsWith(string prefix) {

    Trienode *curr = root;
    int preIndex;
    for(int i = 0;prefix[i] != '\0';i++)//Check all adjacent to it 
    {
        preIndex = prefix[i] - 'a';
        if(curr->child[preIndex] == NULL)//if its null ok then crete node th
        {
            return false;
        }
        curr = curr->child[preIndex];//Now we have to follow from here for the remaining things..
    }
    return (curr->count > 0); 
}

//https://leetcode.com/problems/implement-trie-prefix-tree/
