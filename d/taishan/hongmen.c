// Room: /d/taishan/hongmen.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "���Ź�");
	set("long", @LONG
���Ź�������Ϫ����������룬��̩ɽ��Ϫ���Ż����ʰ��հ���
�ռ䡣�ټӹ�ǰ���ذ�ɫʯ�������٣�����һ��ߵʹ��䡢ɫ��������
�������ݵĹŽ���Ⱥ���Է��Ƹ󶴱���������е���ʯ�����ӡ��Թ���
���������ա�֮���������Թ�����ʫ�����賿�Ǻ��ţ���ɫ�����񡣸�
������̣�ƽ�뾡���̡���
LONG );
	set("exits", ([
		"east"      : __DIR__"mileyuan",
		"northeast" : __DIR__"xiaodongtian",
		"northup"   : __DIR__"yitian",
		"southdown" : __DIR__"baihe",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 550);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
