#include <iostream>
using namespace std;

class TrieNode{
public:
    char word; // the character contained in the trie node
    TrieNode **children; // an array of pointers to the children of this trie node
    bool isTerminal; // a boolean indicating whether the trie node marks the end of a word

    // constructor for TrieNode
    TrieNode(char word)
    {
        this->word=word;
        children=new TrieNode*[26]; // creating an array of pointers to hold 26 (a-z) child nodes
        for(int i=0;i<26;i++)
        {
            children[i]=NULL; // initially, all child pointers are set to NULL
        }
        isTerminal=false; // initially, isTerminal is set to false as the trie node doesn't mark the end of any word
    }
};

class Trie{
public:
    TrieNode* root; // a pointer to the root node of the trie

    // constructor for Trie
    Trie()
    {
        root=new TrieNode('\0'); // creating a root node with character '\0'
    }

    // helper function to insert a word into the trie
    void insertWord(TrieNode *root,string word)
    {
        // if the word is empty, mark the root node as terminal
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        // find the index of the first character in the word
        int index=word[0]-'a';

        // create a TrieNode child variable to store the address of the child node
        TrieNode* child;

        // check if the children array of that index (first character of word) is filled or null
        if(root->children[index]!=NULL)
        {
            // if not null, contain that address into child and call recursion over that child to check or insert the next character
            child=root->children[index];
        }
        else{
            // if null, add that child by creating a TrieNode and passing the first character, and then connect it to that index of the children array
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        // recursively call insertWord on the next substring of the word
        insertWord(child,word.substr(1));
    }

    // function to insert a word into the trie
    void insert(string word)
    {
        insertWord(root,word);
    }

    // function to search for a word in the trie
    bool searchWord(TrieNode *root,string word)
    {
        // if the word is empty, return the value of isTerminal for the current trie node
        if(word.size()==0)
        {
            return root->isTerminal;
        }

        // find the index of the first character in the word
        int index=word[0]-'a';
        TrieNode *child;

        // check if the children array of that index (first character of word) is filled or null
        if(root->children[index]!=NULL)
        {
            // if not null, contain that address into child
            child=root->children[index];
        }
        else{
            // if null, the word is not found in the trie
            return false;
        }

        // recursively call searchWord on the next substring of the word
        return searchWord(child,word.substr(1));
    }

    // function to search for a word in the trie
    bool search(string word)
    {
        if(word.size()==0)
        {
            return false;
        }
        return searchWord(root,word);
    }


    // Function to remove a word from the Trie data structure
void removeWord(TrieNode* root, string word)
{
    // Base case: if the word is empty, mark the last node as non-terminal
    if (word.size() == 0)
    {
        root->isTerminal = false;
        return;
    }

    // Small calculation: find the child node corresponding to the first character of the word
    TrieNode* child;
    int index = word[0] - 'a';
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // The word is not found in the Trie
        return;
    }

    // Recursively remove the word from the child node
    removeWord(child, word.substr(1));

    // Remove the child node if it is useless (i.e., non-terminal and has no children)
    if (child->isTerminal == false)
    {
        for (int i = 0; i < 26; i++)
        {
            if (child->children[i] != NULL)
            {
                return;
            }
        }
        delete child;
        root->children[index] = NULL;
    }
}

// Wrapper function to remove a word from the Trie data structure
    void removeWord(string word)
    {
        removeWord(root, word);
    }


};

int main()
{
    Trie *t=new Trie();
    t->insert("and");
    t->insert("are");
    t->insert("dot");
    if(t->search("and"))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }




}

