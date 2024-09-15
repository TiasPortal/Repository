
public class DecisionTree
{

    //Changed to public
    public static LinkedBinaryTree<String> tree;

    public DecisionTree(String filename) throws FileNotFoundException
    {
        File inputFile = new File(filename);
        Scanner scan = new Scanner(inputFile);
        int numberNodes = scan.nextInt();
        scan.nextLine();
        int root = 0, left, right;

        List<LinkedBinaryTree<String>> nodes = new java.util.ArrayList<LinkedBinaryTree<String>>();

        for (int i = 0; i < numberNodes; i++){
            nodes.add(i, new LinkedBinaryTree<String>(scan.nextLine()));
        }

        while (scan.hasNext()){
            root = scan.nextInt();
            left = scan.nextInt();
            right = scan.nextInt();

            scan.nextLine();
            nodes.set(root, new LinkedBinaryTree<String>((nodes.get(root)).getRootElement(), nodes.get(left), nodes.get(right)));

        }

        tree = nodes.get(root);
    }

    /**
     *  Follows the decision tree based on user responses.
     */
    public void evaluate()
    {
        LinkedBinaryTree<String> current = tree;
        Scanner scan = new Scanner(System.in);

        while (current.size() > 1)
        {
            System.out.println(current.getRootElement());
            if (scan.nextLine().equalsIgnoreCase("N"))
                current = current.getLeft();
            else
                current = current.getRight();
        }

        System.out.println(current.getRootElement());
    }
}
