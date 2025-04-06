#include "_rebuild/rebuild.h"

std::string script = R"(
target "build/linked_tests" needs "build/linked_tests.o"
	cmd "g++ -o #OUT #DEPENDS"

ctarget "build/linked_tests.o" needs "tests/tests.cpp"
	cmd "g++ -c -o #OUT #DEPENDS -Ilinked"
	ctargs "-Ilinked"
)";

int main(int argc, char **argv) {
  system("mkdir -p build");
  rescript::do_rescript(script);
  return 0;
}
