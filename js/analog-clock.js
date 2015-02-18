(function ($) {
  Drupal.behaviors.analogClock = {
    attach: function (context, settings) {

      var settings = Drupal.settings.advance_clock.settings;

      if (settings.show_date == 1) {
        $('.analog-clocks .timezone').each(function (i) {

          var tz = $(this).data('location');
          var now = moment().tz(tz);

          if (settings.show_date) {
            $(this).find('.date').html(now.format("d MMM YYYY"));
          }
        });
      }

      // Run a timer every second and update the clock
      (function update_time() {

        var now = moment();

        //update  time
        $('.analog-clocks .timezone').each(function (i) {
          var tz = $(this).data('location');
          var now = moment().tz(tz);
          var second = now.seconds() * 6;
          var minute = now.minutes() * 6 + second / 60;
          var hour = ((now.hours() % 12) / 12) * 360 + minute / 60;

          $(this).find('.hour').css("transform", "rotate(" + hour + "deg)");
          $(this).find('.min').css("transform", "rotate(" + minute + "deg)");
          $(this).find('.sec').css("transform", "rotate(" + second + "deg)");

        });

        setTimeout(update_time, 1000);

      })();
    }
  }

})(jQuery);
