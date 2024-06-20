import jsjf.*;
import java.io.*;
import java.util.*;

public class BackPainAnalyzer
{
    /**
     *  Asks questions of the user to diagnose a medical problem.
     */
    public static void main(String[] args) throws FileNotFoundException
    {
        System.out.println("BackPainAnalyzer Tree");
        System.out.println("So, you're having back pain.");
        
        //The DecisionTree() method creates a tree based on the BackPainTree.Txt file
        System.out.println(" ");
        DecisionTree expert = new DecisionTree("BackPainTree.txt");
        
        //Follows the decision tree based on user responses (Y or N)
        expert.evaluate();
        System.out.println(" ");
        System.out.println("///////////////////////////////////////////////////////");

        
        //Count variable is used to number the nodes that are being printed out.
        int count = 1;

        //Preforms an in order traversal
        System.out.println(" ");
        System.out.println("In Order Traversal" );
        Iterator in = expert.tree.iteratorInOrder();

        while(in.hasNext()){
            System.out.println(count + ". "+(in.next()).toString());
            count++;
        }

        //Performs a post order traversal
        System.out.println(" ");     
        System.out.println("Post Order :" );
        Iterator post = expert.tree.iteratorPostOrder();
        count = 1;//Restarts count

        while(post.hasNext()){
            System.out.println(count + ". "+(post.next()).toString());
            count++;
        }

        //Performs a Pre order traversal
        System.out.println(" ");
        System.out.println("Pre Order :" );
        Iterator pre = expert.tree.iteratorPreOrder();
        count = 1;//Restarts count
        
        while(pre.hasNext()){
            System.out.println(count + ". "+(pre.next()).toString());
            count++;
        }

        //Preforms a level order traversal
        System.out.println(" ");
        System.out.println("Level Order Traversal : " );
        Iterator level = expert.tree.iteratorLevelOrder();
        count = 1;//Restarts count

        while(level.hasNext()){
            System.out.println(count + ". "+(level.next().toString()));
            count++;
        }

        System.out.println(" ");
        System.out.println("///////////////////////////////////////////////////////");

       
    }
}
