/**
 *	@author Lorenzo Cauli
 *	@version 0.1
 */

/*
 - state: boolean
 
 + Bit()
 + Bit(in in: boolean)
 + Bit(in in: Bit)
 
 + getState(): boolean
 + setState(): void

 + and(in b2: Bit): Bit
 
 */

public class Bit{
    private boolean state;

    public Bit(){
        state = true;
    }

    public Bit(boolean in){
        state = in;
    }

    public Bit(Bit in) {
        if (in != null) {
            state = in.getState();
        }
        else state = true;
    }

    public boolean getState(){return state;}

    public void setState(boolean in) {
        state = in;
    }

    public Bit and(Bit b2){
		Bit out;
		if (b2 != null) out = new Bit(state & b2.getState());
		else out = null;
		return out;
	}

    public Bit not(){
		return new Bit(!state);
	}

    public Bit or(Bit b2){
		Bit out;
		if (b2 != null) out = new Bit(state | b2.getState());
		else out = null;
		return out;
	}

}
