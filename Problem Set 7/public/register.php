<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
       if($_POST["username"] == "")
       apologize("Invalid Username");
       else if($_POST["password"] == "")
       apologize("Invalid PASSWORD");
       else if($_POST["password"] != $_POST["check"])
       apologize("RETRY -> Password didn't match");
       else if(query("INSERT INTO users (username,hash,cash) VALUES( ? , ? ,10000.00)", $_POST["username"],crypt($_POST["password"]))===false)
       apologize("Please use any other username");
       else 
       {
       	$row = query("SELECT LAST_INSERT_ID() AS id");
       	$id = $row[0]["id"];
       	$_SESSION["id"] = $id;
       	redirect("index.php");
       }
    }

?>

