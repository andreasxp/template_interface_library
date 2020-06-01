#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <zh/hello_world.hpp>

TEST_CASE("Unit.Test") {
	CHECK(hello_world() == "Hello World!");
}
