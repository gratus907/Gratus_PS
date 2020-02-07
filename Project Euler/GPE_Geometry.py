import math

# A R2 Point
class Point:
	def __init__(self, x,y):
		self.x = x
		self.y = y

	def toString(self):
		return "Point(%s,%s)" % (self.x, self.y)

	def move(self, dx, dy):
		self.x = self.x + dx
		self.y = self.y + dy

	def dist_from_origin(self):
		return Point.dist(self,Point(0,0))

	def dist(self, other):
		dx = self.x - other.x
		dy = self.y - other.y
		return math.hypot(dx,dy)

	def angle_between_points(self, other):
		dx = self.x - other.x
		dy = self.y - other.y
		radi = math.atan2(dy,dx)
		return radi*180.0/math.pi

def triangle_area(A, B, C):
	S = 0
	S += (A.x*B.y+B.x*C.y+C.x*A.y)
	S -= (A.y*B.x+B.y*C.x+C.y*A.x)
	S /= 2.0
	return abs(S)

def angle_measure(x, y):
	r = math.sqrt(x*x+y*y)

	angle = math.acos(x/r)
	if x>0 and y<0:
		return angle+180/math.pi
	return angle
