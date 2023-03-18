#include <iostream>
using namespace std;

class TrieNode{
public:
    char word;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char word)
    {
        this->word=word;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
public:
    TrieNode* root;

    Trie()
    {
        root=new TrieNode('\0');
    }

    void insertWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));
    }
    void insert(string word)
    {
        insertWord(root,word);
    }
    bool searchWord(TrieNode *root,string word)
    {

        if(word.size()==0)
        {
            return root->isTerminal;
        }

        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchWord(child,word.substr(1));
    }

    bool search(string word)
    {
        if(word.size()==0)
        {

            return false;
        }
        return searchWord(root,word);
    }

    void removeWord(TrieNode*root,string word)
    {
        //base case
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }
        //small calculation
        TrieNode * child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            //word not found
            return ;
        }
        removeWord(child,word.substr(1));
        //remove childNode it is useless
        if(child->isTerminal==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                {
                    return ;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void removeWord(string word)
    {
        removeWord(root,word);
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
    t->removeWord("and");



}

