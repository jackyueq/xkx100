// Room: /d/baihuagu/tree.c ����
// Last Modified by Winder on Mar. 5 2001
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ�ڰ�����ɴ��۾������õ�������·���ֺ��󵽴�
������·�������ڴ�������ʧ�˷����Ⱳ�Ӿͱ�������߳�ȥ�ˡ�
LONG);
	set("outdoors", "baihuagu");
	set("exits", ([ 
		"north": __DIR__"treen",  
		"west" : __DIR__"treew",
		"south": __DIR__"trees",
		"out"  : __DIR__"ent",
		"east" : __DIR__"treee",
	]));
	set("coor/x", -450);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_go","go");
}
int do_go()
{
	if(random(40)<(this_player()->query("kar")))
	{
		this_player()->move(__DIR__"tree1");
		return 1;
	}
	else
		if(random(5))
		{
			this_player()->move(this_object());
			return 1;
		}
}
