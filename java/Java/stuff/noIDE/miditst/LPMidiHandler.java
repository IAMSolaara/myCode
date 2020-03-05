import java.util.Scanner;
import java.util.List;
import javax.sound.midi.*;
import java.io.*;

public class LPMidiHandler {
    private MidiDevice launchpad;
    private MidiDevice loopMidi;

    public LPMidiHandler() {
        setLaunchpad();
        setLoopMidi();

    }

    public void getDevices() {
        System.out.println(launchpad.getDeviceInfo());
        System.out.println(loopMidi.getDeviceInfo());
    }

    private void setLaunchpad() {
        try {
            MidiDevice.Info[] midiInfo = MidiSystem.getMidiDeviceInfo();
            for (int i = 0; i < midiInfo.length; i++) {
                System.out.println("Device #" + i + ": " + midiInfo[i].getName());
            }
            Scanner sc = new Scanner(System.in);
            System.out.println("Which device is the launchpad? [0-" + (midiInfo.length - 1) + "]");
            int choice = sc.nextInt();
            if (choice < 0 || choice >= midiInfo.length) {
                System.out.println("Bad choice");
                System.exit(0);
            } else {
                launchpad = MidiSystem.getMidiDevice(midiInfo[choice]);
            }
        } catch (MidiUnavailableException ex) {
            ex.printStackTrace();
        }
    }

    private void setLoopMidi() {
        try {
            MidiDevice.Info[] midiInfo = MidiSystem.getMidiDeviceInfo();
            for (int i = 0; i < midiInfo.length; i++) {
                System.out.println("Device #" + i + ": " + midiInfo[i].getName());
            }
            Scanner sc = new Scanner(System.in);
            System.out.println("Which device is the loop port? [0-" + (midiInfo.length - 1) + "]");
            int choice = sc.nextInt();
            if (choice < 0 || choice >= midiInfo.length) {
                System.out.println("Bad choice");
                System.exit(-1);
            } else {
                loopMidi = MidiSystem.getMidiDevice(midiInfo[choice]);
            }
        } catch (MidiUnavailableException ex) {
            ex.printStackTrace();
        }
    }

    public void openDevices() {
        try {
            launchpad.open();
            loopMidi.open();
        }

        catch (Exception ex) {
            ex.printStackTrace();
            System.exit(-2);
        }
    }

    public void closeDevices() {
        try {
            launchpad.close();
            loopMidi.close();
        }

        catch (Exception ex) {
            ex.printStackTrace();
            System.exit(-2);
        }
    }


    public void testNotes() {
        try {
            Receiver test = launchpad.getReceiver();
           
        } catch (Exception ex) {
            ex.printStackTrace();
            System.exit(-3);
        }
    }

    public static void main(String[] args) {
        LPMidiHandler test = new LPMidiHandler();
        //test.getDevices();
        test.openDevices();
        test.testNotes();
        test.closeDevices();
    }
}
