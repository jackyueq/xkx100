// Room: /wuliang/shanlu7.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��ɽ��ɽ·�����￪ʼ������ʯ�̵档�����ŵ�������ɬ���͡�
���µ�ɽ·ת��һ��ɽ�ꡣɽ����ð�����̣�����ʮ����֮�࣬����
ɽ��ˮ��ĵط������������е㲻�Ծ���
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"northup"   : __DIR__"shanlu8",
		"southdown" : __DIR__"shanlu6",
	]));
	set("objects", ([
		__DIR__"npc/rong" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79970);
	set("coor/z", 60);
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (objectp(present("rong ziju", environment(me))) &&
		dir == "northup")
           return notify_fail("���Ӿ���ס��˵����ũ����Ű�����Ǻ��ˣ��ѱ����Ǽ�ϸ��������ɽ��\n");
        return ::valid_leave(me, dir);
}