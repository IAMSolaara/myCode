/**
@author Lorenzo Cauli
@version 1.0
 */

/*
  - character: char
  + caseOffset: int

  + Lettera(in c: char)
  + Lettera(in ref: Lettera)

  + getCharacter(): char
  + isMaiuscolo(): boolean

  - compreso(in x, min, max: char): boolean
  + switchCase(): void
  + toString(): String
  + equals(in o: Object): boolean

 */

public class LetteraSpeciale {
    private char character;

    public LetteraSpeciale(char in) {
	if (!compreso(in, 'A', 'Z') && !compreso(in, 'a', 'z')) character = in;
	else character = ' ';
    }

    public LetteraSpeciale(LetteraSpeciale in){
	if (ref != null) character = ref.getCharacter();
	else character = ' ';
    }

    public char getCharacter(){return character;}

    public boolean isSpecial(){
	boolean out = true;
	if (compreso(character, ' ', '~')) out = false;
	return out;
    }

    public boolean isNumber(){
	boolean out = true;
	if (!compreso(character, '0', '9')) out = false;
	return out;
    }

    public boolean isSymbol(){
	boolean out = true;
	if 
    }
}
