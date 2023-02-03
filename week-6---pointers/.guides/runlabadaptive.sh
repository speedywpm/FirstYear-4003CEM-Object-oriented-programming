echo -e "5\n42\n69\n128\n3\n999\n" | 
match -s "Element 4 is 999" -s "Element 3 is 3" -s "Element 2 is 128" -s "Element 1 is 69" -s "Element 0 is 42" runcpp --memory lab_adaptive.cpp 