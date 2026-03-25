public class Main {
	
	public static void main(String[] args) {
			
			new Xpto();
			new Xpto();
			new Xpto();
			
			System.out.printf("Qtd de instâncias criadas: %d", Xpto.contInst);
			
	}
		
	
}


//Minha dúvida: Eu to criadno 3 objetos, mas onde o meu sistema busca o valor de contInst = 3?
//Cada um dos 3 objetos tem o conInst = 3? Onde ele busca essa informação na memória


//Resposta: Java(JVM) cria a área da classe que o JVM trata variáveis static como atributos da classe e não do objeto
//Exemplo visual:

//Área da CLASSE (metadados da JVM)
//┌─────────────────────┐
//│ Classe Xpto         │
//│ contInst = 3        │   ← variável static
//└─────────────────────┘
//
//
//Heap (OBJETOS)
//┌───────────┐
//│ objeto a  │
//│           │
//└───────────┘
//
//┌───────────┐
//│ objeto b  │
//│           │
//└───────────┘
//
//┌───────────┐
//│ objeto c  │
//│           │
//└───────────┘

//