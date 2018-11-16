isPrime = []
primes = []
possibleSums = []

def generatePrimes(n):
	# isPrime = [True for i in range(n+1)]
	for i in range(n+1):
		isPrime.append(True)
	isPrime[0] = isPrime[1] = False

	i = 2
	while(i*i <= n):
	    if (isPrime[i] == True):
	        j = 2
	        while(i*j <= n):
	            isPrime[i*j] = False
	            j += 1
	    i += 1
	    
	# primes = []
	# primesCount = 0
	for i in range(2, n):
	    if isPrime[i]:
	        primes.append(i)
	        # primesCount += 1

	# return isPrime, primes, primesCount

def canBeSumOfPrimes(n):
	for i in range(2, n-1):
		if(isPrime[i] and isPrime[n-i]):
			return True
	return False

def generatePossibleSums(n):
	# possibleSums = []
	# possibleSumCount = 0
	for i in range(5, n):
		if not(canBeSumOfPrimes(i)):
			possibleSums.append(i)
			# possibleSumCount += 1

	# return possibleSums, possibleSumCount

def isPossibleSum(n):
	for i in range(len(possibleSums)):
		if (possibleSums[i] == n):
			return True
	return False

def findNumbers(inputNumber):

	generatePrimes(inputNumber)
	generatePossibleSums(inputNumber)

	sums = [{'Count': 0, 'x': 0, 'y': 0} for i in range(inputNumber)]
	
	for i in range(5, 2500):
		
		possibleCount = 0
		n1 = 0
		n2 = 0

		j = 2
		while (j*j <= i):
			if(i % j == 0):
				if(isPossibleSum(j + i/j)):
					n1 = j
					n2 = i/j
					possibleCount += 1
			j += 1

		if possibleCount == 1:
			sum_ij = n1 + n2
			sums[sum_ij]['Count'] += 1
			sums[sum_ij]['x'] = n1
			sums[sum_ij]['y'] = n2

	for i in range(n):
		if(sums[i]['Count'] == 1):

			x = sums[i]['x']
			y = sums[i]['y']
			ans = [x, y]
			return ans

	ans = []
	return ans
			

n = 100
ans = findNumbers(n)
print ans[0], ans[1]