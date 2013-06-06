
public class CallThirdParty {
      
      public native int[] CallThirdPartyDll(double[]    arg_DoubleArray, 
    		  								int         arg_SizeofArray,
                                            boolean     arg_print);
      static
      {
          System.loadLibrary("MediumDll");
      }
}