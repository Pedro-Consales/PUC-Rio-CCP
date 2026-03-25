
public class Assento {
	
	private int fila;
	private char assento;
	private boolean livre;
	
	public Assento(int fila, char assento) {
		
		this.fila = fila;
		this.assento = assento;
		this.livre = true; //Se eu criar um assento ele tem que começar livre
	}
	
	public boolean getEstado() {
		return this.livre;
	}
	
	public void reserva() {
		this.livre = false;
	}
	
}
