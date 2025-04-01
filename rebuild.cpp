#include "_rebuild/rebuild.h"

int main(int argc, char **argv) {
  system("mkdir -p build");
  rebuild_targets.push_back(Target::create(
      "build/linked_tests", {"build/linked_tests.o"}, "g++ -o #OUT #DEPENDS"));
  rebuild_targets.push_back(
      CTarget::create("build/linked_tests.o", {"tests/tests.cpp"},
                      "g++ -c -o #OUT #DEPENDS -Ilinked",
                      REBUILD_STANDARD_CXX_COMPILER, "-Ilinked"));
  return 0;
}
