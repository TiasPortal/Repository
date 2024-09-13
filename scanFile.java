import java.io.*; 
import java.util.*;

public class ScanFile {

    public static void main(String[] args) throws IOException {

        try{
            //creates input file, output file, scanner, printWriter, and the array lists titles and duplicates
            File inFile = new File("bookTitles.inp.txt");
            String outName = "duplicateTitles.out.txt";
            PrintWriter outFile = new PrintWriter(outName);
            Scanner scan = new Scanner(inFile);
            List titles = new ArrayList <String>(); //List for all titles
            List duplicates = new ArrayList <String>();// list for only duplicates
            
            //Scans the input file and adds every title to the array.
            while(scan.hasNext()){
                titles.add(scan.nextLine());
            }

            //For loop checks whether the titles are equal to eachother and checks whether they have already been checked
            //if the title has not been checked before it is added to the duplicates list and printed to the outFile.
            for(int i = 0; i < titles.size(); i ++){
                for(int j = i+1; j < titles.size(); j++){
                    if(titles.get(i).equals(titles.get(j))&&!(duplicates.contains(titles.get(i)))){
                        duplicates.add(titles.get(i));
                        outFile.print(titles.get(i)+"\n");

                    }  
                }
            }
            
            outFile.close();

        } catch(FileNotFoundException e){
            System.out.println("file not found");
        }

    }
}
