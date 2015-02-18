<?php
/**
 * @file
 * digital clock template to display a list of rows.
 *
 * - $clocks : list of clocks with time zone, city name and time difference
 * - $settings : settings for clocks
 * @ingroup advance_clock > templates
 */
?>
<?php
$clocks = $variables['clocks'];
$settings = $variables['settings'];
?>
<div class="container">
  <div class="digital-clocks">
    <ul>
      <?php
      foreach ($clocks as $key => $clock) {
        ?>
        <li class="digital-clock">
          <div class="timezone"
               data-location="<?php print $clock['timezone'];?>">
            <div class="city">
              <?php
              if ($settings['show_city']) {
                print $clock['city'];
              }
              else {
                print $clock['timezone'];
              }
              ?>
            </div>
            <div class="display">
              <span class="digits"></span>
              <span class="ampm"></span>
              <div class="date"></div>
            </div>
          </div>
        </li>
      <?php
      }
      ?>
    </ul>
  </div>
</div>
