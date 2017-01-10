<!DOCTYPE html>

<html>

    <head>

        <link href="/css/bootstrap.min.css" rel="stylesheet"/>
        <link href="/css/bootstrap-theme.min.css" rel="stylesheet"/>
        <link href="/css/styles.css" rel="stylesheet"/>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">

 

        <?php if (isset($title)): ?>
            <title>C$50 Finance: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>C$50 Finance</title>
        <?php endif ?>

        <script src="/js/jquery-1.11.1.min.js"></script>
        <script src="/js/bootstrap.min.js"></script>
        <script src="/js/scripts.js"></script>

    </head>

    <body>

        <div class="container">

            <div id="top">
                <a href="/"><img alt="C$50 Finance" src="/img/logo.gif"/></a>
            </div>
        	<?php if($_SESSION != []): ?>
        	<div style = "position:relative;padding-left:390px;">
        	<ul class="nav nav-pills" >
        		 <li><i class="material-icons" style="font-size:35px;color:red;"><a href="/">home</a></i></li>
        		 <li> <a href="/quote.php">QUOTE</a></li>
 				 <li> <a href="/buy.php">BUY</a></li>
 				 <li><a href="/sell.php">SELL</a></li>
 				 <li><a href="/history.php">HISTORY</a></li>
 				 <li class="dropdown">
      				<a class="dropdown-toggle" data-toggle="dropdown" href="#"><i class="material-icons" style="font-size:20px;">menu</i></a>
      					<ul class="dropdown-menu">
        				<li><a href="/chgpass.php">Change Password</a></li>
        				<li><a href="/logout.php"><b>Log Out</b></a></li>                        
      					</ul>
    			 </li>
 			</ul>
 			</div>
 			<?php endif ?>

            <div id="middle">
