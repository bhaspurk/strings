#include "Trie.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Trie::Trie()
:m_base_node(NULL)
{

}

Trie::~Trie()
{

}


int Trie::AddString(std::string text)
{
	//get base node ptr
	Node *node = GetBaseNode();
	if(!node)
		return -1;

	for(auto c: text)
	{
		node = InsertGetNextNode(node, c);
		if(!node)
			return -1;
	
	}		
	//mark the end flag for the last node
	MarkEnd(node);
	return 0;
}

//Returns the base node ptr
Trie::Node* Trie::GetBaseNode()
{
	if(m_base_node)
		return m_base_node;
	else
	{
		Node *tmp = CreateNode();
		m_base_node = tmp;
		return m_base_node;
	}
	return NULL;
				
}

//Create new Node
Trie::Node * Trie::CreateNode()
{
	Node *tmp = new Node();
	if(!tmp)
		cout<<"Error: Could not create Node"<<endl;

	return tmp;
}


//Adds a pointer at the location of the char, if one doesnt exist.
Trie::Node *Trie::InsertGetNextNode(Node *node, char c)
{
	if(node)
	{	
		if(node->str_arr[c])
			return node->str_arr[c];
		else
		{
			Node *tmp = CreateNode();
			node->str_arr[c] = tmp;
			return tmp;
		}
	}

	return NULL;
}


//Mark the end flag for node
int Trie::MarkEnd(Node *node)
{
	if(node)
	{
		node->end = true;
		return 0;
	}

	return -1;
}

int Trie::DeleteString(std::string text)
{
	return 0;
}


int Trie::FindExact(std::string text)
{
	return 0;
}


//Print all the text strings stored
void Trie::PrintAll()
{
	Node *tmp = GetBaseNode();
	string str = "";
	PrintDFS(tmp, str);		
}

//DFS for nodes	
void Trie::PrintDFS(Node * node, string str)
{
	if(!node)
		return;

	if(node->end)
		cout<<str<<endl;

	for(int i=0; i< ASCII_LEN; i++)
	{	
		Node *ptr = node->str_arr[i];
		if(ptr)
		{
			string app_str(str);
			PrintDFS(ptr, app_str.append(1,i));
		}
	}	
}

int Trie::PrintAllStartingWith(std::string text)
{
	//get base
	Node *node = GetBaseNode();
	if(!node)
		return -1;

	Node *tmp = NULL;
	for(auto c: text)
	{
		tmp = FindCharNode(node, c);
		if(!tmp)
			return -1;
		node = tmp;
	}

	//If all characters were found, then do the PrintAll
	//but start from the spot till where we traversed already.
	PrintDFS(tmp, text);

	return 0;
}


//Find the Node if the char has been stored already
Trie::Node * Trie::FindCharNode(Node *node, char c)
{
	if(node)
	{
		if(node->str_arr[c])
			return node->str_arr[c];
	}

	return NULL;
}

int Trie::CountAllStartingWith(std::string text)
{
	return 0;
}


int main()
{

	Trie t;
	t.AddString("Hero");
	t.AddString("Heroine");
	t.AddString("NPD");
	t.AddString("NPD-iHub");
	t.AddString("NPD-Remote");
	t.AddString("NPD-Rx");

	//t.PrintAll();
	t.PrintAllStartingWith("NPD-R");

	return 0;
}
