import sys

R = [0]*10

t, w = map(int, input().split())
for tc in range(t):
	print("56")
	sys.stdout.flush()
	val = int(input())
	R[1] = val//(2**56)
	val = val - (R[1]*(2**56))
	R[2] = val//(2**28)
	val = val - (R[2]*(2**28))
	# val is now, R[3]* 2^18 + R[4]*2^14 + R[5]*2^11+R[6]*2^9
	print("168")
	sys.stdout.flush()
	val2 = int(input())
	while val2 < 0:
		val2 += (2**63)
	R[3] = val2//(2**56)
	val2 = val2 - (R[3]*(2**56))
	val -= R[3]*(2**18)
	R[4] = val2//(2**42)
	val2 = val2 - (R[4]*(2**42))

	val -= R[4]*(2**14)
	# val is now, R[5]*2^11+R[6]*2^9
	# val2 is now, R[5]*2^33+R[6]*2^27
	val3  = val * (2**22)
	R[6] = (val3 - val2) // (2**31-2**28)
	val -= R[6]*(2**9)
	R[5] = val//(2**11)

	print(R[1], R[2], R[3], R[4], R[5], R[6])
	sys.stdout.flush()
	verdict = int(input())
	if (verdict==-1):
		quit()
	if (verdict==-1):
		continue
quit()