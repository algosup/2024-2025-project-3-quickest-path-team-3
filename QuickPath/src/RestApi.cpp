#include "RestApi.hpp"
#include "PathFinder.hpp"
#include <sstream>
#include <iostream>

RestApi::RestApi(Graph& graph) : graph(graph) {} // Constructor to initialize the RestApi object

// Function to run the REST API server
void RestApi::run() {
    app.Get("/", [](const httplib::Request& req, httplib::Response& res) { // Handle the root endpoint
        res.set_content("Welcome to the REST API. Try /quickestpath with parameters.", "text/plain");
    });

    // Handle the quickest path endpoint
    app.Get("/quickestpath", [this](const httplib::Request& req, httplib::Response& res) {
        auto source = req.get_param_value("source"); // Get the source parameter from the request
        auto destination = req.get_param_value("destination"); // Get the destination parameter from the request
        auto format = req.get_param_value("format"); // Get the format parameter from the request

        // Check if the source or destination parameters are missing
        if (source.empty() || destination.empty()) {
            res.status = 400; // Set the response status to 400
            res.set_content("Missing source or destination parameter", "text/plain"); // Set the response content
            return;
        }

        int sourceInt = std::stoi(source); // Convert the source parameter to an integer
        int destinationInt = std::stoi(destination); // Convert the destination parameter to an integer
        if (sourceInt < 0 || destinationInt < 0) {
            res.status = 400; // Set the response status to 400
            res.set_content("Source and destination must be non-negative integers", "text/plain"); // Set the response content
            return;
        }

        PathFinder pathFinder(graph); // Create a PathFinder object with the graph
        auto result = pathFinder.findQuickestPath(source, destination); // Find the quickest path between the source and destination
        int time = result.first; // Get the time from the result
        const auto& path = result.second; // Get the path from the result

        // Check if the time is -1, indicating that the path was not found
        if (time == -1) {
            res.status = 404; // Set the response status to 404
            res.set_content("Path not found", "text/plain"); // Set the response content
            return;
        }

        std::ostringstream os; // Create an output string stream
        if (format == "xml") { // Check if the format is XML
            os << "<response><time>" << time << "</time><path>"; // Write the time and path to the output stream
            for (const auto& node : path) os << "<node>" << node << "</node>"; // Write each node in the path to the output stream
            os << "</path></response>"; // Close the XML response
            res.set_content(os.str(), "application/xml"); // Set the response content
        } else { // Default to JSON
            os << "{ \"time\": " << time << ", \"path\": ["; // Write the time and path to the output stream
            for (size_t i = 0; i < path.size(); ++i) { // Write each node in the path to the output stream
                os << "\"" << path[i] << "\"";  // Add the node to the output stream
                if (i != path.size() - 1) os << ","; // Add a comma if it's not the last node
            }
            os << "] }"; // Close the JSON response
            res.set_content(os.str(), "application/json"); // Set the response content
        }
    });

    std::cout << "Server running on http://localhost:18080" << std::endl; // Print the server URL
    app.listen("0.0.0.0", 18080); // Start the server
}