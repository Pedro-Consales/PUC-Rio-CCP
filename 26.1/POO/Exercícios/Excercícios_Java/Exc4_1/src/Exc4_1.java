
public class Exc4_1 {
	
	public static void main(String[] args) {
		
		C o=new C(5);
		o.exibe();
		
	}

	
}

//1) O que será exibido no console quando o método main() for executado? Ilustre
//a sua resposta descrevendo, passo-a-passo, o que o programa irá executar

//EXPLICAÇÃO PASSO A PASSO DA ORDEM DE INICIALIZAÇÃO
//Exercício 4.1

//Hierarquia de classes

//Object
//↑
//A
//↑
//B
//↑
//C


//O programa executa:

//C o = new C(5);


//--------------------------------------------------
//PASSO 1 — chamada do construtor de C
//--------------------------------------------------

//Quando new C(5) é executado, o construtor de C começa.
//Porém, antes de executar o corpo do construtor, Java
//automaticamente chama o construtor da classe pai.

//public C(int c) {
//  super();   // inserido automaticamente
//  x += c;
//  y *= c;
//}


//--------------------------------------------------
//PASSO 2 — chamada do construtor de B
//--------------------------------------------------

//O construtor de B também chama automaticamente
//o construtor da sua classe pai.

//public B() {
//  super();   // inserido automaticamente
//  x *= 2;
//  y *= 2;
//}


//--------------------------------------------------
//PASSO 3 — chamada do construtor de A
//--------------------------------------------------

//public A() {
//  super();   // chama Object()
//  x *= x;
//  y *= y;
//}


//--------------------------------------------------
//PASSO 4 — inicialização das variáveis
//--------------------------------------------------

//Antes de qualquer construtor executar, as variáveis
//recebem os valores padrão:

//x = 0
//y = 0


//--------------------------------------------------
//PASSO 5 — bloco de inicialização da classe A
//--------------------------------------------------

//{
//  x += 10;
//  y += 10;
//}

//x = 10
//y = 10


//--------------------------------------------------
//PASSO 6 — execução do construtor de A
//--------------------------------------------------

//x *= x
//y *= y

//x = 10 * 10 = 100
//y = 10 * 10 = 100


//--------------------------------------------------
//PASSO 7 — retorno para o construtor de B
//--------------------------------------------------

//x *= 2
//y *= 2

//x = 200
//y = 200


//--------------------------------------------------
//PASSO 8 — retorno para o construtor de C
//--------------------------------------------------

//x += 5
//y *= 5

//x = 205
//y = 1000


//--------------------------------------------------
//RESULTADO FINAL
//--------------------------------------------------

//o.exibe();

//x = 205
//y = 1000





// 2) Mova o bloco de inicialização da classe A para a classe C e reexecute o método
// main(). O que será exibido? Ilustre a sua resposta descrevendo, passo-apasso, o que o programa irá executar.

//EXPLICAÇÃO PASSO A PASSO — QUESTÃO 2
//(bloco de inicialização movido da classe A para a classe C)

//Hierarquia das classes

//Object
//↑
//A
//↑
//B
//↑
//C

//O programa executa:

//C o = new C(5);


//--------------------------------------------------
//PASSO 1 — criação do objeto
//--------------------------------------------------

//Quando new C(5) é executado, Java inicia a construção
//do objeto começando pela classe mais acima da hierarquia.

//Mesmo que não apareça no código, todo construtor chama
//automaticamente super() antes de executar seu próprio corpo.


//--------------------------------------------------
//PASSO 2 — valores iniciais das variáveis
//--------------------------------------------------

//Antes de qualquer construtor ou bloco executar,
//Java inicializa as variáveis de instância com valores default.

//x = 0
//y = 0


//--------------------------------------------------
//PASSO 3 — construtor da classe A
//--------------------------------------------------

//public A() {
//  x *= x;
//  y *= y;
//}

//x = 0 * 0 = 0
//y = 0 * 0 = 0

//valores continuam:

//x = 0
//y = 0


//--------------------------------------------------
//PASSO 4 — construtor da classe B
//--------------------------------------------------

//public B() {
//  x *= 2;
//  y *= 2;
//}

//x = 0 * 2 = 0
//y = 0 * 2 = 0

//valores continuam:

//x = 0
//y = 0


//--------------------------------------------------
//PASSO 5 — bloco de inicialização da classe C
//--------------------------------------------------

//{
//  x += 10;
//  y += 10;
//}

//x = 0 + 10 = 10
//y = 0 + 10 = 10


//--------------------------------------------------
//PASSO 6 — construtor da classe C
//--------------------------------------------------

//public C(int c) {
//  x += c;
//  y *= c;
//}

//c = 5

//x = 10 + 5 = 15
//y = 10 * 5 = 50


//--------------------------------------------------
//RESULTADO FINAL
//--------------------------------------------------

//o.exibe();

//x = 15
//y = 50

