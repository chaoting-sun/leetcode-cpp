// ## Understand

// I need to check some constraints:
// 1. what is the range of number of calls to birth and death?
//  - birth + death -> 10^5
//  - getInheritanceOrder -> 10
// 2. what is the max length of name?
//  - 1 <= name.length <= 15
// 3. will there be invalid inputs for birth? for example, parentName == childName
// 4. will there be invalid inputs for deadth? for example, name does not appear
//  - No. All name arguments of death will be passed to either the constructor or as childName to birth first.

// Some questions not asked
// does name consist of lowercase English letters only?
//  - yes


// ## Match

// The problem needs us to track the relationship of parent and child, and older and younger siblings.
// As the order of consideration is parent to child, then older to younger siblings, I can map this
// problem as a DFS problem.


// ## Plan

// I will build a tree, in which every node includes name, a vector that stores the address of children
// nodes in the order of birthday, and a variable is_alive to represent if this person is still alive.
// Also, I use a map, name to node address to get the node in O(1).
// when birth function is called, I use the map to locate the node, create a child node for it, and push
// the child address to the vector.
// when death function is called, I use the map to locate the node, and mark it as is_alive = false


// ## Pre-Evaluation

// Time: 10^5 * O(1) + 10 * O(10^5) * O(15) = O(10^7)
//  birth: O(1)
//  death: O(1)
//  getInheritanceOrder: the complexity will be related to output size, including the length of name and number of people alive
// Space: O(15 * 10^5) = O(10^6)
//  the length of name * the number of people


// ## Implementation

struct Node {
    string name;
    vector<Node*> children;
    bool is_alive;
    Node(string name) {
        this->name = name;
        this->is_alive = true;
    }
};

class ThroneInheritance {
private:
    Node* root;
    unordered_map<string, Node*> name_to_node;

    void buildInheritance(const Node* node, vector<string>& inheritance) {
        if (node->is_alive) {
            inheritance.push_back(node->name);
        }
        for (const Node* child: node->children) {
            buildInheritance(child, inheritance);
        }
    }

public:
    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        name_to_node[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node* parent_node = name_to_node[parentName];

        Node* child_node = new Node(childName);
        name_to_node[childName] = child_node;
        parent_node->children.push_back(child_node);
    }
    
    void death(string name) {
        Node* node = name_to_node[name];
        node->is_alive = false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> inheritance;
        buildInheritance(root, inheritance);
        return inheritance;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */


// ## Review

// test case:
// ThroneInheritance(john)
// getInheritanceOrder()
// trace:
// create node(john) -> name_to_node[john] = node(john, is_alive=true)
// > getInheritanceOrder()
//  buildInheritance(root)
//  inheritence = [john]
//  < returns [john]

// test case:
// ThroneInheritance(john)
// birth(john, bob)
// birth(john, alex)
// death(john)
// getInheritanceOrder()
// trace:
// create node(john) -> name_to_node[john] = node(john, is_alive=true)
// > birth(john, bob)
//  parent_node = node(john, is_alive=true)
//  child_node = node(bob, is_alive=true)
//  name_to_node[bob] = node(bob, is_alive=true)
//  node(john, is_alive=true, children=[node(bob, is_alive=true)])
// > birth(john, alex)
//  parent_node = node(john, is_alive=true)
//  child_node = node(alex, is_alive=true)
//  name_to_node[alex] = node(alex, is_alive=true)
//  node(john, is_alive=true, children=[node(bob, is_alive=true), node(alex, is_alive=true)])
// > death(john)
//  node(john, is_alive=true) = name_to_node[john]
//  -> node(john, is_alive=false)
// > getInheritanceOrder(node(john, is_alive=false))
//  child = node(bob, is_alive=true)
//  inheritance = [bob]
//  child = node(alex, is_alive=true)
//  inheritance = [bob, alex]


// ## Evaluation

// The same as pre-evaluation


// Submit Error

// CE: cannot initialize a parameter of type 'Node *' with an lvalue of type 'const Node *'

// void buildInheritance(Node* node, vector<string>& inheritance) {
//     if (node->is_alive) {
//         inheritance.push_back(node->name);
//     }
//     for (const Node* child: node->children) {
//         buildInheritance(child, inheritance);
//     }
// }

// to

// void buildInheritance(const Node* node, vector<string>& inheritance) {
//     if (node->is_alive) {
//         inheritance.push_back(node->name);
//     }
//     for (const Node* child: node->children) {
//         buildInheritance(child, inheritance);
//     }
// }