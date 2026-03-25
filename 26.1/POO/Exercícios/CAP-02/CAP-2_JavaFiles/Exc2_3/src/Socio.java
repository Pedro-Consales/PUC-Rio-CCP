public class Socio{
	
	String nome;
	String endereco;
	String dt_nasc;
	int matricula;
	
	public Socio(int x) {
		matricula=x;
	}
	
	
	String getMatricula() {
		
		int numerando = (this.matricula)/10;
		int digito = (this.matricula) % 10;
		
		String str_numerando = Integer.toString(numerando);
		String str_digito = Integer.toString(digito);
		
		return str_numerando + '-' + str_digito;
		
	}
	
}