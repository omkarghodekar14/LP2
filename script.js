const patterns = [
    { pattern: "hi", response: "Hello! How can I help you?" },
    { pattern: "hello", response: "Hi there!" },
    { pattern: "name", response: "I am a simple chatbot." },
    { pattern: "how are you", response: "I'm always here to assist you." },
    { pattern: "bye", response: "Goodbye! Have a great day." }
];

document.addEventListener("DOMContentLoaded", function () {
    const chatBox = document.querySelector(".chatbox");
    const inputField = document.querySelector(".chat-input textarea");
    const sendBtn = document.querySelector("#send-btn");

    function addMessage(message, isUser) {
        const messageElement = document.createElement("li");
        messageElement.classList.add("chat", isUser ? "outgoing" : "incoming");
        messageElement.innerHTML = `<p>${message}</p>`;
        chatBox.appendChild(messageElement);
        chatBox.scrollTop = chatBox.scrollHeight; // Auto-scroll to the latest message
    }

    function getResponse(userInput) {
        userInput = userInput.toLowerCase();
        for (let pattern of patterns) {
            if (userInput.includes(pattern.pattern)) {
                return pattern.response;
            }
        }
        return "Sorry, I didn't understand that.";
    }

    function handleUserInput() {
        const userMessage = inputField.value.trim();
        if (userMessage === "") return;

        addMessage(userMessage, true); // Show user message
        setTimeout(() => {
            const botResponse = getResponse(userMessage);
            addMessage(botResponse, false); // Show bot response
        }, 500);

        inputField.value = ""; // Clear input field
    }

    sendBtn.addEventListener("click", handleUserInput);
    inputField.addEventListener("keypress", function (event) {
        if (event.key === "Enter" && !event.shiftKey) {
            event.preventDefault();
            handleUserInput();
        }
    });
});
