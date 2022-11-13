# Installtion guide for Gtest and Gbenchmark

These instructions build and install gtest and gbenchmark system wide
All files are installed in /usr/local/include

## Google test

Download latest stable release zip from google/googletest
Currently its [1.12.1](https://github.com/google/googletest/releases/tag/release-1.12.1)
unzip the file, rename folder to "googletest"
Run following commands:

```sh
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
```

### Google test output

```sh
Install the project...
-- Install configuration: ""
-- Up-to-date: /usr/local/include
-- Installing: /usr/local/include/gmock
-- Installing: /usr/local/include/gmock/gmock-matchers.h
-- Installing: /usr/local/include/gmock/gmock-more-actions.h
-- Installing: /usr/local/include/gmock/internal
-- Installing: /usr/local/include/gmock/internal/gmock-port.h
-- Installing: /usr/local/include/gmock/internal/gmock-internal-utils.h
-- Installing: /usr/local/include/gmock/internal/gmock-pp.h
-- Installing: /usr/local/include/gmock/internal/custom
-- Installing: /usr/local/include/gmock/internal/custom/gmock-port.h
-- Installing: /usr/local/include/gmock/internal/custom/gmock-matchers.h
-- Installing: /usr/local/include/gmock/internal/custom/gmock-generated-actions.h
-- Installing: /usr/local/include/gmock/internal/custom/README.md
-- Installing: /usr/local/include/gmock/gmock-function-mocker.h
-- Installing: /usr/local/include/gmock/gmock-more-matchers.h
-- Installing: /usr/local/include/gmock/gmock-cardinalities.h
-- Installing: /usr/local/include/gmock/gmock-spec-builders.h
-- Installing: /usr/local/include/gmock/gmock-nice-strict.h
-- Installing: /usr/local/include/gmock/gmock.h
-- Installing: /usr/local/include/gmock/gmock-actions.h
-- Installing: /usr/local/lib/libgmock.a
-- Installing: /usr/local/lib/libgmock_main.a
-- Installing: /usr/local/lib/pkgconfig/gmock.pc
-- Installing: /usr/local/lib/pkgconfig/gmock_main.pc
-- Installing: /usr/local/lib/cmake/GTest/GTestTargets.cmake
-- Installing: /usr/local/lib/cmake/GTest/GTestTargets-noconfig.cmake
-- Installing: /usr/local/lib/cmake/GTest/GTestConfigVersion.cmake
-- Installing: /usr/local/lib/cmake/GTest/GTestConfig.cmake
-- Up-to-date: /usr/local/include
-- Installing: /usr/local/include/gtest
-- Installing: /usr/local/include/gtest/gtest-matchers.h
-- Installing: /usr/local/include/gtest/gtest-death-test.h
-- Installing: /usr/local/include/gtest/gtest-spi.h
-- Installing: /usr/local/include/gtest/gtest-assertion-result.h
-- Installing: /usr/local/include/gtest/internal
-- Installing: /usr/local/include/gtest/internal/gtest-string.h
-- Installing: /usr/local/include/gtest/internal/gtest-death-test-internal.h
-- Installing: /usr/local/include/gtest/internal/gtest-port.h
-- Installing: /usr/local/include/gtest/internal/gtest-port-arch.h
-- Installing: /usr/local/include/gtest/internal/gtest-internal.h
-- Installing: /usr/local/include/gtest/internal/gtest-param-util.h
-- Installing: /usr/local/include/gtest/internal/gtest-type-util.h
-- Installing: /usr/local/include/gtest/internal/gtest-filepath.h
-- Installing: /usr/local/include/gtest/internal/custom
-- Installing: /usr/local/include/gtest/internal/custom/gtest-port.h
-- Installing: /usr/local/include/gtest/internal/custom/README.md
-- Installing: /usr/local/include/gtest/internal/custom/gtest.h
-- Installing: /usr/local/include/gtest/internal/custom/gtest-printers.h
-- Installing: /usr/local/include/gtest/gtest-message.h
-- Installing: /usr/local/include/gtest/gtest-param-test.h
-- Installing: /usr/local/include/gtest/gtest-typed-test.h
-- Installing: /usr/local/include/gtest/gtest_pred_impl.h
-- Installing: /usr/local/include/gtest/gtest_prod.h
-- Installing: /usr/local/include/gtest/gtest-test-part.h
-- Installing: /usr/local/include/gtest/gtest.h
-- Installing: /usr/local/include/gtest/gtest-printers.h
-- Installing: /usr/local/lib/libgtest.a
-- Installing: /usr/local/lib/libgtest_main.a
-- Installing: /usr/local/lib/pkgconfig/gtest.pc
-- Installing: /usr/local/lib/pkgconfig/gtest_main.pc
```

## Google benchmark

Download latest stable release zip from google/benchmark
Currently its [1.7.1](https://github.com/google/benchmark/releases/tag/v1.7.1)
unzip the file, rename folder to "benchmark"
Run following commands:

```sh
cd benchmark
mkdir build
cd build
cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON ..
make
sudo make install
```

### Google benchmark output

```sh
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/lib/libbenchmark.a
-- Installing: /usr/local/lib/libbenchmark_main.a
-- Installing: /usr/local/include/benchmark
-- Installing: /usr/local/include/benchmark/export.h
-- Installing: /usr/local/include/benchmark/benchmark.h
-- Installing: /usr/local/lib/cmake/benchmark/benchmarkConfig.cmake
-- Installing: /usr/local/lib/cmake/benchmark/benchmarkConfigVersion.cmake
-- Installing: /usr/local/lib/pkgconfig/benchmark.pc
-- Installing: /usr/local/lib/cmake/benchmark/benchmarkTargets.cmake
-- Installing: /usr/local/lib/cmake/benchmark/benchmarkTargets-noconfig.cmake
-- Installing: /usr/local/share/doc/benchmark
-- Installing: /usr/local/share/doc/benchmark/perf_counters.md
-- Installing: /usr/local/share/doc/benchmark/random_interleaving.md
-- Installing: /usr/local/share/doc/benchmark/user_guide.md
-- Installing: /usr/local/share/doc/benchmark/releasing.md
-- Installing: /usr/local/share/doc/benchmark/AssemblyTests.md
-- Installing: /usr/local/share/doc/benchmark/dependencies.md
-- Installing: /usr/local/share/doc/benchmark/index.md
-- Installing: /usr/local/share/doc/benchmark/_config.yml
-- Installing: /usr/local/share/doc/benchmark/platform_specific_build_instructions.md
-- Installing: /usr/local/share/doc/benchmark/reducing_variance.md
-- Installing: /usr/local/share/doc/benchmark/tools.md
-- Installing: /usr/local/share/doc/benchmark/python_bindings.md
```
