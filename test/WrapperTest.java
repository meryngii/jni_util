
public class WrapperTest extends NativeWrapper
{
    public WrapperTest() {
        init();
    }
    
    private native void init();
    
    public native void put(int x);

    public native void show();
    
    public native void destroy();
}

