def reverse( sequence ):
	reversed = []
	for i in range(len(sequence)-1,-1,-1):
		reversed.append( sequence[i] )
	return reversed

if __name__ == "__main__":
	sequence = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 ]

	reversed = reverse( sequence )

	print( "original: ", end="" )
	for i in range(len(sequence)):
		print( sequence[i], end=", " )
	print()

	print( "reversed: ", end="" )
	for i in range(len(reversed)):
		print( reversed[i], end=", " )
	print()