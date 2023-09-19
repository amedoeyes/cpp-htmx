#include <inja/inja.hpp>
#include <nlohmann/json.hpp>
#include <retina.hpp>
#include <string>

using json = nlohmann::json;

auto main() -> int {
	retina::Server server{8080};

	json data;

	std::string html = inja::render(
		R"(
			{% extends "src/index.html" %}
			{% block root %}
				{% include "src/counter.html" %}
			{% endblock %}
		)",
		data
	);

	server.route(
		"/", retina::Method::get,
		[&html](const retina::Request &, retina::Response &res) {
			res.set(retina::Field::content_type, "text/html");
			res.body() = html;
		}
	);

	int count = 0;

	server.route(
		"/counter", retina::Method::get,
		[&count](const retina::Request &, retina::Response &res) {
			res.body() = std::to_string(count);
		}
	);

	server.route(
		"/counter", retina::Method::post,
		[&count](const retina::Request &, retina::Response &res) {
			res.body() = std::to_string(++count);
		}
	);

	server.start();

	return 0;
}
