################################################################################
################################################################################
## Template file for problem 1. You have to fill in the function findNumbers  ##
## defined below. The function takes in an input number and return the list   ##
## of numbers that satisfy the problem statement. Please ensure you return a  ##
## list as the submission will be auto evaluated. We have provided a little   ##
## helper to ensure that the return value is correct.                         ##
##                                                                            ##
## You can run this template file to see the output of your function.         ##
## First replace the TEST_NUMBER with correct number.                         ##
## Then simply run: `python problem1_template.py`                             ##
## You should see the output printed once your program runs.                  ##
##                                                                            ##
## DO NOT CHANGE THE NAME OF THE FUNCTION BELOW. ONLY FILL IN THE LOGIC.      ##
## DONT FORGET TO RETURN THE VALUES AS A LIST                                 ##
## IF YOU MAKE ANY IMPORTS PUT THEM IN THE BODY OF THE FUNCTION               ##
##                                                                            ##
## You are free to write additional helper functions but ensure they are all  ##
## in this file else your submission wont work.                               ##
##                                                                            ##
## Good Luck!                                                                 ##
################################################################################
################################################################################

TEST_NUMBER = 0
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
    ##################################
    ##          FILL ME IN          ##
    ##################################
    
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

    return []

def ensureNumbers(returnList):
    for num in returnList:
        if type(num) is int:
            continue
        else:
            print(num, ' is not an integer.')
            raise TypeError('The return value is not a list of integers')
    return returnList

def ensureListOfNumbers(returnList):
    if type(returnList) is list:
        return ensureNumbers(returnList)
    else:
        print('Return value is not a list. Please ensure you return a list.')
        raise TypeError('The return value is not a list')



if __name__ == "__main__":
    print(ensureListOfNumbers(findNumbers(TEST_NUMBER)))