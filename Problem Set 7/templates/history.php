
<table class="table table-striped">

    <thead align= "center">
        <tr>
            <th>Symbol</th>
            <th>Transaction</th>
            <th>Shares</th>
            <th>Price</th>
            <th>Date & Time</th>
            
        </tr>
    </thead>                           
	<tbody align= "left">
<?php foreach ($history as $position): ?>

    <tr>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["transaction"] ?></td>
        <td><?= $position["shares"] ?></td>
         <td>$<?= $position["price"] ?></td>
        <td><?= $position["d&t"]?></td>
        
    </tr>

<?php endforeach ?>
	</tbody>
</table>

