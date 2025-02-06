#include "../../src/Graph.hpp"
#include "../../src/PathFinder.hpp"
#include "../../src/RestApi.hpp"

// Adding a new landmark node should return its new index and update all data structures
TEST_CASE("ensure_node_adds_new_landmark_and_returns_index", "[graph]") {
    Graph g;

    int index = g.ensureNode("A");

    REQUIRE(index == 0);
    REQUIRE(g.nodeIndex.at("A") == 0);
    REQUIRE(g.indexToNode[0] == "A");
    REQUIRE(g.adjList[0].empty());

    int index2 = g.ensureNode("B");

    REQUIRE(index2 == 1);
    REQUIRE(g.nodeIndex.at("B") == 1);
    REQUIRE(g.indexToNode[1] == "B");
    REQUIRE(g.adjList[1].empty());
}