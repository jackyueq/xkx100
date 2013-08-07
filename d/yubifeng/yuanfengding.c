// /yubifeng/yuanfengding.c
// Last modified by winder 2003.9.2

int do_stamp(string arg);

inherit ROOM;

void create()
{
	set("short", "Բ�嶥");
	set("long", @LONG
�嶥������ǧ��������δ���ڵļ����������ѩ����������Զ��
���ܣ�Ⱥ�����ϣ���ȼ亮��ᴩ��˻���������嶥���У���һ��΢��
��С�ѡ�
LONG );
	set("exits", ([
		"northdown" : __DIR__"yuanfeng",
	]));
	set("objects", ([
		__DIR__"npc/tong1" : 1,
		__DIR__"npc/tong2" : 1,
	]));
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5120);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_stamp","stamp");
	add_action("do_stamp","tread");
	add_action("do_stamp","cai");
	add_action("do_stamp","ta");
}

int do_stamp(string arg)
{
	object me = this_player();
	int n;

	n = me->query_skill("force", 1);

	if ( !arg || (arg != "wo" && arg != "xiaowo"))
	{
		write("��Ҫ��̤ʲôѽ��\n");
		return 1;
	}
	if(n > 100 && me->query("qi") > 1000)
	{
		message_vision("$N������һ��������׼�˷�λ��һ�����߽���ȥ��\n...\n���ߵ�Բ��֮�����Ѷ����У�������̤����Ȼ�����ɶ����������䡣\n...\n$N���з�����˫���ŵأ�����������ߡ��������ѩ����ǰ������������ͨ����\n",me);
		me->move(__DIR__"tongdao1");
	}
	else
	{
		message_vision("$N�ڷ嶥����̤ȥ���ߵñ�мѩ�����ɣ����ȫ�޶�����\n", me);
		me->receive_damage("qi",10);
	}
	return 1;
}
