
import java.util.LinkedList;

public class LinkedStack<T> implements StackADT<T>
{

    private LinkedList<T> list;
    private int size;

    //Creates an empty stack
    public LinkedStack(){
        list = new LinkedList<T>();
        size = 0;
    }

    //Adds the specified element to the top of this stack.  
    public void push(T element){
        list.add(element);
        size++;
    }

    //Removes and returns the top element from this stack. 
    public T pop()throws EmptyCollectionException{

       T element;
   
        if(isEmpty()){
         throw new EmptyCollectionException("ArrayStack is empty");
        }else{
            element = list.remove(size-1);
            size--;
        }
        
        return element; 
    }

    //Returns the element at the top of the stack without removing it from the stack. 
    public T peek()throws EmptyCollectionException{

        T element;
        
        if(isEmpty()){
           throw new EmptyCollectionException("ArrayStack is empty");
           
        }else{
            element = list.get(size-1);
        }
        
        return element; 

    }

    // Returns true if this stack contains no elements. 
    public boolean isEmpty(){
        return (size == 0);
    }

    //Returns the number of elements in this stack. 
    public int size(){
        return size;
    }

    //Returns a string representation of this stack.
    public String toString(){

        String result = "Results : ";

        for(int i = 0;i < size;i++){     
            result = result +"\n"+ list.get(i);        
        } 

        return result;
    }
}
