// Room: /d/nanshaolin/celang1.c
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
		"west"      : __DIR__"sengshe4", 
		"south"     : __DIR__"stoneroad4", 
		"northwest" : __DIR__"huaishu2",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

