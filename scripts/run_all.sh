#!/usr/bin/env bash
cd "${1:-.}" || exit 1
mkdir -p build/tests || exit 1
mapfile -t tests < <(find stress_tests -name '*.cpp' | sort)
pass=0
fail=0
for test in "${tests[@]}"; do
    echo "$test:"
    binary="build/tests/${test//\//_}"
    if ${CXX:-g++} ${CXXFLAGS:--std=c++20 -Isrc} -Wall -Wfatal-errors -O2 "$test" -o "$binary" && "$binary"; then
        ((pass+=1))
    else
        ((fail+=1))
    fi
done
echo "$pass/${#tests[@]} tests passed"
((fail == 0 && pass > 0))
