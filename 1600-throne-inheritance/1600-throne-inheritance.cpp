// ## Understand

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
        // I create child, storing it in the hash map and the children of its parent
        unique_ptr<Person> child = make_unique<Person>(move(childName));
        Person* child_ptr = child.get();
        family_tree[child_ptr->name] = move(child);
        
        family_tree[parentName]->children.push_back(child_ptr);
    }
    
    void death(string name) {
        // If the person exists, mark it as dead
        if (family_tree.count(name)) {
            family_tree[move(name)]->is_alive = false;
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