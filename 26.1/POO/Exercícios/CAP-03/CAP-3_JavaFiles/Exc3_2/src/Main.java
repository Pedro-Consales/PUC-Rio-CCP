public class Main{
	
	public double obtemPi(int n) {
		return Matematica.pi(n);
	}
	
	
	public static void main(String[] args) {
		
		double piiii = obtemPi(5);
		
		
		
		
	}
	
	
}

//O código não compila porque o método obtemPi não é static.
//O método main é static, portanto pertence à classe e não a um objeto. Por isso eu posso rodar //sem criar um anova instancia
//
//Métodos que não são static pertencem a uma instância da classe,
//então precisam de um objeto criado para serem chamados.
//
//Como não existe um objeto Main dentro de main(), o compilador
//não sabe qual instância deve executar obtemPi().
//
//Para funcionar sem erro seria necessário criar um objeto:
//
//Main m = new Main();
//double p = m.obtemPi(5);
//
//Alternativamente, poderíamos declarar obtemPi como static. (muito melhor)