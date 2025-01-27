#include "RestApi.h"
#include "PathFinder.h"
#include <sstream>
#include <iostream>

RestApi::RestApi(Graph& graph) : graph(graph) {}

void RestApi::run() {
    app.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Welcome to the REST API. Try /quickestpath with parameters.", "text/plain");
    });

    app.Get("/quickestpath", [this](const httplib::Request& req, httplib::Response& res) {
        auto source = req.get_param_value("source");
        auto destination = req.get_param_value("destination");

        if (source.empty() || destination.empty()) {
            res.status = 400;
            res.set_content("Missing source or destination parameter", "text/plain");
            return;
        }

        PathFinder pathFinder(graph);
        auto result = pathFinder.findQuickestPath(source, destination);
        int time = result.first;
        const auto& path = result.second;

        if (time == -1) {
            res.status = 404;
            res.set_content("Path not found", "text/plain");
            return;
        }

        std::ostringstream os;
        os << "{ \"time\": " << time << ", \"path\": [";
        for (size_t i = 0; i < path.size(); ++i) {
            os << "\"" << path[i] << "\"";
            if (i != path.size() - 1) os << ",";
        }
        os << "] }";
        res.set_content(os.str(), "application/json");
    });

    std::cout << "Server running on http://localhost:18080" << std::endl;
    app.listen("0.0.0.0", 18080);
}
