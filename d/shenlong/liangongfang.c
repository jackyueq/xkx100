// liangongfang.c ������
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������ܵ�����������������������ż������ţ���λ��
���̳�������ϥ���������������ı�����һЩ���ӣ������з����˸���
ҩ�ơ������Ϸ��ż��������̴Ӹ����Ի���ڹ��ķ����ӡ�
LONG
	);
	set("exits", ([
		"south" : __DIR__"zhulin2",
	]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_practice", "practice");
	add_action("do_practice", "lian");
}

int do_practice(string arg)
{
	object me = this_player();
	string skill;
	int lvl;

	if( (int)me->query("sg/exp") < 5000 )
	{
		message("vision", 
			"ֻ��һλ�����̳��ϰ�"+me->name() + "һ�����˳�ȥ��\n",
			environment(me), ({me}));
		me->move(__DIR__"zhulin1");
		message_vision("$N�������̳������˳�����\n", me);
		return 1;
	}

	if( !arg ) return ("/cmds/skill/enable")->main(me, arg);

	if(arg == "strike" && me->query_skill_mapped(arg) == "huagu-mianzhang" )
		return 0;

	write("��������ϰ�������Ƶĳ�����\n");
	return 1;
}

