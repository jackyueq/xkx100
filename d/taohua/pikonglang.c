// Room: /d/taohua/pikonglang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������ȴ���С��͸�����죬���Կ���������Խ��塣��
����ȥ���ǰ������ϵĴ󺣣������ϰ�Ÿ���ɷ�����ȥ�����ǡ������
��ɡ���������һ�˰���һ�ų��������Ϸ���һ����̨������һ�ŵ���
��(lazhu)��
LONG
	);
        set("item_desc", ([ 
		"lazhu" : "�����ں�����ҡҷ��һ���ƵĹ⣬�������һ��(pai)�ͻ�������ӡ�\n",
	]));
        set("exits", ([ 
		"north" : __DIR__"zoulang4",
	]));
	set("outdoors","taohua");
	set("no_clean_up", 0);
	set("coor/x", 9020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_pai", "pai");
}
int do_pai(string arg)
{       
        mapping fam;
	object me = this_player();

	if (arg != "lazhu")
		return notify_fail("����ʲô�ģ������Ӱ���\n");
	if (!living(me)) return 0;
	if (!(fam = me->query("family")) || fam["family_name"] != "�һ���")
		return notify_fail("��Ǳ������ӣ������ڴ�������\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("�����������̨�������͵�һ�������Ӧ�ֶ���\n");
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("����������̨���������������ζ�û��һ�Σ�\n");
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	write( "����������̨�������͵�һ�������ҡҡ�λξ�Ȼû��\n");
	return 1;
}