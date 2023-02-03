print( "Fraction converter" )
nom = float(input())
denom = float(input())

try:
    decimal = nom / denom
    print( decimal )
except ZeroDivisionError:
    print( "Denominator can't be 0" )
