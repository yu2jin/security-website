<?php
require_once './layout.inc';

$base = new Layout;

$base->link = './style.css';
$base->content = "
<form action='./registo.php' method='post'>
	<table style='margin:0 auto; margin-top:5%;'>
		<tr>
			<th colspan='2'>ȸ������</th>
		</tr>
		<tr>
			<td>���̵�</td>
			<td><input type='text' size='16' name='id' placeholder='���̵�'/></td>
		</tr>
		<tr>
			<td>��й�ȣ</td>
			<td><input type='password' size='16' name='pass1' placeholder='��й�ȣ'/></td>
		</tr>
		<tr>
			<td>��й�ȣ Ȯ��</td>
			<td><input type='password' size='16' name='pass2' placeholder='��й�ȣ Ȯ��'/></td>
		</tr>
		<tr>
			<td>�̸���</td>
			<td><input type='text' size='16' name='mail' placeholder='�̸���'/></td>
		</tr>
		<tr>
			<td colspan='2' style='text-align:center;'><input type='submit' value='���'/></td>
		</tr>
	</table>
</form>
";

$base->LayoutMain();
?>