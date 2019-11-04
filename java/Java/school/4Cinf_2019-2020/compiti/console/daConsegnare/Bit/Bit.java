
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

    public getState(){return state;}

    public setState(boolean in) {
        state = in;
    }

    public void and(){}

}
