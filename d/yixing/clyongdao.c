// /d/yixing/clbajiaoting.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
��������ͨ��һ��ʯ�ң��Ա߱���ÿ����Զ����һյ�͵ƣ�ͷ��
�Ǹ߸ߵĹ������Ե���Щ��ɭ�ɲ�������������������أ������˵Ȳ�
������ǰ����
LONG );
	set("exits", ([
		"east" : __DIR__"clshishi",
		"west" : __DIR__"clhuayuan",
	]));
	set("objects",([
		__DIR__"npc/cl_bangzhong" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if( dir != "east" ) return ::valid_leave(me, dir);
	if( !(ob = present("changle bangzhong", environment(me))) )
		 return ::valid_leave(me, dir);
	if( !living(ob) ) return ::valid_leave(me, dir);
	return notify_fail(sprintf("%s��������ǰ��˵���������ǹ�Ѻ������ͽ�ĵط�������ذɡ�\n", ob->name()));
}

