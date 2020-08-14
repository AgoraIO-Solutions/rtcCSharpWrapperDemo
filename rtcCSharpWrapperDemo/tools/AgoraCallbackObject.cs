using System;

namespace agora_gaming_rtc
{
    public sealed class AgoraCallbackObject {
        public GameObject _CallbackGameObject 
        {
            get; 
            set;
        }

        public AgoraCallbackQueue _CallbackQueue {
            set;
            get;
        } 

        public string _GameObjectName {
            set;
            get;
        }  

        public AgoraCallbackObject(string gameObjectName)
        {
            InitGameObject(gameObjectName);
        }

        public void Release()
        {
            if (!ReferenceEquals(_CallbackGameObject, null))
            {
                if (!ReferenceEquals(_CallbackQueue, null))
                {
                    _CallbackQueue.ClearQueue();
                }
                GameObject.Destroy(_CallbackGameObject);
                _CallbackGameObject = null;
                _CallbackQueue = null;
            }
        }

        private void InitGameObject(string gameObjectName)
        {
            DeInitGameObject(gameObjectName);
            _CallbackGameObject = new GameObject(gameObjectName);
            _CallbackQueue = new AgoraCallbackQueue();
            GameObject.DontDestroyOnLoad(_CallbackGameObject);
        }

        private void DeInitGameObject(string gameObjectName)
        {
            GameObject gameObject = GameObject.Find(gameObjectName);
            if (!ReferenceEquals(gameObject, null))
            {
                AgoraCallbackQueue callbackQueue = gameObject.GetComponent<AgoraCallbackQueue>();
                if (!ReferenceEquals(callbackQueue, null))
                {
                    callbackQueue.ClearQueue();
                }
                GameObject.Destroy(gameObject);
                gameObject = null;
                callbackQueue = null;
            }
        }
    }

    public class GameObject
    {
        private string gameObjectName;

        private string data;

        private AgoraCallbackQueue queue;

        public GameObject(string gameObjectName)
        {
            this.gameObjectName = gameObjectName;
        }

        internal static void Destroy(GameObject gameObject)
        {

        }

        internal static void DontDestroyOnLoad(GameObject callbackGameObject)
        {

        }

        internal static GameObject Find(string gameObjectName)
        {
            return new GameObject("");
        }

        internal T AddComponent<T>()
        {
            return default(T);
        }

        internal T GetComponent<T>()
        {
            return default(T);
        }
    }
}