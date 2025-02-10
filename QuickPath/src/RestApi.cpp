#include "RestApi.hpp"
#include "PathFinder.hpp"
#include <sstream>
#include <iostream>

RestApi::RestApi(Graph& graph) : graph(graph) {} // Constructor to initialize the RestApi object

// Function to run the REST API server
void RestApi::run() {
    app.set_base_dir("."); // Ensure static files can be served if needed

    // Allow CORS (Cross-Origin Resource Sharing) for frontend requests
    app.Options(".*", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
    });

    app.Get("/", [](const httplib::Request& req, httplib::Response& res) { // Handle the root endpoint
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content("Welcome to the REST API. Try /quickestpath with parameters.", "text/plain");
    });

    // Handle the quickest path endpoint
    app.Get("/quickestpath", [this](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*"); // Allow frontend requests

        auto source = req.get_param_value("source"); // Get the source parameter from the request
        auto destination = req.get_param_value("destination"); // Get the destination parameter from the request
        auto format = req.get_param_value("format"); // Get the format parameter from the request

        // Check if the source or destination parameters are missing
        if (source.empty() || destination.empty()) {
            res.status = 400; // Set the response status to 400
            res.set_content("Missing source or destination parameter", "text/plain");
            return;
        }

        PathFinder pathFinder(graph); // Create a PathFinder object with the graph
        auto result = pathFinder.findQuickestPath(source, destination); // Find the quickest path between the source and destination
        int time = result.first; // Get the time from the result
        const auto& path = result.second; // Get the path from the result

        // Check if the path was found
        if (time == -1) {
            res.status = 404; // Set the response status to 404
            res.set_content("Path not found", "text/plain");
            return;
        }

        std::ostringstream os;
        if (format == "xml") { // XML response
            os << "<response><time>" << time << "</time><path>";
            for (const auto& node : path) os << "<node>" << node << "</node>";
            os << "</path></response>";
            res.set_content(os.str(), "application/xml");
        } else { // Default JSON response
            os << "{ \"time\": " << time << ", \"path\": [";
            for (size_t i = 0; i < path.size(); ++i) {
                os << "\"" << path[i] << "\"";
                if (i != path.size() - 1) os << ",";
            }
            os << "] }";
            res.set_content(os.str(), "application/json");
        }
    });

    std::cout << "Server running on http://localhost:18080" << std::endl;
    app.listen("0.0.0.0", 18080); // Start the server and allow external access
}
