<?php
class DBC
{
	public $db;
	public $query;
	public $result;

	public function DBI()
	{
		$this->db = new mysqli('localhost', 'root', 'apmsetup', 'needprograms'); //host, id, pw, database �����Դϴ�.
		$this->db->query('SET NAMES UTF8');
		
		if(mysqli_connect_errno())
		{
			header("Content-Type: text/html; charset=UTF-8");
			echo "������ ���̽� ������ �����߽��ϴ�.";
			exit;
		}
	}

	public function DBQ()
	{
		$this->result = $this->db->query($this->query);
	}

	public function DBO()
	{
		$this->result->free;
		$this->db->close();
	}
}
?>