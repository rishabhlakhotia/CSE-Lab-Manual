<?php
session_start();

if (isset($_SESSION['views']))
    $_SESSION['views'] = $_SESSION['views'] + 1;

else
    $_SESSION['views'] = 1;

echo "page views = " . $_SESSION['views'];
?>
