// Room: /d/baihuagu/tree1.c
// Last Modified by Winder on Mar. 5 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ�ڰ�����ɴ��۾�����ǿ�������һ�㡣һ��ϸϸ
�Ĺ���(light)͸���������Ҷ�ķ������������ƺ�Ԥʾ������ϣ����
LONG);
	set("outdoors", "baihuagu");
	set("exits", ([ 
		"north": __DIR__"tree",  
		"west" : __DIR__"tree",
		"south": __DIR__"tree",
		"east" : __DIR__"tree",
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_go","go");
	add_action("do_look","look");
}
int do_look(string arg)
{
	string *dirc = ({ "��","��","��","��","��"});
	int i;
	i=random(4)+1;
	if (!arg||!(arg=="light" || arg=="����"))
		return notify_fail("��Ҫ��ʲ�᣿\n");
	message_vision(HIW "$N��ϸ�۲����,�������Ǵ�"+dirc[i]+"��͸�����ġ�\n" NOR,this_player());
	this_object()->set_temp("marks/�ٻ���",i);
	return 1;
}
int do_go(string arg)
{
	string *dira=({"+-*/","east","south","west","north"});
	string *dirb=({"+-*/","e","s","w","n"});
	int a;
	a=(int)this_object()->query_temp("marks/�ٻ���");
	this_object()->set_temp("marks/�ٻ���",0);
	if (arg==dira[a]||arg==dirb[a])
	{
		this_player()->move(__DIR__"out");
	}
	else
		if(random(4)) this_player()->move(__DIR__"tree");
		else this_player()->move(__DIR__"bhgent");
	return 1;
}
