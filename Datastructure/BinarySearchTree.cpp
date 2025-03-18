#include <iostream>
using namespace std;

// 이진 탐색 트리의 노드 구조체
struct TreeNode 
{
    int key;// 노드의 값
    TreeNode* left;   // 왼쪽 자식을 가리키는 포인터
    TreeNode* right;  // 오른쪽 자식을 가리키는 포인터

    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

// BST 클래스 정의
class BST 
{
public:
    TreeNode* root;

    BST() { root = nullptr; }

    // 노드 삽입 함수
    TreeNode* insert(TreeNode* node, int key) 
    {
        if (node == nullptr) 
        {  // 빈 자리면 새로운 노드 삽입
            return new TreeNode(key);
        }

        if (key < node->key)
        {  // key가 작으면 왼쪽으로 이동
            node->left = insert(node->left, key);
        }
        else if (key > node->key) 
        {  // key가 크면 오른쪽으로 이동
            node->right = insert(node->right, key);
        }

        return node;  // 부모 노드 반환 (트리 갱신)
    }

    void insert(int key) 
    {
        root = insert(root, key);
    }

    // 중위 순회 (오름차순 정렬 출력)
    void inorder(TreeNode* node) 
    {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void printSorted()
    {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(7);

    cout << "Sorted Tree: ";
    tree.printSorted();  // 정렬된 순서로 출력

    return 0;
}
