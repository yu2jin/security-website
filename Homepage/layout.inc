<?php
// ������ �����մϴ�.
// ���Ŀ� ��� �� �α��� ��.
session_start();

// class�� �̿��� ��ü ���� ���
class Layout
{
	public $title="Need Programs"; // �� ������ ����
	private $menu = array('Board'=>'board', 'Programs'=>'programs', 'Notice'=>'notice');
	private $pmenu = array('��ü'=>'?tn=all', '����'=>'?tn=press');
	private $bmenu = array('��ü'=>'?tn=all', '�����Խ���'=>'?tn=press');
	public $link; // CSS ��ũ �±�
	public $style; // ��Ÿ�� ���� 
	public $content; // ���� ������
	public $board; //�Խ��� �̸� ����
	private $sub; // ���� �޴��� ����
	private $login; // �α����̳� �α׾ƿ��� ���

	// ���̾ƿ��� ���
	public function LayoutMain()
	{
		echo $this->ThisBoard(); // ���� �Խ����� �̸��� Ȯ��
		echo "<!DOCTYPE html>\n<html lang='ko'>";
		echo "<head>\n<meta charset='utf-8'/>";
		echo "<title>".$this->title."</title>";
		echo $this->LayoutStyle(); // ��Ÿ���� ���̾ƿ��� �߰�.
		echo "</head>\n<body>\n<div id='container'>";
		echo	$this->LayoutHeader(); // ��� �κ��� ���̾ƿ��� �߰�
		echo	$this->LayoutContent(); // ������ �κ��� ���̾ƿ��� �߰�
		echo	$this->LayoutSide(); // ���̵� �κ��� ���̾ƿ��� �߰�
		echo	$this->LayoutFooter(); // Ǫ�� �κ��� ���̾ƿ��� �߰�
		echo "</div></body>\n</html>";
	}

	// ���� �Խ����� �̸��� Ȯ��
	public function ThisBoard()
	{
		$this->board = explode('/', $_SERVER['PHP_SELF']);
	}

	// ��Ÿ���� �߰�
	public function LayoutStyle()
	{
		echo "<link rel='stylesheet' type='text/css' href='".$this->link."'/> ";
		echo "<style>".$this->style."</style>";
	}

	// ��� �κ� �߰�
	public function LayoutHeader()
	{
		$this->LayoutLogin();
		echo "<header>
			<div id='logo'><h1><a href='/'>Need Programs</a></h1></div>
				<div id='navset'>
					<nav id='menu'>
						";
		$this->LayoutMenu($this->menu, 0); // $menu �迭�� �̿��ؼ� �޴� �κ��� ȣ��
		echo "		</nav>
					<nav id='login'>".$this->login."</nav>
				</div>
			<div class='ad_1'>
				// ���� ����
			</div>
		</header>";
	}
	
	public function LayoutMenu($menu, $side) // �迭�� <li> �� �̿��ؼ� �޴� �κ��� ȣ��
	{
		while (list($key, $value) = each($menu))
		{
			$this->ThisMenu($key, $value, $side);
        	}
	}
	
	public function ThisMenu($key, $value ,$side) //�޾ƿ� ������ �޴��� �����
	{
		if($side=='1')
		{
			if(strpos($_SERVER['REQUEST_URI'], $value)==false)
			{
				$thismenu = $thismenu."<li><a href='./".$value."'>".$key."</a></li>";
			} else
			{
				$thismenu = $thismenu."<li><b style='border-bottom:4px solid #90bbff;'>".$key."</b></li>";
			}
		} else
		{		
			if(strpos($_SERVER['PHP_SELF'], $value)==false)
			{
				$thismenu = $thismenu."<li><a href='/".$value."'>".$key."</a></li>";
			} else
			{
				$thismenu = $thismenu."<li><b style='border-bottom:4px solid #90bbff;'>".$key."</b></li>";
			}
		}
		echo $thismenu;
	}

	public function LayoutLogin()
	{
		if($_SESSION['id']=="")
		{
			if(strpos($_SERVER['PHP_SELF'], "login.php"))
			{
				$this->login="<b style='border-bottom:3px solid #90bbff;'>Login</b>";
			} else
			{
				$this->login="<a href='/login.php'>Login</a>";
			}
		} else
		{
			$this->login="<a href='/Logout.php'>Logout</a>";
		}
	}

	// ������ �߰�
	public function LayoutContent()
	{
		echo "<section><article>".$this->content."</article>";
	}

	// ���̵�� �߰�
	public function SideMenu()
	{
		$this->board=explode('/', $_SERVER['PHP_SELF']);
		switch($this->board[1])
		{
			case notice : 
				echo "<h3 style='margin: 5px 0 10px 0;text-align:center;'><a href='".$_SERVER['PHP_SELF']."'>��������</a></h3>";
				break;
			case programs : 
				echo "<h3 style='margin: 5px 0 10px 0;text-align:center;'><a href='".$_SERVER['PHP_SELF']."'>���α׷�</a></h3>";
				$this->LayoutMenu($this->pmenu, 1);
				break;
			case board : 
				echo "<h3 style='margin: 5px 0 10px 0;text-align:center;'><a href='".$_SERVER['PHP_SELF']."'>�Խ���</a></h3>";
				$this->LayoutMenu($this->bmenu, 1);
				break;
			default : 
				echo "@@@���̵�� ������";
		}
	}

	public function LayoutSide()
	{		
		echo "<aside>";
		$this->SideMenu();
		echo "</aside></section>";
	}

	// Ǫ�� �κ� �߰�
	public function LayoutFooter()
	{
		echo "<footer>Copyright �� Kurien. All rights reserved. Need Programs</footer>";
	}
}

?>