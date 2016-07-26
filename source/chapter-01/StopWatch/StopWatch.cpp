// StopWatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

class CStopWatch
{
public:
    CStopWatch()
        : m_uValue(0){}

public:
    void Start()
    {
        s_pThis = this;
        ::SetTimer(NULL, 0, 1000, TimerProc); // 创建一个间隔1s的定时器
    }

protected:
    void AddValue(){ m_uValue ++; }

    void Show(){ std::cout << m_uValue << std::endl; }

    static void CALLBACK TimerProc(HWND hWnd, UINT uMsg, 
        UINT iTimerID, DWORD dwTime)
    {
        CStopWatch *pWatch = (CStopWatch*)s_pThis;
        if(pWatch)
        {
            pWatch->AddValue();
            pWatch->Show();
        }        
    }

protected:
    unsigned int m_uValue;
    static void *s_pThis;
};

void *CStopWatch::s_pThis = NULL;

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

