// Room: /d/nanshaolin/songshu4
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��߸ߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����
ɡ��������գ��������ڵ�˿��Ҳ�ޡ�һ���ྻ����ʯС���������С�
�����Ժ����ǽ���Ժ��Ժ��վ������ɮ�����ܵ��ػ��š�
LONG
	);
	set("outdoor","nanshaolin");
	set("exits", ([
		"west" : __DIR__ "songshu3",
		"east" : __DIR__ "jieluyuan",
	]));
	set("objects",([
		__DIR__"npc/zjseng" : 1,
		__DIR__"npc/slseng" : 1
		
	]));
	set("coor/x", 1830);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	if (dir == "east")
	{
		if( mapp(fam = me->query("family")) &&
			fam["family_name"] == "��������" &&
			fam["generation"] <= 20 )
			return ::valid_leave(me, dir);
		if( me->query("guilty") == 0 || !userp(me) &&
			me->query("id") != "seng bing" )
		{
			return notify_fail("ֻ��Ժ�ڴ���һ����������˵������δ����ɣ����ܽ������Ժ��\n");
		}
	}
	return ::valid_leave(me, dir);
}

