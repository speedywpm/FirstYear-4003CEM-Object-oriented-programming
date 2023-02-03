import unittest

class Tests(unittest.TestCase):
	def test_bigger(self):
		self.assertTrue( 1 < 0 )

	def test_equals(self):
		self.assertEqual( 1+1, 2 )

	def test_div(self):
		with self.assertRaises(ZeroDivisionError):
			1 / 0

if __name__ == '__main__':
	unittest.main()
