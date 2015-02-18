(function ($) {
  Drupal.behaviors.digitalClock = {
    attach: function (context, settings) {

      var settings = Drupal.settings.advance_clock.settings;

      if (settings.hr_format == 0) {
        var format = "hh:mm";
      } else {
        var format = "HH:mm";
      }
      if (settings.show_sec == 1) {
        format += ":ss";
      }

      if (settings.show_date == 1) {
        $('.digital-clocks .timezone').each(function (i) {

          var tz = $(this).data('location');
          var now = moment().tz(tz);

          if (settings.show_date) {
            $(this).find('.date').html(now.format("d MMM YYYY"));
          }
        });
      }

      // Update the clock
      (function update_time() {

        var now = moment().format(format);

        //update  time
        $('.digital-clocks .timezone').each(function (i) {
          var tz = $(this).data('location');
          var now = moment().tz(tz);
          $(this).find('.digits').html(now.format(format));
          if (settings.hr_format == 0) {
            $(this).find('.ampm').html(now.format("A"));
          }
        });

        if (settings.show_sec == 1) {
          // Schedule this function to be run again in 1 sec
          setTimeout(update_time, 1000);
        } else {
          // Schedule this function to be run again in 1 min
          setTimeout(update_time, 60000);
        }

      })();
    }
  }

})(jQuery);
