// Room: /yangzhou/ouxiangqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ź����");
	set("long",@LONG
ź���ž��������ţ�λ�������¶��ϲ࣬��������������֧������
���ֺɻ������������ºӣ��������ź󣬺��ϻ����Թ������ţ�������
�����š�
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"northwest" : __DIR__"lianxingsi",
		"southeast" : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}