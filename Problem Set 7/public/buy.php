<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    	$cash = query("SELECT `cash` FROM `users` WHERE id = ? ",$_SESSION["id"]);
    	$cash = $cash[0];
    	$stock = lookup($_POST["symbol"]);
    	$cas = $stock["price"]*$_POST["shares"];
    	if($stock["name"] == "")
    		apologize("No such stock with this symbol");
    	else if( !preg_match("/^\d+$/", $_POST["shares"]))
    		apologize("Please input exact shares");
    	elseif($cas > $cash["cash"])
    		apologize("insuuficient balance");
    	 elseif(query("SELECT * FROM `tbl` WHERE id = ? AND symbol = ?",$_SESSION["id"],$_POST["symbol"]) == true)
    	{
    	$S=query("UPDATE `tbl` SET `shares`= shares + ? , `purchase` = (purchase + ?)/2 WHERE (id = ? AND symbol = ?)", $_POST["shares"],$stock["price"], $_SESSION["id"] ,strtoupper($_POST["symbol"]));
 		}
    	else 
    	{
    		$s=query("INSERT INTO `tbl`(`id`, `symbol`, `shares`,`purchase`) VALUES (?,?,?,? / shares)",$_SESSION["id"],strtoupper($_POST["symbol"]),$_POST["shares"],$cas);
    	}
 		
 		$s=query("INSERT INTO `history`(`id`, `d&t`, `transaction`, `symbol`, `shares`,`price`) VALUES ( ?,NOW(),?,?,?,?)", $_SESSION["id"],"BUY",strtoupper ($_POST["symbol"]),$_POST["shares"],number_format($stock["price"], 2, '.', ','));
 		
 		$S=query("UPDATE `users` SET `cash` = cash - ?  WHERE id = ? ", $cas,$_SESSION["id"]);
    	redirect("index.php");
    }
    
    
    	
  ?>
