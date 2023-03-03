package Lesson2;

import java.util.Scanner;

public class ComputeLoan {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter annual interest rate , e.g., 7.25: ");
        double annualInterestRate = input.nextDouble();
        double monthlyInterestRate = annualInterestRate / 1200;
        System.out.print("Enter number of years as an integer , e.g., 5: ");
        int numberOfYears = input.nextInt();
        System.out.print("Enter loan amount , e.g., 120000.95: ");
        double loanAmount = input.nextDouble();
        double monthLyPayment = loanAmount * monthlyInterestRate
                / (1 - 1 / Math.pow(1 + monthlyInterestRate, numberOfYears * 12));
        double totalPayment = monthLyPayment * numberOfYears * 12;
        System.out.println("The monthly payment is $" + (int) (monthLyPayment * 100) / 100.0);
        System.out.println("The monthly payment is $" + (int) (totalPayment * 100) / 100.0);
        input.close();
    }
}
