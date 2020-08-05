def multiply(x,y):
	return x*y
def add(x,y):
	return x+y
def minus(x,y):
	return x-y
def divide(x,y):
	x = float(x)
	y = float(y)
	return x/y	
def operation(x,y):
	multiply=x*y
	add=x+y
	minus=x-y
	divide=float(x)/float(y)
	return[multiply,add,minus,divide]