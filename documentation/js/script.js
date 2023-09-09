document.getElementById('toggleSidebar').addEventListener('click', function () {
    var sidebar = document.getElementById('sidebar');
    var toggleButton = document.getElementById('toggleSidebar');
  
    sidebar.classList.toggle('collapsed');
    sidebar.classList.toggle('expanded');
  
    // Toggle the collapsed class on the button
    toggleButton.classList.toggle('collapsed');
    toggleButton.classList.toggle('expanded');
  });
  