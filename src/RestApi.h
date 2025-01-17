#ifndef RESTAPI_H
#define RESTAPI_H

#include "Graph.h"
#include "httplib.h"

class RestApi {
public:
    RestApi(Graph& graph);
    void run();

private:
    Graph& graph;
    httplib::Server app;
};

#endif // RESTAPI_H
