#!/usr/bin/env bash
cd "${1:-.}" || exit 1
mapfile -t tests < <(find src -type f \( -name '*.hpp' \) ! -path 'src/contest/*' ! -name 'example.hpp' | sort)
pass=0
fail=0
for test in "${tests[@]}"; do
    echo "$test:"
    if ./scripts/test_compiles.sh "$test"; then
        ((pass+=1))
    else
        ((fail+=1))
    fi
done
echo "$pass/${#tests[@]} syntax checks passed"
((fail == 0 && pass > 0))
