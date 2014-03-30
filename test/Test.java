
public class Test
{
    static {
        System.loadLibrary("test");
    }

    public static void main(String[] argv) {
        Test test = new Test();
        test.showString("abc");
        test.showIntArray(new int[] {1, 2, 3});
    }

    public native void showString(String test);
    
    public native void showIntArray(int[] test);
}

