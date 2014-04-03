
public abstract class NativeWrapper
{
    private long mHandle = 0;
    
    public abstract void destroy();
    
    @Override
    protected void finalize() throws Throwable
    {
        destroy();
        
        super.finalize();
    }
}

