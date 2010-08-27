Drupal.behaviors.hippelicious_settings = function (context) {
  $('select#edit-style').each(function() {
    $(this).change(function() {
      if ($(this).val() == 'custom') {
        $('.hippelicious-custom-settings').show('medium');
      }
      else {
        $('.hippelicious-custom-settings').hide('medium');
      }
    });
  });

  // Add Farbtastic
  var target = $('#edit-background-color', context);
  if (target) {
    var farb = $.farbtastic('div#hippelicious-colorpicker', target);
    target
      .focus(function() {
        $('div#hippelicious-colorpicker').show('medium');
      })
      .blur(function() {
        $('div#hippelicious-colorpicker').hide('medium');
      });
  }
};
