// Room: /heizhao/shiliang3.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ����͹��ƽ���ּ�����������֮�У�ʯ���ﻬ�쳣���ߵ�Խ
��������Խ�������ʯ���������Ȼ�жϣ�Լ���߰˳߳���һ��ȱ
�ڣ�ȱ�ڱ˶���ϥ����һ����������������һ���飬�������С���
�����������һ���̶̵�ȱ�ڡ�ȱ���Ǳ�һƬ�����������ҡҷ��
һ�����
LONG );
	set("outdoors", "taoyuan");
	set("no_fight", 1);
	set("objects", ([
		CLASS_D("dali")+"/yideng/du" : 1,
	]));
	set("exits", ([
		"south"  : __DIR__"shiliang2",
		"north"  : __DIR__"hetang",
	]));
	set("coor/x", -5020);
	set("coor/y", -1230);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}