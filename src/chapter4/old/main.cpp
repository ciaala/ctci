#include <iostream>
#include "GraphNode.h"
#include <vector>

using namespace std;

extern int testGraphNode();

void
main_chapter41() {

    std::vector <pair<string, string>> dependencies = {{"a", "b"},
                                                       {"c", "d"}};

    auto root = GraphNode::createManaged();

}

int main_chapter4() {
    main_chapter41();
    return testGraphNode();
}