#include "MetaDataObserver.h"

 namespace agora {
     namespace unity {
        MetaDataObserver::~MetaDataObserver()
        {
            clearData();
        }

        MetaDataObserver::MetaDataObserver()
        {
            _metadata.buffer = NULL;
        }

        void MetaDataObserver::sendMetadata(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStampMs)
        {
            _metaMutex.lock();
            _metadata.uid = uid;
            _metadata.size = size;
            _metadata.buffer = buffer;
            _metadata.timeStampMs = timeStampMs;
            _metaMutex.unlock();
        }

        bool MetaDataObserver::onReadyToSendMetadata(Metadata &metadata)
        {
            if (funcOnReadyToSendMetadata != NULL)
            {
                bool rc = funcOnReadyToSendMetadata();
                _metaMutex.lock();
                if (_metadata.buffer != NULL)
                {
                    metadata.uid = _metadata.uid;
                    metadata.timeStampMs = _metadata.timeStampMs;
                    metadata.size = _metadata.size;
                    memcpy(metadata.buffer, _metadata.buffer, _metadata.size);
                    _metadata.buffer = NULL;
                }
                _metaMutex.unlock();
                if(rc)
                { 
                    return true;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }

        void MetaDataObserver::onMetadataReceived(const Metadata &metadata)
        {
           if (funcOnMetadataReceived != NULL)
           {
                funcOnMetadataReceived(metadata.uid, metadata.size, metadata.buffer, metadata.timeStampMs);
           }
        }

        int MetaDataObserver::getMaxMetadataSize()
        {
            if (funcOnGetMaxMetadataSize != NULL)
            {
                return funcOnGetMaxMetadataSize();
            }
            return metaDataSize;
        }

        void MetaDataObserver::initEventOnMetaDataCallback(FUNC_OnMetadataReceived onMetadataReceived, FUNC_OnReadyToSendMetadata onReadyToSendMetadata, FUNC_OnGetMaxMetadataSize onGetMaxMetadataSize)
        {
            funcOnMetadataReceived = onMetadataReceived;
            funcOnReadyToSendMetadata = onReadyToSendMetadata;
            funcOnGetMaxMetadataSize = onGetMaxMetadataSize;
        }

        void MetaDataObserver::clearData()
        {
            funcOnMetadataReceived = NULL;
            funcOnReadyToSendMetadata = NULL;
            funcOnGetMaxMetadataSize = NULL;
        }
     }
 }
