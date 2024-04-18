#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

void encode(Node* root, std::string str, std::unordered_map<char, std::string> &huffmanCode)
{
    if (root == nullptr)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int &index, std::string str)
{
    if (root == nullptr)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        std::cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
    {
        decode(root->left, index, str);
    }
    else
    {
        decode(root->right, index, str);
    }
}

void buildHuffmanTree(std::string text)
{
    std::unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }

    std::priority_queue<Node*, std::vector<Node*>, comp> pq;

    std::cout << "Characters frequencies are :\n" << '\n';
    for (auto pair : freq)
    {
        std::cout << pair.first << " " << pair.second << '\n';
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node* root = pq.top();

    std::unordered_map<char, std::string> huffnamCode;
    encode(root, "", huffnamCode);

    std::cout << "Huffman Code are :\n" << '\n';
    for (auto pair : huffnamCode)
    {
        std::cout << pair.first << " " << pair.second << '\n';
    }

    std::string str = "";
    for (char ch : text)
    {
        str += huffnamCode[ch];
    }

    std::cout << "\nEncoded string is :\n" << str << '\n';

    int index = -1;
    std::cout << "\nDecoded string is: \n";
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}

int main()
{
    std::ifstream file("C:\\CLionProjects\\new1\\text.txt"); // enter text file path
    std::string str;
    std::getline(file, str);
    //std::cout << str;

    buildHuffmanTree(str);
    return 0;
}
