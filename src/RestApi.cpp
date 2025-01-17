#include "RestApi.h"
#include <sstream>
#include <iostream>

RestApi::RestApi(Graph& graph) : graph(graph) {}

void RestApi::run() {
    // Root endpoint
    app.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Welcome to the REST API. Try /quickestpath with parameters.", "text/plain");
    });

    // Endpoint for quickest path
    app.Get("/quickestpath", [this](const httplib::Request& req, httplib::Response& res) {
        auto source = req.get_param_value("source");
        auto destination = req.get_param_value("destination");
        auto format = req.has_param("format") ? req.get_param_value("format") : "";

        if (source.empty() || destination.empty()) {
            res.status = 400;
            res.set_content("Missing source or destination parameter", "text/plain");
            return;
        }

        auto result = graph.quickestPath(source, destination);
        int time = result.first;
        const std::vector<std::string>& path = result.second;

        if (time == -1) {
            res.status = 404;
            res.set_content("Path not found", "text/plain");
            return;
        }

        std::ostringstream os;
        if (format == "xml") {
            os << "<response><time>" << time << "</time><path>";
            for (const auto& landmark : path) {
                os << "<landmark>" << landmark << "</landmark>";
            }
            os << "</path></response>";
            res.set_content(os.str(), "application/xml");
        } else {
            os << "{ \"time\": " << time << ", \"path\": [";
            for (size_t i = 0; i < path.size(); ++i) {
                os << "\"" << path[i] << "\"";
                if (i != path.size() - 1) os << ",";
            }
            os << "] }";
            res.set_content(os.str(), "application/json");
        }
    });

    // Default error handler
    app.set_error_handler([](const httplib::Request& req, httplib::Response& res) {
        res.status = 404;
        res.set_content("The requested resource was not found.", "text/plain");
    });

    std::cout << "Server running on http://localhost:18080" << std::endl;
    app.listen("0.0.0.0", 18080);
}
