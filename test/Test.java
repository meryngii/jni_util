
public class Test
{
    static {
        System.loadLibrary("test");
    }

    public static void main(String[] argv) {
        Test test = new Test();
        test.showString("abc");
        test.showIntArray(new int[] {1, 2, 3});
    
        test.testWrapper();
    }

    public void testWrapper() {
        WrapperTest wrapperTest = new WrapperTest();

        wrapperTest.put(111);
        wrapperTest.put(222);
        wrapperTest.put(333);
        wrapperTest.show();
        
        // It is very important to destroy native object explicitly
        // because sometimes the finalizers are not called if an object is collected by GC.
        wrapperTest.destroy();
    }

    public native void showString(String test);
    
    public native void showIntArray(int[] test);
}

