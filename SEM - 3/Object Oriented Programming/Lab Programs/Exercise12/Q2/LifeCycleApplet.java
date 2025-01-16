package Exercise12.Q2;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

public class LifeCycleApplet extends Applet {
    
    @Override
    public void init() {
        // Initialization code
        System.out.println("Applet is initializing...");
        // Set background color
        setBackground(Color.LIGHT_GRAY);
    }
    
    @Override
    public void start() {
        // Code to start the applet
        System.out.println("Applet is starting...");
    }
    
    @Override
    public void paint(Graphics g) {
        // Drawing code
        g.drawString("Welcome to the Applet Life Cycle Demo", 20, 20);
    }
    
    @Override
    public void stop() {
        // Code to stop the applet
        System.out.println("Applet is stopping...");
    }
    
    @Override
    public void destroy() {
        // Code to clean up resources
        System.out.println("Applet is being destroyed...");
    }
}
