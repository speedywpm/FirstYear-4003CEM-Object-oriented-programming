import unittest
import os
import re

class AiTest(unittest.TestCase):
    srcName = "lab_ai3.cpp"
    filepath = os.path.join("../", srcName)

    def exist(self): return os.path.isfile( AiTest.filepath )

    def test_1_exist(self):
        """ Test that the source file exists in the directory """

        self.assertTrue( self.exist(), 
            "{} does not exist in directory".format(AiTest.srcName) )

    def test_3_output(self):
        """ Test that the file contains the expected line"""

        lineReg = re.compile( r"secondAI\s*\.\s*say_hello\s*\(\s*\)\s*;" )

        found = False
        with open(AiTest.filepath, "r") as f:
            found = lineReg.search( f.read() ) != None

        if not found:
            self.fail( "{} did not contain expected line".format(AiTest.srcName) )

if __name__ == '__main__':
    unittest.main(failfast=True)
