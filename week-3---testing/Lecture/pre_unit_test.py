import unittest

class Tests(unittest.TestCase):
	def test_bigger(self):
#IF SOLUTION
		self.assertTrue( 1 > 0 )
#ELSE SOLUTION		
		self.assertTrue( 1 < 0 )
#END SOLUTION	

	def test_equals(self):
		self.assertEqual( 1+1, 2 )

	def test_div(self):
		with self.assertRaises(ZeroDivisionError):
			1 / 0

if __name__ == '__main__':
	unittest.main()
