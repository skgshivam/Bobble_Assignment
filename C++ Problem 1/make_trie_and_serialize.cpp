#include<bits/stdc++.h>
#include<iostream>
#include <iostream>
#include<cstdio> 
#define MARKER ')' 
#define N 27 // 27 English Alphabets and 1 for ' ; 

using namespace std;

struct Node{
    string key;
    int value;
    bool isEnd;
    Node *child[N];
   
};

struct Node* getNode(void){
    struct Node *pNode = new Node;
    pNode->isEnd = false;
    pNode->value = -1;
    for(int i=0;i<N;i++){
        pNode->child[i] = NULL;
    }

    return pNode;
}

void insert(struct Node *root, vector<string> row) 
{ 
    struct Node *pCrawl = root; 
    string key = row[0];
    int val = stoi(row[1]);

    for (int i = 0; i < key.length(); i++) 
    { 
        int index;
        if(key[i]=='\'')
            index = 27;
        else    
            index = key[i] - 'a'; 
        if (!pCrawl->child[index]) 
            pCrawl->child[index] = getNode(); 
  
        pCrawl = pCrawl->child[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEnd = true; 
    pCrawl->value = val;
} 

void search(struct Node *root, string key) 
{ 
    struct Node *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index;
        if(key[i]=='\'')
            index = 27;
        else    
            index = key[i] - 'a'; 

        if (!pCrawl->child[index]) 
            {
                cout<<"No";
                return;
            } 
  
        pCrawl = pCrawl->child[index]; 
    } 
    if(pCrawl != NULL && pCrawl->isEnd){
        cout<<"YES, "<<pCrawl->value<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;
} 


int main(){


    struct Node *root = getNode(); 

    //Read CSV  
    ifstream fin("EnglishDictionary.csv", ios::in);

    vector<string> row; 
    string line, word; 

    int val;
    while(std::getline(fin, line))
    {
       
        std::stringstream ss(line);
        int colIdx = 0;

        row.clear();

        while (getline(ss, word, ',')) { 
  
           row.push_back(word);
        } 
        insert(root, row);

        
    }
    //Serialize the Trie
    string key1;
    while(1){
        cout<<"Enter the key you want to search (0 to exit) : ";
        cin>>key1;

        if(key1=="0")
            break;

        search(root, key1);    

    }
    return 0;
}