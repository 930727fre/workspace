// Select all radio buttons on the page
var radioButtons = document.querySelectorAll('input[type="radio"]');

// Iterate through each radio button
radioButtons.forEach(function(radioButton) {
    // Check if the label text is "同意"
    if (radioButton.labels[0].textContent.trim() === '同意') {
        // Click the radio button
        radioButton.click();
    }
    if (radioButton.labels[0].textContent.trim() === '2-3小時') {
        // Click the radio button
        radioButton.click();
    }
    if (radioButton.labels[0].textContent.trim() === '90分以上') {
        // Click the radio button
        radioButton.click();
    }        
    if (radioButton.labels[0].textContent.trim() === '75%以上') {
        // Click the radio button
        radioButton.click();
    }
    if (radioButton.labels[0].textContent.trim() === '是') {
        // Click the radio button
        radioButton.click();
    }
    if (radioButton.labels[0].textContent.trim() === '教師安排的課程內容難易度適中') {
        // Click the radio button
        radioButton.click();
    }            
});

// Function to toggle the state of checkboxes based on label text
function toggleCheckbox(labelText) {
    var checkboxes = document.querySelectorAll('input[type="checkbox"]');
    checkboxes.forEach(function(checkbox) {
        if (checkbox.labels[0].textContent.trim() === labelText) {
            checkbox.checked = !checkbox.checked;
        }
    });
}

// Example usage
toggleCheckbox('教師安排的課程內容難易度適中');

// Select the textarea by its id
var textarea = document.getElementById('textarea1');

// Set the value of the textarea to "謝謝教授"
textarea.value = '謝謝教授';
