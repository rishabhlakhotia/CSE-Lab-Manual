interface Vehicle
{
	void steering();
	void brake();
}

class Bus implements Vehicle
{
	public void steering()
	{
		System.out.println("Bus Steering is round and medium sized");
	}
	public void brake()
	{
		System.out.println("Always use brakes to stop the bus.");
	}
}

class Lorry implements Vehicle
{
	public void steering()
	{
		System.out.println("Lorry Steering is round and big sized");
	}
	public void brake()
	{
		System.out.println("Always use brakes to stop the Lorry.");
	}
}

class Car implements Vehicle
{
	public void steering()
	{
		System.out.println("Car Steering is round and small sized");
	}
	public void brake()
	{
		System.out.println("Always use brakes to stop the car.");
	}
}

class MyVehicle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vehicle b = new Bus();
		b.steering();
		b.brake();

		Vehicle v= new Lorry();
		v.steering();
		v.brake();

		Vehicle c= new Car();
		c.steering();
		c.brake();
	}

}
