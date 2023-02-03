import sys

def main():
	size = 0

	# get the size
	while size <= 0:
		try:
			size = int(input('Enter a size '))

			if size <= 0:
				print('Not a valid size')

		except ValueError:
			print('Not an integer')

	print('Reading in',size,'values')

	# create a list of the right size
	values = [None]*size

	# get the values
	for i in range(size):
		values[i] = input('Enter a value ')

	# print everything in reverse
	for i in range(size-1,-1,-1):
		print('Element',i,'is',values[i])	

if __name__ == '__main__':
	sys.exit( main() )