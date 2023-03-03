package Lesson2;

import java.util.Scanner;

public class FahrenheitTocelsius {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a degree int Fahrenheit: ");
        double fahrenheit = input.nextDouble();
        double celsius = (5.0 / 9) * (fahrenheit - 32);
        System.out.println("Fahrenheit " + fahrenheit + " is " + celsius + " in Celsius");
        input.close();
    }
}
