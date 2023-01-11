import java.math.*;
//Calculating Kinetic Energy (KE=1/2 m*v*v)
//& Calculating Electric Potential Energy(EPE=k(*q1*q2/r))
class Equation implements Runnable  {
    private float mass , velocity,velocity_sq,q1,q2,r,q ;
    float KE,EPE;
    float K=(float) 8.99E9;

    public Equation(float mass , float velocity,float q1,float q2,float r) {
        this.mass = mass;
        this.velocity = velocity;
        this.q1=q1;
        this.q2=q2;
        this.r=r;
    }

    public void run() {
        
    	velocity_sq= velocity*velocity;
       KE=(float) ((0.5)*(mass)*velocity_sq);
       q=q1*q2;
       EPE=((K)*(q/r));
    }

    public float getsolve1() {
        return velocity_sq;
    }
    public float getsolve2()
    {
    	return mass;
    }
    public float finalsolve()
    {
    	return KE;
    }
    public float getcal1()
    {
    	return q;
    }
    public float getcal2()
    {
    	return r;
    }
    public float finalcal()
    {
    	return EPE;
    }
    }



