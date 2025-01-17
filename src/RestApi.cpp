#include "RestApi.h"
#include <crow.h>
#include <sstream>

RestApi::RestApi(Graph& graph) : graph(graph) {}

void RestApi::run() {
    CROW_ROUTE(app, "/quickestpath")
        .methods("GET"_method)
        ([this](const crow::request& req) {
            auto source = req.url_params.get("source");
            auto destination = req.url_params.get("destination");
            auto format = req.url_params.get("format");

            if (!source || !destination) {
                return crow::response(400, "Missing source or destination parameter");
            }

            auto result = graph.quickestPath(source, destination);
            int time = result.first;
            const std::vector<std::string>& path = result.second;

            if (time == -1) {
                return crow::response(404, "Path not found");
            }

            std::ostringstream os;
            if (format && std::string(format) == "xml") {
                os << "<response><time>" << time << "</time><path>";
                for (const auto& landmark : path) {
                    os << "<landmark>" << landmark << "</landmark>";
                }
                os << "</path></response>";
                return crow::response(200, os.str());
            } else {
                crow::json::wvalue jsonResponse;
                jsonResponse["time"] = time;
                jsonResponse["path"] = path;
                return crow::response(200, jsonResponse);
            }
        });

    app.port(18080).multithreaded().run();
}
