// Room: /d/lingxiao/boot.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
������һ����ɽ��ɽ´��̧ͷ������ɽ�ϻ�ѩ���������չ���ӳ��
��˸���ԡ�ɽ���ƺ���ã��ѩ�����������⽻���ڰ������ѩ֮�䣬��
���ܿ�����һ������ɽ����·����һ��ľ��(sign)��
LONG ); 
	set("item_desc", ([
		"sign": HIG"���"+HIC"����"+HIW"һ��ë"NOR+"\n"
	]) );
	set("exits",([
		"southeast"  : "/d/xuedao/sroad3",
		"westup"  : __DIR__"sroad1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("outdoors", "lingxiao");
	set("coor/x", -31000);
	set("coor/y", -9000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

