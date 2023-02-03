#!/bin/bash

match -s "int.*4.*bytes.*8.*bytes" -s "unsigned.*int.*4.*bytes.*8.*bytes" -s "short.*2.*bytes.*8.*bytes" -s "char.*1.*byte.*8.*bytes" -s "float.*4.*bytes.*8.*bytes" -s "double.*8.*bytes.*8.*bytes" -s "string.*8.*bytes.*8.*bytes" -s "array.*10.*elements.*40.*bytes.*8.*bytes" runcpp pre_pointer.cpp