// Room: /d/baituo/tangwu.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
һ��������ݣ���������̫ʦ�ζ���̴��ľ�Ƴɡ������ǰѳߴ�
��һ���ĵ�̫ʦ�θ��ǲ������������й���һ�Ҷ�(bian)������ƫ��
�ķ��Ű��ڣ����������档
LONG);
	set("item_desc", ([
		"bian" : HIW"
	    ��������������������������������������������
	    ��������������������������������������������       
	    ��������    ��    ��    ɽ    ׯ    ��������
	    ��������������������������������������������
	    ��������������������������������������������\n"NOR,		
	]));
	set("exits", ([
		"south" : __DIR__"menlang",
		"west"  : __DIR__"zhailuo",
		"east"  : __DIR__"shuifang",
		"north" : __DIR__"tuitang",
	]));
	set("coor/x", -50010);
	set("coor/y", 20052);
	set("coor/z", 30);
	set("no_clean_up", 0);
	setup(); 
	replace_program(ROOM);
}
