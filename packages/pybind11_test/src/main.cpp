#include <pybind11/pybind11.h>
#include <iostream>

using std::cout;
using std::endl;

int add(int i, int j) {
    return i + j;
}

static bool my_init_ = [] () {
  cout << "loading library pybind11_test, build at " << __TIME__ << endl;
  return true;
}();

namespace py = pybind11;

PYBIND11_MODULE(pybind11_test, m) {
    cout << "exporting module pybind11_test" << endl;
    m.def("add", &add);
    m.def("hello", []() { cout << "hello world" << endl; });
}
