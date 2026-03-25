
public class Xpto {

	static int contInst;
	
	public Xpto() {
		contInst += 1;
	}
	
	 static int getQtdInst() {
		return contInst;
	}
	
	
}
