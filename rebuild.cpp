#include "rebuild.h"

int main(int argc, char **argv) {
  system("mkdir -p build");
  rebuild_targets.push_back(
      new Target("build/linked_tests", {"build/linked_tests.o"},
                 "g++ -o build/linked_tests build/linked_tests.o"));
  rebuild_targets.push_back(
      new Target("build/linked_tests.o", {"tests/tests.cpp", "linked/linked.h"},
                 "g++ -c -o build/linked_tests.o -Ilinked tests/tests.cpp"));
  return 0;
}
