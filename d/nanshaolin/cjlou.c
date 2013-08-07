// Room: /d/nanshaolin/cjlou.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ؾ���һ¥");
	set("long", @LONG
������������ֲؾ��󡣴˴��ؾ�֮����������ɽ��Ժ�����º���
��ƥ�����ﶼ���������飬�߼��������ܣ���ܼ��������һ��ͨ��
�Ŀ�϶�����Ŵ�����м䣬����ط������ɳ���������Ŀ�⼰�����㿴
�����Ϸ��˼����𾭡�
LONG );
	set("exits", ([
		"out" : __DIR__"xiaoxi1",
		"up"  : __DIR__"cjlou1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dachi" : 1,
		BOOK_DIR+"fojing1" : random(2),
	]));
	set("coor/x", 1890);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
        if( !present("shou yu", me) &&
		(objectp(present("dachi dashi", environment(me)))) )
	{
		if (dir == "up" )
		{
			return notify_fail("��մ�ʦ˵��: ��δ����ɣ������϶�¥��\n");
		}
	}
	return ::valid_leave(me, dir);
}

