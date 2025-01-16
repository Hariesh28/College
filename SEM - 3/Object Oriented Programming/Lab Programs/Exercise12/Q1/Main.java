package Exercise12.Q1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("My Frame :)");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 400);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(9, 1));

        JCheckBox[] checkBoxes = new JCheckBox[7];
        for (int i = 1; i <= 7; i++) {
            checkBoxes[i - 1] = new JCheckBox("Checkbox " + i);
            panel.add(checkBoxes[i - 1]);
        }

        ButtonGroup group = new ButtonGroup();
        JRadioButton[] radioButtons = new JRadioButton[7];
        for (int i = 1; i <= 7; i++) {
            radioButtons[i - 1] = new JRadioButton("Option " + i);
            group.add(radioButtons[i - 1]);
            panel.add(radioButtons[i - 1]);
        }

        JButton button = new JButton("Show Selected");
        panel.add(button);

        JTextField textField = new JTextField();
        panel.add(textField);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                StringBuilder selectedNumbers = new StringBuilder("Selected: ");

                for (int i = 0; i < checkBoxes.length; i++) {
                    if (checkBoxes[i].isSelected()) {
                        selectedNumbers.append("Checkbox ").append(i + 1).append(" ");
                    }
                }

                for (int i = 0; i < radioButtons.length; i++) {
                    if (radioButtons[i].isSelected()) {
                        selectedNumbers.append("Option ").append(i + 1).append(" ");
                    }
                }

                textField.setText(selectedNumbers.toString());
            }
        });

        frame.add(panel);
        frame.setVisible(true);
    }
}
