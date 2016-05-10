# momentcpp
Like [moment.js](http://momentjs.com/), in c++

__IMPORTANT__: do not use it (experimental)

# usage
```c++
#include <iostream>
#include <moment>

int main(){
  std::cout << moment::moment() << std::endl;
}
```


# build
```sh
$ mkdir build && cd build
$ cmake .. && make --build .
```

# test
this project use [google test](https://github.com/google/googletest). To run tests:
```sh
# make sure project is built, then
$ ./build/moment_test
```

see [this](http://stackoverflow.com/questions/13513905/how-to-setup-googletest-as-a-shared-library-on-linux?answertab=votes#tab-top) if you have troubles installing it.
