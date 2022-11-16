# Filter Project

## Build

Pre-requisites: google/test and google/benchmark
See [this](./installation-google-test-and-benchmark.md)

To build and run the project:

```sh
make clean && make
./main-app
```

To genrate graphs, run:

```sh
./generateGraph.sh
```

For time benchmarking, run:

```sh
./timeBenchmarking.sh <no.of iterations> <input size> <filter size>
```

## Performance

-------------
