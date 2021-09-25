#include <iostream>
#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>
#include <GroupsockHelper.hh>

static char const* inputFileName = "test.264";

int main(int argc, char* argv[])
{
    /* ���������� */
    TaskScheduler* scheduler = BasicTaskScheduler::createNew();
    UsageEnvironment* env = BasicUsageEnvironment::createNew(*scheduler);

    /* ����rtsp������ */
    RTSPServer* rtspServer = RTSPServer::createNew(*env, 8554);
    if (rtspServer == NULL)
    {
        *env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
        return -1;
    }

    /* �����Ự */
    ServerMediaSession* sms = ServerMediaSession::createNew(*env, "live", "test", "test");
    
    /* ����ӻỰ */
    sms->addSubsession(H264VideoFileServerMediaSubsession::createNew(*env, inputFileName, True));
    
    /* ���������ӻỰ */
    rtspServer->addServerMediaSession(sms);

	char* url = rtspServer->rtspURL(sms);
	// *env << 
    std::cout<<"Play this stream using the URL \"" << url << "\"\n";
	delete[] url;

    /* ѭ�������¼� */
    env->taskScheduler().doEventLoop();

    return 0;
}
