#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <memory>

class GraphNode;                                                                // forward declaration
class ChatLogic;                                                                // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                                                                  // constructor WITHOUT memory allocation
    ChatBot(std::string filename);                                              // constructor WITH memory allocation
    ~ChatBot();

    // Copy(assignment) constructors and move(assignment) constructors for Chatbot
    ChatBot(const ChatBot &chatbot_src);
    ChatBot &operator=(const ChatBot &chatbot_src);
    ChatBot(ChatBot &&chatbot_src);
    ChatBot &operator=(ChatBot &&chatbot_src);


    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
