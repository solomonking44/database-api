#include <iostream>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>


using namespace Pistache;

class HelloHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(__attribute__((unused)) const Http::Request& request, Http::ResponseWriter response) {
        response.send(Http::Code::Ok, "Hello, Solomon\n");
    }
};

int main() {
    Address addr(Ipv4::any(), Port(9080));

    auto opts = Http::Endpoint::options().threads(1);
    Http::Endpoint server(addr);
    server.init(opts);
    std::cout << "Server running" << std::endl;
    server.setHandler(Http::make_handler<HelloHandler>());
    server.serve();
}