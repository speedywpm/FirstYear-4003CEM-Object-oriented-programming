#!/bin/bash

# ====== do all the standard checks ===
echo -e "5\n42\n69\n128\n3\n999\n" | match -s "Element 4 is 999" -s "Element 3 is 3" -s "Element 2 is 128" -s "Element 1 is 69" -s "Element 0 is 42" runcpp --memory lab_smart.cpp 
standardtest=$?  

if [[ $standardtest -ne 0 ]]
then
  exit $standardtest
fi

echo "PROGRAM RUNS"

# ====== test that smartpointers are being used ===
cat lab_smart.cpp | sed 's/#include\s\s*<memory>//g' | g++ --std=c++14 -I/home/codio/workspace -x c++ - -o .guides/runner &>/dev/null
compile=$?

if [[ $compile -eq 0 ]]
then
  echo ""
  echo "PROGRAM IS NOT USING SMARTPOINTERS"
  exit 1
fi

exit 0
