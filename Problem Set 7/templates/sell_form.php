<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="symbol" style="width:160px">
                <option value=""></option>
                <?php 
                	$stocks = query("SELECT * FROM `tbl` WHERE id = ?",$_SESSION["id"]);
                	foreach ($stocks as $stock): ?>
                <option<?= " value = ".$stock["symbol"]." > ".$stock["symbol"] ."----(".$stock["shares"].")"?></option>
                <?php endforeach ?>   
            </select>	
        </div>
        <div class="form-group">
            <input autofocus class="form-control" name="shares" placeholder="no. of shares" type="text" size="15"/>
        </div>     	
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>
