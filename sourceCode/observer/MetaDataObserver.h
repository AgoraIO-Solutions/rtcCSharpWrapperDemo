#ifndef WRAPPER_META_DATA_OBSERVER
#define WRAPPER_META_DATA_OBSERVER
#include "../common_header.h"
#include <queue>

namespace agora{
    namespace unity{
        class MetaDataObserver : public IMetadataObserver
        { 
            private:
                FUNC_OnMetadataReceived funcOnMetadataReceived = NULL;
                FUNC_OnReadyToSendMetadata funcOnReadyToSendMetadata = NULL;
                FUNC_OnGetMaxMetadataSize funcOnGetMaxMetadataSize = NULL;
                int metaDataSize = 1024;
                Metadata _metadata;
                std::mutex _metaMutex;


            public: 
                ~MetaDataObserver();
                MetaDataObserver();    

                virtual int getMaxMetadataSize();
                virtual bool onReadyToSendMetadata(Metadata &metadata);
                virtual void onMetadataReceived(const Metadata &metadata);
                virtual void initEventOnMetaDataCallback(FUNC_OnMetadataReceived onMetadataReceived, FUNC_OnReadyToSendMetadata onReadyToSendMetadata, FUNC_OnGetMaxMetadataSize onGetMaxMetadataSize);
                virtual void clearData();
                virtual void sendMetadata(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStamps);
        };
    }
}
#endif
