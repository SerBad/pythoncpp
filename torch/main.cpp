#include <iostream>
#include <torch/extension.h>
#include <string>
#include <typeinfo>
#include <ctime>


//告诉编译器使用 std 命名空间。
using namespace std;

int main()
{
   //不带结束换行符的
   cout << "Hello"  ;
   //带结束换行符的
   cout << "  World" << endl; // 输出 Hello World
   return 0;
}

string test(){
    py::object return_on_python=py::module::import("main").attr("return_on_python");
    string result = std::string(return_on_python("aaaa").str()) ;
    return result;
}

//需要暴露的方法，这里必须要定义下
//关键是pybind11
PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.doc() = "pybind11 example plugin";
  m.def("main", &main, "这里是main方法的注释");
  m.def("test", &test, "这里是test方法的注释");
}