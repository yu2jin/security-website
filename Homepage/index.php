<?php
include_once "./layout.inc"; // ���̾ƿ��� include �� 

$base = new Layout; // Layout class ��ü�� ����

$base->link='./style.css'; // ��Ÿ�� �߰�
$base->content="<a href='#'>��ũ</a>������ ���� �κ��Դϴ�."; //������ ����

$base->LayoutMain(); //���� �������� �Էµ� ��ü�� ���
?>