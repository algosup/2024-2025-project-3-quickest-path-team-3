#ifndef RESTAPI_H
#define RESTAPI_H

#include "Graph.h"
#include <crow.h>

class RestApi {
public:
    RestApi(Graph& graph);
    void run();

private:
    Graph& graph;
    crow::SimpleApp app;
};

#endif // RESTAPI_H
