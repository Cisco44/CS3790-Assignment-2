import java.io.*;

public class PrimeTester impliments Runnable
{
	private int thrdId, N, M;
	
	boolean isPrime(int num)
        {
		double sqrtNum = num;
		sqrtNum = Math.sqrt(sqrtNum);
		for(int i = 2; i < sqrtNum; i++)
                {
			if(num % i == 0) return false;
		}
		return true;
	}
	
	int run(int thrdId, N, M)
        {
		this.thrdId = thrdId;
		this.N = N;
		this.M = M;
		
		int lowerBound = thrdId * (N/M) + 1;
		int upperBound = (thrdId + 1) * (N/M);
		
		for(int i = lowerBound; i < upperBound; i++)
			if(isPrime(i))
				printf("Thread %d found the prime: %d\n", thrdId, i);
	}
}