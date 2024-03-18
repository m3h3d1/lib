document.addEventListener('DOMContentLoaded', function() {
  const darkModeButton = document.querySelector('.dark-mode-button');
  const iconDark = document.getElementById('icon-dark');
  const iconLight = document.getElementById('icon-light');

  // Toggle between light and dark mode
  function toggleDarkMode() {
    const isEnabled = localStorage.getItem('dark-mode') === 'true';
    if (isEnabled) {
      disableDarkMode();
    } else {
      enableDarkMode();
    }
  }

  // Enable dark mode
  function enableDarkMode() {
    DarkReader.setFetchMethod(window.fetch);
    DarkReader.enable();
    localStorage.setItem('dark-mode', 'true');
    iconDark.style.display = 'none';
    iconLight.style.display = 'inline';
  }

  // Disable dark mode
  function disableDarkMode() {
    DarkReader.disable();
    localStorage.setItem('dark-mode', 'false');
    iconDark.style.display = 'inline';
    iconLight.style.display = 'none';
  }

  // Initialize dark mode based on user preference or stored value
  function initializeDarkMode() {
    const prefersDarkMode = window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches;
    const isEnabled = localStorage.getItem('dark-mode') === 'true';
    if ((isEnabled || prefersDarkMode) && DarkReader.isEnabled()) {
      enableDarkMode();
    } else {
      disableDarkMode();
    }
  }

  // Event listener for dark mode toggle button
  darkModeButton.addEventListener('click', toggleDarkMode);

  // Initialize dark mode
  initializeDarkMode();
});
