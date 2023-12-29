while True:
	try:
		a = int (input ())
		if a < 0 or 100 < a:
			break
		ans = a
		for i in range (1, a):
			ans *= i
		print (ans)
	except:
		break
