import nltk
from nltk.chat.util import Chat, reflections

s
pairs = [
    ["hi|hello|hey", ["Hello!", "Hey there!", "Hi! How can I help you?"]],
    ["how are you?", ["I'm doing great, thanks!", "I'm fine. What about you?"]],
    ["(.*) your name?", ["I'm a chatbot!", "Call me AI Assistant."]],
    ["what can you do?", ["I can chat with you, answer questions, and assist with tasks."]],
    ["bye|goodbye", ["Goodbye!", "See you later!", "Take care!"]]
]


chatbot = Chat(pairs, reflections)


print("Hello! I am your chatbot. Type 'bye' to exit.")
chatbot.converse()

