import sys

def some_function( values ):
	for i in range(len(values)):
		values[i] *= 2

def main():
	v = [ i for i in range(5) ]
	print(v)  # [0, 1, 2, 3, 4]

	some_function(v)
	print(v)  # [0, 2, 4, 6, 8]

if __name__ == '__main__':
	sys.exit(main())