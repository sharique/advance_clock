<?php
/**
 * @file
 * Analog clock template to display a list of rows.
 *
 * Variables
 * - $clocks : list of clocks with time zone, city name and time difference
 * - $settings : settings for clocks
 *
 * @ingroup advance_clock > templates
 */
?>
<?php
$clocks = $variables['clocks'];
$settings = $variables['settings'];
?>
<div class="container">
  <div class="analog-clocks">
    <ul>
      <?php
      foreach ($clocks as $key => $clock):
        ?>
        <li class="analog-clock">
          <div class="timezone"
               data-location="<?php print $clock['timezone']; ?>">
            <div class="city">
              <?php
              if ($settings['show_city']):
                print $clock['city'];
              else:
                print $clock['timezone'];
              endif;
              ?>
            </div>
            <div class="display">
              <ul class="dial">
                <li class="sec"></li>
                <li class="min"></li>
                <li class="hour"></li>
              </ul>
            </div>
            <div class="date"></div>
          </div>
        </li>
      <?php
      endforeach;
      ?>
    </ul>
  </div>
</div>
