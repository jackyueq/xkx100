// Room: /d/shenlong/hechuan.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "�Ӵ�");
	set("long", @LONG
����һ��װ�λ����ĺӴ������в��õ��������Ź뷿������������
���ǵ������һ�㣬���͵ð������Ȳ��ѡ���������������ҩ�������
����֫����˫�ۻ��ǡ�
LONG
	);
	set("exits", ([
		"out" : "/d/forest/bank2",
	]));
	set("objects", ([
		__DIR__"npc/lan" : 1,
	]));
	set("outdoors", "shenlong");
	setup();
}

void init()
{
	object me = this_player();
	int lose, period, lvl;

	if( interactive(me = this_player()) )
	{
		if( lvl = me->query_skill("force", 1) > 149 ) return;

		write("��⣡���ж��ˣ���һ����������ѡ�\n");
		lose = 140 - lvl;
		if( lose < 0 ) lose = 0;
		lose += 10;

		me->add_temp("apply/damage", -lose);
		me->add_temp("apply/attack", -lose);
		me->add_temp("apply/dodge", -lose);

		period = 1000 / (5 + me->query_skill("force", 1));
		if( period < 1 ) period = 1;
		period += random(period);

		call_out("recover", period, me, lose);
	}
}
	
void recover(object me, int lose)
{
	 me->add_temp("apply/damage", lose);
	 me->add_temp("apply/attack", lose);
	 me->add_temp("apply/dodge", lose);
	 write("���˹�Ƭ�̣����ڽ��඾�Ƴ��е�ȫ����̹��\n");
}
