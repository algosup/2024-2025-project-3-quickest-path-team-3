#ifndef RESTAPI_HPP
#define RESTAPI_HPP

#include "Graph.hpp"
#include "httplib.hpp"

class RestApi {
public:
    explicit RestApi(Graph& graph);
    void run();

private:
    Graph& graph;
    httplib::Server app;
};

#endif
