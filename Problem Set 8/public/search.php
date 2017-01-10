<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

		$_GET["geo"] .= "%";		
		$places = query("SELECT * FROM `places` WHERE(`place_name` LIKE ? OR `admin_name1` LIKE  ? OR `postal_code` LIKE  ?) LIMIT 20",$_GET["geo"],$_GET["geo"],$_GET["geo"]);
	
    // output places as JSON (pretty-printed for debugging convenience)
       header("Content-type: application/json");
       print(json_encode($places, JSON_PRETTY_PRINT));

?>
