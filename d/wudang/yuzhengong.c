//Room: yuzhengong.c ���湬
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","���湬");
	set("long",@LONG
�����ǽ����䵱ɽ�ĵ�һ���������湬�����ޱȣ�����ǧ��ʳ�ޣ�
�ǽ���͵�һ��Ъ�Ŵ��������������ڴ˽�����������˹��й�������
�����������������˱չ��Ѿã����˲�֪���Ƿ������˼䣬��䴫˵
���ѵõ����ţ�����Ĥ�ݡ�
LONG);
	set("objects", ([
	     CLASS_D("wudang") +"/zhixiang": 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
	    "northdown": __DIR__"shijie1",
	    "southup"  : __DIR__"wdbl",
	]));
	set("coor/x", -2050);
	set("coor/y", -820);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( dir == "southup" &&
		me->query("wudang/offerring")<me->query("age") &&
		me->query("title") != "�䵱��ͯ" &&
		me->query("family/family_name") != "�䵱��" &&
		objectp(present("lingxu daozhang", environment(me))) &&
		!objectp(present("incense", me)) )
	{
		return notify_fail("��������ȵ����粻����ɽ���㣬������أ�\n");
	}
	return ::valid_leave(me, dir);
}
