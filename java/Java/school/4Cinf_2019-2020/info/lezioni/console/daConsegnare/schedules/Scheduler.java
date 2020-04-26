import java.io.*;
import java.util.Scanner;

public class Scheduler {
    private CodaAttraversabile ready;
    private Processo execProc;
    private int nextPid, quanto;

    public Scheduler (int qnt) {
        if (qnt >0) {
            quanto = qnt;
        }
        else quanto = 3;
        execProc = null;
        ready = new CodaAttraversabile();
        nextPid = 1;
    }

    public void readFromFile(String name) throws FileNotFoundException, NullPointerException{
        Scanner s;
        File f;
        try{
            f = new File(name);
            s=new Scanner(f);

        }
        catch(FileNotFoundException e) {
            throw new FileNotFoundException("File non trovato");
        }
        catch(NullPointerException e) {
            throw new NullPointerException("UsAGE: WIP");
        }
    }

    public int getQuanto(){return quanto;}

    public Processo getExecProc(){return new Processo(execProc);}

    public String listReadyProc(){return ready.toString();}

    public String toString(){
        String s = "Quanto CPU: "+ quanto + "\n";
        if (execProc != null) s+= "Processo in esecuzione: "+ execProc.toString() + "\n";
        else s += "Nessun processo in esecuzione\n";

        s += "Prossimo PID: " + nextPid + "\n";
        s += "Processi pronti: \n" + ready.toString();
        return s;
    }
}
