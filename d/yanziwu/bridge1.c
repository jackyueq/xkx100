// Room: /d/yanziwu/bridge1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������С·�����������������˵��ˣ�ÿÿ������·��������С
��������������û������һ����ζ���������������к�Ҷ���������
Ծ���������ޡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"path10",
		"north"  : __DIR__"path11",
	]));
	set("coor/x", 1240);
	set("coor/y", -1230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}