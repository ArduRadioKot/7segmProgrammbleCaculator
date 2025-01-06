document.addEventListener('DOMContentLoaded', () => {
    const portSelect = document.getElementById('port');

    // Populate COM ports
    const ports = ['COM1', 'COM2', 'COM3'];
    ports.forEach(port => {
        const option = document.createElement('option');
        option.value = port;
        option.textContent = port;
        portSelect.appendChild(option);
    });

    // Initialize CodeMirror
    const codeArea = CodeMirror(document.getElementById('editor'), {
        lineNumbers: true,
        mode: 'javascript',
        theme: 'default', // Use your custom theme here
        autoCloseBrackets: true,
        matchBrackets: true,
        lineWrapping: true
    });

    // Custom command to change colors
    codeArea.addKeyMap({
        'Ctrl-C': function(cm) {
            const selectedText = cm.getSelection();
            // Implement your custom command logic here
            console.log('Selected text:', selectedText);
        }
    });

    document.getElementById('uploadButton').addEventListener('click', uploadCode);
    document.getElementById('openButton').addEventListener('click', openFile);
    document.getElementById('saveButton').addEventListener('click', saveFile);
    document.getElementById('quitButton').addEventListener('click', quit);

    function uploadCode() {
        const code = codeArea.getValue();
        const port = portSelect.value;
        console.log(`Uploading code to ${port}:`, code);
        alert('Code sent to Arduino!');
    }

    function openFile() {
        // Implement file opening logic here
    }

    function saveFile() {
        // Implement file saving logic here
    }

    function quit() {
        // Implement quit logic here
    }
});