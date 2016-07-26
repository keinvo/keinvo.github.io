template <class T>  
class CSingleton  
{  
public:  
       static inline T* Instance();       
private:  
       CSingleton(void){}   
       ~CSingleton(void){}  
  
       CSingleton(const CSingleton&){}   
       CSingleton & operator= (const CSingleton &){}   
  
       static auto_ptr<T> _instance;  
       static CQuickLock _rs;   
};  
  
template <class T>  
auto_ptr<T> CSingleton<T>::_instance;  
  
template <class T>  
CQuickLock CSingleton<T>::_rs;   

template <class T>  
inline T* CSingleton<T>::Instance()  
{  
  
    if( 0 == _instance.get() )  
    {  
    //CScopedLock lock(_rs);   
          if( 0== _instance.get())  
          {  
               _instance.reset ( new T);  
          }  
    }  
    return _instance.get();  
}  
