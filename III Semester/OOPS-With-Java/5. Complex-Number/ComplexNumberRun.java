class ComplexNumber
{
	double real;
	double imag;
	
	ComplexNumber()
	{
		real = 0.0;
		imag = 0.0;
	}
	ComplexNumber(double a)
	{
		real = a;
		imag = 0;
	}
	ComplexNumber(double a, double b)
	{
		real = a;
		imag = b;
	}
	ComplexNumber(ComplexNumber ob)
	{
		real = ob.real;
		imag = ob.imag;
	}
	
	void add(ComplexNumber c1, ComplexNumber c2)
	{
		double realSum = c1.real+c2.real;
		double imagSum = c1.imag+c2.imag;
		System.out.println("Sum is "+realSum+"+i"+imagSum);
	}
	
	void sub(ComplexNumber c1, ComplexNumber c2)
	{
		double realDiff = c1.real-c2.real;
		double imagDiff = c1.imag-c2.imag;
		System.out.println("Difference is "+realDiff+"-i"+imagDiff);
	}
}

class ComplexNumberRun
{
	public static void main(String args[])
	{
		ComplexNumber cn1 = new ComplexNumber();
		ComplexNumber cn2 = new ComplexNumber(10);
		ComplexNumber cn3 = new ComplexNumber(20,30);
		ComplexNumber cn4 = new ComplexNumber(cn3);
		cn1.add(cn1,cn4);
		cn2.sub(cn2,cn3);
	}
}
