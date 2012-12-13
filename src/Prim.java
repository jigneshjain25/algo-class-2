import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.PriorityQueue;


public class Prim {
	public static void main(String[] args) {
		long startTime = System.nanoTime();
		
		int n = 0,m,x,y,z;
		Node Nodes[] = null;
		String line,result[];
		try {
			BufferedReader br = new BufferedReader(new FileReader("edges_big.txt"));
			line=br.readLine();
			result=line.split(" ");
			
			n=Integer.parseInt(result[0]);
			Nodes = new Node[n];
			for(int i=0;i<n;i++)
				Nodes[i]=new Node(i+1);
			
			m=Integer.parseInt(result[1]);
			
			while((line=br.readLine())!=null){
				result=line.split(" ");
				x=Integer.parseInt(result[0]);
				y=Integer.parseInt(result[1]);
				z=Integer.parseInt(result[2]);
				//System.out.println(x+" "+y+" "+z);
				Nodes[x-1].adj.add(y);
				Nodes[y-1].adj.add(x);
				Nodes[x-1].weight.add(z);
				Nodes[y-1].weight.add(z);
				
			}
		
			/*int c=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<Nodes[i].adj.size();j++){
					System.out.println((i+1)+" "+Nodes[i].adj.get(j)+" "+weight[i][Nodes[i].adj.get(j)-1]);
					c++;
				}
			System.out.println(c);*/
			
			} catch (Exception e) {
			System.out.println("Error opening the input file");
			e.printStackTrace();
		}
		
		int st=7;
		Nodes[st].status=0;
		
		for(int i=0;i<Nodes[st].adj.size();i++)
			if(Nodes[st].weight.get(i) < Nodes[Nodes[st].adj.get(i)-1].key)
				Nodes[Nodes[st].adj.get(i)-1].key = Nodes[st].weight.get(i);
				
		PriorityQueue<Node> heap = new PriorityQueue<Node>();
		for(int i=0;i<n;i++)
			if(i!=st)
				heap.add(Nodes[i]);
		
		long ans=0;
		while(!heap.isEmpty())
		{
			Node temp = heap.remove();
			ans+=temp.key;
			temp.status=0;
			temp.key=Integer.MAX_VALUE;
			
			for(int i=0;i<temp.adj.size();i++)
				if(Nodes[temp.adj.get(i)-1].status==1 &&  Nodes[temp.no-1].weight.get(i) < Nodes[temp.adj.get(i)-1].key)
				{
					heap.remove(Nodes[temp.adj.get(i)-1]);
					Nodes[temp.adj.get(i)-1].key = Nodes[temp.no-1].weight.get(i);
					heap.add(Nodes[temp.adj.get(i)-1]);
				}
					
		}
		
		System.out.println(ans);
		long endTime = System.nanoTime();
		double ns=((double)endTime-(double)startTime)/(double)1000000000;
		System.out.println("Took "+ns + " s"); 
	}

}
