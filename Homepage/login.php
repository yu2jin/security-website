<?php
require_once './layout.inc';
require_once './db.php';

$base = new Layout;

$base->link = './style.css';

$db = new DBC;
$db->DBI();

$id = $_POST['logid'];
$pass = $_POST['logpass'];

$db->query = "select id, pass, permit from member where id='".$id."' and pass=password('".$pass."')";
$db->DBQ();

$num = $db->result->num_rows;
$data = $db->result->fetch_row();

$db->DBO();

if($num==1)
{
	$_SESSION['id'] = $id;
	$_SESSION['permit'] = $data[2];
	echo "<script>location.replace('/');</script>";
} else if(($id!="" || $pass!="") && $data[0]!=1)
{
	echo "<script>alert('���̵�� ��й�ȣ�� ���� �ʽ��ϴ�.');</script>";
}

$base->content = "
<form action='".$_SERVER['PHP_SELF']."' method='post'>
	<table style='margin:0 auto; margin-top:5%;'>
		<tr>
			<th colspan='2'>�α���</th>
		</tr>
		<tr>
			<td><input type='text' name='logid'size='16' placeholder='���̵�'/></td>
			<td rowspan='2'><input type='submit' value='�α���' style='height:50px;'/></td>
		</tr>
		<tr>
			<td><input type='password' name='logpass' size='16' placeholder='��й�ȣ'/></td>
		</tr>
		<tr>
			<td><a href='./registi.php'>���</a></td>
			<td style='text-align:right;'><a href='./find.php'>ã��</a></td>
		</tr>
	</table>
</form>
";

$base->LayoutMain();
?>