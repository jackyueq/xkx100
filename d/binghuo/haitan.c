// Room: /binghuo/haitan.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���𵺺�̲");
	set("long", @LONG
����һ������ĵ��졣�����Ļ�����ΧһƬ���̣�������������
��ʯ��᾵�ɽ�壬���ι�����Ī����״����Щɽ����ǻ�ɽ���۽�ǧ
�������ѻ����ɡ�����ȴ��һƬ��������ͷ��ƽҰ���˻�ɽ��������
�뺣�ж��ɡ��ô���Ȼ�ؽ������������ɽ���겻�𣬵���������
����ɽ��������һ�����ƣ���ɽ��������ѩ��ƽҰ��ȴ��Ŀ���̣���
�ɴ�أ��ߴ��쳣����������滨��������Ϊ�������ޡ��⵺�ϼ���
���������������չŲ���Ļ�ߣ��㱻��Ϊ���𵺡�
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"east"   : __DIR__"caodi1",
		"west"   : __DIR__"shulin1",
		"north"  : __DIR__"pingyuan1",
		"enter"  : __DIR__"southboat1",
	]));
	setup();
}

void init()
{
	object me;
	me=this_player();
	me->set("startroom",base_name(environment(me)));
	return;
}
