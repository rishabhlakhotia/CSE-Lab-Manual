<html>
  <body>
    <form action="11a.php">
        NAME:<input type="text" name="name1"><br />
        add1:<input type="text" name="addr1"><br />
        add2:<input type="text" name="addr2"><br />
        email:<input type="text" name="emails"><br />
        Submit:<input type="submit">
      </form>

      <form action="11b.php">
        Name:<input type="text" name="name"><br />
        Submit:<input type="submit">
    </form>
  </body>
</html>


<?php
  mysql_connect("localhost", "root", "fedora") or die(mysql_error());
  mysql_select_db("student") or die(mysql_error());

  $name  = $_GET['name1'];
  $add1  = $_GET['addr1'];
  $add2  = $_GET['addr2'];
  $email = $_GET['emails'];

  echo "hello" . $name;
  $query = "insert into i values('$name','$add1','$add2','$email')";

  mysql_query($query) or die(mysql_error());
  echo "INSERTED";
?>


<?php
  mysql_connect("localhost", "root", "fedora") or die(mysql_error());
  mysql_select_db("student") or die(mysql_error());

  $name = $_GET['name'];
  $res  = mysql_query("select * from i where n='$name'");

  echo "<table border='1'>";
  echo "<tr><th>Name</th><th>Address1</th><th>Address2</th><th>EmailID</th></tr>";

  while ($arr = mysql_fetch_row($res))
      echo "<tr><td>$arr[0]</td><td>$arr[1]</td><td>$arr[2]</td><td>$arr[3]</td>";
  echo "</table>";
?>
