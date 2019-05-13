#include <string>
#include <array>

/**
* A class to create and use a Trie structure
*/
class Trie
{

public:
	struct Node;

	const static int ASCII_LEN = 128;
	struct Node{
		std::array<Node *, ASCII_LEN> str_arr;
		bool end;
		
	};

	Trie();
	~Trie();
	int AddString(std::string text);
	int DeleteString(std::string text);
	int FindExact(std::string text);
	int PrintAllStartingWith(std::string text);
	int CountAllStartingWith(std::string text);
	void PrintAll();

private:
	Node * GetBaseNode();
	Node * CreateNode();
	Node * InsertGetNextNode(Node*, char);
	void PrintDFS(Node *, std::string);
	int MarkEnd(Node*);	
	Node * FindCharNode(Node *, char);
	
	Node * m_base_node;

};
