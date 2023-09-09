# Lua

This project is Lua v5.4.6, and Sol2 v3.3.0 packaged for arduino/platformio.

Today only the [arduino espressif32](https://github.com/espressif/arduino-esp32) core works.

## Usage

To build Sol2, your project must use C++17. To remove older C++ standards and build with C++17 in platformio:

```ini
build_flags =
        -std=gnu++17

build_unflags =
        -std=gnu++11
        -std=gnu++14
```

## Examples

See the [examples](examples) directory for some demos.

# License

Lua is distributed under the MIT license. See https://www.lua.org/license.html.

Sol2 is distributed under the MIT license. See https://github.com/ThePhD/sol2/blob/develop/LICENSE.txt.

This project is also distributed under the MIT license. See [LICENSE](LICENSE).

