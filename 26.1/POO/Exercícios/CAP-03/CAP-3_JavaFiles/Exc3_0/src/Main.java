public class Main{
	
	
	public static void main(String[] args) {
		
		
		Vetor v1 = new Vetor(3,4);
		Vetor v2 = new Vetor(7,6);
		
		
		System.out.println("========= Versão 1 -> soma dois vetores v1 e v2 e guarda em v1 =========== \n\n");
		
		//Versão 1
		System.out.println("Vetor 1: ");
		v1.exibe();
		System.out.println("Vetor 2: ");
		v2.exibe();
	
		v1.soma1(v2); //Método calcula a soma vetoria de v1 com v2
		System.out.println("Após a soma do vetor 1 com vetor 2");
		
		System.out.println("Vetor 1: ");
		v1.exibe();
		System.out.println("Vetor 2: ");
		v2.exibe();
		
		
		System.out.println("\n\n========= Versão 1 -> soma dois vetores v1 e v2 e guarda em v1 =========== \n\n");
		
		
		
		
		
		System.out.println("\n\n========= Versão 2 -> soma dois vetores v1 e v2 e retorna um novo vetor =========== \n\n");
		
		//Versão 2
		
		Vetor v3 = Vetor.soma2(v1, v2);
		
		System.out.println("Vetor 3: ");
		v3.exibe();
		
		
		
		

		System.out.println("\n\n========= Versão 2 -> soma dois vetores v1 e v2 e retorna um novo vetor =========== \n\n");
		

	}
	
	
	
	
	
}
