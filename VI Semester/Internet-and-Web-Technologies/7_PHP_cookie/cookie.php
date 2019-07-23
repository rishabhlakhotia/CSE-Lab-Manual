<?php
$inTwoMonths = 60 * 60 * 24 * 60 + time();
setcookie('lastVisit', date("h:i:s A - m/d/y"), $inTwoMonths);

if (isset($_COOKIE['lastVisit']))
    $visit = $_COOKIE['lastVisit'];

else
    echo "You've got some expired cookies!";

echo "Your last visit was - " . $visit;
?>
