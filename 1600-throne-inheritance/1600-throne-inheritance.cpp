// ## Understand

// the max length of name? -> 15
// the number calls for each method? -> birth+dead: 10^5, getInheritanceOrder: 10


// ## Match

// I will map the family inheritance problem to a preorder traversal on an N-ary tree, in which each node
// represent a person in this family.
// for the birth call, I add the new child under the existing parent node; for the death call, I mark the
// node as death

// ## Plan
// I will create a custom node representing a person, including the property name, existing children, and if
// the person is alive.
// Also, as the birth and death call can be up to 10^5 times, I will use a hashmap to record the address of
// node from the person's name, so that each birth and death call can be in constant time.

// In worst case, the king has about 10^5 children. The memory of all nodes will take:
// name: 15 * 10^5 bytes
// children: 8 * 10^5 bytes
// is_alive: 1 * 10^5 bytes
// totally: 24 * 10^5 bytes ~ 10^6 bytes = 1MB. it is acceptable.


class ThroneInheritance {
private:
    // a person's property includes name, his children, and if he's alive
    struct Person {
        string name;
        vector<Person*> children;
        bool is_alive = true;
        Person(string name) : name(move(name)) {}
    };

    // I use the hash map to quickly jump to the node
    // here I use smart pointer to manage the owership in the hash map
    unordered_map<string, unique_ptr<Person>> family_tree;
    // The root of the tree for the king
    Person* king;

    void dfs(Person* curr, vector<string>& inheritance_order) {
        if (curr->is_alive) {
            inheritance_order.push_back(curr->name);
        }
        for (Person* child: curr->children) {
            dfs(child, inheritance_order);
        }
    }

public:
    ThroneInheritance(string kingName) {
        unique_ptr<Person> new_king = make_unique<Person>(move(kingName));
        king = new_king.get();
        family_tree[king->name] = move(new_king);
    }
    
    void birth(string parentName, string childName) {
        // check the existence of the parent
        auto it = family_tree.find(parentName);
        if (it == family_tree.end()) {
            return;
        }

        // I create child, storing it in the hash map and the children of its parent
        unique_ptr<Person> child = make_unique<Person>(move(childName));
        Person* child_ptr = child.get();
        family_tree[child_ptr->name] = move(child);
        
        it->second->children.push_back(child_ptr);
    }
    
    void death(string name) {
        // If the person exists, mark it as dead
        auto it = family_tree.find(name);
        if (it != family_tree.end()) {
            it->second->is_alive = false;
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> inheritance_order;
        // Run a preorder traversal
        dfs(king, inheritance_order);
        return inheritance_order;
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
// happy case:
// ThroneInheritance('a') -> birth('a', 'b') -> death('b') -> getInheritanceOrder()
// trace:
// > ThroneInheritance('a')
//  create node, person[a] = node(a, is alive), save in king
// > birth('a', 'b')
//  create node, person['b'] = node(b, is alive), node(a, is alive)->children = [node(b, is alive)]
// > death('b')
//  b exists -> person['b'] = node(b, dead)
// > getInheritanceOrder()
//  dfs(node(a, is alive)) -> inheritance_order = [a]
//  children: node(b, dead)
//  dfs(node(b, dead)) -> dead
//  return [a]

// base case:
// ThroneInheritance('a') -> getInheritanceOrder()
// trace:
// > ThroneInheritance('a')
//  create node, person[a] = node(a, is alive), save in king
// > getInheritanceOrder()
//  dfs(node(a, is alive)) -> inheritance_order = [a]
//  children: none
// < return [a]

// trap path:
// ThroneInheritance('a') -> birth('a', 'b') -> birth('a', 'c') -> death('a') -> getInheritanceOrder()
// trace:
// > ThroneInheritance('a')
//  create node, person[a] = node(a, is alive), save in king
// > birth('a', 'b')
//  create node, person['b'] = node(b, is alive), node(a, is alive)->children = [node(b, is alive)]
// > birth('a', 'c')
//  create node, person['c'] = node(c, is alive), node(a, is alive)->children = [node(b, is alive), node(c, is alive)]
// > death('a')
//  a exists -> node(a, dead)
// > getInheritanceOrder()
//  dfs(node(a, dead)) -> dead
//  children: node(b, is alive), node(c, is alive)
//      dfs(node(b, is alive)) -> inheritance_order = [b]
//          children: none
//      dfs(node(c, is alive)) -> inheritance_order = [b, c]
///         children: none
//  < return [b, c]


// Evaluation:

// Time:
//  birth() and death() take O(name.length) -> O(name.length * 10^5) = O(15 * 10^5) = O(10^6)
//  getInheritanceOrder() -> O((# birth call) * 10 * name.length) = O(10^5 * 10 * 15) = O(10^7)
// Space:
//  O(name.length * (# birth call)) = O(15 * 10^5) = O(10^6)