// Room: /d/yanping/xianxialing.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "��ϼ��");
	set("long", @LONG
������������ˮ����ϼ�롣���������������дУ������˳�����
��β�ɡ���;��ɽ·ʮ�����У������Ŀ���Ҳ��������������Խ��Խ��
�Ա�ʶ�ˡ�
LONG );
	set("exits", ([
		"northdown" : "/d/jiaxing/jnroad4",
		"south"     : __DIR__"erbapu",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));
	set("outdoors", "jiangnan");
	set("coor/x", 1500);
	set("coor/y", -3000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
