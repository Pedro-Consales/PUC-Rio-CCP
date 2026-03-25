
public class Vetor {
	private double x;
	private double y;
	
	public Vetor() {
		this.x = 0;
		this.y = 0;
	}//"this" nesse caso é opcional, mas é um boa prática
	
	public Vetor(double x) {
		this.x = x;
		this.y = 0;
	}
	
	
	public Vetor(double x, double y) {
		this.x = x;
		this.y = y;
	}
	

	void exibe(){
		System.out.printf("(x,y) = (%5.2f, %5.2f) \n", this.x, this.y);
	}
	
	
	void soma1(Vetor v2) { //Se um método usa atributos da classe não use static. Se não usa, use static (repare que nos outros eu passo parametros mas nenhum usa Static
		
		double x = (this.x + v2.x);
		double y = (this.y + v2.y);
		
		
		this.x = x;
		this.y = y;
		
	}
	
	
	public static Vetor soma2(Vetor v1, Vetor v2) { //Métodos static pertencem à classe e não ao objeto. Veja que a chamada na main é Vetor.método() p soma1 é diferente, o objeto v1 é a o objeto já criado a partir da classe Vetor. Então usamos v1.soma() na mains
	//public faz com que esse método possa ser chamado dentro de qualquer outra classe
		double x = (v1.x + v2.x);
		double y = (v1.y + v2.y);
		
		
		Vetor novo_vetor = new Vetor(x,y);
		return novo_vetor;
		
		
	}
	
		
}
