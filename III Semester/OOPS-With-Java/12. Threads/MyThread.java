class One extends Thread
{

	One()
	{
		start();
	}

	public void run()
	{
		for(;;)
		{
			try
			{
				sleep(1000);
			}
			catch(InterruptedException e)
			{
			}
			System.out.println("Good Morning");
		}
	}
}

class Two extends Thread
{
	Two()
	{
		start();
	}

	public void run()
	{
		for(;;)
		{
			try	
			{
				sleep(2000);
			}
			catch(InterruptedException e)
			{
			}
			System.out.println("Hello");
		}
	}
}

class Three extends Thread
{
	Three()
	{
		start();
	}

	public void run()
	{
		for(;;)
		{
			try
			{
				sleep(3000);
			}
			catch(InterruptedException e)
			{
			}
			System.out.println("Welcome");
		}
	}
}

class MyThread
{
	public static void main(String args[])
	{
		new One();
		new Two();
		new Three();			
	}
}
