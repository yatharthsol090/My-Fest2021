package JAVA.miniProjects;

/**
 * This calculator only calculates the gross typing speed in words per minute.
 * This program won't consider the wrong words penalty.
 *
 */

import java.io.IOException;
import java.util.Scanner;

public class typingSpeed {

    // This methods add the "press enter to continue" functionality.
    private static void pressAnyKeyToContinue() {
        System.out.print("Press Enter(only) key to continue...");
        try
        {
            System.in.read();
        }
        catch(IOException e){
            System.out.println(e);
        }
    }

    //This method gives the basic info to how to use the program to the user.
    public static void infoForUser(){
        System.out.println("---------------------------------------------------------------------------------------------------------------");
        System.out.println("|   • Welcome!!!!!                                                                                            |");
        System.out.println("|   • Here you can calculate your typing speed.                                                               |");
        System.out.println("|   • You just have to type a short sentence of at least 40 letters after the timer (3..2..1..go!.).          |");
        System.out.println("|   • It is advised to type \"The quick brown fox jumps over the lazy dog\" as it contains all the letters.     |");
        System.out.println("|   • After completing the typing press enter to finish.                                                      |");
        System.out.println("---------------------------------------------------------------------------------------------------------------\n");
    }


    //This method is called if letter enters by the user were less than needed to calculate the typing speed.
    public static void ifLessWords(){
        System.out.println("You need to enter at least 40 characters to get accurate results");
    }


    //This method is called if everything went right and print the typing speed.
    public static void finalSpeed(long stopTime, long startTime,int length){
        long reaction = (stopTime - startTime)/1000;
        float reactionInMinutes = reaction/60F;
        int speed =(int)((length/5)/reactionInMinutes);
        System.out.println("\nYour typing speed was "+speed+" WPM");
    }

    //This is the main method which calls other methods according to the needs.
    //Call this method in the "main" to run the program.
    public static void main() throws InterruptedException{
        //calling this method to print the basic info.
        infoForUser();
        //Calling this method to add the "press enter to continue" functionality.
        pressAnyKeyToContinue();

        //Starting the countdown.
        /////////////////////////////////////////
        System.out.println("1");
        Thread.sleep(1000);
        System.out.println("2");
        Thread.sleep(1000);
        System.out.println("3");
        Thread.sleep(1000);
        System.out.println("ref: \"The quick brown fox jumps over the lazy dog\"");
        System.out.println("GO!!!!!!");
        ////////////////////////////////////////

        Scanner scan = new Scanner(System.in);

        //Taking the input from user and noting the start time and end time.
        long startTime = System.currentTimeMillis();
        System.out.println("Start typing!!");
        String phrase = scan.nextLine();
        long stopTime = System.currentTimeMillis();

        //Calculating no. of the characters entered by the user.
        int length = phrase.length();

        //Running this if condition if rules were not followed and user entered the less characters.
        if(length<40){
            ifLessWords();
            System.out.println("Enter \"y/Y\" to continue or \"n/N\" to exit");
            String yN = scan.next();
            //If "Y" is entered, calling the main method again to re run the program.
            if(yN.equals("y") || yN.equals("Y")){
                main();
            }
            //If entered "N", then ending the program.
            else if(yN.equals("n") || yN.equals("N")) {
                System.out.println("Exiting.......");
                System.exit(0);
            }
        }

        //If everything went right then calling this method for final result and to print it, in this else statement.
        else {
            finalSpeed(stopTime, startTime, length);
        }
    }

    public static void main(String[] args) throws InterruptedException{
        //calling the main() to run the program.
        main();
    }
}
