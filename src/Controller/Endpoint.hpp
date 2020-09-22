#pragma once


namespace Prog3 { namespace Controller {

class Endpoint
{
public:
    Endpoint();
    Endpoint(Endpoint &&) = default;
    Endpoint(const Endpoint &) = default;
    Endpoint &operator=(Endpoint &&) = default;
    Endpoint &operator=(const Endpoint &) = default;
    ~Endpoint();

private:
};

}}
