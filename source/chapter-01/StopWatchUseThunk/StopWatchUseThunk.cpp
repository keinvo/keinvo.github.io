// StopWatchUseThunk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#if !defined(PAGE_SIZE)
#define PAGE_SIZE 4096
#endif

#pragma pack(push,1)
struct SimpleThunk
{
    DWORD   m_mov;
    DWORD   m_this;
    BYTE    m_jmp;
    DWORD   m_relproc;
    BOOL Init(DWORD_PTR proc, void *pThis)
    {
        // mov dword ptr [esp+0x04], pThis
        m_mov = 0x042444C7;
        m_this = PtrToUlong(pThis);

        // jmp m_relproc
        m_jmp = 0xe9;
        m_relproc = DWORD((INT_PTR)proc - ((INT_PTR)this+sizeof(SimpleThunk)));

        return TRUE;
    }

    void* operator new(size_t)
    {
        return ::VirtualAlloc(NULL, PAGE_SIZE, MEM_RESERVE|MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    }
    void operator delete(void* p)
    {
        ::VirtualFree(p, 0, MEM_RELEASE);
    }
};
#pragma pack(pop)

class CStopWatch
{
public:
    CStopWatch()
        : m_uValue(0)
        , m_hWnd(NULL)
    { 
        m_pThunk = new SimpleThunk();
        m_pThunk->Init((DWORD_PTR)TimerProc, this);
    }

    ~CStopWatch() { delete m_pThunk; }

public:
    void Start()
    {
        TIMERPROC proc = (TIMERPROC)m_pThunk;
        m_hWnd = NULL;
        ::SetTimer(m_hWnd, 0, 1000, proc); // 创建一个间隔1s的定时器
    }

protected:
    void AddValue(){ m_uValue ++; }

    void Show(){ std::cout << m_uValue << std::endl; }

    static void CALLBACK TimerProc(HWND hWnd, UINT uMsg, 
        UINT iTimerID, DWORD dwTime, DWORD_PTR This)
    {
        CStopWatch *pThis = (CStopWatch*)hWnd;
        {
            pThis->AddValue();
            pThis->Show();
        }
    }

protected:
    unsigned int m_uValue;
    HWND m_hWnd;
    SimpleThunk *m_pThunk;
};

int _tmain(int argc, _TCHAR* argv[])
{
    CStopWatch watch;
    watch.Start();

    MSG msg;
    while(GetMessage(&msg,NULL,0,0))
    {
        if(msg.message==WM_TIMER)
        {
            DispatchMessage(&msg);
        }
    }

    return 0;
}