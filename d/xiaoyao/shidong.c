// shidong.c
// Modified by Winder June.25 2000

inherit ROOM;
int do_push(string arg);

void create()
{
	set("short", "Բ��ʯ��");
	set("long", @LONG
������Բ��ʯ�ң����������͸�������������ʵز�����⡣ϸ��
��⴦������һ�ȴ�����Ȼ������ʯ�ڵ�һ���ˮ����Լ��ͭ���С��
�������ˮ����͸�롣һβ��Ϻ�ڴ����ι�������һ�����ư��õ�����
�ڴ���Ȼ������˫������ˮ��������ȥ��ֻ������ˮ����ס�϶�����Ϻ
ˮ�������ζ�����Ŀ���������޾�����ԭ������֮�ؾ���ˮ�ף�������
ʯ��֮�˻���ټ����������������ˮ�����˽���������ˮ�����Ǽ�
�ѵõı�����з���һֻʯ������ǰ�еʣ����ϼ���һͭ�������Է�
��Щ��������֮�����������ǹ�����ӡ�ͭ��(mirror)������ͭ�̣���
��Ҳ�ǳ����������֪���ж������������ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"damen",
		"east" : __DIR__"shiji2",
		"west" : __DIR__"shiji1",
	]));
	set("item_desc", ([
		"mirror" : "��������һ��б�õ�ͭ����ӳ���������磬ʯ��\n������һ���졣\n",
	]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/first" :1,
	]));
	set("coor/x", -50020);
	set("coor/y", -21040);
	set("coor/z", -40);
	setup();
}

void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg!="stone") return 0;
	write("��æ������ȥ��ʹ������ʯ�ڡ�\n");
	if(random((int)me->query("kar")) < 10 ||
		me->query_skill("beiming-shengong",1) <= 40 )
	{
                write("��ʯ���Ʋ����ġ�\n");
		return 1;
	};
	write("��Ȼ��һ���ţ������ƿ���¶��һ������\n");
	this_object()->set("exits/north","/d/xiaoyao/shishi3");
	return 1;
}