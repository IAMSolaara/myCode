/**
 * @author Lorenzo Cauli
 * @version Molto.0
 */

//molti tanti import
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.TimerTask;
import java.util.Timer;

public class GUI {
    public static boolean ran = false;
    public static void main(String[] args) {
        try {
            // declare scheduler
            Scheduler s = new Scheduler(2);

            // declare oggetto finestro
            JFrame mainWin = new JFrame("PROCESSY");
            // setta dimensiona
            mainWin.setSize(1024, 768);
            // operazione da fare quando si preme il pulsantino carino ics
            mainWin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            // pannello a sinistra che lancha i processi
            JPanel lPanel = new JPanel();
            lPanel.setSize(new Dimension(100,mainWin.getHeight()));
            lPanel.setLocation(0, 0);
            lPanel.setBorder(BorderFactory.createLineBorder(Color.black));

            //pannello a destra per vedere l'ecose
            JPanel rPanel = new JPanel();
            rPanel.setSize(new Dimension(mainWin.getWidth() - lPanel.getWidth(), mainWin.getHeight()));
            rPanel.setLocation(lPanel.getWidth(), 0);
            //disattivare layoutmanager per manovrare dimensione e posizione dei panel dentro rPanel
            rPanel.setLayout(null);
            //impostazione bordo carino
            rPanel.setBorder(BorderFactory.createLineBorder(Color.red));

            //pannello processo in esecuzione
            JPanel runningPanel = new ProcessesPanel();
            //impostazione dimensioni e postazione
            runningPanel.setSize(new Dimension(rPanel.getWidth(), 100));
            runningPanel.setLocation(0,rPanel.getHeight()-runningPanel.getHeight());
            //impostazione bordo carino con titolo Running
            runningPanel.setBorder(BorderFactory.createTitledBorder("Running"));

            //pannello coda processi
            JPanel queuePanel = new ProcessesPanel();
            //impostazione dimensioni e postazione
            queuePanel.setSize(new Dimension(rPanel.getWidth(), rPanel.getHeight() - runningPanel.getHeight()));
            queuePanel.setBorder(BorderFactory.createTitledBorder("Queue"));

            //aggiunta pannelli coda e esecuzione in pannello destro
            rPanel.add(BorderLayout.NORTH, queuePanel);
            rPanel.add(BorderLayout.SOUTH, runningPanel);

            // pulsante per avviare le cose
            JButton runBtn = new JButton("Run");
            // actionlistener per avviare le cose
            runBtn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    // creazione oggetto thread
                    if (!ran) {
                        new Thread() {
                            // creazione classe task
                            class Task extends TimerTask {
                                // run task
                                public void run() {
                                    try {
                                        // exec dello scheduler
                                        s.exec();
                                        // aggiorna pannello processo esecuzione
                                        ((ProcessesPanel) runningPanel).update(s.getExecProc());
                                        // aggiorna pannello processi in coda
                                        ((ProcessesPanel) queuePanel).update(s.getReadyProcesses());
                                    } catch (InterruptedException ex) {
                                        ex.printStackTrace();
                                    }
                                }
                            }

                            // run thread
                            public void run() {
                                ran = true;
                                Timer ti = new Timer();
                                ti.schedule(new Task(), 1, 500);
                            }
                        }.start();
                    }
                }
            });
            //aggiunta pulsante avvio a pannello sinistro
            lPanel.add(runBtn);

            //pulsanti per processi di demo
            //firefox
            JButton firefoxBtn = new JButton(new ImageIcon(new ImageIcon("./firefox.png", "Firefox").getImage().getScaledInstance(64, 64, Image.SCALE_DEFAULT)));
            firefoxBtn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    s.addProcess("Firefox", 9);
                    ((ProcessesPanel)queuePanel).update(s.getReadyProcesses());
                }
            });
            lPanel.add(firefoxBtn);
            
            //vscode
            JButton vscBtn = new JButton(new ImageIcon(new ImageIcon("./VSCode.png", "VSCode").getImage().getScaledInstance(64, 64, Image.SCALE_DEFAULT)));
            vscBtn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    s.addProcess("VSCode", 6);
                    ((ProcessesPanel)queuePanel).update(s.getReadyProcesses());
                }
            });
            lPanel.add(vscBtn);
            
            //minecraft
            JButton mcBtn = new JButton(new ImageIcon(new ImageIcon("./minecraft.png", "MineCraft").getImage().getScaledInstance(64, 64, Image.SCALE_DEFAULT)));
            mcBtn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    s.addProcess("MineCraft", 12);
                    ((ProcessesPanel)queuePanel).update(s.getReadyProcesses());
                }
            });
            lPanel.add(mcBtn);

            //aggiunge lPanel alla finestra principale
            mainWin.getContentPane().add(lPanel);
            //aggiunge rPanel alla finestra principale
            mainWin.getContentPane().add(rPanel);
            //disattiva layout manager finestra principale
            mainWin.getContentPane().setLayout(null);
            //DIAMO IL VIA ALLE DANZE
            mainWin.setVisible(true);

        } catch (NullPointerException e) {
            System.out.println(e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("USAGE: java Test <nomeFile>");
        }
    }
}
