// Room: /d/nanshaolin/celang2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�������������ȡ�����������������Ҳ�ò�������˸��ַ����ͼ
�Σ����������ֱʣ��˵�׳��������������һƬ�����֣����ﻨ������
���������Ŀ�������������ɮ������Ϣ�õ�ɮ�ᡣ   
LONG );
	set("exits", ([
		"northeast" : __DIR__"songshu3",
		"south"     : __DIR__"stoneroad3",
		"east"      : __DIR__"sengshe1",   
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

