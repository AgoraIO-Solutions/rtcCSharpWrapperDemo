#ifndef WRAPPER_PACKET_OBSERVER
#define WRAPPER_PACKET_OBSERVER
#include "../common_header.h"
#include <queue>

namespace agora {
    namespace unity {
        class PacketObserver : public IPacketObserver
        {   
            private:
                FUNC_OnReceiveAudioPacket funcOnReceiveAudioPacket = NULL;
                FUNC_OnReceiveVideoPacket funcOnReceiveVideoPacket = NULL;
                FUNC_OnSendAudioPacket funcOnSendAudioPacket = NULL;
                FUNC_OnSendVideoPacket funcOnSendVideoPacket = NULL;
                std::mutex _funcOnReceiveAudioMutex;
                std::mutex _funcOnReceiveVideoMutex;
                std::mutex _funcOnSendAudioMutex;
                std::mutex _funcOnSendVideoMutex;

            public:
                PacketObserver();
                ~PacketObserver();
                virtual bool onReceiveAudioPacket(Packet& packet);
                virtual bool onReceiveVideoPacket(Packet& packet);
	            virtual bool onSendAudioPacket(Packet& packet);
	            virtual bool onSendVideoPacket(Packet& packet);
                virtual void resetData();
                virtual void initEventOnPacketCallback(FUNC_OnReceiveAudioPacket onReceiveAudioPacket, FUNC_OnReceiveVideoPacket onReceiveVideoPacket, FUNC_OnSendAudioPacket onSendAudioPacket, FUNC_OnSendVideoPacket onSendVideoPacket);
        };
    }
}
#endif
