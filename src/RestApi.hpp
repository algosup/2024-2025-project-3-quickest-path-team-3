#ifndef RESTAPI_H
#define RESTAPI_H

#include "Graph.hpp"
#include "httplib.hpp"

class RestApi {
public:
    RestApi(Graph& graph);
    void run();

private:
    Graph& graph;
    httplib::Server app;
};

#endif // RESTAPI_H
