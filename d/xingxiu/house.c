// /d/xingxiu/house.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
����һ�������ҵ�ͥԺ���ſڴ���������Ͷ��Ժ������˾��ú�
���졣Ժ�Ӷ����ǰ����Ŀ��������߾����������֡�
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"yili",
	    "east" : __DIR__"house1",
	]));
	set("objects", ([
		__DIR__"npc/kid": 1,
		__DIR__"npc/bayi": 1
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");

	set("coor/x", -38900);
	set("coor/y", 13000);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) &&
		objectp(present("bayi", environment(me))) && 
		dir == "east")
		return notify_fail("����˵���ҰѰ���������ҵĿ������ˣ�˭Ҳ�����ȥ��\n");
	return ::valid_leave(me, dir);
}
