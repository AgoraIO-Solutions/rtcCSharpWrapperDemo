#include "PacketObserver.h"

namespace agora {
    namespace unity {

        PacketObserver::PacketObserver()
        {
            resetData();
        }

        PacketObserver::~PacketObserver()
        {
            resetData();
        }

        void PacketObserver::resetData()
        {
            _funcOnReceiveAudioMutex.lock();
            funcOnReceiveAudioPacket = NULL;
            _funcOnReceiveAudioMutex.unlock();
            _funcOnReceiveVideoMutex.lock();
            funcOnReceiveVideoPacket = NULL;
            _funcOnReceiveVideoMutex.unlock();
            _funcOnSendAudioMutex.lock();
            funcOnSendAudioPacket = NULL;
            _funcOnSendAudioMutex.unlock();
            _funcOnSendVideoMutex.lock();
            funcOnSendVideoPacket = NULL;
            _funcOnSendVideoMutex.unlock();
        }
        
        bool PacketObserver::onSendAudioPacket(Packet& packet)
        {
            _funcOnSendAudioMutex.lock();
            if (funcOnSendAudioPacket != NULL)
            {
                if(funcOnSendAudioPacket(packet.buffer, &packet.size))
                {
                    _funcOnSendAudioMutex.unlock();
                    return true;
                }
                else
                {
                    _funcOnSendAudioMutex.unlock();
                    return false;
                }
            }
            _funcOnSendAudioMutex.unlock();
            return true;
        }

        bool PacketObserver::onSendVideoPacket(Packet& packet)
        {
            _funcOnSendVideoMutex.lock();
            if (funcOnSendVideoPacket != NULL)
            {
                if(funcOnSendVideoPacket(packet.buffer, &packet.size))
                {
                    _funcOnSendVideoMutex.unlock();
                    return true;
                }
                else
                {
                    _funcOnSendVideoMutex.unlock();
                    return false;
                }
            }
            _funcOnSendVideoMutex.unlock();
            return true;
        }

        bool PacketObserver::onReceiveAudioPacket(Packet& packet)
        {
            _funcOnReceiveAudioMutex.lock();
            if (funcOnReceiveAudioPacket != NULL)
            {
                if(funcOnReceiveAudioPacket(packet.buffer, &packet.size))
                {
                    _funcOnReceiveAudioMutex.unlock();
                    return true;
                }
                else
                {
                    _funcOnReceiveAudioMutex.unlock();
                    return false;
                }
            }
            _funcOnReceiveAudioMutex.unlock();
            return true;
        }

        bool PacketObserver::onReceiveVideoPacket(Packet& packet)
        {
            _funcOnReceiveVideoMutex.lock();
            if (funcOnReceiveVideoPacket != NULL)
            {
                if(funcOnReceiveVideoPacket(packet.buffer, &packet.size))
                {
                    _funcOnReceiveVideoMutex.unlock();
                    return true;
                }
                else
                {
                    _funcOnReceiveVideoMutex.unlock();
                    return false;
                }
            }
            _funcOnReceiveVideoMutex.unlock();
            return true;
        }

        void PacketObserver::initEventOnPacketCallback(FUNC_OnReceiveAudioPacket onReceiveAudioPacket, FUNC_OnReceiveVideoPacket onReceiveVideoPacket, FUNC_OnSendAudioPacket onSendAudioPacket, FUNC_OnSendVideoPacket onSendVideoPacket)
        {
            _funcOnReceiveAudioMutex.lock();
            funcOnReceiveAudioPacket = onReceiveAudioPacket;
            _funcOnReceiveAudioMutex.unlock();
            _funcOnReceiveVideoMutex.lock();
            funcOnReceiveVideoPacket = onReceiveVideoPacket;
            _funcOnReceiveVideoMutex.unlock();
            _funcOnSendAudioMutex.lock();
            funcOnSendAudioPacket = onSendAudioPacket;
            _funcOnSendAudioMutex.unlock();
            _funcOnSendVideoMutex.lock();
            funcOnSendVideoPacket = onSendVideoPacket;
            _funcOnSendVideoMutex.unlock();
        }
    }
}