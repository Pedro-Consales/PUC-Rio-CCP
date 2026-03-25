package lista;


public class Vetor {
	
	private double x,y;
	
	public Vetor(double x,double y) {
		this.x=x;
		this.y=y;
	}
	
	private Vetor() {} // Isso é um construtor válido que eu posso chamar e se não passar parametro ele me retona com valores x e y = 0.0
	
	public Vetor clone() {
		
		Vetor v = new Vetor();
		v.x = this.x;
		v.y = this.y;
		
		return v;	
	}
	
	public String toString() {
		
		String result = String.format("(%f , %f)", this.x, this.y);
		
		return result;
	}
	
	public double getX() {
		return this.x;
	}
	public double getY() {
		return this.y;
	}
	
}