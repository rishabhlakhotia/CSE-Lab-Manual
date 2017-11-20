import java.util.*;

abstract class Solid
{
	double radius;

	public abstract void surfaceArea();
	public abstract void volume();
	public abstract void readRadius();

	public double baseArea(double r)
	{
	  double p;
	  p=Math.PI*r*r;
	  return(p);
	}
 }

class Cylinder extends Solid
{
	double height;
	public Cylinder(double h)
	{
		height=h;
	}


	public void readRadius()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the radius of cylinder");
		radius=sc.nextDouble();
	}

	public void surfaceArea()
	{
		double bArea;
		double totalArea;
		bArea=baseArea(radius);
		totalArea=2*Math.PI*radius*height+2*bArea;
		System.out.println("Surface area of cylinder is"+totalArea);
 	}

	public void volume()
	{
		System.out.println("\nVolume of the cylinder is"+height*(baseArea(radius)));
	}
}


class Cone extends Solid
{
	double height;

	public Cone(double h)
	{
		height=h;
	}

	public void readRadius()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the radius of cone: ");
		radius=sc.nextDouble();
	}

	public void surfaceArea()
	{
		double area;
		double slantHeight;

		slantHeight=Math.sqrt(radius*radius+height*height);
		area=(Math.PI*radius)*(radius+slantHeight);
		System.out.println("Surface area of a cone is: "+area);
	}

	public void volume()
	{
		double volume;
		volume=(1.0/3)*(baseArea(radius))*height;
		System.out.println("Volume of cone is:"+volume);
	}
}

class Sphere extends Solid
{
	public void readRadius()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the radius of sphere");
		radius=sc.nextDouble();
	}

	
	public void surfaceArea()
	{
		System.out.println("Surface area of a sphere is: "+4*baseArea(radius));

	}

	public void volume()
	{
		double volume;
		volume=(4.0/3)*(baseArea(radius))*radius;
		System.out.println("Volume of cone is:"+volume);
	}
}

class MySolid
{
	public static void main(String args[])
	{
		Solid s=new Cylinder(7);
		s.readRadius();
		s.surfaceArea();
		s.volume();
		
		s=new Cone(7);
		s.readRadius();
		s.surfaceArea();
		s.volume();

		s=new Sphere();
		s.readRadius();
		s.surfaceArea();
		s.volume();
	}
}
