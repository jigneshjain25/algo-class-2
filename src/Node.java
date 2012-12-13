import java.util.ArrayList;


public class Node implements Comparable<Node>{
	/* denoting vertex is spanned or not
	 * 0 spanned
	 * 1 not spanned
	 */
     int status=1;
	
	//prims key
	 int key=Integer.MAX_VALUE;
	 
	 int no;
	
	 ArrayList<Integer> adj= new ArrayList<Integer>();
	 ArrayList<Integer> weight= new ArrayList<Integer>();
	 
	 public Node(int n)
	 {
		 no=n;
	 }
	
	@Override
	public int compareTo(Node o) {
		if(this.key > o.key)
			return 1;
		else if(this.key < o.key)
			return -1;
		return 0;
	}
	
}
