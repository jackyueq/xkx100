// Room: /d/xingxiu/xxh.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "���޺�");
	set("long", @LONG
��������ɽ���µ����޺����ߡ���Բ�����ﶼ��һ���޼ʵĺ���
�����󣬵���ʮ���ն񡣵��������˳�֮Ϊ��������һ���м�ֻ��Ⱥ��
�������ڡ����������Ҳ�Ҳ����ˡ�������������������̳�����ں�
���롣
    ������һ���ݾ���ͨ������ɽ��
LONG );
	set("exits", ([
		"north"   : __DIR__"xxh1",
		"westup"  : __DIR__"tianroad3",
		"southup" : __DIR__"tianroad2",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/zhaixing" : 1,
		__DIR__"npc/gushou"  : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou" : 1,
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -50000);
	set("coor/y", 20100);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "north" && dir != "westup")
	{
		return ::valid_leave(me, dir);
	}
	else
	{
		if (objectp(present("zhaixing zi", environment(me))) && 
			living(present("zhaixing zi", environment(me))))
		{
			if ((me->query("shen") > 100))
				return notify_fail("ժ���Ӻȵ�����λ"+RANK_D->query_respect(me)+"���ߣ�\n");
		}
		return ::valid_leave(me, dir);
	}
}
