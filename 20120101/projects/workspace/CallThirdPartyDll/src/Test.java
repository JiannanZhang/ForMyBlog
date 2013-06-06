
public class Test {
     public static void main(String[] args) {
    	 
         double doubleArray[] = {1.1, 2.5, 5,2};
         
         CallThirdParty callThirdParty = new CallThirdParty();
         int cutOffArray[] = callThirdParty.CallThirdPartyDll(doubleArray, 3, true);
         
         for (int i = 0; i < cutOffArray.length; ++i)
        	 System.out.println(cutOffArray[i]);
     }
}