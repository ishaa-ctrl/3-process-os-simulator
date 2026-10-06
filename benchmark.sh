#!/bin/bash

echo "===================================="
echo "   OS SIMULATOR BENCHMARK"
echo "===================================="

echo ""
echo "Running standalone benchmark..."
./benchmark/standalone

echo ""
echo "Running multi-process simulator..."
echo "Start the simulator using:"
echo "./launcher"

echo ""
echo "Benchmark comparison:"
echo "Standalone: measured above"
echo "Multi-process: measure using the simulator execution time"
