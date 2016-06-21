//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <atomic>
#include <algorithm>

using namespace std;

namespace exercise16_12 {

    unordered_map<string, int> tag_map = {
            {"family",    1},
            {"person",    2},
            {"firstName", 3},
            {"lastName",  4},
            {"state",     5}
    };


    class XMLNode {
        static atomic<unsigned> Counter;
        unsigned id;
    public:
        unordered_map<string, string> attributes;
        vector<XMLNode *> children;
        string tag;
        string text;

        XMLNode(string tag) : tag(tag), id(Counter++) { }

        ~XMLNode() {
            cout << "Destroying XMLNode[" << this->id << "]" << endl;
            for_each(children.begin(), children.end(), [](XMLNode *child) { delete child; });
        }

        XMLNode *addAttribute(string tag, string value) {
            attributes.emplace(tag, value);
            return this;
        };

        XMLNode *addChild(XMLNode *node) {
            children.push_back(node);
            return node;
        }

        XMLNode *setText(string text) {
            this->text = text;
            return this;
        }
    };

    atomic<unsigned> XMLNode::Counter(0);

    void encodeElement(ostringstream &ost, XMLNode *node) {

        ost << tag_map[node->tag];

        for (auto item : node->attributes) {
            ost << " ";
            ost << tag_map[item.first] << " " << item.second;
        }


        ost << " " << 0;

        if (node->text.length() > 0) {
            ost << " ";
            ost << node->text;
        }
        for (auto child : node->children) {
            ost << " ";
            encodeElement(ost, child);
        }
        ost << " " << 0;
    }

    void main() {
        // ROOT NODE
        XMLNode *root = new XMLNode("family");
        root->addAttribute("lastName", "McDowell")->addAttribute("state", "CA");
        root->addChild(new XMLNode("person"))->addAttribute("firstName", "Gayle")->setText("Some Message");
        ostringstream ost;
        encodeElement(ost, root);
        cout << ost.str() << endl;
        delete root;
    }

}
